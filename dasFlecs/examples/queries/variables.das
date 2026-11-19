options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/variables
//
// Query variables are named placeholders in a query, written as $name. A query with
// variables is evaluated like a join: here, (Eats, $food) finds what an entity eats,
// and Healthy($food) only keeps foods that have the Healthy tag.

[export]
def main() {
    var ecs = ecs_init()

    let Eats = ecs_tag(ecs, "Eats")
    let Healthy = ecs_tag(ecs, "Healthy")

    let Apples = ecs_entity(ecs, "Apples")
    let Salad = ecs_entity(ecs, "Salad")
    let Burgers = ecs_entity(ecs, "Burgers")
    let Pizza = ecs_entity(ecs, "Pizza")
    let Chocolate = ecs_entity(ecs, "Chocolate")

    ecs_add_id(ecs, Apples, Healthy)
    ecs_add_id(ecs, Salad, Healthy)

    let bob = ecs_entity(ecs, "Bob")
    ecs_add_pair(ecs, bob, Eats, Apples)
    ecs_add_pair(ecs, bob, Eats, Burgers)
    ecs_add_pair(ecs, bob, Eats, Pizza)

    let alice = ecs_entity(ecs, "Alice")
    ecs_add_pair(ecs, alice, Eats, Salad)
    ecs_add_pair(ecs, alice, Eats, Chocolate)
    ecs_add_pair(ecs, alice, Eats, Apples)

    // Here we're creating a query that has a single variable. Note how the
    // same variable is used in both terms, which means the query will
    // only return entities that eat healthy food.
    //
    // The equivalent of this query in the DSL is:
    //   (Eats, $food), Healthy($food)
    var desc : ecs_query_desc_t
    desc.terms[0].first.id = Eats
    desc.terms[0].second.name = "$food"
    desc.terms[1].first.id = Healthy
    desc.terms[1].src.name = "$food"
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Lookup the index of the variable. This will let us quickly lookup its
    // value while we're iterating.
    let food_var = ecs_query_find_var(q, "food")

    // Iterate the query
    ecs_query_each(ecs, q) $(it) {
        let food = ecs_iter_get_var(it, food_var)
        for (i in range(it.count)) {
            print("{ecs_get_name(ecs, ecs_iter_entity(it, i))} eats {ecs_get_name(ecs, food)}\n")
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  Bob eats Apples
//  Alice eats Apples
//  Alice eats Salad
