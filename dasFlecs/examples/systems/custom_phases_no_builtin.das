options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/custom_phases_no_builtin
//
// This application demonstrates how to use custom phases for systems, without
// using or branching off of the builtin pipelines.

// Dummy system
def Sys(it : ecs_iter_t const?) {
    print("system {ecs_get_name(it.stage, it.system)}\n")
}

def dummy_system(ecs : ecs_world_t?; name : string; phase : ecs_entity_t) {
    var desc : ecs_system_desc_t
    desc.entity = ecs_entity(ecs, name)
    desc.phase = phase
    ecs_system_init(ecs, desc) @(it : ecs_iter_t const?) {
        Sys(it)
    }
}

[export]
def main() {
    var ecs = ecs_init()

    // Create three custom phases. Note that the two phases have the Phase tag,
    // which is necessary for the builtin pipeline to discover which systems it
    // should run.
    let Update = ecs_new_w_id(ecs, EcsPhase)
    let Physics = ecs_new_w_id(ecs, EcsPhase)
    let Collisions = ecs_new_w_id(ecs, EcsPhase)

    ecs_add_pair(ecs, Physics, EcsDependsOn, Update)
    ecs_add_pair(ecs, Collisions, EcsDependsOn, Physics)

    // Create 3 dummy systems.
    dummy_system(ecs, "CollisionSystem", Collisions)
    dummy_system(ecs, "PhysicsSystem", Physics)
    dummy_system(ecs, "GameSystem", Update)

    // Run pipeline
    ecs_progress(ecs, 0.0)

    flecs_fini(ecs)
}

// Output:
//  system GameSystem
//  system PhysicsSystem
//  system CollisionSystem
