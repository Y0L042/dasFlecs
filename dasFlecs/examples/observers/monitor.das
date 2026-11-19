options gen2
require flecs/flecs_boost

// Port of flecs examples/c/observers/monitor
//
// A monitor observer triggers when an entity starts/stop matching the observer
// query. The observer communicates whether an entity is "entering/leaving" the
// monitor by setting ecs_iter_t::event to EcsOnAdd (for entering) or
// EcsOnRemove (for leaving).
//
// To specify that an observer is a monitor observer, the EcsMonitor tag must be
// provided as event. No additional event kinds should be provided for a monitor
// observer.

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

    var desc : ecs_observer_desc_t
    desc.query.terms[0].id = ecs_id(ecs, type<Position>)
    desc.query.terms[1].id = ecs_id(ecs, type<Velocity>)
    desc.events[0] = EcsMonitor    // Monitor entities entering/leaving the query
    ecs_observer_init(ecs, desc) @(it : ecs_iter_t const?) {
        let world = it.stage
        let event = it.event
        let event_id = it.event_id

        for (i in range(it.count)) {
            let e = ecs_iter_entity(it, i)
            if (event == EcsOnAdd) {
                print(" - Enter: {ecs_get_name(world, event_id)}: {ecs_get_name(world, e)}\n")
            } elif (event == EcsOnRemove) {
                print(" - Leave: {ecs_get_name(world, event_id)}: {ecs_get_name(world, e)}\n")
            }
        }
    }

    // Create entity
    let e = ecs_entity(ecs, "e")

    // This does not yet trigger the monitor, as the entity does not yet match.
    ecs_set(ecs, e, Position(x = 10.0lf, y = 20.0lf))

    // This triggers the monitor with EcsOnAdd, as the entity now matches.
    ecs_set(ecs, e, Velocity(x = 1.0lf, y = 2.0lf))

    // This triggers the monitor with EcsOnRemove, as the entity no longer matches.
    ecs_remove(ecs, e, type<Position>)

    flecs_fini(ecs)
}

// Output:
//   - Enter: Velocity: e
//   - Leave: Position: e
