options gen2
require flecs/flecs_boost

// Port of flecs examples/c/script/rest_call
// example: no-run (runs a REST server until the process is stopped, like the C example)
//
// A function registered with ecs_function_init can be called over the REST API.

[export]
def main() {
    var world = ecs_init()

    var fdesc : ecs_function_desc_t
    fdesc.name = "sum"
    fdesc.return_type = ecs_id_ecs_i32_t
    fdesc.params[0].name = "a"
    fdesc.params[0]._type = ecs_id_ecs_i32_t
    fdesc.params[1].name = "b"
    fdesc.params[1]._type = ecs_id_ecs_i32_t
    ecs_function_init(world, fdesc) @(ctx : ecs_function_ctx_t const?; argc : int; argv : ecs_value_t const?; result : ecs_value_t?) {
        unsafe {
            let a = *reinterpret<int?>(argv[0].ptr)
            let b = *reinterpret<int?>(argv[1].ptr)
            *reinterpret<int?>(result.ptr) = a + b
        }
    }

    print("Try: curl 'http://localhost:27750/call/sum?a=10&b=20'\n")

    var app : ecs_app_desc_t
    app.enable_rest = true
    ecs_app_run(world, unsafe(addr(app)))
}
