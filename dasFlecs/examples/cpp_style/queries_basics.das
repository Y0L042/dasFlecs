options gen2
require flecs/flecs_boost

// flecs examples/c/queries/basics in the C++-style API. The typed block is the query; it
// is built once ([CACHED]: a cached flecs query) and reused by later runs of this line.

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
    var world = FlecsWorld()

    // Create a few test entities for a Position, Velocity query
    world.entity("e1").set(Position(x = 10.0lf, y = 20.0lf)).set(Velocity(x = 1.0lf, y = 2.0lf))
    world.entity("e2").set(Position(x = 10.0lf, y = 20.0lf)).set(Velocity(x = 3.0lf, y = 4.0lf))

    // This entity will not match as it does not have Position, Velocity
    world.entity("e3").set(Position(x = 10.0lf, y = 20.0lf))

    // Iterate entities matching Position, [in] Velocity
    ecs_query(world) $ [CACHED] (e : FlecsEntity; var p : Position; v : Velocity) {
        p.x += v.x
        p.y += v.y
        print("{e.name()}: \{{p.x:.6f}, {p.y:.6f}\}\n")
    }

    // The same query as an object, from the query builder (C++ world.query_builder())
    var q = world.query_builder().with_(type<Position>).with_(type<Velocity>).in_().cached().build()
    verify(q.count() == 2)
    q.destruct()

    world.fini()
}

// Output:
//  e1: {11.000000, 22.000000}
//  e2: {13.000000, 24.000000}
