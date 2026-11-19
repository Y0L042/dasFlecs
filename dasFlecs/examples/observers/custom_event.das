options gen2
require flecs/flecs_boost

// Port of flecs examples/c/observers/custom_event
//
// Observers can be used to match custom events. Custom events can be emitted
// using the ecs_emit function. This function is also used by builtin events,
// so builtin and custom events use the same rules for matching with observers.
//
// An event consists out of three pieces of data used to match with observers:
//  - An single event kind (EcsOnAdd, EcsOnRemove, ...)
//  - One or more event ids (Position, Velocity, ...)
//  - A source (either an entity or a table)

struct Position {
    x : double
    y : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)

    // Create custom event
    let MyEvent = ecs_entity(ecs, "MyEvent")

    // Create observer for custom event
    ecs_observer(ecs, "Observer", MyEvent, "Position") @(it : ecs_iter_t const?) {
        let world = it.stage

        // The event kind
        let event = it.event

        // The (component) id for which the event was emitted
        let event_id = it.event_id

        for (i in range(it.count)) {
            let e = ecs_iter_entity(it, i)
            print(" - {ecs_get_name(world, event)}: {ecs_get_name(world, event_id)}: {ecs_get_name(world, e)}\n")
        }
    }

    // Create entity
    let e = ecs_entity(ecs, "e")

    // The observer query can be matched against the entity, so make sure it
    // has the Position component before emitting the event. This does not
    // trigger the observer yet.
    ecs_set(ecs, e, Position(x = 10.0lf, y = 20.0lf))

    // Emit the custom event
    var ids = [ecs_id(ecs, type<Position>)]
    var ids_type : ecs_type_t
    ids_type._array = unsafe(addr(ids[0]))
    ids_type.count = 1                              // 1 id
    var desc : ecs_event_desc_t
    desc.event = MyEvent
    desc.ids = unsafe(addr(ids_type))
    desc.entity = e
    ecs_emit(ecs, unsafe(addr(desc)))

    flecs_fini(ecs)
}

// Output:
//   - MyEvent: Position: e
