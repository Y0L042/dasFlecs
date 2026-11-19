options gen2
require flecs/flecs_boost

// Components are plain das structs.
struct Position {
    x : float
    y : float
}

struct Velocity {
    x : float
    y : float
}

[export]
def main() {
    var world = ecs_init()

    // entities with components; components register on first use
    for (i in range(3)) {
        let e = ecs_new(world)
        ecs_set_name(world, e, "mover{i}")
        ecs_set(world, e, Position(x = float(i), y = 0.0))
        ecs_set(world, e, Velocity(x = 1.0, y = float(i + 1)))
    }
    let still = ecs_new(world)
    ecs_set_name(world, still, "still")
    ecs_set(world, still, Position(x = 10.0, y = 10.0))   // no Velocity: the system skips it

    // system: runs once per frame in the OnUpdate phase
    ecs_system(world, "Move", EcsOnUpdate, "Position, [in] Velocity") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            ecs_field_view(it, type<Velocity>, 1) $(var v) {
                for (pi, vi in p, v) {
                    pi.x += vi.x
                    pi.y += vi.y
                }
            }
        }
    }

    for (frame in range(3)) {
        ecs_progress(world, 0.0)
    }

    // read back with a query
    var q = ecs_query(world, "Position")
    ecs_query_each(world, q) $(it) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            for (i in range(it.count)) {
                print("{ecs_get_name(world, ecs_iter_entity(it, i))}: ({p[i].x}, {p[i].y})\n")
            }
        }
    }
    ecs_query_fini(q)

    let pos = ecs_get(world, still, type<Position>)
    print("still has Velocity: {ecs_has(world, still, type<Velocity>)}, position ({pos.x}, {pos.y})\n")
    flecs_fini(world)
}
