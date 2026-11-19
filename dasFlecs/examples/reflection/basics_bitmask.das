options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/basics_bitmask

// Toppings is a uint32 bitmask (a C typedef of uint32_t)
let Bacon = 0x1u
let Lettuce = 0x2u
let Tomato = 0x4u

struct Sandwich {
    toppings : uint
}

[export]
def main() {
    var ecs = ecs_init()

    // Register components as usual. Toppings has no das type of its own, so it is
    // registered by name and size (ECS_COMPONENT(ecs, Toppings)).
    let Toppings = ecs_component_register(ecs, "Toppings", typeinfo sizeof(type<uint>), typeinfo alignof(type<uint>))
    ecs_id(ecs, type<Sandwich>)

    // Add reflection data to components
    var bdesc : ecs_bitmask_desc_t
    bdesc.entity = Toppings    // Make sure to use existing id
    bdesc.constants[0].name = "Bacon"
    bdesc.constants[0].value = uint64(Bacon)
    bdesc.constants[1].name = "Lettuce"
    bdesc.constants[1].value = uint64(Lettuce)
    bdesc.constants[2].name = "Tomato"
    bdesc.constants[2].value = uint64(Tomato)
    ecs_bitmask_init(ecs, unsafe(addr(bdesc)))

    var sdesc : ecs_struct_desc_t
    sdesc.entity = ecs_id(ecs, type<Sandwich>)    // Make sure to use existing id
    sdesc.members[0].name = "toppings"
    sdesc.members[0]._type = Toppings
    ecs_struct_init(ecs, unsafe(addr(sdesc)))

    // Create entity with Sandwich as usual
    let ent = ecs_new(ecs)
    ecs_set(ecs, ent, Sandwich(toppings = Bacon | Lettuce))

    // Convert Sandwich component to flecs expression string
    let ptr = ecs_get(ecs, ent, type<Sandwich>)
    let str = ecs_take(ecs_ptr_to_expr(ecs, ecs_id(ecs, type<Sandwich>), ptr))
    print("{str}\n")    // {toppings: Bacon|Lettuce}

    flecs_fini(ecs)
}

// Output:
//  {toppings: Lettuce|Bacon}
