options gen2
require flecs/flecs_boost

// Port of flecs examples/c/entities/fwd_declare_component
//
// In C, ECS_COMPONENT declares a function-local variable with the component id, so other
// functions need ECS_COMPONENT_DECLARE. In daslang the component id is looked up by type
// with ecs_id(world, type<T>), from any function, so nothing has to be forward declared.
// Entity handles (tags, plain entities) are still ordinary variables.

// The component type
struct Position {
    x : double
    y : double
}

// Forward declared entity handles
var Wizard : ecs_entity_t
var Platoon_1 : ecs_entity_t

def create_npc(world : ecs_world_t?) : ecs_entity_t {
    let result = ecs_new(world)

    // The component id is found from the type: no forward declaration needed
    ecs_set(world, result, Position(x = 10.0lf, y = 20.0lf))
    ecs_add_id(world, result, Wizard)
    ecs_add_id(world, result, Platoon_1)

    return result
}

[export]
def main() {
    var world = ecs_init()

    // Register the component
    ecs_id(world, type<Position>)

    // Same for the tag
    Wizard = ecs_tag(world, "Wizard")

    // A forward declared entity can be assigned as any variable
    Platoon_1 = ecs_new(world)

    // Create new entity with Position
    let e = create_npc(world)
    let p = ecs_get(world, e, type<Position>)
    print("\{{p.x:.6f}, {p.y:.6f}\}\n")

    // To access the component id directly, use ecs_id
    print("Id of Position is {int(ecs_id(world, type<Position>))}\n")

    flecs_fini(world)
}

// Output:
//  {10.000000, 20.000000}
//  Id of Position is 19
