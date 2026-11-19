options gen2
require flecs

// Builtin entity ids, import-time ids and flag constants — raw API only.
[export]
def main() {
    var world = ecs_init()
    print("EcsOnUpdate         = {EcsOnUpdate}\n")
    print("EcsChildOf          = {EcsChildOf}\n")
    print("EcsWildcard         = {EcsWildcard}\n")
    print("ecs_id_EcsComponent = {ecs_id_EcsComponent}\n")
    print("ECS_PAIR            = {ECS_PAIR}\n")
    // assigned when the units addon is imported (ecs_init does not import units)
    print("EcsMeters() before import = {EcsMeters()}\n")
    ecs_import_FlecsUnits(world)
    ecs_import_FlecsStats(world)
    print("EcsMeters() after import  = {EcsMeters()}\n")
    print("ecs_id_EcsWorldStats() = {ecs_id_EcsWorldStats()}\n")
    print("EcsSelf             = {EcsSelf}, EcsUp = {EcsUp}, EcsTraverseFlags = {EcsTraverseFlags}\n")

    let parent = ecs_new(world)
    let child = ecs_new(world)
    // ecs_pair(EcsChildOf, parent), spelled out (flecs_boost provides ecs_pair)
    let pair = ECS_PAIR | (EcsChildOf << 32ul) | uint64(uint(parent))
    ecs_add_id(world, child, pair)
    print("child has (ChildOf, parent): {ecs_has_id(world, child, pair)}\n")
    print("parent of child == parent: {ecs_get_parent(world, child) == parent}\n")
    ecs_fini(world)
}
