options gen2
require flecs

// Raw generated C API only — no flecs_boost helpers.
[export]
def main() {
    print("flecs {flecs_version()}\n")
    var world = ecs_init()
    let e = ecs_new(world)
    ecs_set_name(world, e, "Bob")
    print("entity {e} name = {ecs_get_name(world, e)}\n")
    let found = ecs_lookup(world, "Bob")
    print("lookup Bob -> {found} (same: {found == e})\n")
    print("is_alive: {ecs_is_alive(world, e)}\n")
    ecs_delete(world, e)
    print("is_alive after delete: {ecs_is_alive(world, e)}\n")
    let info = ecs_get_world_info(world)
    print("frame_count_total = {info.frame_count_total}, last_component_id = {info.last_component_id}\n")
    print("FLECS_TERM_COUNT_MAX = {FLECS_TERM_COUNT_MAX}\n")
    ecs_fini(world)
    print("done\n")
}
