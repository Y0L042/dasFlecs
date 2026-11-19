options gen2

// Pairs, hierarchies and wildcard queries.
require dastest/testing_boost public
require flecs/flecs_boost

struct Likes {
    amount : int
}

[test]
def test_pairs(t : T?) {
    t |> run("pair encoding") @(t : T?) {
        let p = ecs_pair(EcsChildOf, 1234ul)
        t |> success(ecs_is_pair(p))
        t |> success(!ecs_is_pair(EcsChildOf))
        t |> equal(ecs_pair_first_raw(p), EcsChildOf)
        t |> equal(ecs_pair_second_raw(p), 1234ul)
    }
    t |> run("ChildOf hierarchy") @(t : T?) {
        var world = ecs_init()
        let parent = ecs_entity(world, "parent")
        let child = ecs_entity(world, "child")
        ecs_add_pair(world, child, EcsChildOf, parent)
        t |> success(ecs_has_pair(world, child, EcsChildOf, parent))
        t |> equal(ecs_get_parent(world, child), parent)
        t |> equal(ecs_lookup(world, "parent.child"), child)
        // deleting the parent deletes its children
        ecs_delete(world, parent)
        t |> success(!ecs_is_alive(world, child))
        flecs_fini(world)
    }
    t |> run("wildcard query over relationship targets") @(t : T?) {
        var world = ecs_init()
        let likes = ecs_entity(world, "Likes")
        let apples = ecs_entity(world, "Apples")
        let pears = ecs_entity(world, "Pears")
        let bob = ecs_entity(world, "Bob")
        let alice = ecs_entity(world, "Alice")
        ecs_add_pair(world, bob, likes, apples)
        ecs_add_pair(world, bob, likes, pears)
        ecs_add_pair(world, alice, likes, pears)
        var q = ecs_query(world, "(Likes, *)")
        // one result per (entity, matched pair)
        var matches = 0
        ecs_query_each(world, q) $(it) {
            matches += it.count
        }
        t |> equal(matches, 3)
        ecs_query_fini(q)
        var qp = ecs_query(world, "(Likes, Pears)")
        t |> equal(ecs_query_count_entities(world, qp), 2)
        ecs_query_fini(qp)
        flecs_fini(world)
    }
    t |> run("remove pair") @(t : T?) {
        var world = ecs_init()
        let a = ecs_new(world)
        let b = ecs_new(world)
        let rel = ecs_entity(world, "Rel")
        ecs_add_pair(world, a, rel, b)
        ecs_remove_pair(world, a, rel, b)
        t |> success(!ecs_has_pair(world, a, rel, b))
        flecs_fini(world)
    }
}
