options gen2
require flecs/flecs_boost

// Port of flecs examples/c/observers/two_components
//
// An observer can match multiple components/tags. Only entities that match the
// entire observer query will be forwarded to the callback. For example, an
// observer for Position,Velocity won't match an entity that only has Position.

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

    ecs_observer(ecs, "Observer", EcsOnSet, "Position, Velocity") @(it : ecs_iter_t const?) {
        let world = it.stage
        let event = it.event
        let event_id = it.event_id

        ecs_field_view(it, type<Position>, 0) $(var p) {
            ecs_field_view(it, type<Velocity>, 1) $(var v) {
                for (i in range(it.count)) {
                    let e = ecs_iter_entity(it, i)
                    print("{ecs_get_name(world, event)}: {ecs_get_name(world, event_id)}: {ecs_get_name(world, e)}: p: \{{p[i].x:.6f}, {p[i].y:.6f}\} v: \{{v[i].x:.6f}, {v[i].y:.6f}\}\n")
                }
            }
        }
    }

    // Create entity
    let e = ecs_entity(ecs, "e")

    // Set Position (emits EcsOnSet, does not yet match observer)
    ecs_set(ecs, e, Position(x = 10.0lf, y = 20.0lf))

    // Set Velocity (emits EcsOnSet, matches observer)
    ecs_set(ecs, e, Velocity(x = 1.0lf, y = 2.0lf))

    flecs_fini(ecs)
}

// Output:
//  OnSet: Velocity: e: p: {10.000000, 20.000000} v: {1.000000, 2.000000}
