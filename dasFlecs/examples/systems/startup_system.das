options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/startup_system
//
// Startup systems are systems registered with the EcsOnStart phase, and are
// only ran during the first frame. Just like with regular phases, custom phases
// can depend on the EcsOnStart phase (see custom_phases example). Phases that
// depend on EcsOnStart are also only ran during the first frame.
//
// Other than that, startup systems behave just like regular systems (they can
// match components, can introduce merge points), with as only exception that
// they are guaranteed to always run on the main thread.

[export]
def main() {
    var ecs = ecs_init()

    // Startup system
    ecs_system(ecs, "Startup", EcsOnStart, "") @(it : ecs_iter_t const?) {
        print("{ecs_get_name(it.stage, it.system)}\n")
    }

    // Regular system
    ecs_system(ecs, "Update", EcsOnUpdate, "") @(it : ecs_iter_t const?) {
        print("{ecs_get_name(it.stage, it.system)}\n")
    }

    // First frame. This runs both the Startup and Update systems
    ecs_progress(ecs, 0.0)

    // Second frame. This runs only the Update system
    ecs_progress(ecs, 0.0)

    flecs_fini(ecs)
}

// Output:
//  Startup
//  Update
//  Update
