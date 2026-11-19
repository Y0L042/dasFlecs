options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/facts
//
// This example shows how to use queries for testing facts. A fact is a query
// that has no variable elements. Consider a regular ECS query like this:
//   Position, Velocity
//
// When written out in full, this query looks like:
//   Position($this), Velocity($this)
//
// "this" is a (builtin) query variable that is unknown before we evaluate the
// query. Therefore this query does not test a fact, we can't know which values
// This will assume.
//
// An example of a fact-checking query is:
//   IsA(Cat, Animal)
//
// This is a fact: the query has no elements that are unknown before evaluating
// the query. A query that checks a fact does not return entities, but will
// instead return the reasons why a fact is true (if it is true).

def check(ecs : ecs_world_t?; friends : ecs_query_t?; x_var, y_var : int; x, y : ecs_entity_t) : string {
    var it = ecs_query_iter(ecs, friends)
    ecs_iter_set_var(unsafe(addr(it)), x_var, x)
    ecs_iter_set_var(unsafe(addr(it)), y_var, y)
    return ecs_iter_is_true(unsafe(addr(it))) ? "Yes" : "No"
}

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

    // Create a query that checks if two entities like each other. By itself this
    // query is not a fact, but we can use it to check facts by populating both
    // of its variables.
    //
    // The equivalent of this query in the DSL is:
    //   Likes($X, $Y), Likes($Y, $X)
    //
    // Instead of using variables we could have created a query that referred the
    // entities directly, but then we would have to create a query for each
    // fact, vs reusing a single query for multiple facts.
    //
    // See the setting_variables example for more details
    //
    // (The second term is ported as written in the C example, "$x", "$x".)
    var desc : ecs_query_desc_t
    desc.terms[0].first.id = Likes
    desc.terms[0].src.name = "$x"
    desc.terms[0].second.name = "$y"
    desc.terms[1].first.id = Likes
    desc.terms[1].src.name = "$x"
    desc.terms[1].second.name = "$x"
    var friends = ecs_query_init(ecs, unsafe(addr(desc)))

    // Lookup the index of the variables.
    let x_var = ecs_query_find_var(friends, "x")
    let y_var = ecs_query_find_var(friends, "y")

    print("Are Bob and Alice friends? {check(ecs, friends, x_var, y_var, bob, alice)}\n")
    print("Are Bob and John friends? {check(ecs, friends, x_var, y_var, bob, john)}\n")
    print("Are Jane and John friends? {check(ecs, friends, x_var, y_var, jane, john)}\n")

    // It doesn't matter who we assign to X or Y. After the variables are
    // substituted, either yields a fact that is true.
    print("Are John and Jane friends? {check(ecs, friends, x_var, y_var, john, jane)}\n")

    ecs_query_fini(friends)

    flecs_fini(ecs)
}

// Output:
//  Are Bob and Alice friends? No
//  Are Bob and John friends? No
//  Are Jane and John friends? No
//  Are John and Jane friends? No
