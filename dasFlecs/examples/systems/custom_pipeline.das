options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/custom_pipeline
//
// Custom pipelines make it possible for applications to override which systems
// are ran by a pipeline and how they are ordered. Pipelines are queries under
// the hood, and custom pipelines override the query used for system matching.

// If you only want to use custom phases in addition or in place of the builtin
// phases see the custom_phases and custom_phases_no_builtin examples, as this
// does not require using a custom pipeline.

[export]
def main() {
    var ecs = ecs_init()

    let Physics = ecs_tag(ecs, "Physics")

    // Create a pipeline that matches systems with Physics. Note that this
    // pipeline does not require the use of phases (see custom_phases) or of the
    // DependsOn relationship.
    var pdesc : ecs_pipeline_desc_t
    pdesc.query.terms[0].id = EcsSystem    // Mandatory, must always match systems
    pdesc.query.terms[1].id = Physics
    let pipeline = ecs_pipeline_init(ecs, unsafe(addr(pdesc)))

    // Configure the world to use the custom pipeline
    ecs_set_pipeline(ecs, pipeline)

    // Create system with Physics tag (ECS_SYSTEM(ecs, Sys, Physics, 0))
    ecs_system(ecs, "Sys", Physics, "") @(it : ecs_iter_t const?) {
        print("System ran!\n")
    }

    // Runs the pipeline & system
    ecs_progress(ecs, 0.0)

    flecs_fini(ecs)
}

// Output:
//  System ran!
