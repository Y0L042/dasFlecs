options gen2

// Queries: expression queries, field views, shared fields.
require dastest/testing_boost public
require flecs/flecs_boost

struct Position {
    x : float
    y : float
}

struct Velocity {
    x : float
    y : float
}

struct Gravity {
    g : float
}

def make_world() : ecs_world_t? {
    var world = ecs_init()
    for (i in range(4)) {
        let e = ecs_new(world)
        ecs_set(world, e, Position(x = float(i), y = 0.0))
        if (i % 2 == 0) {
            ecs_set(world, e, Velocity(x = 1.0, y = 1.0))
        }
    }
    return world
}

[test]
def test_query(t : T?) {
    t |> run("count matches") @(t : T?) {
        var world = make_world()
        var q1 = ecs_query(world, "Position")
        var q2 = ecs_query(world, "Position, Velocity")
        var q3 = ecs_query(world, "Position, !Velocity")
        t |> equal(ecs_query_count_entities(world, q1), 4)
        t |> equal(ecs_query_count_entities(world, q2), 2)
        t |> equal(ecs_query_count_entities(world, q3), 2)
        ecs_query_fini(q1)
        ecs_query_fini(q2)
        ecs_query_fini(q3)
        flecs_fini(world)
    }
    t |> run("field views read and write") @(t : T?) {
        var world = make_world()
        var q = ecs_query(world, "Position, Velocity")
        ecs_query_each(world, q) $(it) {
            ecs_field_view(it, type<Position>, 0) $(var p) {
                ecs_field_view(it, type<Velocity>, 1) $(var v) {
                    for (pi, vi in p, v) {
                        pi.x += vi.x * 10.0
                    }
                }
            }
        }
        var sum = 0.0
        var all = ecs_query(world, "Position")
        ecs_query_each(world, all) $(it) {
            ecs_field_view(it, type<Position>, 0) $(var p) {
                for (pi in p) {
                    sum += pi.x
                }
            }
        }
        t |> equal(sum, 0.0 + 1.0 + 2.0 + 3.0 + 20.0)
        ecs_query_fini(q)
        ecs_query_fini(all)
        flecs_fini(world)
    }
    t |> run("singleton is a shared field of one element") @(t : T?) {
        var world = make_world()
        let gid = ecs_id(world, type<Gravity>)
        ecs_add_id(world, gid, EcsSingleton)    // component can only be set on itself
        ecs_set(world, gid, Gravity(g = 9.8))
        var q = ecs_query(world, "Position, Gravity")
        var seen = 0
        var len = -1
        ecs_query_each(world, q) $(it) {
            seen += it.count
            ecs_field_view(it, type<Gravity>, 1) $(var g) {
                len = length(g)
                t |> equal(g[0].g, 9.8)
            }
        }
        t |> equal(seen, 4)
        t |> equal(len, 1)
        ecs_query_fini(q)
        flecs_fini(world)
    }
    t |> run("entity ids of a table") @(t : T?) {
        var world = ecs_init()
        let e = ecs_new(world)
        ecs_set(world, e, Position(x = 1.0, y = 2.0))
        var q = ecs_query(world, "Position")
        var found = 0ul
        ecs_query_each(world, q) $(it) {
            found = ecs_iter_entity(it, 0)
        }
        t |> equal(found, e)
        ecs_query_fini(q)
        flecs_fini(world)
    }
}
