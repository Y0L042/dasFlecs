options gen2
require flecs/flecs_boost

// Port of flecs examples/c/prefabs/basics
//
// Prefabs are entities that can be used as templates for other entities. They
// are created with a builtin Prefab tag, which by default excludes them from
// queries and systems.
//
// Prefab instances are entities that have an IsA relationship to the prefab.
// The IsA relationship causes instances to inherit the components from the
// prefab. By default all instances for a prefab share its components.
//
// Inherited components save memory as they only need to be stored once for all
// prefab instances. They also speed up the creation of prefabs, as inherited
// components don't need to be copied to the instances.
//
// To get a private copy of a component, an instance can add it which is called
// an override. Overrides can be manual (by using add) or automatic (see the
// override example).
//
// If a prefab has children, adding the IsA relationship instantiates the prefab
// children for the instance (see hierarchy example).

struct Defense {
    value : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Defense>)

    // Make Defense component inheritable. By default components are copied from
    // the instance to the prefab. An inherited component is only stored on the
    // prefab, and is shared across all instances.
    ecs_add_pair(ecs, ecs_id(ecs, type<Defense>), EcsOnInstantiate, EcsInherit)

    // Create a SpaceShip prefab with a Defense component.
    let SpaceShip = ecs_entity(ecs, "SpaceShip")
    ecs_add_id(ecs, SpaceShip, EcsPrefab)
    ecs_set(ecs, SpaceShip, Defense(value = 50.0lf))

    // Create a prefab instance
    let inst = ecs_entity(ecs, "my_spaceship")
    ecs_add_pair(ecs, inst, EcsIsA, SpaceShip)

    // Because of the IsA relationship, the instance now shares the Defense
    // component with the prefab, and can be retrieved as a regular component:
    let d_inst = ecs_get(ecs, inst, type<Defense>)
    print("defense: {d_inst.value:.6f}\n")

    // Because the component is shared, changing the value on the prefab will
    // also change the value for the instance:
    ecs_set(ecs, SpaceShip, Defense(value = 100.0lf))
    print("defense after set: {d_inst.value:.6f}\n")    // now prints 100

    // Prefab components can be iterated like regular components:
    var qdesc : ecs_query_desc_t
    qdesc.terms[0].id = ecs_id(ecs, type<Defense>)
    var q = ecs_query_init(ecs, unsafe(addr(qdesc)))

    ecs_query_each(ecs, q) $(it) {
        ecs_field_view(it, type<Defense>, 0) $(var d) {
            for (i in range(it.count)) {
                print("{ecs_get_name(ecs, ecs_iter_entity(it, i))}: defense: {d[length(d) == 1 ? 0 : i].value:.6f}\n")
            }
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  defense: 50.000000
//  defense after set: 100.000000
//  my_spaceship: defense: 100.000000
