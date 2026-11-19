options gen2
require flecs/flecs_boost

// Port of flecs examples/c/prefabs/slots
//
// Prefab hierarchies that use the non-fragmenting Parent storage automatically
// let applications resolve an instantiated child from its prefab child. This
// provides slot-like lookup without adding a relationship to either entity.

[export]
def main() {
    var ecs = ecs_init()

    // Create a prefab hierarchy with non-fragmenting Parent storage.
    let SpaceShip = ecs_entity(ecs, "SpaceShip")
    ecs_add_id(ecs, SpaceShip, EcsPrefab)

    let Engine = ecs_new_w_parent(ecs, SpaceShip, "Engine")
    let Cockpit = ecs_new_w_parent(ecs, SpaceShip, "Cockpit")
    let PilotSeat = ecs_new_w_parent(ecs, Cockpit, "PilotSeat")

    // Create a prefab instance.
    let inst = ecs_entity(ecs, "my_spaceship")
    ecs_add_pair(ecs, inst, EcsIsA, SpaceShip)

    // Get the instantiated children from their prefab children. A nested child
    // is resolved from the corresponding instance parent.
    let inst_engine = ecs_get_target(ecs, inst, Engine, 0)
    let inst_cockpit = ecs_get_target(ecs, inst, Cockpit, 0)
    let inst_seat = ecs_get_target(ecs, inst_cockpit, PilotSeat, 0)

    print("instance engine found:  {inst_engine != 0ul}\n")
    print("instance cockpit found: {inst_cockpit != 0ul}\n")
    print("instance seat found:    {inst_seat != 0ul}\n")

    flecs_fini(ecs)
}

// Output:
//  instance engine found:  true
//  instance cockpit found: true
//  instance seat found:    true
