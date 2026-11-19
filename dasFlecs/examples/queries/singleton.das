options gen2
require flecs/flecs_boost

// Port of flecs examples/c/queries/singleton
//
// This example shows how to use singleton components in queries. A singleton is a
// component that is set on its own component entity. Marking a component with the
// Singleton trait makes queries match it from the component entity.

struct Gravity {
    value : double
}

struct Velocity {
    x : double
    y : double
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Velocity>)
    ecs_id(ecs, type<Gravity>)

    // Mark Gravity as singleton
    ecs_add_id(ecs, ecs_id(ecs, type<Gravity>), EcsSingleton)

    // Set singleton
    ecs_singleton_set(ecs, Gravity(value = 9.81lf))

    // Set Velocity
    let e1 = ecs_entity(ecs, "e1")
    let e2 = ecs_entity(ecs, "e2")
    let e3 = ecs_entity(ecs, "e3")

    ecs_set(ecs, e1, Velocity(x = 0.0lf, y = 0.0lf))
    ecs_set(ecs, e2, Velocity(x = 0.0lf, y = 1.0lf))
    ecs_set(ecs, e3, Velocity(x = 0.0lf, y = 2.0lf))

    // Create query that matches Gravity as singleton
    var desc : ecs_query_desc_t
    desc.terms[0].id = ecs_id(ecs, type<Velocity>)
    desc.terms[1].id = ecs_id(ecs, type<Gravity>)
    var q = ecs_query_init(ecs, unsafe(addr(desc)))

    // In a query string expression you can use the $ shortcut for singletons:
    //   Velocity, Gravity($)

    ecs_query_each(ecs, q) $(it) {
        ecs_field_view(it, type<Velocity>, 0) $(var v) {
            ecs_field_view(it, type<Gravity>, 1) $(var g) {
                for (i in range(it.count)) {
                    // Gravity is a singleton: one value for all entities
                    v[i].y += g[0].value
                    print("{ecs_get_name(ecs, ecs_iter_entity(it, i))} velocity is \{{v[i].x:.6f}, {v[i].y:.6f}\}\n")
                }
            }
        }
    }

    ecs_query_fini(q)
    flecs_fini(ecs)
}

// Output:
//  e1 velocity is {0.000000, 9.810000}
//  e2 velocity is {0.000000, 10.810000}
//  e3 velocity is {0.000000, 11.810000}
