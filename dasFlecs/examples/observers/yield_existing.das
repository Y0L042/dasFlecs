options gen2
require flecs/flecs_boost

// Port of flecs examples/c/observers/yield_existing
//
// Observers can enable a "yield_existing" feature that upon creation of the
// observer produces events for all entities that match the observer query. The
// feature is only implemented for the builtin EcsOnAdd and EcsOnSet events.

struct Position {
    x : double
    y : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)

    // Create existing entities with Position component
    let e1 = ecs_entity(ecs, "e1")
    ecs_set(ecs, e1, Position(x = 10.0lf, y = 20.0lf))

    let e2 = ecs_entity(ecs, "e2")
    ecs_set(ecs, e2, Position(x = 20.0lf, y = 30.0lf))

    var desc : ecs_observer_desc_t
    desc.query.terms[0].id = ecs_id(ecs, type<Position>)
    desc.events[0] = EcsOnSet
    desc.yield_existing = true    // Trigger for existing matching entities
    ecs_observer_init(ecs, desc) @(it : ecs_iter_t const?) {
        let world = it.stage
        let event = it.event
        let event_id = it.event_id

        ecs_field_view(it, type<Position>, 0) $(var p) {
            for (i in range(it.count)) {
                let e = ecs_iter_entity(it, i)
                print(" - {ecs_get_name(world, event)}: {ecs_get_name(world, event_id)}: {ecs_get_name(world, e)}: \{{p[i].x:.6f}, {p[i].y:.6f}\}\n")
            }
        }
    }

    flecs_fini(ecs)
}

// Output:
//   - OnSet: Position: e1: {10.000000, 20.000000}
//   - OnSet: Position: e2: {20.000000, 30.000000}
