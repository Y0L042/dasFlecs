options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/world_ser_deser

struct Position {
    x : double
    y : double
}

struct Velocity {
    x : double
    y : double
}

def xy_struct(world : ecs_world_t?; e : ecs_entity_t) {
    var desc : ecs_struct_desc_t
    desc.entity = e
    desc.members[0].name = "x"
    desc.members[0]._type = ecs_id_ecs_f64_t
    desc.members[1].name = "y"
    desc.members[1]._type = ecs_id_ecs_f64_t
    ecs_struct_init(world, unsafe(addr(desc)))
}

// Register components and systems in a module. This excludes them by default
// from the serialized data, and makes it easier to import across worlds.
def MoveModuleImport(world : ecs_world_t?) {
    ecs_module(world, "MoveModule")

    xy_struct(world, ecs_id(world, type<Position>))
    xy_struct(world, ecs_id(world, type<Velocity>))

    ecs_system(world, "Move", EcsOnUpdate, "Position, [in] Velocity") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            ecs_field_view(it, type<Velocity>, 1) $(var v) {
                for (i in range(it.count)) {
                    p[i].x += v[i].x
                    p[i].y += v[i].y
                    print("{ecs_get_name(it.stage, ecs_iter_entity(it, i))}: \{{p[i].x:.6f}, {p[i].y:.6f}\}\n")
                }
            }
        }
    }
}

[export]
def main() {
    var world_a = ecs_init()
    ecs_import(world_a, "MoveModule") @(w : ecs_world_t?) {
        MoveModuleImport(w)
    }

    let ent_1 = ecs_entity(world_a, "ent_1")
    let ent_2 = ecs_entity(world_a, "ent_2")
    ecs_set(world_a, ent_1, Position(x = 10.0lf, y = 20.0lf))
    ecs_set(world_a, ent_2, Position(x = 30.0lf, y = 40.0lf))
    ecs_set(world_a, ent_1, Velocity(x = 1.0lf, y = -1.0lf))
    ecs_set(world_a, ent_2, Velocity(x = -1.0lf, y = 1.0lf))

    // Serialize world to JSON
    let json = ecs_take(ecs_world_to_json(world_a, null))
    print("{json}\n\n")

    // Create second world, import same module
    var world_b = ecs_init()
    ecs_import(world_b, "MoveModule") @(w : ecs_world_t?) {
        MoveModuleImport(w)
    }

    // Deserialize JSON into second world
    ecs_world_from_json(world_b, json, null)

    // Run system once for both worlds
    ecs_progress(world_a, 0.0)
    print("\n")
    ecs_progress(world_b, 0.0)

    flecs_fini(world_a)
    flecs_fini(world_b)
}

// Output:
//  {"results":[{"name":"ent_1", "id":477, "components":{"move.module.Position":{"x":10, "y":20}, "move.module.Velocity":{"x":1, "y":-1}}}, {"name":"ent_2", "id":478, "components":{"move.module.Position":{"x":30, "y":40}, "move.module.Velocity":{"x":-1, "y":1}}}]}
//
//  ent_1: {11.000000, 19.000000}
//  ent_2: {29.000000, 41.000000}
//
//  ent_1: {11.000000, 19.000000}
//  ent_2: {29.000000, 41.000000}
