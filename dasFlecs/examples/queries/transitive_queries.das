options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/transitive_queries
//
// Transitive relationships make it possible to tell the ECS that if an entity
// has a relationship (R, X) and X has relationship (R, Y), the entity should be
// treated as if it also has (R, Y). In practice this is useful for expressing
// things like:
//
// Bob lives in SanFrancisco
// San Francisco is located in the United States
// Therefore Bob also lives in the United States.
//
// An example of transitivity can be seen in the component_inheritance example.
// This example uses the builtin IsA relationship, which is transitive. This
// example shows how to achieve similar behavior with a user-defined relationship.

def place(ecs : ecs_world_t?; name : string; kind, LocatedIn, parent : ecs_entity_t) : ecs_entity_t {
    let e = ecs_entity(ecs, name)
    ecs_add_id(ecs, e, kind)
    if (parent != 0ul) {
        ecs_add_pair(ecs, e, LocatedIn, parent)
    }
    return e
}

[export]
def main() {
    var ecs = ecs_init()

    // Create a LocatedIn relationship with transitive property
    let LocatedIn = ecs_new(ecs)
    ecs_add_id(ecs, LocatedIn, EcsTransitive)

    let Planet = ecs_tag(ecs, "Planet")
    let Continent = ecs_tag(ecs, "Continent")
    let Country = ecs_tag(ecs, "Country")
    let State = ecs_tag(ecs, "State")
    let City = ecs_tag(ecs, "City")
    let Person = ecs_tag(ecs, "Person")

    // Add some locations
    let earth = place(ecs, "Earth", Planet, LocatedIn, 0ul)

    let north_america = place(ecs, "NorthAmerica", Continent, LocatedIn, earth)
    let europe = place(ecs, "Europe", Continent, LocatedIn, earth)

    let united_states = place(ecs, "UnitedStates", Country, LocatedIn, north_america)
    let netherlands = place(ecs, "Netherlands", Country, LocatedIn, europe)

    let california = place(ecs, "California", State, LocatedIn, united_states)
    let washington = place(ecs, "Washington", State, LocatedIn, united_states)
    let noord_holland = place(ecs, "NoordHolland", State, LocatedIn, netherlands)

    let san_francisco = place(ecs, "SanFrancisco", City, LocatedIn, california)
    let seattle = place(ecs, "Seattle", City, LocatedIn, washington)
    let amsterdam = place(ecs, "Amsterdam", City, LocatedIn, noord_holland)

    // Let's add some people
    place(ecs, "Bob", Person, LocatedIn, san_francisco)
    place(ecs, "Alice", Person, LocatedIn, seattle)
    place(ecs, "Job", Person, LocatedIn, amsterdam)

    // Create a query that finds the countries persons live in. Note that these
    // have not been explicitly added to the Person entities, but because the
    // LocatedIn is transitive, the query engine will traverse the relationship
    // until it found something that is a country.
    //
    // The equivalent of this query in the DSL is:
    //   Person, (LocatedIn, $location), Country($location)
    var desc : ecs_query_desc_t
    desc.terms[0].id = Person
    desc.terms[1].first.id = LocatedIn
    desc.terms[1].second.name = "$location"
    desc.terms[2].first.id = Country
    desc.terms[2].src.name = "$location"
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Lookup the index of the variable. This will let us quickly lookup its
    // value while we're iterating.
    let location_var = ecs_query_find_var(q, "location")

    // Iterate the query
    ecs_query_each(ecs, q) $(it) {
        let location = ecs_iter_get_var(it, location_var)
        for (i in range(it.count)) {
            print("{ecs_get_name(ecs, ecs_iter_entity(it, i))} lives in {ecs_get_name(ecs, location)}\n")
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  Bob lives in UnitedStates
//  Alice lives in UnitedStates
//  Job lives in Netherlands
