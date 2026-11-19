options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/system_ctx
//
// Applications can pass context data to a system. A common use case where this
// comes in handy is when a system needs to iterate more than one query. The
// following example shows how to pass a custom query into a system for a simple
// collision detection example.

struct Position {
    x : double
    y : double
}

struct Radius {
    value : double
}

def sqr(value : double) : double {
    return value * value
}

def distance_sqr(p1, p2 : Position) : double {
    return sqr(p2.x - p1.x) + sqr(p2.y - p1.y)
}

// rand() as implemented by the MSVC C runtime (seed 1), so the entities get the same
// positions as in the C example
var rand_state = 1u
def c_rand() : int {
    rand_state = rand_state * 214013u + 2531011u
    return int((rand_state >> 16u) & 0x7fffu)
}

def Collide(it : ecs_iter_t const?) {
    let q_collide = unsafe(reinterpret<ecs_query_t?>(it.ctx))    // Get query from system context

    ecs_field_view(it, type<Position>, 0) $(var p1) {
        ecs_field_view(it, type<Radius>, 1) $(var r1) {
            for (i in range(it.count)) {
                let e1 = ecs_iter_entity(it, i)

                // For each matching entity, iterate the query
                ecs_query_each(it.stage, q_collide) $(qit) {
                    ecs_field_view(qit, type<Position>, 0) $(var p2) {
                        ecs_field_view(qit, type<Radius>, 1) $(var r2) {
                            for (j in range(qit.count)) {
                                let e2 = ecs_iter_entity(qit, j)
                                if (e1 == e2) {
                                    // don't collide with self
                                    continue
                                }

                                if (e2 > e1) {
                                    // Simple trick to prevent collisions from being detected
                                    // twice with the entities reversed.
                                    continue
                                }

                                // Check for collision
                                let d_sqr = distance_sqr(p1[i], p2[j])
                                let r_sqr = sqr(r1[i].value + r2[j].value)
                                if (r_sqr > d_sqr) {
                                    print("{int(e1)} and {int(e2)} collided!\n")
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)
    ecs_id(ecs, type<Radius>)

    // Create a query for Position that we can use inside the collide system to
    // check each entity with each other entity.
    var qdesc : ecs_query_desc_t
    qdesc.terms[0].id = ecs_id(ecs, type<Position>)
    qdesc.terms[0].inout = int16(ecs_inout_kind_t.EcsIn)
    qdesc.terms[1].id = ecs_id(ecs, type<Radius>)
    qdesc.terms[1].inout = int16(ecs_inout_kind_t.EcsIn)
    var q_position = ecs_query_init(ecs, unsafe(addr(qdesc)))

    // Create collide system that passes query as context
    var sdesc : ecs_system_desc_t
    sdesc.query.terms[0].id = ecs_id(ecs, type<Position>)
    sdesc.query.terms[0].inout = int16(ecs_inout_kind_t.EcsIn)
    sdesc.query.terms[1].id = ecs_id(ecs, type<Radius>)
    sdesc.query.terms[1].inout = int16(ecs_inout_kind_t.EcsIn)
    sdesc.ctx = unsafe(reinterpret<void?>(q_position))
    let collide = ecs_system_init(ecs, sdesc) @(it : ecs_iter_t const?) {
        Collide(it)
    }

    // Create a few test entities
    for (i in range(10)) {
        let e = ecs_new(ecs)
        let x = double(c_rand() % 100)
        let y = double(c_rand() % 100)
        ecs_set(ecs, e, Position(x = x, y = y))
        ecs_set(ecs, e, Radius(value = double(c_rand() % 10 + 1)))
    }

    // Run the system
    ecs_run(ecs, collide, 0.0, null)

    ecs_query_fini(q_position)
    flecs_fini(ecs)
}

// Output:
//
