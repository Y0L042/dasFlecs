options gen2
require flecs/flecs_boost

// Phases, observers, hierarchies and manually-run systems.

struct Health {
    value : int
}

struct Damage {
    amount : int
}

// das lambdas capture locals by copy: shared state the callbacks update lives at module level
var log : array<string>

[export]
def main() {
    var world = ecs_init()
    // register components before naming them in query expressions (like ECS_COMPONENT in C)
    ecs_id(world, type<Health>)
    ecs_id(world, type<Damage>)

    // observers fire on component events
    ecs_observer(world, EcsOnAdd, "Health") @(it : ecs_iter_t const?) {
        for (i in range(it.count)) {
            log |> push("OnAdd Health -> {ecs_get_name(it.world, ecs_iter_entity(it, i))}")
        }
    }
    ecs_observer(world, EcsOnRemove, "Health") @(it : ecs_iter_t const?) {
        for (i in range(it.count)) {
            log |> push("OnRemove Health -> {ecs_get_name(it.world, ecs_iter_entity(it, i))}")
        }
    }

    // a hierarchy: ship -> engine, ship -> cockpit
    let ship = ecs_entity(world, "ship")
    let engine = ecs_entity(world, "engine")
    let cockpit = ecs_entity(world, "cockpit")
    ecs_add_pair(world, engine, EcsChildOf, ship)
    ecs_add_pair(world, cockpit, EcsChildOf, ship)
    for (e in [engine, cockpit]) {
        ecs_set(world, e, Health(value = 100))
    }
    ecs_set(world, engine, Damage(amount = 30))
    print("engine path: {ecs_get_path_w_sep(world, 0ul, engine, ".", "")}\n")

    // phases run in order: PreUpdate, OnUpdate, PostUpdate
    ecs_system(world, "Report", EcsPostUpdate, "Health") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Health>, 0) $(var h) {
            for (i in range(it.count)) {
                log |> push("PostUpdate {ecs_get_name(it.world, ecs_iter_entity(it, i))} health={h[i].value}")
            }
        }
    }
    ecs_system(world, "ApplyDamage", EcsOnUpdate, "Health, Damage") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Health>, 0) $(var h) {
            ecs_field_view(it, type<Damage>, 1) $(var d) {
                for (i in range(it.count)) {
                    h[i].value -= d[i].amount
                    log |> push("OnUpdate damage {ecs_get_name(it.world, ecs_iter_entity(it, i))} -{d[i].amount}")
                }
            }
        }
    }
    ecs_system(world, "Begin", EcsPreUpdate, "") @(it : ecs_iter_t const?) {
        log |> push("PreUpdate frame start")
    }

    ecs_progress(world, 0.0)

    // a system outside the pipeline (phase 0), run on demand
    let heal = ecs_system(world, "Heal", 0ul, "Health") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Health>, 0) $(var h) {
            for (hi in h) {
                hi.value = 100
            }
        }
        log |> push("Heal ran on {it.count} entities")
    }
    ecs_run(world, heal, 0.0, null)

    // wildcard query: every (ChildOf, *) pair
    var q = ecs_query(world, "(ChildOf, ship)")
    log |> push("children of ship: {ecs_query_count_entities(world, q)}")
    ecs_query_fini(q)

    ecs_remove(world, cockpit, type<Health>)

    for (line in log) {
        print("{line}\n")
    }
    print("engine health = {ecs_get(world, engine, type<Health>).value}\n")
    flecs_fini(world)
}
