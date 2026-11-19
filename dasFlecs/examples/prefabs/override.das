options gen2
require flecs/flecs_boost

// Port of flecs examples/c/prefabs/override
//
// When an entity is instantiated from a prefab, components are by default
// copied from the prefab to the instance. This behavior can be customized with
// the OnInstantiate trait, which has three options:
//
// - Copy (copy to instance)
// - Inherit (inherit from prefab)
// - DontInherit (don't copy or inherit)
//
// When a component is inheritable, it can be overridden manually by adding the
// component to the instance, which also copies the value from the prefab
// component. Additionally, when creating a prefab it is possible to flag a
// component as "auto override", which can change the behavior for a specific
// prefab from "inherit" to "override".
//
// This example shows how these different features can be used.

struct Attack {
    value : double
}

struct Defense {
    value : double
}

struct Damage {
    value : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Attack>)
    ecs_id(ecs, type<Defense>)
    ecs_id(ecs, type<Damage>)

    // Change the instantiation behavior for Attack and Defense to inherit.
    ecs_add_pair(ecs, ecs_id(ecs, type<Attack>), EcsOnInstantiate, EcsInherit)
    ecs_add_pair(ecs, ecs_id(ecs, type<Defense>), EcsOnInstantiate, EcsInherit)

    let SpaceShip = ecs_entity(ecs, "SpaceShip")
    ecs_add_id(ecs, SpaceShip, EcsPrefab)
    ecs_set(ecs, SpaceShip, Attack(value = 75.0lf))
    ecs_set(ecs, SpaceShip, Defense(value = 100.0lf))
    ecs_set(ecs, SpaceShip, Damage(value = 50.0lf))

    // Create a prefab instance.
    let inst = ecs_entity(ecs, "my_instance")
    ecs_add_pair(ecs, inst, EcsIsA, SpaceShip)

    // The entity will now have a private copy of the Damage component, but not
    // of the Attack and Defense components. We can see this when we look at the
    // type of the instance:
    print("instance type = [{ecs_take(ecs_type_str(ecs, ecs_get_type(ecs, inst)))}]\n")

    // Even though Attack was not copied to the instance when instantiated, we
    // can still override it manually afterwards by adding it to the instance:
    ecs_add(ecs, inst, type<Attack>)

    // The Attack component is now owned and shows up in the entity type:
    print("instance type = [{ecs_take(ecs_type_str(ecs, ecs_get_type(ecs, inst)))}]\n")

    // We can get all components on the instance, regardless of whether they
    // are overridden or not. Note that the overridden components (Attack and
    // Damage) are initialized with the values from the prefab component:
    let attack = ecs_get(ecs, inst, type<Attack>)
    let defense = ecs_get(ecs, inst, type<Defense>)
    let damage = ecs_get(ecs, inst, type<Damage>)

    print("attack: {attack.value:.6f}\n")
    print("defense: {defense.value:.6f}\n")
    print("damage: {damage.value:.6f}\n")

    flecs_fini(ecs)
}

// Output:
//  instance type = [Damage, (Identifier,Name), (IsA,SpaceShip)]
//  instance type = [Attack, Damage, (Identifier,Name), (IsA,SpaceShip)]
//  attack: 75.000000
//  defense: 100.000000
//  damage: 50.000000
