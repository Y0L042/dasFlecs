options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/entity_type
//
// Members of type ecs_entity_t are serialized as entity paths.

struct TypeWithEntity {
    e : ecs_entity_t
}

// ECS_STRUCT(TypeWithEntity, ...) description (see auto_define_struct)
let TypeWithEntity_desc = "\{ ecs_entity_t e; \}"

[export]
def main() {
    var ecs = ecs_init()

    let twe = ecs_id(ecs, type<TypeWithEntity>)
    ecs_meta_from_desc(ecs, twe, ecs_type_kind_t.EcsStructType, TypeWithEntity_desc)

    let foo = ecs_set_name(ecs, 0ul, "Foo")
    let e = ecs_insert(ecs, TypeWithEntity(e = foo))

    // Convert component to flecs expression string
    let ptr = ecs_get(ecs, e, type<TypeWithEntity>)
    print("{ecs_take(ecs_ptr_to_expr(ecs, twe, ptr))}\n")    // {e: Foo}

    flecs_fini(ecs)
}

// Output:
//  {e: Foo}
