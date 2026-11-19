options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/target_fps
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

    // Set target FPS to 1 frame per second
    ecs_set_target_fps(ecs, 1.0)

    // Run 5 frames
    for (i in range(5)) {
        // To make sure the frame doesn't run faster than the specified target
        // FPS ecs_progress will insert a sleep if the measured delta_time is
        // smaller than 1 / target_fps.
        //
        // By default ecs_progress uses the sleep function provided by the OS
        // which is not always very accurate. If more accuracy is required the
        // sleep function of the OS API can be overridden with a custom one.
        //
        // If a value other than 0 is provided to the delta_time argument of
        // ecs_progress, this value will be used to calculate the length of
        // the sleep to insert.
        ecs_progress(ecs, 0.0)
    }

    flecs_fini(ecs)
}

// Output:
//  delta_time: 1.000000
//  delta_time: 1.005051
//  delta_time: 1.004336
//  delta_time: 1.005041
//  delta_time: 0.944849
