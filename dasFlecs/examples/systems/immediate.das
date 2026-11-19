options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/immediate
//
// When an application calls ecs_progress(), the world is put in readonly mode.
// This ensures that systems (on multiple threads) can safely iterate
// components, without having to worry about components moving around while
// they're being read. This has as side effect that any operations (like adding
// or removing components) are not visible until the end of the frame (see the
// sync_point example for more details).
// Sometimes this is not what you want, and you need a change to be visible
// immediately. For these use cases, applications can use an immediate system.
// This temporarily takes the world out of readonly mode, so a system can make
// changes that are directly visible.
// Because they mutate the world directly, immediate systems are never ran on
// more than one thread, and no other systems are ran at the same time.

var Waiter : ecs_entity_t
var Plate : ecs_entity_t

// System that assigns plates to waiter. By making this system immediate
// plate assignments are assigned directly (not deferred) to waiters, which
// ensures that we won't assign plates to the same waiter more than once.
def AssignPlate(it : ecs_iter_t const?) {
    let ecs = it.stage
    let q_waiter = unsafe(reinterpret<ecs_query_t?>(it.ctx))    // Get query from system context

    // Iterate unassigned plates
    for (i in range(it.count)) {
        let plate = ecs_iter_entity(it, i)

        // Find an available waiter
        var qit = ecs_query_iter(ecs, q_waiter)
        let waiter = ecs_iter_first(unsafe(addr(qit)))    // Get first matching entity
        if (waiter != 0ul) {
            // An available waiter was found, assign a plate to it so that the
            // next plate will no longer find it.
            ecs_add_pair(it.world, waiter, Plate, plate)
            ecs_add_pair(ecs, plate, Waiter, waiter)
            print("Assigned {ecs_get_name(ecs, waiter)} to {ecs_get_name(ecs, plate)}!\n")
        } else {
            // No available waiters, can't assign the plate
            pass
        }
    }
}

[export]
def main() {
    var ecs = ecs_init()

    Waiter = ecs_tag(ecs, "Waiter")
    Plate = ecs_tag(ecs, "Plate")

    // Create query to find all waiters without a plate
    var qdesc : ecs_query_desc_t
    qdesc.terms[0].id = Waiter
    qdesc.terms[1].id = ecs_pair(Plate, EcsWildcard)
    qdesc.terms[1].oper = int16(ecs_oper_kind_t.EcsNot)
    var q_waiter = ecs_query_init(ecs, unsafe(addr(qdesc)))

    // Find all plates without a Waiter
    var sdesc : ecs_system_desc_t
    sdesc.entity = ecs_entity(ecs, "AssignPlate")
    sdesc.phase = EcsOnUpdate
    sdesc.query.terms[0].id = Plate
    sdesc.query.terms[1].id = ecs_pair(Waiter, EcsWildcard)
    sdesc.query.terms[1].oper = int16(ecs_oper_kind_t.EcsNot)
    sdesc.ctx = unsafe(reinterpret<void?>(q_waiter))
    sdesc.immediate = true    // disable readonly mode for this system
    ecs_system_init(ecs, sdesc) @(it : ecs_iter_t const?) {
        AssignPlate(it)
    }

    // Create a few plates and waiters
    let waiter_1 = ecs_entity(ecs, "waiter_1")
    ecs_add_id(ecs, waiter_1, Waiter)
    let waiter_2 = ecs_entity(ecs, "waiter_2")
    ecs_add_id(ecs, waiter_2, Waiter)
    let waiter_3 = ecs_entity(ecs, "waiter_3")
    ecs_add_id(ecs, waiter_3, Waiter)

    let plate_1 = ecs_entity(ecs, "plate_1")
    ecs_add_id(ecs, plate_1, Plate)
    let plate_2 = ecs_entity(ecs, "plate_2")
    ecs_add_id(ecs, plate_2, Plate)
    ecs_add_pair(ecs, plate_2, Waiter, waiter_1)    // already assigned
    let plate_3 = ecs_entity(ecs, "plate_3")
    ecs_add_id(ecs, plate_3, Plate)

    // Also assign plate_2 to waiter_1
    ecs_add_pair(ecs, waiter_1, Plate, plate_2)

    // Run the system
    ecs_progress(ecs, 0.0)

    ecs_query_fini(q_waiter)
    flecs_fini(ecs)
}

// Output:
//  Assigned waiter_3 to plate_1!
//  Assigned waiter_2 to plate_3!
