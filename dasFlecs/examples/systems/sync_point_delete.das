options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/sync_point_delete

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

    // This example shows how to annotate systems that delete entities, in a way
    // that allows the scheduler to correctly insert sync points. See the
    // sync_point example for more details on sync points.
    //
    // While annotating a system for a delete operation follows the same
    // design as other operations, one key difference is that a system often
    // does not know which components a to be deleted entity has. This makes it
    // impossible to annotate the system in advance for specific components.
    //
    // To ensure the scheduler is still able to insert the correct sync points,
    // a system can use a wildcard to indicate that any component could be
    // modified by the system, which forces the scheduler to insert a sync.

    ecs_id(ecs, type<Position>)
    ecs_id(ecs, type<Velocity>)

    // Basic move system.
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

    // Delete entities when p.x >= 3. Add wildcard annotation to indicate any
    // component could be written by the system. Position itself is added as
    // const, since inside the system we're only reading it.
    //
    // Note how the system uses the same annotations as the sync_point example.
    ecs_system(ecs, "DeleteEntity", EcsOnUpdate, "[in] Position, [out] *()") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            for (i in range(it.count)) {
                if (p[i].x >= 3.0lf) {
                    let e = ecs_iter_entity(it, i)
                    print("Delete entity {ecs_get_name(it.stage, e)}\n")
                    ecs_delete(it.stage, e)
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
    ecs_set(ecs, e1, Position(x = 0.0lf, y = 0.0lf))
    ecs_set(ecs, e1, Velocity(x = 1.0lf, y = 2.0lf))

    let e2 = ecs_entity(ecs, "e2")
    ecs_set(ecs, e2, Position(x = 1.0lf, y = 2.0lf))
    ecs_set(ecs, e2, Velocity(x = 1.0lf, y = 2.0lf))

    // Run systems. Debug logging enables us to see the generated schedule
    ecs_log_set_level(1)
    while (ecs_progress(ecs, 0.0)) {
        if (ecs_count(ecs, type<Position>) == 0) {
            break    // No more entities left with Position
        }
    }
    ecs_log_set_level(-1)    // Restore so we don't get world cleanup logs

    flecs_fini(ecs)
}

// Output:
//  e1: {1.000000, 2.000000}
//  e2: {2.000000, 4.000000}
//  Delete entity e2
//  e1: {2.000000, 4.000000}
//  Delete entity e1
