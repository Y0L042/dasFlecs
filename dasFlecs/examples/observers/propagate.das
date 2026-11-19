options gen2
require flecs/flecs_boost

// Port of flecs examples/c/observers/propagate
//
// Events are propagated along relationship edges. This means that observers can
// listen for events from a parent or prefab, like triggering when a component
// inherited from a prefab was set.
//
// Event propagation happens automatically when an observer contains a query
// with the EcsUp flag set (indicating upwards traversal). Observers use the
// same matching logic as queries: if a query with upwards traversal matches an
// entity, so will an observer.
//
// Events are only propagated along traversable relationship edges.

struct Position {
    x : double
    y : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)

    // Create observer that listens for events from both self and parent
    var desc : ecs_observer_desc_t
    // Listen for Position events from self
    desc.query.terms[0].id = ecs_id(ecs, type<Position>)
    // Listen for Position events from parent
    desc.query.terms[1].id = ecs_id(ecs, type<Position>)
    desc.query.terms[1].src.id = EcsUp
    desc.query.terms[1].trav = EcsChildOf
    desc.events[0] = EcsOnSet
    ecs_observer_init(ecs, desc) @(it : ecs_iter_t const?) {
        let world = it.stage

        // The event kind
        let event = it.event

        // The (component) id for which the event was emitted
        let event_id = it.event_id

        // Grab Position from self and parent
        ecs_field_view(it, type<Position>, 0) $(var p_self) {
            ecs_field_view(it, type<Position>, 1) $(var p_parent) {
                for (i in range(it.count)) {
                    let e = ecs_iter_entity(it, i)
                    // the parent field is shared: one element for all entities
                    let pp = p_parent[length(p_parent) == 1 ? 0 : i]
                    print(" - {ecs_get_name(world, event)}: {ecs_get_name(world, event_id)}: {ecs_get_name(world, e)}: self: \{{p_self[i].x:.6f}, {p_self[i].y:.6f}\}, parent: \{{pp.x:.6f}, {pp.y:.6f}\}\n")
                }
            }
        }
    }

    // Create entity and parent
    let p = ecs_entity(ecs, "p")
    let e = ecs_entity(ecs, "p.e")    // Create as child of p

    // Set Position on entity. This doesn't trigger the observer yet, since the
    // parent doesn't have Position yet.
    ecs_set(ecs, e, Position(x = 10.0lf, y = 20.0lf))

    // Set Position on parent. This event will be propagated and trigger the
    // observer, as the observer query now matches.
    ecs_set(ecs, p, Position(x = 1.0lf, y = 2.0lf))

    flecs_fini(ecs)
}

// Output:
//   - OnSet: Position: e: self: {10.000000, 20.000000}, parent: {1.000000, 2.000000}
