options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/component_inheritance
//
// This example shows how queries can be used to match simple inheritance trees.

def unit_type(ecs : ecs_world_t?; name : string; base : ecs_entity_t) : ecs_entity_t {
    let e = ecs_entity(ecs, name)
    ecs_add_pair(ecs, e, EcsIsA, base)
    return e
}

def unit(ecs : ecs_world_t?; name : string; kind : ecs_entity_t) {
    let e = ecs_entity(ecs, name)
    ecs_add_id(ecs, e, kind)
}

[export]
def main() {
    var ecs = ecs_init()

    // Create a simple hierarchy of unit types.
    let Unit = ecs_tag(ecs, "Unit")

    let CombatUnit = unit_type(ecs, "CombatUnit", Unit)
    let MeleeUnit = unit_type(ecs, "MeleeUnit", CombatUnit)
    let RangedUnit = unit_type(ecs, "RangedUnit", CombatUnit)

    let Warrior = unit_type(ecs, "Warrior", MeleeUnit)
    let Wizard = unit_type(ecs, "Wizard", RangedUnit)
    let Marksman = unit_type(ecs, "Marksman", RangedUnit)
    let Builder = unit_type(ecs, "Builder", Unit)

    // Create a few units
    unit(ecs, "warrior_1", Warrior)
    unit(ecs, "warrior_2", Warrior)

    unit(ecs, "marksman_1", Marksman)
    unit(ecs, "marksman_2", Marksman)

    unit(ecs, "wizard_1", Wizard)
    unit(ecs, "wizard_2", Wizard)

    unit(ecs, "builder_1", Builder)
    unit(ecs, "builder_2", Builder)

    // Create a query to find all ranged units
    var desc : ecs_query_desc_t
    desc.terms[0].id = RangedUnit
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Iterate the query
    ecs_query_each(ecs, q) $(it) {
        for (i in range(it.count)) {
            print("Unit {ecs_get_name(ecs, ecs_iter_entity(it, i))} found\n")
        }
    }

    ecs_query_fini(q)

    flecs_fini(ecs)
}

// Output:
//  Unit marksman_1 found
//  Unit marksman_2 found
//  Unit wizard_1 found
//  Unit wizard_2 found
