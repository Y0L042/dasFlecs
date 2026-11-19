options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/auto_define_enum
//
// ECS_ENUM / ECS_STRUCT capture the type body as a string; ecs_meta_from_desc
// parses that string into reflection data (see auto_define_struct).

enum Color {
    Red
    Black
    White
    StainlessSteel
}

struct Car {
    brand : string
    color : Color
    speed : float
}

// Color is used by Car, so it must also be captured
let Color_desc = "\{ Red, Black, White, StainlessSteel \}"
let Car_desc = "\{ const char *brand; Color color; float speed; \}"

[export]
def main() {
    var ecs = ecs_init()

    // Register both components. Note that Color is registered first, so that
    // when Car is registered, the type information of Color can be looked up
    ecs_meta_from_desc(ecs, ecs_id(ecs, type<Color>), ecs_type_kind_t.EcsEnumType, Color_desc)
    ecs_meta_from_desc(ecs, ecs_id(ecs, type<Car>), ecs_type_kind_t.EcsStructType, Car_desc)

    // Serialize as usual
    var value = Car(brand = "Delorean", color = Color.StainlessSteel, speed = 1.21)
    let json = ecs_take(ecs_ptr_to_json(ecs, ecs_id(ecs, type<Car>), unsafe(addr(value))))
    print("{json}\n")    // {"brand": "Delorean", "color": "StainlessSteel", "speed": 1.21}

    flecs_fini(ecs)
}

// Output:
//  {"brand":"Delorean", "color":"StainlessSteel", "speed":1.2100000381}
