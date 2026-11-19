options gen2
require flecs/flecs_boost

// Port of flecs examples/c/script/expr_run
//
// This example shows how to run an expression once. To see how to parse an
// expression and run it multiple times, see the expr_w_vars example.

[export]
def main() {
    var world = ecs_init()

    // Declare value that will hold the expression result. Specify that we want
    // the returned value to be of type i32. If the expression type doesn't
    // match the specified type, it will be casted.
    var result = 0
    var result_value : ecs_value_t
    result_value._type = ecs_id_ecs_i32_t
    result_value.ptr = unsafe(addr(result))

    // Run the expression. If the operation is successful it returns a pointer
    // to the character after the last parsed token. That is the end of the string
    // here, which das prints as "", so the pointer itself is compared with null.
    let rest = ecs_expr_run(world, "10 + 20", unsafe(addr(result_value)), null)
    if (unsafe(reinterpret<void?>(rest)) == null) {
        print("expression failed to run\n")
        return
    }

    print("result = {result}\n")

    flecs_fini(world)
}

// Output:
//  result = 30
