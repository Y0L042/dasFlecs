options gen2
require flecs/flecs_boost

// flecs examples/c/systems/pipeline in the C++-style API: one system from (world, name,
// phase), one from a system builder.

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

    // Create system for moving an entity in the EcsOnUpdate phase
    ecs_system(world, "Move", EcsOnUpdate) $(var p : Position; v : Velocity) {
        p.x += v.x
        p.y += v.y
    }

    // Create system for printing a Position in the EcsPostUpdate phase
    ecs_system(world.system("PrintPosition").kind(EcsPostUpdate)) $(e : FlecsEntity; p : Position) {
        print("{e.name()}: \{{p.x:.6f}, {p.y:.6f}\}\n")
    }

    // Create a few test entities for a Position, Velocity query
    world.entity("e1").set(Position(x = 10.0lf, y = 20.0lf)).set(Velocity(x = 1.0lf, y = 2.0lf))
    world.entity("e2").set(Position(x = 10.0lf, y = 20.0lf)).set(Velocity(x = 3.0lf, y = 4.0lf))

    // Run the default pipeline. This will run all systems ordered by their
    // phase. Systems within the same phase are ran in declaration order. This
    // function is usually called in a loop.
    world.progress()

    world.fini()
}

// Output:
//  e1: {11.000000, 22.000000}
//  e2: {13.000000, 24.000000}
