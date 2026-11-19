options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/sync_point

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

    // System that sets velocity using ecs_set for entities with Position.
    // While systems are progressing, operations like ecs_set are deferred until
    // it is safe to merge. By default this merge happens at the end of the
    // frame, but we can annotate systems to give the scheduler more information
    // about what it's doing, which allows it to insert sync points earlier.
    //
    // The parentheses after Velocity indicate that the component is not used
    // to match entities, while [out] indicates that it is written. A subsequent
    // system that accesses the component will cause the scheduler to insert a
    // sync point.
    //
    // Note that sync points are never necessary/inserted for systems that write
    // components provided by their signature, as these writes directly happen
    // in the ECS storage and are never deferred.
    //
    // The [none] annotation for Position tells the scheduler that while we
    // want to match entities with Position, we're not interested in reading or
    // writing the component value.
    ecs_system(ecs, "SetVelocity", EcsOnUpdate, "[none] Position, [out] Velocity()") @(it : ecs_iter_t const?) {
        for (i in range(it.count)) {
            ecs_set(it.stage, ecs_iter_entity(it, i), Velocity(x = 1.0lf, y = 2.0lf))
        }
    }

    // This system reads Velocity, which causes the insertion of a sync point.
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

    // Print resulting Position
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

    // Run systems. Debug logging enables us to see the generated schedule
    ecs_log_set_level(1)
    ecs_progress(ecs, 0.0)
    ecs_log_set_level(-1)    // Restore so we don't get world cleanup logs

    flecs_fini(ecs)
}

// Output:
//  e1: {11.000000, 22.000000}
//  e2: {11.000000, 22.000000}
