options gen2
require flecs/flecs_boost

// Port of flecs examples/c/observers/enqueue_event
//
// This is the same example as custom_event, but instead of emit() the example
// uses the enqueue() function. Whereas emit() invokes observers synchronously,
// enqueue() adds the event to the command queue, which delays invoking
// observers until the next time the command queue is flushed.

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

    let stage_1 = ecs_is_stage(ecs) ? ecs : ecs_get_stage(ecs, 0)

    // Emit the custom event
    var ids = [ecs_id(ecs, type<Position>)]
    var ids_type : ecs_type_t
    ids_type._array = unsafe(addr(ids[0]))
    ids_type.count = 1                              // 1 id
    var desc : ecs_event_desc_t
    desc.event = MyEvent
    desc.ids = unsafe(addr(ids_type))
    desc.entity = e
    ecs_enqueue(stage_1, unsafe(addr(desc)))

    print("Event enqueued!\n")

    // Flushes the queue, and invokes the observer
    ecs_merge(stage_1)

    flecs_fini(ecs)
}

// Output:
//  Event enqueued!
//   - MyEvent: Position: e
