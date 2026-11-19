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
    var world = FlecsWorld()

    // observers fire on component events
    ecs_observer(world, EcsOnAdd) $(e : FlecsEntity; h : Health) {
        log |> push("OnAdd Health -> {e.name()}")
    }
    ecs_observer(world, EcsOnRemove) $(e : FlecsEntity; h : Health) {
        log |> push("OnRemove Health -> {e.name()}")
    }

    // a hierarchy: ship -> engine, ship -> cockpit
    let ship = world.entity("ship")
    let engine = world.entity("engine").child_of(ship).set(Health(value = 100)).set(Damage(amount = 30))
    let cockpit = world.entity("cockpit").child_of(ship).set(Health(value = 100))
    print("engine path: {engine.path()}\n")

    // phases run in order: PreUpdate, OnUpdate, PostUpdate
    ecs_system(world, "Report", EcsPostUpdate) $(e : FlecsEntity; h : Health) {
        log |> push("PostUpdate {e.name()} health={h.value}")
    }
    ecs_system(world, "ApplyDamage", EcsOnUpdate) $(e : FlecsEntity; var h : Health; d : Damage) {
        h.value -= d.amount
        log |> push("OnUpdate damage {e.name()} -{d.amount}")
    }
    // a system without terms runs once per frame: use the builder's iter() directly
    world.system("Begin").kind(EcsPreUpdate).iter() @(it : ecs_iter_t const?) {
        log |> push("PreUpdate frame start")
    }

    world.progress()

    // a system outside the pipeline (kind 0), run on demand
    let heal = ecs_system(world.system("Heal").kind(0ul)) $(e : FlecsEntity; var h : Health) {
        h.value = 100
        log |> push("Heal ran on {e.name()}")
    }
    heal.run()

    // pair query: every child of ship
    var q = world.query_builder().with_(EcsChildOf, ship).build()
    log |> push("children of ship: {q.count()}")
    q.destruct()

    cockpit.remove(type<Health>)

    for (line in log) {
        print("{line}\n")
    }
    print("engine health = {engine.get(type<Health>).value}\n")
    world.fini()
}
