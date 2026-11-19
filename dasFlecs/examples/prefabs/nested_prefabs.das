options gen2
require flecs/flecs_boost

// Port of flecs examples/c/prefabs/nested_prefabs
//
// Nested prefabs make it possible to reuse an existing prefab inside another
// prefab. An example of where this could be useful is a car with four wheels:
// instead of defining four times what a wheel is a Car prefab can reference an
// existing Wheel prefab.
//
// Nested prefabs can be created by adding a child that is a variant (inherits
// from) another prefab. For more information on variants, see the variants
// example.
//
// Instantiated children from a nested prefab still inherit from the original
// prefab. The reason for this is that an instantiated child is an exact copy
// of the prefab child, and the prefab child only has an IsA relationship to the
// nested prefab.

struct TirePressure {
    value : double
}

def wheel(ecs : ecs_world_t?; name : string; Wheel : ecs_entity_t) {
    let e = ecs_entity(ecs, name)
    ecs_add_id(ecs, e, EcsPrefab)
    ecs_add_pair(ecs, e, EcsIsA, Wheel)
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<TirePressure>)

    // Create a Wheel prefab.
    let Wheel = ecs_entity(ecs, "Wheel")
    ecs_add_id(ecs, Wheel, EcsPrefab)
    ecs_set(ecs, Wheel, TirePressure(value = 32.0lf))

    // Create a Car prefab with four wheels. Note how the wheel names are
    // prefixed with 'Car.', this is has the same effect as adding the
    // (ChildOf, Car) relationship.
    let Car = ecs_entity(ecs, "Car")
    ecs_add_id(ecs, Car, EcsPrefab)
    wheel(ecs, "Car.FrontLeft", Wheel)
    wheel(ecs, "Car.FrontRight", Wheel)
    wheel(ecs, "Car.BackLeft", Wheel)
    wheel(ecs, "Car.BackRight", Wheel)

    // Create a prefab instance.
    let inst = ecs_entity(ecs, "my_car")
    ecs_add_pair(ecs, inst, EcsIsA, Car)

    // Lookup one of the wheels
    let inst_front_left = ecs_lookup_child(ecs, inst, "FrontLeft")

    // The type shows that the child has a private copy of the TirePressure
    // component, and an IsA relationship to the Wheel prefab.
    print("type: [{ecs_take(ecs_type_str(ecs, ecs_get_type(ecs, inst_front_left)))}]\n")

    // Get the TirePressure component & print its value
    let p = ecs_get(ecs, inst_front_left, type<TirePressure>)
    print("pressure: {p.value:.6f}\n")

    flecs_fini(ecs)
}

// Output:
//  type: [TirePressure, (Identifier,Name), (ChildOf,my_car), (IsA,Wheel)]
//  pressure: 32.000000
