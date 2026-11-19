options gen2

// Systems through the callback bridge.
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

// das lambdas capture locals by copy: counters live at module level
var calls = 0
var last_count = 0
var last_delta = 0.0
var order : array<string>

[test]
def test_system(t : T?) {
    t |> run("runs once per frame with the matched entities") @(t : T?) {
        calls = 0
        var world = ecs_init()
        for (i in range(5)) {
            let e = ecs_new(world)
            ecs_set(world, e, Position(x = 0.0, y = 0.0))
            ecs_set(world, e, Velocity(x = 1.0, y = 2.0))
        }
        ecs_system(world, "Move", EcsOnUpdate, "Position, [in] Velocity") @(it : ecs_iter_t const?) {
            calls ++
            last_count = it.count
            last_delta = it.delta_time
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
            ecs_progress(world, 0.5)
        }
        t |> equal(calls, 3)
        t |> equal(last_count, 5)
        t |> equal(last_delta, 0.5)
        var q = ecs_query(world, "Position")
        ecs_query_each(world, q) $(it) {
            ecs_field_view(it, type<Position>, 0) $(var p) {
                for (pi in p) {
                    t |> equal(pi.x, 3.0)
                    t |> equal(pi.y, 6.0)
                }
            }
        }
        ecs_query_fini(q)
        flecs_fini(world)
    }
    t |> run("phases run in pipeline order") @(t : T?) {
        clear(order)
        var world = ecs_init()
        ecs_system(world, "C", EcsPostUpdate, "") @(it : ecs_iter_t const?) {
            order |> push("post")
        }
        ecs_system(world, "A", EcsPreUpdate, "") @(it : ecs_iter_t const?) {
            order |> push("pre")
        }
        ecs_system(world, "B", EcsOnUpdate, "") @(it : ecs_iter_t const?) {
            order |> push("update")
        }
        ecs_progress(world, 0.0)
        t |> equal(length(order), 3)
        t |> equal(order[0], "pre")
        t |> equal(order[1], "update")
        t |> equal(order[2], "post")
        flecs_fini(world)
    }
    t |> run("ecs_run runs a system outside the pipeline") @(t : T?) {
        calls = 0
        var world = ecs_init()
        let sys = ecs_system(world, "Manual", 0ul, "") @(it : ecs_iter_t const?) {
            calls ++
        }
        ecs_progress(world, 0.0)
        t |> equal(calls, 0)
        ecs_run(world, sys, 0.0, null)
        t |> equal(calls, 1)
        flecs_fini(world)
    }
    t |> run("callback holders are freed with the world") @(t : T?) {
        let before = flecs_callback_count()
        var world = ecs_init()
        let sys = ecs_system(world, "", EcsOnUpdate, "") @(it : ecs_iter_t const?) {
            calls ++
        }
        t |> equal(flecs_callback_count(), before + 1)
        ecs_delete(world, sys)
        t |> equal(flecs_callback_count(), before)
        ecs_system(world, "", EcsOnUpdate, "") @(it : ecs_iter_t const?) {
            calls ++
        }
        flecs_fini(world)
        t |> equal(flecs_callback_count(), before)
    }
}
