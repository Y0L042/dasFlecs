options gen2
require flecs/flecs_boost

// Port of flecs examples/c/hello_world

struct Position {
    x : double
    y : double
}

struct Velocity {
    x : double
    y : double
}

[export]
def main() {
    // Create the world
    var world = ecs_init()

    // Register components
    ecs_id(world, type<Position>)
    ecs_id(world, type<Velocity>)

    // Register system. System callbacks may be called multiple times, as entities are
    // grouped in tables by which components they have, and each table has its own set of
    // component arrays.
    ecs_system(world, "Move", EcsOnUpdate, "Position, Velocity") @(it : ecs_iter_t const?) {
        // Print the set of components for the iterated over entities
        let type_str = ecs_take(ecs_table_str(it.stage, it._table))
        print("Move entities with [{type_str}]\n")

        // Iterate entities for the current table
        ecs_field_view(it, type<Position>, 0) $(var p) {
            ecs_field_view(it, type<Velocity>, 1) $(var v) {
                for (pi, vi in p, v) {
                    pi.x += vi.x
                    pi.y += vi.y
                }
            }
        }
    }

    // Register tags (components without a size)
    let Eats = ecs_tag(world, "Eats")
    let Apples = ecs_tag(world, "Apples")
    ecs_tag(world, "Pears")

    // Create an entity with name Bob, add Position and food preference
    let Bob = ecs_entity(world, "Bob")
    ecs_set(world, Bob, Position(x = 0.0lf, y = 0.0lf))
    ecs_set(world, Bob, Velocity(x = 1.0lf, y = 2.0lf))
    ecs_add_pair(world, Bob, Eats, Apples)

    // Run systems twice. Usually this function is called once per frame
    ecs_progress(world, 0.0)
    ecs_progress(world, 0.0)

    // See if Bob has moved (he has)
    let p = ecs_get(world, Bob, type<Position>)
    print("Bob's position is \{{p.x:.6f}, {p.y:.6f}\}\n")

    flecs_fini(world)

}

// Output:
//  Move entities with [Position, Velocity, (Identifier,Name), (Eats,Apples)]
//  Move entities with [Position, Velocity, (Identifier,Name), (Eats,Apples)]
//  Bob's position is {2.000000, 4.000000}
