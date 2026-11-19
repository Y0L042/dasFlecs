options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/cyclic_variables
//
// This example shows how a query may have terms with cyclic dependencies on
// variables.

[export]
def main() {
    var ecs = ecs_init()

    let Likes = ecs_tag(ecs, "Likes")    // Likes relationship

    let bob = ecs_entity(ecs, "Bob")
    let alice = ecs_entity(ecs, "Alice")
    let john = ecs_entity(ecs, "John")
    let jane = ecs_entity(ecs, "Jane")

    ecs_add_pair(ecs, bob, Likes, alice)
    ecs_add_pair(ecs, alice, Likes, bob)
    ecs_add_pair(ecs, john, Likes, jane)
    ecs_add_pair(ecs, jane, Likes, john)
    ecs_add_pair(ecs, bob, Likes, jane)    // inserting a bit of drama

    // The following query will only return entities that have a cyclic Likes
    // relationship- that is they must both like each other.
    //
    // The equivalent query in the DSL is:
    //   Likes($X, $Y), Likes($Y, $X)
    //
    // This is also an example of a query where all sources are variables. By
    // default queries use the builtin "this" variable as subject, which is what
    // populates the entities array in the query result (accessed by the
    // iter::entity function).
    //
    // Because this query does not use This at all, the entities array will not
    // be populated, and it.count will always be 0.
    var desc : ecs_query_desc_t
    desc.terms[0].first.id = Likes
    desc.terms[0].src.name = "$x"
    desc.terms[0].second.name = "$y"
    desc.terms[1].first.id = Likes
    desc.terms[1].src.name = "$y"
    desc.terms[1].second.name = "$x"
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Lookup the index of the variables. This will let us quickly lookup their
    // values while we're iterating.
    let x_var = ecs_query_find_var(q, "x")
    let y_var = ecs_query_find_var(q, "y")

    // Iterate the query
    ecs_query_each(ecs, q) $(it) {
        let x = ecs_iter_get_var(it, x_var)
        let y = ecs_iter_get_var(it, y_var)
        print("{ecs_get_name(ecs, x)} likes {ecs_get_name(ecs, y)}\n")
    }

    ecs_query_fini(q)

    flecs_fini(ecs)
}

// Output:
//  Alice likes Bob
//  John likes Jane
//  Jane likes John
//  Bob likes Alice
