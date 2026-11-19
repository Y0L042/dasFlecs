options gen2

// flecs_boost typed component helpers.
require dastest/testing_boost public
require flecs/flecs_boost

struct Position {
    x : float
    y : float
}

struct Mass {
    value : double
    flags : uint8
}

[test]
def test_components(t : T?) {
    t |> run("registration is cached and named after the das type") @(t : T?) {
        var world = ecs_init()
        let id = ecs_id(world, type<Position>)
        t |> success(id != 0ul)
        t |> equal(ecs_id(world, type<Position>), id)
        t |> equal(ecs_get_name(world, id), "Position")
        t |> equal(ecs_lookup(world, "Position"), id)
        flecs_fini(world)
        t |> success(world == null)
    }
    t |> run("set / get round trip") @(t : T?) {
        var world = ecs_init()
        let e = ecs_new(world)
        ecs_set(world, e, Position(x = 1.5, y = -2.0))
        ecs_set(world, e, Mass(value = 80.25lf, flags = 7u8))
        let p = ecs_get(world, e, type<Position>)
        t |> success(p != null)
        t |> equal(p.x, 1.5)
        t |> equal(p.y, -2.0)
        let m = ecs_get(world, e, type<Mass>)
        t |> equal(m.value, 80.25lf)
        t |> equal(m.flags, 7u8)
        flecs_fini(world)
    }
    t |> run("get_mut writes through") @(t : T?) {
        var world = ecs_init()
        let e = ecs_new(world)
        ecs_set(world, e, Position(x = 0.0, y = 0.0))
        var p = ecs_get_mut(world, e, type<Position>)
        p.x = 42.0
        ecs_modified(world, e, type<Position>)
        t |> equal(ecs_get(world, e, type<Position>).x, 42.0)
        flecs_fini(world)
    }
    t |> run("add / has / remove") @(t : T?) {
        var world = ecs_init()
        let e = ecs_new(world)
        t |> success(!ecs_has(world, e, type<Position>))
        t |> success(ecs_get(world, e, type<Position>) == null)
        ecs_add(world, e, type<Position>)
        t |> success(ecs_has(world, e, type<Position>))
        ecs_remove(world, e, type<Position>)
        t |> success(!ecs_has(world, e, type<Position>))
        flecs_fini(world)
    }
    t |> run("each world registers separately") @(t : T?) {
        var a = ecs_init()
        var b = ecs_init()
        let ida = ecs_id(a, type<Position>)
        let idb = ecs_id(b, type<Position>)
        t |> equal(ecs_get_name(a, ida), "Position")
        t |> equal(ecs_get_name(b, idb), "Position")
        flecs_fini(a)
        flecs_fini(b)
    }
}
