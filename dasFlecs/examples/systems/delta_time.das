options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/delta_time
// example: output-varies (measured frame times)

[export]
def main() {
    var ecs = ecs_init()

    // Create system that prints delta_time. This system doesn't query for any
    // components which means it won't match any entities, but will still be ran
    // once for each call to ecs_progress.
    ecs_system(ecs, "PrintDeltaTime", EcsOnUpdate, "") @(it : ecs_iter_t const?) {
        // Print delta_time. The same value is passed to all systems.
        print("delta_time: {double(it.delta_time):.6f}\n")
    }

    // Call progress with 0.0 for the delta_time parameter. This will cause
    // ecs_progress to measure the time passed since the last frame. The
    // delta_time of the first frame is a best guess (16ms).
    ecs_progress(ecs, 0.0)

    // The following calls should print a delta_time of approximately 100ms
    ecs_os_sleep(0, 100 * 1000 * 1000)
    ecs_progress(ecs, 0.0)

    ecs_os_sleep(0, 100 * 1000 * 1000)
    ecs_progress(ecs, 0.0)

    flecs_fini(ecs)
}

// Output:
//  delta_time: 0.016667
//  delta_time: 0.099370
//  delta_time: 0.101454
