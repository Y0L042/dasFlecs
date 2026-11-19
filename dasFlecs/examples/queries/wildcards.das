options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/wildcards
//
// Queries can have wildcard terms that can match multiple instances of a
// relationship or relationship target.

struct Eats {
    amount : int
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Eats>)
    let Apples = ecs_tag(ecs, "Apples")
    let Pears = ecs_tag(ecs, "Pears")

    // Create a query that matches edible components
    var desc : ecs_query_desc_t
    desc.terms[0].id = ecs_pair(ecs_id(ecs, type<Eats>), EcsWildcard)
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Create a few entities that match the query
    let bob = ecs_entity(ecs, "Bob")
    ecs_set_pair(ecs, bob, Eats(amount = 10), Apples)
    ecs_set_pair(ecs, bob, Eats(amount = 5), Pears)

    let alice = ecs_entity(ecs, "Alice")
    ecs_set_pair(ecs, alice, Eats(amount = 4), Apples)

    // Iterate the query
    ecs_query_each(ecs, q) $(it) {
        // Get the food from the (Eats, *) pair the query matched
        let pair = ecs_field_id(it, int8(0))
        let food = ecs_pair_second(ecs, pair)
        ecs_field_view(it, type<Eats>, 0) $(var eats) {
            for (i in range(it.count)) {
                print("{ecs_get_name(ecs, ecs_iter_entity(it, i))} eats {eats[i].amount} {ecs_get_name(ecs, food)}\n")
            }
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  Alice eats 4 Apples
//  Bob eats 10 Apples
//  Bob eats 5 Pears
