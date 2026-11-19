options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/member_ranges

struct CpuUtilization {
    value : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<CpuUtilization>)

    // Register reflection data warning and error ranges. This adds metadata to
    // a type which can be used by tools (like the explorer) to visualize data.
    var desc : ecs_struct_desc_t
    desc.entity = ecs_id(ecs, type<CpuUtilization>)
    desc.members[0].name = "value"
    desc.members[0]._type = ecs_id_ecs_f64_t
    desc.members[0]._range.min = 0.0lf            // Specifics values that the member can assume
    desc.members[0]._range.max = 100.0lf
    desc.members[0].warning_range.min = 0.0lf     // Values outside this range are considered a warning
    desc.members[0].warning_range.max = 60.0lf
    desc.members[0].error_range.min = 0.0lf       // Values outside this range are considered an error
    desc.members[0].error_range.max = 80.0lf
    ecs_struct_init(ecs, unsafe(addr(desc)))

    let m1 = ecs_entity(ecs, "MachineA")
    ecs_set(ecs, m1, CpuUtilization(value = 50.0lf))

    let m2 = ecs_entity(ecs, "MachineB")
    ecs_set(ecs, m2, CpuUtilization(value = 75.0lf))

    let m3 = ecs_entity(ecs, "MachineC")
    ecs_set(ecs, m3, CpuUtilization(value = 90.0lf))

    // Uncomment these lines and open
    //   https://www.flecs.dev/explorer?show=query&query=CpuUtilization
    // to see how ranges affect visualization:
    //   var app : ecs_app_desc_t
    //   app.enable_rest = true
    //   ecs_app_run(ecs, unsafe(addr(app)))

    flecs_fini(ecs)
}

// Output:
//
