options gen2
require flecs/flecs_boost

// Port of flecs examples/c/entities/iterate_components

struct Position {
    x : double
    y : double
}

struct Velocity {
    x : double
    y : double
}

def iterate_components(ecs : ecs_world_t?; e : ecs_entity_t) {
    // First get the entity's type, which is a vector of (component) ids.
    let t = ecs_get_type(ecs, e)

    // 1. The easiest way to print the components is to use ecs_type_str
    print("ecs_type_str: {ecs_take(ecs_type_str(ecs, t))}\n\n")

    // 2. To print individual ids, iterate the type array with ecs_id_str
    for (i in range(t.count)) {
        let id = unsafe(t._array[i])
        print("{i}: {ecs_take(ecs_id_str(ecs, id))}\n")
    }

    print("\n")

    // 3. we can also inspect and print the ids in our own way. This is a
    // bit more complicated as we need to handle the edge cases of what can be
    // encoded in an id, but provides the most flexibility.
    for (i in range(t.count)) {
        let id = unsafe(t._array[i])

        print("{i}: ")

        if (ecs_is_pair(id)) {    // See relationships
            let rel = ecs_pair_first(ecs, id)
            let tgt = ecs_pair_second(ecs, id)
            print("rel: {ecs_get_name(ecs, rel)}, tgt: {ecs_get_name(ecs, tgt)}")
        } else {
            let comp = id & ECS_COMPONENT_MASK
            print("entity: {ecs_get_name(ecs, comp)}")
        }

        print("\n")
    }

    print("\n\n")
}

[export]
def main() {
    var ecs = ecs_init()

    // Ordinary components
    ecs_id(ecs, type<Position>)
    ecs_id(ecs, type<Velocity>)

    // A tag
    let Human = ecs_tag(ecs, "Human")

    // Two tags used to create a pair
    let Eats = ecs_tag(ecs, "Eats")
    let Apples = ecs_tag(ecs, "Apples")

    // Create an entity which all of the above
    let Bob = ecs_new(ecs)

    ecs_set(ecs, Bob, Position(x = 10.0lf, y = 20.0lf))
    ecs_set(ecs, Bob, Velocity(x = 1.0lf, y = 1.0lf))
    ecs_add_id(ecs, Bob, Human)
    ecs_add_pair(ecs, Bob, Eats, Apples)

    // Iterate & components of Bob
    print("Bob's components:\n")
    iterate_components(ecs, Bob)

    // We can use the same function to iterate the components of a component
    print("Position's components:\n")
    iterate_components(ecs, ecs_id(ecs, type<Position>))

    flecs_fini(ecs)
}

// Output:
//  Bob's components:
//  ecs_type_str: Position, Velocity, Human, (Eats,Apples)
//
//  0: Position
//  1: Velocity
//  2: Human
//  3: (Eats,Apples)
//
//  0: entity: Position
//  1: entity: Velocity
//  2: entity: Human
//  3: rel: Eats, tgt: Apples
//
//
//  Position's components:
//  ecs_type_str: Component, (Identifier,Name), (Identifier,Symbol)
//
//  0: Component
//  1: (Identifier,Name)
//  2: (Identifier,Symbol)
//
//  0: entity: Component
//  1: rel: Identifier, tgt: Name
//  2: rel: Identifier, tgt: Symbol
