options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/change_tracking
//
// Queries have a builtin mechanism for tracking changes per matched table. This
// is a cheap way of eliminating redundant work, as many entities can be skipped
// with a single check.
//
// This example shows how to use change tracking in combination with using
// prefabs to store a single dirty state for multiple entities.

struct Dirty {
    value : bool
}

struct Position {
    x : double
    y : double
}

def b2i(b : bool) : int {
    return b ? 1 : 0
}

[export]
def main() {
    var world = ecs_init()

    ecs_id(world, type<Dirty>)
    ecs_id(world, type<Position>)

    // Make Dirty inheritable so that queries can match it on prefabs
    ecs_add_pair(world, ecs_id(world, type<Dirty>), EcsOnInstantiate, EcsInherit)

    // Create a query that just reads a component. We'll use this query for
    // change tracking.
    // Each query has its own private dirty state which is reset only when the
    // query is iterated.
    var rdesc : ecs_query_desc_t
    rdesc.terms[0].id = ecs_id(world, type<Position>)
    rdesc.terms[0].inout = int16(ecs_inout_kind_t.EcsIn)
    rdesc.flags = EcsQueryDetectChanges    // Enable change detection
    var q_read = ecs_query_init(world, unsafe(addr(rdesc)))

    // Create a query that writes the component based on a Dirty state.
    var wdesc : ecs_query_desc_t
    // Only match if Dirty is shared from prefab
    wdesc.terms[0].id = ecs_id(world, type<Dirty>)
    wdesc.terms[0].inout = int16(ecs_inout_kind_t.EcsIn)
    wdesc.terms[0].src.id = EcsUp
    wdesc.terms[0].trav = EcsIsA
    wdesc.terms[1].id = ecs_id(world, type<Position>)
    var q_write = ecs_query_init(world, unsafe(addr(wdesc)))

    // Create two prefabs with a Dirty component. We can use this to share a
    // single Dirty value for all entities in a table.
    let p1 = ecs_entity(world, "p1")
    ecs_add_id(world, p1, EcsPrefab)
    ecs_set(world, p1, Dirty(value = false))

    let p2 = ecs_entity(world, "p2")
    ecs_add_id(world, p2, EcsPrefab)
    ecs_set(world, p2, Dirty(value = true))

    // Create instances of p1 and p2. Because the entities have different
    // prefabs, they end up in different tables.
    let e1 = ecs_entity(world, "e1")
    ecs_add_pair(world, e1, EcsIsA, p1)
    ecs_set(world, e1, Position(x = 10.0lf, y = 20.0lf))

    let e2 = ecs_entity(world, "e2")
    ecs_add_pair(world, e2, EcsIsA, p1)
    ecs_set(world, e2, Position(x = 30.0lf, y = 40.0lf))

    let e3 = ecs_entity(world, "e3")
    ecs_add_pair(world, e3, EcsIsA, p2)
    ecs_set(world, e3, Position(x = 50.0lf, y = 60.0lf))

    let e4 = ecs_entity(world, "e4")
    ecs_add_pair(world, e4, EcsIsA, p2)
    ecs_set(world, e4, Position(x = 70.0lf, y = 80.0lf))

    // We can use the changed() function on the query to check if any of the
    // tables it is matched with has changed. Since this is the first time that
    // we check this and the query is matched with the tables we just created,
    // the function will return true.
    print("q_read changed: {b2i(ecs_query_changed(q_read))}\n")

    // The changed state will remain true until we have iterated each table.
    var it = ecs_query_iter(world, q_read)
    while (ecs_query_next(unsafe(addr(it)))) {
        // With ecs_iter_changed we can check if the table we're currently
        // iterating has changed since last iteration.
        // Because this is the first time the query is iterated, all tables
        // will show up as changed.
        let table_str = ecs_take(ecs_table_str(world, it._table))
        print("it.changed for table [{table_str}]: {b2i(ecs_iter_changed(unsafe(addr(it))))}\n")
    }

    // Now that we have iterated all tables, the dirty state is reset.
    print("q_read changed: {b2i(ecs_query_changed(q_read))}\n\n")

    // Iterate the write query. Because the Position term is InOut (default)
    // iterating the query will write to the dirty state of iterated tables.
    it = ecs_query_iter(world, q_write)
    while (ecs_query_next(unsafe(addr(it)))) {
        let pit = unsafe(addr(it))
        print("iterate table [{ecs_take(ecs_table_str(world, it._table))}]\n")

        // Because we enforced that Dirty is a shared component, we can check
        // a single value for the entire table.
        let dirty = unsafe(ecs_field(pit, type<Dirty>, 0))
        if (!dirty.value) {
            ecs_iter_skip(pit)
            print("it.skip for table [{ecs_take(ecs_table_str(world, it._table))}]\n")
            continue
        }

        // For all other tables the dirty state will be set.
        ecs_field_view(pit, type<Position>, 1) $(var p) {
            for (pi in p) {
                pi.x += 1.0lf
                pi.y += 1.0lf
            }
        }
    }

    // One of the tables has changed, so q_read.changed() will return true
    print("\nq_read changed: {b2i(ecs_query_changed(q_read))}\n")

    // When we iterate the read query, we'll see that one table has changed.
    it = ecs_query_iter(world, q_read)
    while (ecs_query_next(unsafe(addr(it)))) {
        let table_str = ecs_take(ecs_table_str(world, it._table))
        print("it.changed for table [{table_str}]: {b2i(ecs_iter_changed(unsafe(addr(it))))}\n")
    }

    ecs_query_fini(q_read)
    ecs_query_fini(q_write)
    flecs_fini(world)
}

// Output:
//  q_read changed: 1
//  it.changed for table [Position, (Identifier,Name), (IsA,p1)]: 1
//  it.changed for table [Position, (Identifier,Name), (IsA,p2)]: 1
//  q_read changed: 0
//
//  iterate table [Position, (Identifier,Name), (IsA,p1)]
//  it.skip for table [Position, (Identifier,Name), (IsA,p1)]
//  iterate table [Position, (Identifier,Name), (IsA,p2)]
//
//  q_read changed: 1
//  it.changed for table [Position, (Identifier,Name), (IsA,p1)]: 0
//  it.changed for table [Position, (Identifier,Name), (IsA,p2)]: 1
