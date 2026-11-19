options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/setting_variables
//
// This example extends the component_inheritance example, and shows how
// we can use a single query to match units from different players and platoons
// by setting query variables before we iterate.
//
// The units in this example belong to a platoon, with the platoons belonging
// to a player.

let PlayerCount = 100
let PlatoonsPerPlayer = 3

def unit_type(ecs : ecs_world_t?; name : string; base : ecs_entity_t) : ecs_entity_t {
    let e = ecs_entity(ecs, name)
    ecs_add_pair(ecs, e, EcsIsA, base)
    return e
}

[export]
def main() {
    var ecs = ecs_init()

    // See component_inheritance example
    let Unit = ecs_tag(ecs, "Unit")
    let CombatUnit = unit_type(ecs, "CombatUnit", Unit)
    let MeleeUnit = unit_type(ecs, "MeleeUnit", CombatUnit)
    let RangedUnit = unit_type(ecs, "RangedUnit", CombatUnit)
    let Warrior = unit_type(ecs, "Warrior", MeleeUnit)
    let Wizard = unit_type(ecs, "Wizard", RangedUnit)
    let Marksman = unit_type(ecs, "Marksman", RangedUnit)
    unit_type(ecs, "Builder", Unit)

    // Make the ECS aware of the inheritance relationships. Cascading these
    // relationships to the units allows us to query for all units of a
    // certain class, e.g. RangedUnit.
    let Player = ecs_tag(ecs, "Player")
    let Platoon = ecs_tag(ecs, "Platoon")

    // Populate store with players and platoons
    for (p in range(PlayerCount)) {
        var player : ecs_entity_t
        // Give first player a name so we can look it up later
        if (p == 0) {
            player = ecs_entity(ecs, "MyPlayer")
        } else {
            player = ecs_new(ecs)
        }

        // Add player tag so we can query for all players if we want to
        ecs_add_id(ecs, player, Player)

        for (pl in range(PlatoonsPerPlayer)) {
            let platoon = ecs_new_w_pair(ecs, Player, player)

            // Add platoon tag so we can query for all platoons if we want to
            ecs_add_id(ecs, platoon, Platoon)

            // Add warriors, wizards and marksmen to the platoon
            let warrior = ecs_new_w_id(ecs, Warrior)
            ecs_add_pair(ecs, warrior, Platoon, platoon)
            let marksman = ecs_new_w_id(ecs, Marksman)
            ecs_add_pair(ecs, marksman, Platoon, platoon)
            let wizard = ecs_new_w_id(ecs, Wizard)
            ecs_add_pair(ecs, wizard, Platoon, platoon)
        }
    }

    // Create a query to find all RangedUnits for a platoon/player. The
    // equivalent query in the query DSL would look like this:
    //   (RangedUnit), (Platoon, $platoon), Player($platoon, $player)
    //
    // The way to read how this query is evaluated is:
    // - find all entities with (RangedUnit), store them in $this
    // - for each $this, find (Platoon, $platoon), store the target in $platoon
    // - for each $platoon, find Player($platoon, $player), store target in $player
    var desc : ecs_query_desc_t
    desc.terms[0].first.id = RangedUnit
    desc.terms[1].first.id = Platoon
    desc.terms[1].second.name = "$platoon"
    desc.terms[2].first.id = Player
    desc.terms[2].src.name = "$platoon"
    desc.terms[2].second.name = "$player"
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // If we would iterate this query it would return all ranged units for all
    // platoons & for all players. We can limit the results to just a single
    // platoon or a single player setting a variable beforehand. In this example
    // we'll just find all platoons & ranged units for a single player.
    let player_var = ecs_query_find_var(q, "player")
    let platoon_var = ecs_query_find_var(q, "platoon")

    // Iterate query, limit the results to units of MyPlayer
    var it = ecs_query_iter(ecs, q)
    ecs_iter_set_var(unsafe(addr(it)), player_var, ecs_lookup(ecs, "MyPlayer"))
    while (ecs_query_next(unsafe(addr(it)))) {
        let pit = unsafe(addr(it))
        let player = ecs_iter_get_var(pit, player_var)
        let platoon = ecs_iter_get_var(pit, platoon_var)
        let platoon_str = ecs_get_path(ecs, platoon)
        let class_str = ecs_take(ecs_id_str(ecs, ecs_field_id(pit, int8(0))))
        for (i in range(it.count)) {
            let unit_str = ecs_get_path(ecs, ecs_iter_entity(pit, i))
            print("Unit {unit_str} of class {class_str} in platoon {platoon_str} for player {ecs_get_name(ecs, player)}\n")
        }
    }

    // Try removing the ecs_iter_set_var call, this will iterate all ranged units
    // for all platoons and players.

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  Unit #487 of class Marksman in platoon #485 for player MyPlayer
//  Unit #488 of class Wizard in platoon #485 for player MyPlayer
//  Unit #491 of class Marksman in platoon #489 for player MyPlayer
//  Unit #492 of class Wizard in platoon #489 for player MyPlayer
//  Unit #495 of class Marksman in platoon #493 for player MyPlayer
//  Unit #496 of class Wizard in platoon #493 for player MyPlayer
