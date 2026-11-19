options gen2
require flecs/flecs_boost

// Port of flecs examples/c/observers/basics
//
// Observers provide a mechanism for responding to builtin and user defined
// events. They are similar to systems, in that they have the same callback
// signature and use the same query interface to match with entities, but
// instead of a phase they have an event kind.
//
// The most commonly used builtin events are:
//  - EcsOnAdd: a component was added
//  - EcsOnRemove: a component was removed
//  - EcsOnSet: a component's value was changed
//
// The EcsOnAdd and EcsOnRemove events are only thrown when a component is
// actually added or removed. If an application invokes ecs_add and the entity
// already has the component, no event is emitted. Similarly, if an application
// invokes ecs_remove for a component the entity doesn't have, no event is
// emitted. That is in contrast to EcsOnSet, which is invoked each time ecs_set
// or ecs_modified is invoked.
//
// Observers are different from component hooks in a number of ways:
//  - A component can only have one hook, whereas it can match many observers
//  - A hook matches one component, whereas observers can match complex queries
//  - Hooks are for add/set/remove events, observers can match custom events.

struct Position {
    x : double
    y : double
}

def Observer(it : ecs_iter_t const?) {
    let ecs = it.stage

    // The event kind
    let event = it.event

    // The (component) id for which the event was emitted
    let event_id = it.event_id

    // Get component values as usual
    ecs_field_view(it, type<Position>, 0) $(var p) {
        for (i in range(it.count)) {
            let e = ecs_iter_entity(it, i)
            if (event == EcsOnAdd) {
                // No assumptions about the component value should be made here. If
                // a ctor for the component was registered it will be called before
                // the EcsOnAdd event, but a value assigned by set won't be visible.
                print(" - OnAdd: {ecs_get_name(ecs, event_id)}: {ecs_get_name(ecs, e)}\n")
            } else {
                // EcsOnSet or EcsOnRemove event
                print(" - {ecs_get_name(ecs, event)}: {ecs_get_name(ecs, event_id)}: {ecs_get_name(ecs, e)}: \{{p[i].x:.6f}, {p[i].y:.6f}\}\n")
            }
        }
    }
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)

    // ecs_observer_init creates an observer.
    var desc : ecs_observer_desc_t
    // Observer query. Uses same ecs_query_desc_t as systems/queries
    desc.query.terms[0].id = ecs_id(ecs, type<Position>)
    // Events the observer will listen for. Can contain multiple events
    desc.events[0] = EcsOnAdd
    desc.events[1] = EcsOnRemove
    // Observer callback
    ecs_observer_init(ecs, desc) @(it : ecs_iter_t const?) {
        Observer(it)
    }

    // Alternatively an observer can be created from a name, event and query expression
    // (ECS_OBSERVER(ecs, Observer, EcsOnSet, Position)):
    ecs_observer(ecs, "Observer", EcsOnSet, "Position") @(it : ecs_iter_t const?) {
        Observer(it)
    }

    // Create entity
    let e = ecs_entity(ecs, "e")

    // Set Position (emits EcsOnAdd and EcsOnSet)
    ecs_set(ecs, e, Position(x = 10.0lf, y = 20.0lf))

    // Remove component (emits EcsOnRemove)
    ecs_remove(ecs, e, type<Position>)

    // Remove component again (no event is emitted)
    ecs_remove(ecs, e, type<Position>)

    flecs_fini(ecs)
}

// Output:
//   - OnAdd: Position: e
//   - OnSet: Position: e: {10.000000, 20.000000}
//   - OnRemove: Position: e: {10.000000, 20.000000}
