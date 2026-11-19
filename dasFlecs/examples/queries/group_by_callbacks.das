options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/group_by_callbacks
//
// Group callbacks are invoked when a group is created and deleted. The value returned
// by on_group_create is stored as the group context, which can be fetched with
// ecs_query_get_group_ctx and is passed to on_group_delete.

struct Position {
    x : double
    y : double
}

struct GroupCtx {
    counter : int
}

var group_counter = 0

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
    desc.group_by = Group

    // Callback invoked when a new group is created
    ecs_query_desc_on_group_create(desc) @(world : ecs_world_t?; group_id : uint64) : void? {
        print("Group {ecs_get_name(world, group_id)} created\n")
        group_counter ++
        var ctx = new GroupCtx(counter = group_counter)
        return unsafe(reinterpret<void?>(ctx))
    }

    // Callback invoked when a group is deleted
    ecs_query_desc_on_group_delete(desc) @(world : ecs_world_t?; group_id : uint64; ctx : void?) {
        print("Group {ecs_get_name(world, group_id)} deleted\n")
        var gc = unsafe(reinterpret<GroupCtx?>(ctx))
        unsafe {
            delete gc
        }
    }

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

    print("\n")

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
        let group_id = ecs_iter_get_group(it)
        let group_str = ecs_get_path(ecs, group_id)
        let ctx = unsafe(reinterpret<GroupCtx?>(ecs_query_get_group_ctx(q, group_id)))
        print(" - group {group_str}: table [{table_str}]\n")
        print("   counter: {ctx.counter}\n")
        ecs_field_view(it, type<Position>, 0) $(var p) {
            for (pi in p) {
                print("     \{{pi.x:.6f}, {pi.y:.6f}\}\n")
            }
        }
        print("\n")
    }

    // Deleting the query will call the on_group_deleted callback
    ecs_query_fini(q)

    flecs_fini(ecs)
}

// Output:
//  Group Third created
//  Group Second created
//  Group First created
//
//   - group First: table [Position, (Group,First)]
//     counter: 3
//       {3.000000, 3.000000}
//
//   - group First: table [Position, Tag, (Group,First)]
//     counter: 3
//       {6.000000, 6.000000}
//
//   - group Second: table [Position, (Group,Second)]
//     counter: 2
//       {2.000000, 2.000000}
//
//   - group Second: table [Position, Tag, (Group,Second)]
//     counter: 2
//       {5.000000, 5.000000}
//
//   - group Third: table [Position, (Group,Third)]
//     counter: 1
//       {1.000000, 1.000000}
//
//   - group Third: table [Position, Tag, (Group,Third)]
//     counter: 1
//       {4.000000, 4.000000}
//
//  Group First deleted
//  Group Third deleted
//  Group Second deleted
