options gen2
require flecs/flecs_boost

// Port of flecs examples/c/relationships/basics

[export]
def main() {
    var ecs = ecs_init()

    let Eats = ecs_tag(ecs, "Eats")

    // Entity used for Grows relationship
    let grows = ecs_entity(ecs, "Grows")

    // Relationship objects
    let apples = ecs_entity(ecs, "Apples")
    let pears = ecs_entity(ecs, "Pears")

    // Create an entity with 3 relationships. Relationships are like regular components,
    // but combine two types/identifiers into an (relationship, object) pair.
    let bob = ecs_entity(ecs, "Bob")
    // Pairs can be constructed from a type and entity
    ecs_add_pair(ecs, bob, Eats, apples)
    ecs_add_pair(ecs, bob, Eats, pears)
    // Pairs can also be constructed from two entity ids
    ecs_add_pair(ecs, bob, grows, pears)

    // Has can be used with relationships as well
    print("Bob eats apples? {ecs_has_pair(ecs, bob, Eats, apples) ? 1 : 0}\n")

    // Wildcards can be used to match relationships
    print("Bob grows food? {ecs_has_pair(ecs, bob, grows, EcsWildcard) ? 1 : 0}\n")

    // Print the type of the entity. Should output:
    //   (Identifier,Name),(Eats,Apples),(Eats,Pears),(Grows,Pears)
    print("Bob's type: [{ecs_take(ecs_type_str(ecs, ecs_get_type(ecs, bob)))}]\n")

    // Get first target of relationship
    print("Bob eats {ecs_get_name(ecs, ecs_get_target(ecs, bob, Eats, 0))}\n")

    // Get second target of relationship
    print("Bob also eats {ecs_get_name(ecs, ecs_get_target(ecs, bob, Eats, 1))}\n")

    flecs_fini(ecs)
}

// Output:
//  Bob eats apples? 1
//  Bob grows food? 1
//  Bob's type: [(Identifier,Name), (Eats,Apples), (Eats,Pears), (Grows,Pears)]
//  Bob eats Apples
//  Bob also eats Pears
