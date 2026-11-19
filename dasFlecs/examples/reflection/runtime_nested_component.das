options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/runtime_nested_component

[export]
def main() {
    var ecs = ecs_init()

    // Create components for types that aren't known at compile time
    var pdesc : ecs_struct_desc_t
    pdesc.members[0].name = "x"
    pdesc.members[0]._type = ecs_id_ecs_f32_t    // builtin float type
    pdesc.members[1].name = "y"
    pdesc.members[1]._type = ecs_id_ecs_f32_t
    let Point = ecs_struct_init(ecs, unsafe(addr(pdesc)))

    var ldesc : ecs_struct_desc_t
    ldesc.members[0].name = "start"
    ldesc.members[0]._type = Point
    ldesc.members[1].name = "stop"
    ldesc.members[1]._type = Point
    let Line = ecs_struct_init(ecs, unsafe(addr(ldesc)))

    // Create entity, set value of position using reflection API
    let ent = ecs_entity(ecs, "ent")

    // Get type info because we need to pass in the size
    let ti = ecs_get_type_info(ecs, Line)
    var ptr = ecs_ensure_id(ecs, ent, Line, uint64(ti.size))

    var cur = ecs_meta_cursor(ecs, Line, ptr)
    let c = unsafe(addr(cur))
    ecs_meta_push(c)                // {
    ecs_meta_push(c)                //   {
    ecs_meta_set_float(c, 10.0lf)   //     10
    ecs_meta_next(c)                //     ,
    ecs_meta_set_float(c, 20.0lf)   //     20
    ecs_meta_pop(c)                 //   }
    ecs_meta_next(c)                //   ,
    ecs_meta_push(c)                //   {
    ecs_meta_set_float(c, 30.0lf)   //     30
    ecs_meta_next(c)                //     ,
    ecs_meta_set_float(c, 40.0lf)   //     40
    ecs_meta_pop(c)                 //   }
    ecs_meta_pop(c)                 // }

    // Convert component to string
    print("{ecs_take(ecs_ptr_to_expr(ecs, Line, ptr))}\n")
    // {start: {x: 10.00, y: 20.00}, stop: {x: 30.00, y: 40.00}}

    flecs_fini(ecs)
}

// Output:
//  {start: {x: 10, y: 20}, stop: {x: 30, y: 40}}
