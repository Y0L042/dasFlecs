options gen2
require flecs/flecs_boost

// Port of flecs examples/c/script/functions
//
// This example shows how to use user-defined functions in scripts.

let code = "e \{
  Position: \{ sum(10, 20), (30).add(40) \}
\}
"

struct Position {
    x : int
    y : int
}

def sum(ctx : ecs_function_ctx_t const?; argc : int; argv : ecs_value_t const?; result : ecs_value_t?) {
    unsafe {
        *reinterpret<int64?>(result.ptr) = *reinterpret<int64?>(argv[0].ptr) + *reinterpret<int64?>(argv[1].ptr)
    }
}

[export]
def main() {
    var world = ecs_init()

    ecs_id(world, type<Position>)

    // Add reflection data to component so we can assign it in script
    var sdesc : ecs_struct_desc_t
    sdesc.entity = ecs_id(world, type<Position>)    // Make sure to use existing id
    sdesc.members[0].name = "x"
    sdesc.members[0]._type = ecs_id_ecs_i32_t
    sdesc.members[1].name = "y"
    sdesc.members[1]._type = ecs_id_ecs_i32_t
    ecs_struct_init(world, unsafe(addr(sdesc)))

    // Define a sum function
    var fdesc : ecs_function_desc_t
    fdesc.name = "sum"
    fdesc.return_type = ecs_id_ecs_i64_t
    fdesc.params[0].name = "a"
    fdesc.params[0]._type = ecs_id_ecs_i64_t
    fdesc.params[1].name = "b"
    fdesc.params[1]._type = ecs_id_ecs_i64_t
    ecs_function_init(world, fdesc) @(ctx : ecs_function_ctx_t const?; argc : int; argv : ecs_value_t const?; result : ecs_value_t?) {
        sum(ctx, argc, argv, result)
    }

    // Define an add method. A method is like a function, except that it can be
    // called on type instances, and receives the instance as first parameter.
    var mdesc : ecs_function_desc_t
    mdesc.name = "add"
    mdesc.parent = ecs_id_ecs_i64_t    // Add method to i64
    mdesc.return_type = ecs_id_ecs_i64_t
    mdesc.params[0].name = "a"
    mdesc.params[0]._type = ecs_id_ecs_i64_t
    ecs_method_init(world, mdesc) @(ctx : ecs_function_ctx_t const?; argc : int; argv : ecs_value_t const?; result : ecs_value_t?) {
        sum(ctx, argc, argv, result)
    }

    if (ecs_script_run(world, "My script", code, null) != 0) {
        print("script failed to run\n")
        return
    }

    // Get entity and Position component
    let e = ecs_lookup(world, "e")
    let p = ecs_get(world, e, type<Position>)
    print("\{x: {p.x}, y: {p.y}\}\n")

    flecs_fini(world)
}

// Output:
//  {x: 30, y: 70}
