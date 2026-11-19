options gen2
require flecs/flecs_boost

// flecs examples/c/queries/hierarchies in the C++-style API: [CASCADE(parent)] reads the
// parent's WorldTransform, parents before children; parent is null for the root.

struct LocalTransform {
    x : double
    y : double
}

struct WorldTransform {
    x : double
    y : double
}

[export]
def main() {
    var world = FlecsWorld()

    // Whenever we add LocalTransform, also add WorldTransform
    world.component(type<LocalTransform>).entity().add(EcsWith, world.component(type<WorldTransform>))

    // Create a hierarchy. For an explanation see the entities/hierarchy example
    let sun = world.entity("Sun").set(LocalTransform(x = 1.0lf, y = 1.0lf))
    world.entity("Mercury").child_of(sun).set(LocalTransform(x = 1.0lf, y = 1.0lf))
    world.entity("Venus").child_of(sun).set(LocalTransform(x = 2.0lf, y = 2.0lf))
    let earth = world.entity("Earth").child_of(sun).set(LocalTransform(x = 3.0lf, y = 3.0lf))
    world.entity("Moon").child_of(earth).set(LocalTransform(x = 0.1lf, y = 0.1lf))

    // Compute the world transform from the local transform and the parent's world transform
    ecs_query(world) $ [CASCADE(parent)] (local : LocalTransform; var out : WorldTransform; parent : WorldTransform?) {
        out.x = local.x
        out.y = local.y
        if (parent != null) {
            out.x += parent.x
            out.y += parent.y
        }
    }

    // Print world transforms
    ecs_query(world) $(e : FlecsEntity; p : WorldTransform) {
        print("{e.name()}: \{{p.x:.6f}, {p.y:.6f}\}\n")
    }

    world.fini()
}

// Output:
//  Sun: {1.000000, 1.000000}
//  Mercury: {2.000000, 2.000000}
//  Venus: {3.000000, 3.000000}
//  Earth: {4.000000, 4.000000}
//  Moon: {4.100000, 4.100000}
