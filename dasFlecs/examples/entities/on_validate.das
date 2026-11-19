options gen2
require flecs/flecs_boost

// Port of flecs examples/c/entities/on_validate
//
// The on_validate hook can reject a value before it is assigned: when it returns
// false, the set operation is ignored and on_set is not invoked.

struct Position {
    x : double
    y : double
}

[export]
def main() {
    var world = ecs_init()

    ecs_id(world, type<Position>)

    var hooks : ecs_type_hooks_t
    ecs_hooks_on_validate(hooks) @(w : ecs_world_t?; e : ecs_entity_t; ptr : void?) : bool {
        let p = unsafe(reinterpret<Position const?>(ptr))
        return p.x >= 0.0lf && p.x <= 100.0lf && p.y >= 0.0lf && p.y <= 100.0lf
    }
    ecs_hooks_on_set(hooks) @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            for (i in range(it.count)) {
                print("{ecs_get_name(it.stage, ecs_iter_entity(it, i))} set to \{{p[i].x:.0f}, {p[i].y:.0f}\}\n")
            }
        }
    }
    ecs_set_hooks(world, type<Position>, hooks)

    let e = ecs_entity(world, "Entity")
    ecs_set(world, e, Position(x = 50.0lf, y = 50.0lf))
    ecs_set(world, e, Position(x = 150.0lf, y = 50.0lf))

    flecs_fini(world)
}

// Output:
//  Entity set to {50, 50}
