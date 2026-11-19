options gen2
require flecs/flecs_boost

// Port of flecs examples/c/prefabs/variant
//
// Prefabs can inherit from each other, which creates prefab variants. With
// variants applications can reuse a common set of components and specialize it
// by adding or overriding components on the variant.

struct Attack {
    value : double
}

struct Defense {
    value : double
}

struct FreightCapacity {
    value : double
}

struct ImpulseSpeed {
    value : double
}

struct Position {
    x : double
    y : double
}

def prefab(ecs : ecs_world_t?; name : string; base : ecs_entity_t) : ecs_entity_t {
    let e = ecs_entity(ecs, name)
    ecs_add_id(ecs, e, EcsPrefab)
    if (base != 0ul) {
        ecs_add_pair(ecs, e, EcsIsA, base)
    }
    return e
}

// shared (inherited) fields have one element for all entities of the table
def at(arr : array<auto(TT)>; i : int) : TT {
    return arr[length(arr) == 1 ? 0 : i]
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)
    ecs_id(ecs, type<Attack>)
    ecs_id(ecs, type<Defense>)
    ecs_id(ecs, type<FreightCapacity>)
    ecs_id(ecs, type<ImpulseSpeed>)

    // Create a base prefab for SpaceShips.
    let SpaceShip = prefab(ecs, "SpaceShip", 0ul)
    ecs_set(ecs, SpaceShip, ImpulseSpeed(value = 50.0lf))
    ecs_set(ecs, SpaceShip, Defense(value = 25.0lf))

    // Create a Freighter variant which inherits from SpaceShip
    let Freighter = prefab(ecs, "Freighter", SpaceShip)
    ecs_set(ecs, Freighter, FreightCapacity(value = 100.0lf))
    ecs_set(ecs, Freighter, Defense(value = 50.0lf))

    // Create a MammothFreighter variant which inherits from Freighter
    let MammothFreighter = prefab(ecs, "MammothFreighter", Freighter)
    ecs_set(ecs, MammothFreighter, FreightCapacity(value = 500.0lf))

    // Create a Frigate variant which inherits from SpaceShip
    let Frigate = prefab(ecs, "Frigate", SpaceShip)
    ecs_set(ecs, Frigate, Attack(value = 100.0lf))
    ecs_set(ecs, Frigate, Defense(value = 75.0lf))
    ecs_set(ecs, Frigate, ImpulseSpeed(value = 125.0lf))

    // Create an instance of the MammothFreighter. This entity will inherit the
    // ImpulseSpeed from SpaceShip, Defense from Freighter and FreightCapacity
    // from MammothFreighter.
    let inst = ecs_entity(ecs, "my_freighter")
    ecs_add_pair(ecs, inst, EcsIsA, MammothFreighter)

    // Add a private Position component.
    ecs_set(ecs, inst, Position(x = 10.0lf, y = 20.0lf))

    // Instances can override inherited components to give them a private copy
    // of the component. This freighter got an armor upgrade:
    ecs_set(ecs, inst, Defense(value = 100.0lf))

    // Queries can match components from multiple levels of inheritance
    var q = ecs_query(ecs, "Position, ImpulseSpeed, Defense, FreightCapacity")

    ecs_query_each(ecs, q) $(it) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            ecs_field_view(it, type<ImpulseSpeed>, 1) $(var s) {
                ecs_field_view(it, type<Defense>, 2) $(var d) {
                    ecs_field_view(it, type<FreightCapacity>, 3) $(var c) {
                        for (i in range(it.count)) {
                            print("{ecs_get_name(ecs, ecs_iter_entity(it, i))}:\n")
                            print(" - position: {p[i].x:.6f}, {p[i].y:.6f}\n")
                            print(" - impulse speed: {at(s, i).value:.6f}\n")
                            print(" - defense: {at(d, i).value:.6f}\n")
                            print(" - capacity: {at(c, i).value:.6f}\n")
                        }
                    }
                }
            }
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  my_freighter:
//   - position: 10.000000, 20.000000
//   - impulse speed: 50.000000
//   - defense: 100.000000
//   - capacity: 500.000000
