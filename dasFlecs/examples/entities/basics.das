options gen2
require flecs/flecs_boost

// Port of flecs examples/c/entities/basics

struct Position {
    x : double
    y : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)
    let Walking = ecs_tag(ecs, "Walking")

    // Create an entity with name Bob
    let bob = ecs_set_name(ecs, 0ul, "Bob")

    // The set operation finds or creates a component, and sets it.
    ecs_set(ecs, bob, Position(x = 10.0lf, y = 20.0lf))
    // The add operation adds a component without setting a value. This is
    // useful for tags, or when adding a component with its default value.
    ecs_add_id(ecs, bob, Walking)

    // Get the value for the Position component
    let ptr = ecs_get(ecs, bob, type<Position>)
    print("\{{ptr.x:.6f}, {ptr.y:.6f}\}\n")

    // Overwrite the value of the Position component
    ecs_set(ecs, bob, Position(x = 20.0lf, y = 30.0lf))

    // Create another named entity
    let alice = ecs_set_name(ecs, 0ul, "Alice")
    ecs_set(ecs, alice, Position(x = 10.0lf, y = 20.0lf))
    ecs_add_id(ecs, alice, Walking)

    // Print all the components the entity has. This will output:
    //    Position, Walking, (Identifier,Name)
    let str = ecs_take(ecs_type_str(ecs, ecs_get_type(ecs, alice)))
    print("[{str}]\n")

    // Remove tag
    ecs_remove_id(ecs, alice, Walking)

    // Iterate all entities with Position
    ecs_each(ecs, type<Position>) $(it) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            for (i in range(it.count)) {
                print("{ecs_get_name(ecs, ecs_iter_entity(it, i))}: \{{p[i].x:.6f}, {p[i].y:.6f}\}\n")
            }
        }
    }

    flecs_fini(ecs)

}

// Output:
//  {10.000000, 20.000000}
//  [Position, Walking, (Identifier,Name)]
//  Alice: {10.000000, 20.000000}
//  Bob: {20.000000, 30.000000}
