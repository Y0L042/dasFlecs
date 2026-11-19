options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/basics

struct Position {
    x : double
    y : double
}

struct Velocity {
    x : double
    y : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)
    ecs_id(ecs, type<Velocity>)

    // Create a cached query for Position, Velocity. Cached queries are the
    // fastest way to iterate entities as they cache results.
    var desc : ecs_query_desc_t
    desc.terms[0].id = ecs_id(ecs, type<Position>)
    desc.terms[1].id = ecs_id(ecs, type<Velocity>)
    desc.terms[1].inout = int16(ecs_inout_kind_t.EcsIn)
    // QueryCache Auto automatically caches all terms that can be cached.
    desc.cache_kind = ecs_query_cache_kind_t.EcsQueryCacheAuto
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // Create a few test entities for a Position, Velocity query
    let e1 = ecs_entity(ecs, "e1")
    ecs_set(ecs, e1, Position(x = 10.0lf, y = 20.0lf))
    ecs_set(ecs, e1, Velocity(x = 1.0lf, y = 2.0lf))

    let e2 = ecs_entity(ecs, "e2")
    ecs_set(ecs, e2, Position(x = 10.0lf, y = 20.0lf))
    ecs_set(ecs, e2, Velocity(x = 3.0lf, y = 4.0lf))

    // This entity will not match as it does not have Position, Velocity
    let e3 = ecs_entity(ecs, "e3")
    ecs_set(ecs, e3, Position(x = 10.0lf, y = 20.0lf))

    // Iterate entities matching the query
    var it = ecs_query_iter(ecs, q)

    // Outer loop, iterates archetypes
    while (ecs_query_next(unsafe(addr(it)))) {
        let pit = unsafe(addr(it))
        ecs_field_view(pit, type<Position>, 0) $(var p) {
            ecs_field_view(pit, type<Velocity>, 1) $(var v) {
                // Inner loop, iterates entities in archetype
                for (i in range(it.count)) {
                    p[i].x += v[i].x
                    p[i].y += v[i].y
                    print("{ecs_get_name(ecs, ecs_iter_entity(pit, i))}: \{{p[i].x:.6f}, {p[i].y:.6f}\}\n")
                }
            }
        }
    }

    // Cleanup query resources.
    ecs_query_fini(q)

    flecs_fini(ecs)
}

// Output:
//  e1: {11.000000, 22.000000}
//  e2: {13.000000, 24.000000}
