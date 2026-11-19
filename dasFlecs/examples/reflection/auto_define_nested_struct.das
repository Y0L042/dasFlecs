options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/auto_define_nested_struct
//
// ECS_STRUCT captures the struct body as a string; ecs_meta_from_desc parses that
// string into reflection data (see auto_define_struct).

struct Point {
    x : int
    y : int
}

struct Line {
    start : Point
    stop : Point
}

// Point is used by Line, so it must also be captured
let Point_desc = "\{ int32_t x; int32_t y; \}"
let Line_desc = "\{ Point start; Point stop; \}"

[export]
def main() {
    var ecs = ecs_init()

    // Register both components. Note that Point is registered first, so that
    // when Line is registered, the type information of Point can be looked up
    ecs_meta_from_desc(ecs, ecs_id(ecs, type<Point>), ecs_type_kind_t.EcsStructType, Point_desc)
    ecs_meta_from_desc(ecs, ecs_id(ecs, type<Line>), ecs_type_kind_t.EcsStructType, Line_desc)

    // Serialize as usual
    var value = Line(start = Point(x = 1, y = 2), stop = Point(x = 3, y = 4))
    let json = ecs_take(ecs_ptr_to_json(ecs, ecs_id(ecs, type<Line>), unsafe(addr(value))))
    print("{json}\n")    // {"start": {"x": 1, "y": 2}, "stop": {"x": 3, "y": 4}}

    flecs_fini(ecs)
}

// Output:
//  {"start":{"x":1, "y":2}, "stop":{"x":3, "y":4}}
