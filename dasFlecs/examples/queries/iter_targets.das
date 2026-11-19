options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/iter_targets
//
// This example shows how to iterate matching targets of a relationship without
// iterating the same entity multiple times.
//
// When creating a (Relationship, *) query, the query will return one result per
// matching relationship pair, which returns the same entity multiple times.
// This example uses a (Relationship, _) query which at most returns a single
// result per matching pair, and the returned table record to iterate the
// targets for the current result.

[export]
def main() {
    var ecs = ecs_init()

    let Eats = ecs_tag(ecs, "Eats")
    let Pizza = ecs_tag(ecs, "Pizza")
    let Salad = ecs_tag(ecs, "Salad")

    let bob = ecs_entity(ecs, "Bob")
    ecs_add_pair(ecs, bob, Eats, Pizza)
    ecs_add_pair(ecs, bob, Eats, Salad)

    // EcsAny ensures that only a single result is returned per entity, as
    // opposed to EcsWildcard which returns a result per matched pair.
    var desc : ecs_query_desc_t
    desc.terms[0].id = ecs_pair(Eats, EcsAny)
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    ecs_query_each(ecs, q) $(it) {
        let t = ecs_table_get_type(it._table)
        let tr = unsafe(it.trs[0])
        for (i in range(it.count)) {
            print("{ecs_get_name(ecs, ecs_iter_entity(it, i))} eats:\n")
            for (k in range(int(tr.count))) {
                let tgt = ecs_pair_second(ecs, unsafe(t._array[k + int(tr.index)]))
                print(" - {ecs_get_name(ecs, tgt)}\n")
            }
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  Bob eats:
//   - Pizza
//   - Salad
