options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/pipeline

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
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)
    ecs_id(ecs, type<Velocity>)

    // Create system for moving an entity in the EcsOnUpdate phase
    ecs_system(ecs, "Move", EcsOnUpdate, "Position, [in] Velocity") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            ecs_field_view(it, type<Velocity>, 1) $(var v) {
                for (i in range(it.count)) {
                    p[i].x += v[i].x
                    p[i].y += v[i].y
                }
            }
        }
    }

    // Create system for printing a Position in the EcsPostUpdate phase
    ecs_system(ecs, "PrintPosition", EcsPostUpdate, "[in] Position") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            for (i in range(it.count)) {
                print("{ecs_get_name(it.stage, ecs_iter_entity(it, i))}: \{{p[i].x:.6f}, {p[i].y:.6f}\}\n")
            }
        }
    }

    // Create a few test entities for a Position, Velocity query
    let e1 = ecs_entity(ecs, "e1")
    ecs_set(ecs, e1, Position(x = 10.0lf, y = 20.0lf))
    ecs_set(ecs, e1, Velocity(x = 1.0lf, y = 2.0lf))

    let e2 = ecs_entity(ecs, "e2")
    ecs_set(ecs, e2, Position(x = 10.0lf, y = 20.0lf))
    ecs_set(ecs, e2, Velocity(x = 3.0lf, y = 4.0lf))

    // Run the default pipeline. This will run all systems ordered by their
    // phase. Systems within the same phase are ran in declaration order. This
    // function is usually called in a loop.
    ecs_progress(ecs, 0.0)

    flecs_fini(ecs)
}

// Output:
//  e1: {11.000000, 22.000000}
//  e2: {13.000000, 24.000000}
