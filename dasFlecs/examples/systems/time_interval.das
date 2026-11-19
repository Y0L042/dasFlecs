options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/time_interval
// example: no-run (the main loop never exits, like the C example)
//
// This example shows how to run a system at a specified time interval.

def tick_system(ecs : ecs_world_t?; name : string; interval : float) {
    var desc : ecs_system_desc_t
    desc.entity = ecs_entity(ecs, name)
    desc.phase = EcsOnUpdate
    desc.interval = interval    // time in seconds
    ecs_system_init(ecs, desc) @(it : ecs_iter_t const?) {
        print("{ecs_get_name(it.stage, it.system)}\n")
    }
}

[export]
def main() {
    var ecs = ecs_init()

    // Create two systems that are running at different time intervals
    tick_system(ecs, "Tick", 1.0)
    tick_system(ecs, "FastTick", 0.5)

    // Run the main loop at 60 FPS
    ecs_set_target_fps(ecs, 60.0)

    while (ecs_progress(ecs, 0.0)) {
        pass
    }

    flecs_fini(ecs)
}

// Output:
//  FastTick
//  Tick
//  FastTick
//  FastTick
//  Tick
//  FastTick
//  FastTick
//  Tick
//  FastTick
//  FastTick
//  Tick
//  FastTick
//  FastTick
//  Tick
//  FastTick
//  FastTick
//  Tick
//  FastTick
//  FastTick
//  Tick
//  FastTick
//  FastTick
//  Tick
//  FastTick
