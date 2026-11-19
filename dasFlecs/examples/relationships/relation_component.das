options gen2
require flecs/flecs_boost

// Port of flecs examples/c/relationships/relation_component
//
// This example shows how relationships can be combined with components to attach
// data to a relationship.

// Some demo components:
struct Requires {
    amount : double
}

struct Expires {
    timeout : double
}

struct Position {
    x : double
    y : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Requires>)
    ecs_id(ecs, type<Expires>)
    ecs_id(ecs, type<Position>)

    let Gigawatts = ecs_tag(ecs, "Gigawatts")
    let MustHave = ecs_tag(ecs, "MustHave")

    // When one element of a pair is a component and the other element is a tag,
    // the pair assumes the type of the component.
    let e1 = ecs_new(ecs)
    ecs_set_pair(ecs, e1, Requires(amount = 1.21lf), Gigawatts)
    var r = ecs_get_pair(ecs, e1, type<Requires>, Gigawatts)
    print("requires: {r.amount:.2f}\n")

    // The component can be either the first or second part of a pair:
    let e2 = ecs_new(ecs)
    ecs_set_pair_second(ecs, e2, Gigawatts, Requires(amount = 1.21lf))
    r = ecs_get_pair_second(ecs, e2, Gigawatts, type<Requires>)
    print("requires: {r.amount:.2f}\n")

    // Note that <Requires, Gigawatts> and <Gigawatts, Requires> are two
    // different pairs, and can be added to an entity at the same time.

    // If both parts of a pair are components, the pair assumes the type of
    // the first element:
    let e3 = ecs_new(ecs)
    ecs_set_pair(ecs, e3, Expires(timeout = 0.5lf), ecs_id(ecs, type<Position>))
    let e = ecs_get_pair(ecs, e3, type<Expires>, ecs_id(ecs, type<Position>))
    print("expires: {e.timeout:.1f}\n")

    // You can prevent a pair from assuming the type of a component by adding
    // the Tag property to a relationship:
    ecs_add_id(ecs, MustHave, EcsPairIsTag)

    // Even though Position is a component, <MustHave, Position> contains no
    // data because MustHave has the Tag property.
    ecs_new_w_pair(ecs, MustHave, ecs_id(ecs, type<Position>))

    // ecs_get_typeid can be used to find the component type for a pair:
    let requires_id = ecs_id(ecs, type<Requires>)
    let expires_id = ecs_id(ecs, type<Expires>)
    let position_id = ecs_id(ecs, type<Position>)
    print("{ecs_get_path(ecs, ecs_get_typeid(ecs, ecs_pair(requires_id, Gigawatts)))}\n")
    print("{ecs_get_path(ecs, ecs_get_typeid(ecs, ecs_pair(Gigawatts, requires_id)))}\n")
    print("{ecs_get_path(ecs, ecs_get_typeid(ecs, ecs_pair(expires_id, position_id)))}\n")
    print("{ecs_get_path(ecs, ecs_get_typeid(ecs, ecs_pair(MustHave, position_id)))}\n")

    // When querying for a relationship, provide both parts of the pair:
    var qdesc : ecs_query_desc_t
    qdesc.terms[0].id = ecs_pair(requires_id, Gigawatts)
    var q = ecs_query_init(ecs, unsafe(addr(qdesc)))

    // When iterating, always use the pair type:
    ecs_query_each(ecs, q) $(it) {
        ecs_field_view(it, type<Requires>, 0) $(var rf) {
            for (i in range(it.count)) {
                print("requires {rf[i].amount:.2f} gigawatts\n")
            }
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  requires: 1.21
//  requires: 1.21
//  expires: 0.5
//  Requires
//  Requires
//  Expires
//  #0
//  requires 1.21 gigawatts
