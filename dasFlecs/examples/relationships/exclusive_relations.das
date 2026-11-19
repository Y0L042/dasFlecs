options gen2
require flecs/flecs_boost

// Port of flecs examples/c/relationships/exclusive_relations

[export]
def main() {
    var ecs = ecs_init()

    let Platoon = ecs_tag(ecs, "Platoon")

    // Register Platoon as exclusive relationship. This ensures that an entity
    // can only belong to a single Platoon.
    ecs_add_id(ecs, Platoon, EcsExclusive)

    // Create two platoons
    let platoon_1 = ecs_new(ecs)
    let platoon_2 = ecs_new(ecs)

    // Create a unit
    let unit = ecs_new(ecs)

    // Add unit to platoon 1
    ecs_add_pair(ecs, unit, Platoon, platoon_1)

    // Log platoon of unit
    print("Unit in platoon 1: {ecs_has_pair(ecs, unit, Platoon, platoon_1)}\n")
    print("Unit in platoon 2: {ecs_has_pair(ecs, unit, Platoon, platoon_2)}\n\n")

    // Add unit to platoon 2. Because Platoon is an exclusive relationship, this
    // both removes (Platoon, platoon_1) and adds (Platoon, platoon_2) in a
    // single operation.
    ecs_add_pair(ecs, unit, Platoon, platoon_2)

    print("Unit in platoon 1: {ecs_has_pair(ecs, unit, Platoon, platoon_1)}\n")
    print("Unit in platoon 2: {ecs_has_pair(ecs, unit, Platoon, platoon_2)}\n")

    flecs_fini(ecs)
}

// Output:
//  Unit in platoon 1: true
//  Unit in platoon 2: false
//
//  Unit in platoon 1: false
//  Unit in platoon 2: true
