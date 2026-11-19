options gen2

// [ecs_component]: flecs reflection data generated from the struct's fields.
require dastest/testing_boost public
require flecs/flecs_boost
require strings

enum Faction {
    Neutral
    Red
    Blue
}

[ecs_component]
struct Stats {
    hp : int
    speed : float
}

[ecs_component]
struct Unit {
    name : string
    faction : Faction
    stats : Stats
    pos : float3
    flags : uint8
    alive : bool
    ammo : int[3]
    target : uint64
}

struct Plain {
    x : float
}

[test]
def test_reflect(t : T?) {
    t |> run("members are registered") @(t : T?) {
        var w = FlecsWorld()
        let id = ecs_id(w.c_ptr(), type<Unit>)
        t |> success(ecs_has_id(w.c_ptr(), id, ecs_id_EcsStruct))
        t |> success(ecs_has_id(w.c_ptr(), ecs_id(w.c_ptr(), type<Stats>), ecs_id_EcsStruct))
        // a struct without [ecs_component] is registered without members
        t |> success(!ecs_has_id(w.c_ptr(), ecs_id(w.c_ptr(), type<Plain>), ecs_id_EcsStruct))
        w.fini()
    }
    t |> run("json round trip") @(t : T?) {
        var w = FlecsWorld()
        let e = w.entity("u").set(Unit(name = "scout", faction = Faction.Blue, stats = Stats(hp = 7, speed = 2.5),
            pos = float3(1.0, 2.0, 3.0), flags = uint8(5), alive = true, ammo = fixed_array(1, 2, 3), target = 42ul))
        let json = e.to_json()
        t |> success(find(json, "\"name\":\"scout\"") >= 0)
        t |> success(find(json, "\"faction\":\"Blue\"") >= 0)
        t |> success(find(json, "\"stats\":\{\"hp\":7, \"speed\":2.5\}") >= 0)
        t |> success(find(json, "\"pos\":[1, 2, 3]") >= 0)
        t |> success(find(json, "\"ammo\":[1, 2, 3]") >= 0)
        let e2 = w.entity("v").set(Unit())
        e2.from_json(replace(json, "\"name\":\"u\", ", ""))
        let u = e2.get(type<Unit>)
        t |> equal(u.name, "scout")
        t |> equal(u.faction, Faction.Blue)
        t |> equal(u.stats.hp, 7)
        t |> equal(u.stats.speed, 2.5)
        t |> equal(u.pos.z, 3.0)
        t |> equal(int(u.flags), 5)
        t |> success(u.alive)
        t |> equal(u.ammo[2], 3)
        t |> equal(u.target, 42ul)
        w.fini()
    }
    t |> run("FlecsComponent.member") @(t : T?) {
        var w = FlecsWorld()
        w.component(type<Plain>).member(type<float>, "x")
        let e = w.entity("p").set(Plain(x = 1.5))
        t |> success(find(e.to_json(), "\"Plain\":\{\"x\":1.5\}") >= 0)
        w.fini()
    }
}
