options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/units

struct WeatherStation {
    temperature : double
    pressure : double
    precipitation : double
}

def print_value(world : ecs_world_t?; cur : ecs_meta_cursor_t const?) {
    // Get unit entity and component (EcsUnit is a builtin component, so it is read by
    // its id with ecs_get_by_id)
    let u = ecs_meta_get_unit(cur)
    let u_data = ecs_get_by_id(world, u, ecs_id_EcsUnit, type<EcsUnit>)

    // Print value with unit symbol
    print("{ecs_meta_get_member(cur)}: {ecs_meta_get_float(cur):.1f} {u_data.symbol}\n")
}

[export]
def main() {
    var ecs = ecs_init()

    // Import units module.
    ecs_import_FlecsUnits(ecs)

    ecs_id(ecs, type<WeatherStation>)

    // Register reflection data with units. This can improve the way information
    // is visualized in tools, such as the explorer.
    var desc : ecs_struct_desc_t
    desc.entity = ecs_id(ecs, type<WeatherStation>)
    desc.members[0].name = "temperature"
    desc.members[0]._type = ecs_id_ecs_f64_t
    desc.members[0].unit = EcsCelsius()
    desc.members[1].name = "pressure"
    desc.members[1]._type = ecs_id_ecs_f64_t
    desc.members[1].unit = EcsBar()
    desc.members[2].name = "precipitation"
    desc.members[2]._type = ecs_id_ecs_f64_t
    desc.members[2].unit = EcsMilliMeters()
    ecs_struct_init(ecs, unsafe(addr(desc)))

    let e = ecs_insert(ecs, WeatherStation(temperature = 24.0lf, pressure = 1.2lf, precipitation = 0.5lf))

    // Use cursor API to print values with units
    var ptr = ecs_ensure(ecs, e, type<WeatherStation>)
    var cur = ecs_meta_cursor(ecs, ecs_id(ecs, type<WeatherStation>), ptr)
    let c = unsafe(addr(cur))
    ecs_meta_push(c)
    print_value(ecs, c)
    ecs_meta_next(c)
    print_value(ecs, c)
    ecs_meta_next(c)
    print_value(ecs, c)
    ecs_meta_pop(c)

    flecs_fini(ecs)
}

// Output:
//  temperature: 24.0 °C
//  pressure: 1.2 bar
//  precipitation: 0.5 mm
