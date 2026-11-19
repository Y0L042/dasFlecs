options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/runtime_component
//
// A component can be created at runtime from reflection data alone, without a
// matching das (or C) type. Values are read and written with the meta cursor API.

[export]
def main() {
    var ecs = ecs_init()

    // Create component for a type that isn't known at compile time
    var desc : ecs_struct_desc_t
    desc.members[0].name = "x"
    desc.members[0]._type = ecs_id_ecs_f32_t    // builtin float type
    desc.members[1].name = "y"
    desc.members[1]._type = ecs_id_ecs_f32_t
    let Position = ecs_struct_init(ecs, unsafe(addr(desc)))

    // Create entity, set value of position using reflection API
    let ent = ecs_entity(ecs, "ent")

    // Get type info because we need to pass in the size
    let ti = ecs_get_type_info(ecs, Position)
    var ptr = ecs_ensure_id(ecs, ent, Position, uint64(ti.size))

    var cur = ecs_meta_cursor(ecs, Position, ptr)
    let c = unsafe(addr(cur))
    ecs_meta_push(c)                // {
    ecs_meta_set_float(c, 10.0lf)   //   10
    ecs_meta_next(c)                //   ,
    ecs_meta_set_float(c, 20.0lf)   //   20
    ecs_meta_pop(c)                 // }

    // Convert component to string
    print("{ecs_take(ecs_ptr_to_expr(ecs, Position, ptr))}\n")    // {x: 10, y: 20}

    flecs_fini(ecs)
}

// Output:
//  {x: 10, y: 20}
