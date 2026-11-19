options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/group_iter_all
//
// This example demonstrates how to iterate over all active groups of a
// grouped query using ecs_query_get_groups(), and then iterate the entities
// within each group with ecs_iter_set_group(). This is useful when an
// application needs to do per-group logic before/after processing the entities
// in that group.

struct Position {
    x : double
    y : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)

    let Asset_A = ecs_entity(ecs, "Asset_A")
    let Asset_B = ecs_entity(ecs, "Asset_B")
    let Asset_C = ecs_entity(ecs, "Asset_C")

    ecs_set(ecs, ecs_new_w_pair(ecs, EcsIsA, Asset_A), Position(x = 1.0lf, y = 1.0lf))
    ecs_set(ecs, ecs_new_w_pair(ecs, EcsIsA, Asset_A), Position(x = 2.0lf, y = 2.0lf))
    ecs_set(ecs, ecs_new_w_pair(ecs, EcsIsA, Asset_B), Position(x = 3.0lf, y = 3.0lf))
    ecs_set(ecs, ecs_new_w_pair(ecs, EcsIsA, Asset_C), Position(x = 4.0lf, y = 4.0lf))
    ecs_set(ecs, ecs_new_w_pair(ecs, EcsIsA, Asset_C), Position(x = 5.0lf, y = 5.0lf))
    ecs_set(ecs, ecs_new_w_pair(ecs, EcsIsA, Asset_C), Position(x = 6.0lf, y = 6.0lf))

    // Group entities by their IsA target. With no group_by callback set,
    // the default callback uses the relationship's target as the group ID.
    var desc : ecs_query_desc_t
    desc.terms[0].id = ecs_id(ecs, type<Position>)
    desc.group_by = EcsIsA
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Iterate all active groups via the query's group map. The map key is
    // the group ID, which here is the asset entity (the target of IsA).
    let groups = ecs_query_get_groups(q)
    var mit = ecs_map_iter(groups)
    while (ecs_map_next(unsafe(addr(mit)))) {
        let group_id = unsafe(mit.res[0])    // ecs_map_key(&mit)
        print("Group {ecs_get_path(ecs, group_id)}:\n")

        // Iterate just the entities in this group.
        var it = ecs_query_iter(ecs, q)
        ecs_iter_set_group(unsafe(addr(it)), group_id)
        while (ecs_query_next(unsafe(addr(it)))) {
            let pit = unsafe(addr(it))
            ecs_field_view(pit, type<Position>, 0) $(var p) {
                for (i in range(it.count)) {
                    print(" - {ecs_get_path(ecs, ecs_iter_entity(pit, i))}: \{{p[i].x:.0f}, {p[i].y:.0f}\}\n")
                }
            }
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  Group Asset_C:
//   - #480: {4, 4}
//   - #481: {5, 5}
//   - #482: {6, 6}
//  Group Asset_B:
//   - #479: {3, 3}
//  Group Asset_A:
//   - #477: {1, 1}
//   - #478: {2, 2}
