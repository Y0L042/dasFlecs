options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/sorting
//
// Queries can be sorted by a component value with an order_by callback. Sorting is
// cached: when a matched table changes, only the changed tables are sorted again.

struct Position {
    x : double
    y : double
}

def compare_position(e1 : ecs_entity_t; ptr1 : void const?; e2 : ecs_entity_t; ptr2 : void const?) : int {
    let p1 = unsafe(reinterpret<Position const?>(ptr1))
    let p2 = unsafe(reinterpret<Position const?>(ptr2))
    return (p1.x > p2.x ? 1 : 0) - (p1.x < p2.x ? 1 : 0)
}

def print_position(it : ecs_iter_t const?) {
    ecs_field_view(it, type<Position>, 0) $(var p) {
        for (pi in p) {
            print("\{{pi.x:.1f}, {pi.y:.1f}\}\n")
        }
    }
}

def print_query(ecs : ecs_world_t?; q : ecs_query_t?) {
    ecs_query_each(ecs, q) $(it) {
        print_position(it)
    }
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)

    // Create entities, set Position in random order
    let e = ecs_insert(ecs, Position(x = 1.0lf, y = 0.0lf))
    ecs_insert(ecs, Position(x = 6.0lf, y = 0.0lf))
    ecs_insert(ecs, Position(x = 2.0lf, y = 0.0lf))
    ecs_insert(ecs, Position(x = 5.0lf, y = 0.0lf))
    ecs_insert(ecs, Position(x = 4.0lf, y = 0.0lf))

    // Create a sorted system
    var sdesc : ecs_system_desc_t
    sdesc.query.terms[0].id = ecs_id(ecs, type<Position>)
    ecs_query_desc_order_by(sdesc.query) @(e1 : ecs_entity_t; p1 : void const?; e2 : ecs_entity_t; p2 : void const?) : int {
        return compare_position(e1, p1, e2, p2)
    }
    sdesc.query.order_by = ecs_id(ecs, type<Position>)
    let sys = ecs_system_init(ecs, sdesc) @(it : ecs_iter_t const?) {
        print_position(it)
    }

    // Create a sorted query
    var qdesc : ecs_query_desc_t
    qdesc.terms[0].id = ecs_id(ecs, type<Position>)
    ecs_query_desc_order_by(qdesc) @(e1 : ecs_entity_t; p1 : void const?; e2 : ecs_entity_t; p2 : void const?) : int {
        return compare_position(e1, p1, e2, p2)
    }
    qdesc.order_by = ecs_id(ecs, type<Position>)
    var q = ecs_query_init(ecs, unsafe(addr(qdesc)))

    // Iterate query, print values of Position
    print("-- First iteration\n")
    print_query(ecs, q)

    // Change the value of one entity, invalidating the order
    ecs_set(ecs, e, Position(x = 7.0lf, y = 0.0lf))

    // Iterate query again, printed values are still ordered
    print("\n-- Second iteration\n")
    print_query(ecs, q)

    // Create new entity to show that data is also sorted for system
    ecs_insert(ecs, Position(x = 3.0lf, y = 0.0lf))

    // Run system, output will be sorted
    print("\n-- System iteration\n")
    ecs_run(ecs, sys, 0.0, null)

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  -- First iteration
//  {1.0, 0.0}
//  {2.0, 0.0}
//  {4.0, 0.0}
//  {5.0, 0.0}
//  {6.0, 0.0}
//
//  -- Second iteration
//  {2.0, 0.0}
//  {4.0, 0.0}
//  {5.0, 0.0}
//  {6.0, 0.0}
//  {7.0, 0.0}
//
//  -- System iteration
//  {2.0, 0.0}
//  {3.0, 0.0}
//  {4.0, 0.0}
//  {5.0, 0.0}
//  {6.0, 0.0}
//  {7.0, 0.0}
