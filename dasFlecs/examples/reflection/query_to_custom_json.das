options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/query_to_custom_json
//
// Same example as query_to_json, but with customized serializer parameters

struct Position {
    x : float
    y : float
}

struct Velocity {
    x : float
    y : float
}

struct Mass {
    value : float
}

def xy_struct(ecs : ecs_world_t?; e : ecs_entity_t) {
    var desc : ecs_struct_desc_t
    desc.entity = e    // Make sure to use existing id
    desc.members[0].name = "x"
    desc.members[0]._type = ecs_id_ecs_f32_t
    desc.members[1].name = "y"
    desc.members[1]._type = ecs_id_ecs_f32_t
    ecs_struct_init(ecs, unsafe(addr(desc)))
}

[export]
def main() {
    var ecs = ecs_init()

    // Register component as usual
    ecs_id(ecs, type<Position>)
    ecs_id(ecs, type<Velocity>)
    ecs_id(ecs, type<Mass>)

    // Add reflection data to components
    xy_struct(ecs, ecs_id(ecs, type<Position>))
    xy_struct(ecs, ecs_id(ecs, type<Velocity>))

    var mdesc : ecs_struct_desc_t
    mdesc.entity = ecs_id(ecs, type<Mass>)    // Make sure to use existing id
    mdesc.members[0].name = "value"
    mdesc.members[0]._type = ecs_id_ecs_f32_t
    ecs_struct_init(ecs, unsafe(addr(mdesc)))

    let a = ecs_set_name(ecs, 0ul, "a")
    let b = ecs_set_name(ecs, 0ul, "b")
    let c = ecs_set_name(ecs, 0ul, "c")
    let d = ecs_set_name(ecs, 0ul, "d")

    ecs_set(ecs, a, Position(x = 10.0, y = 20.0))
    ecs_set(ecs, b, Position(x = 20.0, y = 30.0))
    ecs_set(ecs, c, Position(x = 30.0, y = 40.0))
    ecs_set(ecs, d, Position(x = 40.0, y = 50.0))

    ecs_set(ecs, a, Velocity(x = 1.0, y = 2.0))
    ecs_set(ecs, b, Velocity(x = 2.0, y = 3.0))
    ecs_set(ecs, c, Velocity(x = 3.0, y = 4.0))
    ecs_set(ecs, d, Velocity(x = 4.0, y = 5.0))

    ecs_set(ecs, c, Mass(value = 10.0))
    ecs_set(ecs, d, Mass(value = 20.0))

    // Query for components
    var q = ecs_query(ecs, "Position, Velocity")
    var it = ecs_query_iter(ecs, q)

    // Serialize query to JSON. Customize serializer to only serialize entity
    // names and component values.
    var desc : ecs_iter_to_json_desc_t
    desc.serialize_values = true
    print("{ecs_take(ecs_iter_to_json(unsafe(addr(it)), unsafe(addr(desc))))}\n")

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  {"results":[{"name":"a"}, {"name":"b"}, {"name":"c"}, {"name":"d"}]}
