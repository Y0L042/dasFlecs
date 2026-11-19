options gen2
require flecs/flecs_boost

// flecs examples/c/hello_world in the C++-style API: FlecsWorld / FlecsEntity handles and a
// typed-block system. Same output as hello_world/hello_world.das.

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
    var world = FlecsWorld()

    // Register system. The block's typed arguments are the query: Position (read-write),
    // Velocity (read-only). The body runs once per matched entity.
    ecs_system(world, "Move", EcsOnUpdate) $(it : ecs_iter_t const?; var p : Position; v : Velocity) {
        // Print the set of components of the table the entity is in
        print("Move entities with [{ecs_take(ecs_table_str(it.stage, it._table))}]\n")
        p.x += v.x
        p.y += v.y
    }

    // Register tags (components without a size)
    let eats = world.entity("Eats")
    let apples = world.entity("Apples")
    world.entity("Pears")

    // Create an entity with name Bob, add Position and food preference
    let bob = world.entity("Bob").set(Position(x = 0.0lf, y = 0.0lf)).set(Velocity(x = 1.0lf, y = 2.0lf)).add(eats, apples)

    // Run systems twice. Usually this function is called once per frame
    world.progress()
    world.progress()

    // See if Bob has moved (he has)
    let p = bob.get(type<Position>)
    print("Bob's position is \{{p.x:.6f}, {p.y:.6f}\}\n")

    world.fini()
}

// Output:
//  Move entities with [Position, Velocity, (Identifier,Name), (Eats,Apples)]
//  Move entities with [Position, Velocity, (Identifier,Name), (Eats,Apples)]
//  Bob's position is {2.000000, 4.000000}
