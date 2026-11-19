options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/nested_struct

struct Point {
    x : float
    y : float
}

struct Line {
    start : Point
    stop : Point
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Point>)
    ecs_id(ecs, type<Line>)

    var pdesc : ecs_struct_desc_t
    pdesc.entity = ecs_id(ecs, type<Point>)
    pdesc.members[0].name = "x"
    pdesc.members[0]._type = ecs_id_ecs_f32_t
    pdesc.members[1].name = "y"
    pdesc.members[1]._type = ecs_id_ecs_f32_t
    ecs_struct_init(ecs, unsafe(addr(pdesc)))

    var ldesc : ecs_struct_desc_t
    ldesc.entity = ecs_id(ecs, type<Line>)
    ldesc.members[0].name = "start"
    ldesc.members[0]._type = ecs_id(ecs, type<Point>)
    ldesc.members[1].name = "stop"
    ldesc.members[1]._type = ecs_id(ecs, type<Point>)
    ecs_struct_init(ecs, unsafe(addr(ldesc)))

    let ent = ecs_new(ecs)
    ecs_set(ecs, ent, Line(start = Point(x = 10.0, y = 20.0), stop = Point(x = 30.0, y = 40.0)))

    let ptr = ecs_get(ecs, ent, type<Line>)
    print("{ecs_take(ecs_ptr_to_expr(ecs, ecs_id(ecs, type<Line>), ptr))}\n")    // {start: {x: 10, y: 20}, stop: {x: 30, y: 40}}

    flecs_fini(ecs)
}

// Output:
//  {start: {x: 10, y: 20}, stop: {x: 30, y: 40}}
