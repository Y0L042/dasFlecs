options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/mutate_entity
// example: output-varies (the last timeout value depends on measured frame time)

struct Timeout {
    value : double
}

[export]
def main() {
    var world = ecs_init()

    ecs_id(world, type<Timeout>)

    // System that deletes an entity after a timeout expires
    ecs_system(world, "Expire", EcsOnUpdate, "Timeout") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Timeout>, 0) $(var t) {
            for (i in range(it.count)) {
                t[i].value -= double(it.delta_time)
                if (t[i].value <= 0.0lf) {
                    // When deleting the entity, use the world provided by the iterator.
                    // To make sure that the storage doesn't change while a system is
                    // iterating entities, and multiple threads can safely access the
                    // data, mutations (like a delete) are added to a command queue and
                    // executed when it's safe to do so.
                    let e = ecs_iter_entity(it, i)
                    ecs_delete(it.stage, e)
                    print("Expire: {ecs_get_name(it.stage, e)} deleted!\n")
                }
            }
        }
    }

    // System that prints remaining expiry time
    ecs_system(world, "PrintExpire", EcsOnUpdate, "[in] Timeout") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Timeout>, 0) $(var t) {
            for (i in range(it.count)) {
                print("PrintExpire: {ecs_get_name(it.stage, ecs_iter_entity(it, i))} has {t[i].value:.2f} seconds left\n")
            }
        }
    }

    // Observer that triggers when the component is actually removed
    ecs_observer(world, "Expired", EcsOnRemove, "Timeout") @(it : ecs_iter_t const?) {
        for (i in range(it.count)) {
            print("Expired: {ecs_get_name(it.stage, ecs_iter_entity(it, i))} actually deleted\n")
        }
    }

    // Create entity that expires after 3 seconds
    let e = ecs_set_name(world, 0ul, "MyEntity")
    ecs_set(world, e, Timeout(value = 3.0lf))

    ecs_set_target_fps(world, 1.0)

    while (ecs_progress(world, 0.0)) {
        // If entity is no longer alive, exit
        if (!ecs_is_alive(world, e)) {
            break
        }

        print("Tick...\n")
    }

    flecs_fini(world)
}

// Output:
//  PrintExpire: MyEntity has 2.00 seconds left
//  Tick...
//  PrintExpire: MyEntity has 1.00 seconds left
//  Tick...
//  Expire: MyEntity deleted!
//  PrintExpire: MyEntity has -0.01 seconds left
//  Expired: MyEntity actually deleted
