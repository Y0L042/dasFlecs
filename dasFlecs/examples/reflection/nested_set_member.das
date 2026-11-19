options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/nested_set_member

struct Point {
    x : float
    y : float
}

struct Line {
    start : Point
    stop : Point
}

// ECS_STRUCT descriptions (see auto_define_struct)
let Point_desc = "\{ float x; float y; \}"
let Line_desc = "\{ Point start; Point stop; \}"

[export]
def main() {
    var ecs = ecs_init()

    ecs_meta_from_desc(ecs, ecs_id(ecs, type<Point>), ecs_type_kind_t.EcsStructType, Point_desc)
    let line_id = ecs_id(ecs, type<Line>)
    ecs_meta_from_desc(ecs, line_id, ecs_type_kind_t.EcsStructType, Line_desc)

    let ent = ecs_new(ecs)
    var ptr = ecs_ensure(ecs, ent, type<Line>)

    var cur = ecs_meta_cursor(ecs, line_id, ptr)
    let c = unsafe(addr(cur))
    ecs_meta_push(c)                // {
    ecs_meta_member(c, "start")     //   start:
    ecs_meta_push(c)                //   {
    ecs_meta_member(c, "x")         //     x:
    ecs_meta_set_float(c, 10.0lf)   //     10
    ecs_meta_member(c, "y")         //     y:
    ecs_meta_set_float(c, 20.0lf)   //     20
    ecs_meta_pop(c)                 //   }
    ecs_meta_member(c, "stop")      //   stop:
    ecs_meta_push(c)                //   {
    ecs_meta_member(c, "x")         //     x:
    ecs_meta_set_float(c, 30.0lf)   //     30
    ecs_meta_member(c, "y")         //     y:
    ecs_meta_set_float(c, 40.0lf)   //     40
    ecs_meta_pop(c)                 //   }
    ecs_meta_pop(c)                 // }

    print("{ecs_take(ecs_ptr_to_expr(ecs, line_id, ptr))}\n")
    // {start: {x: 10.00, y: 20.00}, stop: {x: 30.00, y: 40.00}}

    flecs_fini(ecs)
}

// Output:
//  {start: {x: 10, y: 20}, stop: {x: 30, y: 40}}
