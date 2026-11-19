options gen2
require flecs/flecs_boost

// Port of flecs examples/c/script/async_await
//
// This example shows how to register an async function, and how to await
// it from a script. Async functions don't return a result right away. Instead
// they receive a future, which can be completed at a later point in time. A
// script that awaits a future suspends until the future is completed.
//
// Scripts that use await must run as a task. A task is resumed by the
// application until the script has completed.

let code = "const score = await fetch_score(\"Alice\")

Alice \{
  Score: \{score\}
\}
"

struct Score {
    value : int
}

// Future of the request that the server hasn't responded to yet
var pending_request : ecs_script_future_t?

[export]
def main() {
    var world = ecs_init()

    ecs_id(world, type<Score>)

    var sdesc : ecs_struct_desc_t
    sdesc.entity = ecs_id(world, type<Score>)
    sdesc.members[0].name = "value"
    sdesc.members[0]._type = ecs_id_ecs_i32_t
    ecs_struct_init(world, unsafe(addr(sdesc)))

    // System that responds to the pending request
    ecs_system(world, "ServerProgress", EcsOnUpdate, "") @(it : ecs_iter_t const?) {
        if (pending_request == null) {
            return
        }

        // Resolve the future with the result, after which the script can resume.
        // The callback received a reference to the future, which must be released
        // after the future is completed.
        print("server: responding with 120\n")
        var score = 120
        var value : ecs_value_t
        value._type = ecs_id_ecs_i32_t
        value.ptr = unsafe(addr(score))
        ecs_script_future_resolve(pending_request, unsafe(addr(value)))
        ecs_script_future_release(pending_request)
        pending_request = null
    }

    // Register the async function. Unlike regular functions, the callback
    // receives a future instead of a result.
    var fdesc : ecs_async_function_desc_t
    fdesc.name = "fetch_score"
    fdesc.return_type = ecs_id_ecs_i32_t
    fdesc.params[0].name = "name"
    fdesc.params[0]._type = ecs_id_ecs_string_t
    var no_cancel : lambda<(ctx : ecs_function_ctx_t const?; future : ecs_script_future_t?) : void>
    ecs_async_function_init(world, fdesc, @(ctx : ecs_function_ctx_t const?; argc : int; argv : ecs_value_t const?; future : ecs_script_future_t?) {
        var name : string
        unsafe {
            name = *reinterpret<string?>(argv[0].ptr)
        }
        print("fetch_score(\"{name}\"): request sent\n")

        // Don't complete the future yet, but store it so the server can complete
        // it later.
        pending_request = unsafe(reinterpret<ecs_script_future_t?>(future))
    }, no_cancel)

    var script = ecs_script_parse(world, "scores", code, null, null)
    if (script == null) {
        print("script failed to parse\n")
        return
    }

    // Create a task for the script. A task runs a script until it awaits a
    // future that hasn't been completed yet.
    var task = ecs_script_task_new(script, null)

    // Resume the task each frame until the script is done
    var status = ecs_script_task_resume(task, null)
    while (status == ecs_script_task_status_t.EcsScriptTaskPending) {
        print("script is waiting\n")
        ecs_progress(world, 0.0)
        status = ecs_script_task_resume(task, null)
    }

    if (status != ecs_script_task_status_t.EcsScriptTaskDone) {
        print("script failed to run\n")
        return
    }

    ecs_script_task_free(task)
    ecs_script_free(script)

    let s = ecs_get(world, ecs_lookup(world, "Alice"), type<Score>)
    print("Alice: {s.value}\n")

    flecs_fini(world)
}
