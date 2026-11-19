options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/hierarchies

// Simple transform location with 2D location; one type each for the local and the
// world transform (C uses two typedefs of the same struct)
struct LocalTransform {
    x : double
    y : double
}

struct WorldTransform {
    x : double
    y : double
}

def child(ecs : ecs_world_t?; parent : ecs_entity_t; name : string) : ecs_entity_t {
    var desc : ecs_entity_desc_t
    desc.name = name
    desc.parent = parent
    return ecs_entity_init(ecs, unsafe(addr(desc)))
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<LocalTransform>)
    ecs_id(ecs, type<WorldTransform>)

    // Whenever we add LocalTransform, also add WorldTransform
    ecs_add_pair(ecs, ecs_id(ecs, type<LocalTransform>), EcsWith, ecs_id(ecs, type<WorldTransform>))

    // Create a hierarchy. For an explanation see the entities/hierarchy example
    let sun = ecs_entity(ecs, "Sun")
    ecs_set(ecs, sun, LocalTransform(x = 1.0lf, y = 1.0lf))

    let mercury = child(ecs, sun, "Mercury")
    ecs_set(ecs, mercury, LocalTransform(x = 1.0lf, y = 1.0lf))

    let venus = child(ecs, sun, "Venus")
    ecs_set(ecs, venus, LocalTransform(x = 2.0lf, y = 2.0lf))

    let earth = child(ecs, sun, "Earth")
    ecs_set(ecs, earth, LocalTransform(x = 3.0lf, y = 3.0lf))

    let moon = child(ecs, earth, "Moon")
    ecs_set(ecs, moon, LocalTransform(x = 0.1lf, y = 0.1lf))

    // Create a hierarchical query to compute the global transform from the
    // local transform and the parent transform.
    var desc : ecs_query_desc_t
    // Read from entity's Local transform
    desc.terms[0].id = ecs_id(ecs, type<LocalTransform>)
    desc.terms[0].inout = int16(ecs_inout_kind_t.EcsIn)
    // Write to entity's World transform
    desc.terms[1].id = ecs_id(ecs, type<WorldTransform>)
    desc.terms[1].inout = int16(ecs_inout_kind_t.EcsOut)
    // Read from parent's World transform
    desc.terms[2].id = ecs_id(ecs, type<WorldTransform>)
    desc.terms[2].inout = int16(ecs_inout_kind_t.EcsIn)
    // Get from the parent in breadth-first order (cascade)
    desc.terms[2].src.id = EcsCascade
    // Make parent term optional so we also match the root (sun)
    desc.terms[2].oper = int16(ecs_oper_kind_t.EcsOptional)
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Do the transform
    ecs_query_each(ecs, q) $(it) {
        ecs_field_view(it, type<LocalTransform>, 0) $(var p) {
            ecs_field_view(it, type<WorldTransform>, 1) $(var p_out) {
                // empty when the optional parent term is not set (root)
                ecs_field_view(it, type<WorldTransform>, 2) $(var p_parent) {
                    // Inner loop, iterates entities in archetype
                    for (i in range(it.count)) {
                        p_out[i].x = p[i].x
                        p_out[i].y = p[i].y
                        if (!empty(p_parent)) {
                            p_out[i].x += p_parent[0].x
                            p_out[i].y += p_parent[0].y
                        }
                    }
                }
            }
        }
    }

    // Print ecs transforms
    ecs_each(ecs, type<WorldTransform>) $(it) {
        ecs_field_view(it, type<WorldTransform>, 0) $(var p) {
            for (i in range(it.count)) {
                print("{ecs_get_name(ecs, ecs_iter_entity(it, i))}: \{{p[i].x:.6f}, {p[i].y:.6f}\}\n")
            }
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  Sun: {1.000000, 1.000000}
//  Mercury: {2.000000, 2.000000}
//  Venus: {3.000000, 3.000000}
//  Earth: {4.000000, 4.000000}
//  Moon: {4.100000, 4.100000}
