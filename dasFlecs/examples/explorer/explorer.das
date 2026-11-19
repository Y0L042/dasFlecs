options gen2
require flecs/flecs_boost

// Port of flecs examples/c/explorer
// example: no-run (runs a REST server until the process is stopped, like the C example)
//
// When the application is running, navigate to https://flecs.dev/explorer to inspect it.

struct Mass {
    value : double
}

[export]
def main() {
    var world = ecs_init()

    ecs_import_FlecsUnits(world)
    ecs_import_FlecsStats(world)    // Collect statistics periodically

    // Mass component
    ecs_id(world, type<Mass>)

    var desc : ecs_struct_desc_t
    desc.entity = ecs_id(world, type<Mass>)
    desc.members[0].name = "value"
    desc.members[0]._type = ecs_id_ecs_f64_t
    desc.members[0].unit = EcsKiloGrams()
    ecs_struct_init(world, unsafe(addr(desc)))

    // Simple hierarchy
    let Sun = ecs_entity(world, "Sun")
    ecs_set(world, Sun, Mass(value = 1.988500e31lf))

    ecs_set_scope(world, Sun)
    let Earth = ecs_entity(world, "Earth")
    ecs_set(world, Earth, Mass(value = 5.9722e24lf))

    ecs_set_scope(world, Earth)
    let Moon = ecs_entity(world, "Moon")
    ecs_set(world, Moon, Mass(value = 7.34767309e22lf))

    // Restore default hierarchy scope to root
    ecs_set_scope(world, 0ul)

    // Run application with REST interface. When the application is running,
    // navigate to https://flecs.dev/explorer to inspect it!
    //
    // See docs/FlecsRemoteApi.md#explorer for more information.
    var app : ecs_app_desc_t
    app.enable_rest = true
    ecs_app_run(world, unsafe(addr(app)))
}
