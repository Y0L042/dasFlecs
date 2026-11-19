options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/group_iter
//
// A group iterator iterates over a single group of a grouped query (see the
// group_by example for more details). This can be useful when an application
// may need to match different entities based on the context of the game, such
// as editor mode, day/night, inside/outside or location in the world.
//
// One example is that of an open game which is divided up into world
// cells. Even though a world may contain many entities, only the entities in
// cells close to the player need to be processed.
//
// Instead of creating a cached query per world cell, which could be expensive
// as there are more caches to keep in sync, applications can create a single
// query grouped by world cell, and use group iterators to only iterate the
// necessary cells.

def group_by_relation(ecs : ecs_world_t?; tbl : ecs_table_t?; id : ecs_id_t) : uint64 {
    // Use ecs_search to find the target for the relationship in the table
    var match : ecs_id_t
    if (ecs_search(ecs, tbl, ecs_pair(id, EcsWildcard), unsafe(addr(match))) != -1) {
        return ecs_pair_second(ecs, match)    // World cell is 2nd element of pair
    }
    return 0ul
}

def npc(ecs : ecs_world_t?; WorldCell, cell, kind, Npc : ecs_entity_t) {
    let e = ecs_new_w_pair(ecs, WorldCell, cell)
    ecs_add_id(ecs, e, kind)
    ecs_add_id(ecs, e, Npc)
}

def print_table(ecs : ecs_world_t?; it : ecs_iter_t const?) {
    let table_str = ecs_take(ecs_table_str(ecs, it._table))
    let group_str = ecs_get_path(ecs, ecs_iter_get_group(it))
    print(" - group {group_str}: table [{table_str}]\n")
}

[export]
def main() {
    var ecs = ecs_init()

    // A world cell relationship with four cells
    let WorldCell = ecs_tag(ecs, "WorldCell")
    let Cell_0_0 = ecs_tag(ecs, "Cell_0_0")
    let Cell_0_1 = ecs_tag(ecs, "Cell_0_1")
    let Cell_1_0 = ecs_tag(ecs, "Cell_1_0")
    let Cell_1_1 = ecs_tag(ecs, "Cell_1_1")

    // Npc tags
    let Npc = ecs_tag(ecs, "Npc")
    let Merchant = ecs_tag(ecs, "Merchant")
    let Soldier = ecs_tag(ecs, "Soldier")
    let Beggar = ecs_tag(ecs, "Beggar")
    let Mage = ecs_tag(ecs, "Mage")

    // Create Npcs in world cell 0_0
    npc(ecs, WorldCell, Cell_0_0, Merchant, Npc)
    npc(ecs, WorldCell, Cell_0_0, Merchant, Npc)

    // Create Npcs in world cell 0_1
    npc(ecs, WorldCell, Cell_0_1, Beggar, Npc)
    npc(ecs, WorldCell, Cell_0_1, Soldier, Npc)

    // Create Npcs in world cell 1_0
    npc(ecs, WorldCell, Cell_1_0, Mage, Npc)
    npc(ecs, WorldCell, Cell_1_0, Beggar, Npc)

    // Create Npcs in world cell 1_1
    npc(ecs, WorldCell, Cell_1_1, Soldier, Npc)

    // Create a query that matches all Npc's, grouped by WorldCell
    var desc : ecs_query_desc_t
    desc.terms[0].id = Npc
    ecs_query_desc_group_by(desc) @(world : ecs_world_t?; tbl : ecs_table_t?; id : ecs_id_t) : uint64 {
        return group_by_relation(world, tbl, id)
    }
    desc.group_by = WorldCell
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Iterate all tables
    print("All tables:\n")
    ecs_query_each(ecs, q) $(it) {
        print_table(ecs, it)
        // Uncomment to iterate entities in table
        // for (i in range(it.count)) { }
    }

    print("\n")

    // Only iterate entities in cell 1_0
    print("Tables for cell 1_0:\n")
    var it = ecs_query_iter(ecs, q)
    ecs_iter_set_group(unsafe(addr(it)), Cell_1_0)
    while (ecs_query_next(unsafe(addr(it)))) {
        print_table(ecs, unsafe(addr(it)))
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  All tables:
//   - group Cell_1_1: table [Npc, Soldier, (WorldCell,Cell_1_1)]
//   - group Cell_1_0: table [Npc, Mage, (WorldCell,Cell_1_0)]
//   - group Cell_1_0: table [Npc, Beggar, (WorldCell,Cell_1_0)]
//   - group Cell_0_1: table [Npc, Beggar, (WorldCell,Cell_0_1)]
//   - group Cell_0_1: table [Npc, Soldier, (WorldCell,Cell_0_1)]
//   - group Cell_0_0: table [Npc, Merchant, (WorldCell,Cell_0_0)]
//
//  Tables for cell 1_0:
//   - group Cell_1_0: table [Npc, Mage, (WorldCell,Cell_1_0)]
//   - group Cell_1_0: table [Npc, Beggar, (WorldCell,Cell_1_0)]
