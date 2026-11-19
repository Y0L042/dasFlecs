options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/basics

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

    // Create entity with Position as usual
    let ent = ecs_new(ecs)
    ecs_set(ecs, ent, Position(x = 10.0, y = 20.0))

    // Convert position component to flecs expression string
    let ptr = ecs_get(ecs, ent, type<Position>)
    let str = ecs_take(ecs_ptr_to_expr(ecs, ecs_id(ecs, type<Position>), ptr))
    print("{str}\n")    // {x: 10, y: 20}

    flecs_fini(ecs)
}

// Output:
//  {x: 10, y: 20}
