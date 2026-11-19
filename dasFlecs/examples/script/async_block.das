options gen2
require flecs/flecs_boost

// Port of flecs examples/c/script/async_block
//
// This example shows how to await an async function from an async block. Code
// in an async block runs as a task, which is resumed each frame by ecs_progress
// until the block has completed. This means that unlike the async_await
// example, the application doesn't have to create or resume tasks.
//
// An async block can't create entities, but it can assign mut variables. When a
// mut variable is assigned, the parts of the script that depend on it are
// updated automatically.

let code = "export mut score: i32 = 0

Alice \{
  Score: \{score\}
\}

async \{
  const result = await fetch_score(\"Alice\")
  score = result
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

        // Resolve the future with the result, after which the async block can
        // resume. The callback received a reference to the future, which must be
        // released after the future is completed.
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

    // Create a managed script. Managed scripts are reactive, which means that
    // Alice's Score is updated when the async block assigns the score variable.
    var desc : ecs_script_desc_t
    desc.code = code
    let script = ecs_script_init(world, unsafe(addr(desc)))
    if (script == 0ul) {
        print("script failed to run\n")
        return
    }

    let alice = ecs_lookup(world, "Alice")

    // Each frame resumes the async block, and runs the ServerProgress system
    for (i in range(3)) {
        ecs_progress(world, 0.0)
        print("frame {i}: Alice: {ecs_get(world, alice, type<Score>).value}\n")
    }

    flecs_fini(world)
}

// Output:
//  fetch_score("Alice"): request sent
//  server: responding with 120
//  frame 0: Alice: 0
//  frame 1: Alice: 120
//  frame 2: Alice: 120
