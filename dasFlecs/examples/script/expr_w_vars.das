options gen2
require flecs/flecs_boost

// Port of flecs examples/c/script/expr_w_vars
//
// This example shows how to run an expression that uses variables. Variables
// make it possible to change the inputs to an expression after the expression
// has been parsed. This example also shows how to parse an expression and
// evaluate it multiple times.

[export]
def main() {
    var world = ecs_init()

    // Declare variables that we'll use in the expression
    var vars = ecs_script_vars_init(world)
    let x = ecs_script_vars_define_id(vars, "x", ecs_id_ecs_i32_t)
    let y = ecs_script_vars_define_id(vars, "y", ecs_id_ecs_i32_t)

    // Assign values to variables
    unsafe {
        *reinterpret<int?>(x.value.ptr) = 10
        *reinterpret<int?>(y.value.ptr) = 20
    }

    // Declare value that will hold the expression result. Specify that we want
    // the returned value to be of type i32. If the expression type doesn't
    // match the specified type, it will be casted.
    var result = 0
    var result_value : ecs_value_t
    result_value._type = ecs_id_ecs_i32_t
    result_value.ptr = unsafe(addr(result))

    // Parse expression
    var desc : ecs_expr_eval_desc_t
    desc.vars = vars
    var s = ecs_expr_parse(world, "$x + $y", unsafe(addr(desc)))
    if (s == null) {
        print("failed to parse expression\n")
        return
    }

    // Evaluate expression with variables
    if (ecs_expr_eval(s, unsafe(addr(result_value)), unsafe(addr(desc))) != 0) {
        print("failed to evaluate expression\n")
        return
    }

    print("result = {result}\n")

    // Change variable and reevaluate expression
    unsafe {
        *reinterpret<int?>(y.value.ptr) = 30
    }
    if (ecs_expr_eval(s, unsafe(addr(result_value)), unsafe(addr(desc))) != 0) {
        print("failed to evaluate expression\n")
        return
    }

    print("result = {result}\n")

    // Free resources
    ecs_script_vars_fini(vars)
    ecs_script_free(s)

    flecs_fini(world)
}

// Output:
//  result = 30
//  result = 40
