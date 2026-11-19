options gen2

// Observers through the callback bridge.
require dastest/testing_boost public
require flecs/flecs_boost

struct Health {
    value : int
}

var events : array<string>
var last_value = 0

[test]
def test_observer(t : T?) {
    t |> run("OnAdd / OnSet / OnRemove") @(t : T?) {
        clear(events)
        var world = ecs_init()
        ecs_id(world, type<Health>)
        ecs_observer(world, EcsOnAdd, "Health") @(it : ecs_iter_t const?) {
            events |> push("add")
        }
        ecs_observer(world, EcsOnSet, "Health") @(it : ecs_iter_t const?) {
            events |> push("set")
            ecs_field_view(it, type<Health>, 0) $(var h) {
                last_value = h[0].value
            }
        }
        ecs_observer(world, EcsOnRemove, "Health") @(it : ecs_iter_t const?) {
            events |> push("remove")
        }
        let e = ecs_new(world)
        ecs_set(world, e, Health(value = 10))
        t |> equal(last_value, 10)
        ecs_set(world, e, Health(value = 20))
        t |> equal(last_value, 20)
        ecs_remove(world, e, type<Health>)
        t |> equal(length(events), 4)
        t |> equal(events[0], "add")
        t |> equal(events[1], "set")
        t |> equal(events[2], "set")
        t |> equal(events[3], "remove")
        flecs_fini(world)
    }
    t |> run("observer sees the triggering entity") @(t : T?) {
        clear(events)
        var world = ecs_init()
        ecs_id(world, type<Health>)
        ecs_observer(world, EcsOnAdd, "Health") @(it : ecs_iter_t const?) {
            for (i in range(it.count)) {
                events |> push(ecs_get_name(it.world, ecs_iter_entity(it, i)))
            }
        }
        let e = ecs_entity(world, "hero")
        ecs_add(world, e, type<Health>)
        t |> equal(length(events), 1)
        t |> equal(events[0], "hero")
        flecs_fini(world)
    }
}
