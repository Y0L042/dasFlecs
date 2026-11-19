options gen2
require flecs/flecs_boost

// Port of flecs examples/c/observers/enqueue_entity_event
//
// This is the same example as entity_event, but instead of emit() the example
// uses the enqueue() method. Whereas emit() invokes observers synchronously,
// enqueue() adds the event to the command queue, which delays invoking
// observers until the next time the command queue is flushed.

// Event with payload
struct Resize {
    width : double
    height : double
}

def entity_observer(ecs : ecs_world_t?; widget, event : ecs_entity_t; var callback : lambda<(it : ecs_iter_t const?) : void>) {
    // Use EcsAny to indicate we're not interested in matching specific components.
    var desc : ecs_observer_desc_t
    desc.query.terms[0].id = EcsAny
    desc.query.terms[0].src.id = widget
    desc.events[0] = event
    ecs_observer_init(ecs, desc, callback)
}

[export]
def main() {
    var ecs = ecs_init()

    // Event without payload
    let Click = ecs_tag(ecs, "Click")
    ecs_id(ecs, type<Resize>)

    // Create a widget entity
    let widget = ecs_entity(ecs, "MyWidget")

    // Create entity observer.
    entity_observer(ecs, widget, Click) @(it : ecs_iter_t const?) {
        // The event source can be obtained with ecs_field_src(it, 0). This allows the
        // same event function to be used for different entities.
        print("clicked on {ecs_get_path(it.stage, ecs_field_src(it, int8(0)))}!\n")
    }

    // Create another one for the Resize event
    entity_observer(ecs, widget, ecs_id(ecs, type<Resize>)) @(it : ecs_iter_t const?) {
        // Event payload can be obtained from the it.param member
        let p = unsafe(reinterpret<Resize const?>(it.param))
        print("resized {ecs_get_path(it.stage, ecs_field_src(it, int8(0)))} to \{{p.width:.0f}, {p.height:.0f}\}!\n")
    }

    let stage_1 = ecs_is_stage(ecs) ? ecs : ecs_get_stage(ecs, 0)

    // Emit the Click event
    var click : ecs_event_desc_t
    click.event = Click
    click.entity = widget
    ecs_enqueue(stage_1, unsafe(addr(click)))

    // Emit the Resize event
    var payload = Resize(width = 100.0lf, height = 200.0lf)
    var resize : ecs_event_desc_t
    resize.event = ecs_id(ecs, type<Resize>)
    resize.entity = widget
    resize.param = unsafe(addr(payload))    // pass payload
    ecs_enqueue(stage_1, unsafe(addr(resize)))

    print("Events enqueued\n")

    // Flushes the queue, and invokes the observer
    ecs_merge(stage_1)

    flecs_fini(ecs)
}

// Output:
//  Events enqueued
//  clicked on MyWidget!
//  resized MyWidget to {100, 200}!
