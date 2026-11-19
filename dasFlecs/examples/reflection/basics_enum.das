options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/basics_enum

enum Color {
    Red
    Green
    Blue
}

struct TypeWithEnum {
    color : Color
}

[export]
def main() {
    var ecs = ecs_init()

    // Register components as usual
    ecs_id(ecs, type<Color>)
    ecs_id(ecs, type<TypeWithEnum>)

    // Add reflection data to components
    var edesc : ecs_enum_desc_t
    edesc.entity = ecs_id(ecs, type<Color>)    // Make sure to use existing id
    edesc.constants[0].name = "Red"
    edesc.constants[0].value = int64(Color.Red)
    edesc.constants[1].name = "Green"
    edesc.constants[1].value = int64(Color.Green)
    edesc.constants[2].name = "Blue"
    edesc.constants[2].value = int64(Color.Blue)
    ecs_enum_init(ecs, unsafe(addr(edesc)))

    var sdesc : ecs_struct_desc_t
    sdesc.entity = ecs_id(ecs, type<TypeWithEnum>)    // Make sure to use existing id
    sdesc.members[0].name = "color"
    sdesc.members[0]._type = ecs_id(ecs, type<Color>)
    ecs_struct_init(ecs, unsafe(addr(sdesc)))

    // Create entity with TypeWithEnum as usual
    let ent = ecs_new(ecs)
    ecs_set(ecs, ent, TypeWithEnum(color = Color.Green))

    // Convert TypeWithEnum component to flecs expression string
    let ptr = ecs_get(ecs, ent, type<TypeWithEnum>)
    let str = ecs_take(ecs_ptr_to_expr(ecs, ecs_id(ecs, type<TypeWithEnum>), ptr))
    print("{str}\n")    // {color: Green}

    flecs_fini(ecs)
}

// Output:
//  {color: Green}
