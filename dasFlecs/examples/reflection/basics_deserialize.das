options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/basics_deserialize

struct Position {
    x : float
    y : float
}

[export]
def main() {
    var ecs = ecs_init()

    // Register component as usual
    ecs_id(ecs, type<Position>)

    // Add reflection data to component
    var desc : ecs_struct_desc_t
    desc.entity = ecs_id(ecs, type<Position>)    // Make sure to use existing id
    desc.members[0].name = "x"
    desc.members[0]._type = ecs_id_ecs_f32_t      // builtin float type
    desc.members[1].name = "y"
    desc.members[1]._type = ecs_id_ecs_f32_t
    ecs_struct_init(ecs, unsafe(addr(desc)))

    // Create entity, set value of position using reflection API
    let ent = ecs_entity(ecs, "ent")
    var ptr = ecs_ensure(ecs, ent, type<Position>)
    let pos_id = ecs_id(ecs, type<Position>)

    var cur = ecs_meta_cursor(ecs, pos_id, ptr)
    ecs_meta_push(unsafe(addr(cur)))              // {
    ecs_meta_set_float(unsafe(addr(cur)), 10.0lf) //   10
    ecs_meta_next(unsafe(addr(cur)))              //   ,
    ecs_meta_set_float(unsafe(addr(cur)), 20.0lf) //   20
    ecs_meta_pop(unsafe(addr(cur)))               // }

    print("{ecs_take(ecs_ptr_to_expr(ecs, pos_id, ptr))}\n")    // {x: 10.00, y: 20.00}

    // Use member names before assigning values
    cur = ecs_meta_cursor(ecs, pos_id, ptr)
    ecs_meta_push(unsafe(addr(cur)))              // {
    ecs_meta_member(unsafe(addr(cur)), "y")       //   y:
    ecs_meta_set_float(unsafe(addr(cur)), 10.0lf) //   10
    ecs_meta_member(unsafe(addr(cur)), "x")       //   x:
    ecs_meta_set_float(unsafe(addr(cur)), 20.0lf) //   20
    ecs_meta_pop(unsafe(addr(cur)))               // }

    print("{ecs_take(ecs_ptr_to_expr(ecs, pos_id, ptr))}\n")    // {x: 20.00, y: 10.00}

    flecs_fini(ecs)
}

// Output:
//  {x: 10, y: 20}
//  {x: 20, y: 10}
