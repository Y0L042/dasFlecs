options gen2
require flecs/flecs_boost

// flecs examples/c/observers/basics in the C++-style API: an observer builder with two
// events, and a typed-block observer from (world, event).

struct Position {
    x : double
    y : double
}

[export]
def main() {
    var world = FlecsWorld()

    // An observer for OnAdd and OnRemove. The iterator tells which event fired.
    ecs_observer(world.observer().event(EcsOnAdd).event(EcsOnRemove)) $(it : ecs_iter_t const?; e : FlecsEntity; p : Position) {
        if (it.event == EcsOnAdd) {
            // No assumptions about the component value should be made here. If
            // a ctor for the component was registered it will be called before
            // the EcsOnAdd event, but a value assigned by set is not visible yet.
            print(" - OnAdd: {ecs_get_name(it.world, it.event_id)}: {e.name()}\n")
        } else {
            print(" - {ecs_get_name(it.world, it.event)}: {ecs_get_name(it.world, it.event_id)}: {e.name()}: \{{p.x:.6f}, {p.y:.6f}\}\n")
        }
    }

    // An observer from (world, event)
    ecs_observer(world, EcsOnSet) $(it : ecs_iter_t const?; e : FlecsEntity; p : Position) {
        print(" - OnSet: {ecs_get_name(it.world, it.event_id)}: {e.name()}: \{{p.x:.6f}, {p.y:.6f}\}\n")
    }

    // Create entity, set Position (emits EcsOnAdd and EcsOnSet)
    let e = world.entity("e").set(Position(x = 10.0lf, y = 20.0lf))

    // Remove component (emits EcsOnRemove)
    e.remove(type<Position>)

    // Remove component again (no event is emitted)
    e.remove(type<Position>)

    world.fini()
}

// Output:
//   - OnAdd: Position: e
//   - OnSet: Position: e: {10.000000, 20.000000}
//   - OnRemove: Position: e: {10.000000, 20.000000}
