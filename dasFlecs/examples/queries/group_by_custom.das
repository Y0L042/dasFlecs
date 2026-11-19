options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/group_by_custom
//
// This example does the same as the group_by example, but with a custom
// group_by function. A custom function makes it possible to customize how a
// group id is calculated for a table.

struct Position {
    x : double
    y : double
}

def group_by_relation(ecs : ecs_world_t?; tbl : ecs_table_t?; id : ecs_id_t) : uint64 {
    // Use ecs_search to find the target for the relationship in the table
    var match : ecs_id_t
    if (ecs_search(ecs, tbl, ecs_pair(id, EcsWildcard), unsafe(addr(match))) != -1) {
        return ecs_pair_second(ecs, match)    // First, Second or Third
    }
    return 0ul
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)
    let Tag = ecs_tag(ecs, "Tag")    // Dummy tag to put entities in different tables

    // Create a relationship to use for the group_by function. Tables will
    // be assigned the relationship target as group id
    let Group = ecs_tag(ecs, "Group")

    // Targets for the relationship, which will be used as group ids.
    let First = ecs_tag(ecs, "First")
    let Second = ecs_tag(ecs, "Second")
    let Third = ecs_tag(ecs, "Third")

    // Grouped query
    var desc : ecs_query_desc_t
    desc.terms[0].id = ecs_id(ecs, type<Position>)
    ecs_query_desc_group_by(desc) @(world : ecs_world_t?; tbl : ecs_table_t?; id : ecs_id_t) : uint64 {
        return group_by_relation(world, tbl, id)
    }
    desc.group_by = Group    // Passed to id argument of group_by function
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Create entities in 6 different tables with 3 group ids
    let e1 = ecs_new_w_pair(ecs, Group, Third)
    ecs_set(ecs, e1, Position(x = 1.0lf, y = 1.0lf))
    let e2 = ecs_new_w_pair(ecs, Group, Second)
    ecs_set(ecs, e2, Position(x = 2.0lf, y = 2.0lf))
    let e3 = ecs_new_w_pair(ecs, Group, First)
    ecs_set(ecs, e3, Position(x = 3.0lf, y = 3.0lf))

    let e4 = ecs_new_w_pair(ecs, Group, Third)
    ecs_set(ecs, e4, Position(x = 4.0lf, y = 4.0lf))
    ecs_add_id(ecs, e4, Tag)
    let e5 = ecs_new_w_pair(ecs, Group, Second)
    ecs_set(ecs, e5, Position(x = 5.0lf, y = 5.0lf))
    ecs_add_id(ecs, e5, Tag)
    let e6 = ecs_new_w_pair(ecs, Group, First)
    ecs_set(ecs, e6, Position(x = 6.0lf, y = 6.0lf))
    ecs_add_id(ecs, e6, Tag)

    // The query cache now looks like this:
    //  - group First:
    //     - table [Position, (Group, First)]
    //     - table [Position, Tag, (Group, First)]
    //
    //  - group Second:
    //     - table [Position, (Group, Second)]
    //     - table [Position, Tag, (Group, Second)]
    //
    //  - group Third:
    //     - table [Position, (Group, Third)]
    //     - table [Position, Tag, (Group, Third)]

    // Iterate query, print position & table components
    ecs_query_each(ecs, q) $(it) {
        let table_str = ecs_take(ecs_table_str(ecs, it._table))
        let group_str = ecs_get_path(ecs, ecs_iter_get_group(it))
        print(" - group {group_str}: table [{table_str}]\n")
        ecs_field_view(it, type<Position>, 0) $(var p) {
            for (pi in p) {
                print("     \{{pi.x:.6f}, {pi.y:.6f}\}\n")
            }
        }
        print("\n")
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//   - group First: table [Position, (Group,First)]
//       {3.000000, 3.000000}
//
//   - group First: table [Position, Tag, (Group,First)]
//       {6.000000, 6.000000}
//
//   - group Second: table [Position, (Group,Second)]
//       {2.000000, 2.000000}
//
//   - group Second: table [Position, Tag, (Group,Second)]
//       {5.000000, 5.000000}
//
//   - group Third: table [Position, (Group,Third)]
//       {1.000000, 1.000000}
//
//   - group Third: table [Position, Tag, (Group,Third)]
//       {4.000000, 4.000000}
