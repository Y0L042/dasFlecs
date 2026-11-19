options gen2

// Generated raw API: world lifecycle, entities, names, builtin ids and flag constants.
require dastest/testing_boost public
require flecs

[test]
def test_world(t : T?) {
    t |> run("version") @(t : T?) {
        t |> equal(flecs_version(), "4.2.0")
        t |> equal(FLECS_VERSION_MAJOR, 4)
    }
    t |> run("init / fini") @(t : T?) {
        var world = ecs_init()
        t |> success(world != null)
        t |> equal(ecs_fini(world), 0)
    }
    t |> run("entity lifecycle") @(t : T?) {
        var world = ecs_init()
        let e = ecs_new(world)
        t |> success(ecs_is_alive(world, e))
        ecs_delete(world, e)
        t |> success(!ecs_is_alive(world, e))
        ecs_fini(world)
    }
    t |> run("names and lookup") @(t : T?) {
        var world = ecs_init()
        let e = ecs_new(world)
        ecs_set_name(world, e, "Bob")
        t |> equal(ecs_get_name(world, e), "Bob")
        t |> equal(ecs_lookup(world, "Bob"), e)
        t |> equal(ecs_lookup(world, "Nobody"), 0ul)
        ecs_fini(world)
    }
}

[test]
def test_builtin_ids(t : T?) {
    t |> run("constant ids") @(t : T?) {
        t |> equal(ecs_id_EcsComponent, 1ul)
        t |> success(EcsOnUpdate != 0ul)
        t |> success(EcsChildOf != 0ul)
        t |> equal(ECS_PAIR, 1ul << 63ul)
    }
    t |> run("flag macros") @(t : T?) {
        t |> equal(EcsSelf, 1ul << 63ul)
        t |> equal(EcsUp, 1ul << 62ul)
        t |> equal(EcsTraverseFlags & EcsSelf, EcsSelf)
    }
    t |> run("import-time ids are set by importing the addon") @(t : T?) {
        var world = ecs_init()
        ecs_import_FlecsUnits(world)
        t |> success(EcsMeters() != 0ul)
        t |> success(ecs_is_alive(world, EcsMeters()))
        ecs_fini(world)
    }
}
