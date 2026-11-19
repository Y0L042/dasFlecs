options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/auto_define_struct
//
// In C, ECS_STRUCT captures the struct body as a string, and ECS_META_COMPONENT
// registers the component with reflection data parsed from that string. The same
// flecs function, ecs_meta_from_desc, is used here with the C-style description.

struct Position {
    x : float
    y : float
}

// Captures reflection data for Position
let Position_desc = "\{ float x; float y; \}"

[export]
def main() {
    var ecs = ecs_init()

    // This registers the component with reflection data
    let pos_id = ecs_id(ecs, type<Position>)
    ecs_meta_from_desc(ecs, pos_id, ecs_type_kind_t.EcsStructType, Position_desc)

    // Serialize as usual
    var value = Position(x = 10.0, y = 20.0)
    let json = ecs_take(ecs_ptr_to_json(ecs, pos_id, unsafe(addr(value))))
    print("{json}\n")    // {"x": 10.0, "y": 20.0}

    flecs_fini(ecs)
}

// Output:
//  {"x":10, "y":20}
