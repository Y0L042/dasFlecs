options gen2
require flecs/flecs_boost

// Port of flecs examples/c/prefabs/hierarchy
//
// When a prefab has children, they are instantiated for an instance when the
// IsA relationship to the prefab is added.

[export]
def main() {
    var ecs = ecs_init()

    // Create a prefab hierarchy.
    let SpaceShip = ecs_entity(ecs, "SpaceShip")
    ecs_add_id(ecs, SpaceShip, EcsPrefab)

    let SpaceShipEngine = ecs_entity(ecs, "Engine")
    ecs_add_id(ecs, SpaceShipEngine, EcsPrefab)
    ecs_add_pair(ecs, SpaceShipEngine, EcsChildOf, SpaceShip)

    let SpaceShipCockpit = ecs_entity(ecs, "Cockpit")
    ecs_add_id(ecs, SpaceShipCockpit, EcsPrefab)
    ecs_add_pair(ecs, SpaceShipCockpit, EcsChildOf, SpaceShip)

    // Instantiate the prefab. This also creates an Engine and Cockpit child
    // for the instance.
    let inst = ecs_entity(ecs, "my_spaceship")
    ecs_add_pair(ecs, inst, EcsIsA, SpaceShip)

    let inst_engine = ecs_lookup_child(ecs, inst, "Engine")
    let inst_cockpit = ecs_lookup_child(ecs, inst, "Cockpit")

    print("instance engine:  {ecs_get_path(ecs, inst_engine)}\n")
    print("instance cockpit: {ecs_get_path(ecs, inst_cockpit)}\n")

    flecs_fini(ecs)
}

// Output:
//  instance engine:  my_spaceship.Engine
//  instance cockpit: my_spaceship.Cockpit
