options gen2
require flecs/flecs_boost

// Port of flecs examples/c/systems/basics

struct Position {
    x : double
    y : double
}

struct Velocity {
    x : double
    y : double
}

def Move(it : ecs_iter_t const?) {
    ecs_field_view(it, type<Position>, 0) $(var p) {
        ecs_field_view(it, type<Velocity>, 1) $(var v) {
            for (i in range(it.count)) {
                p[i].x += v[i].x
                p[i].y += v[i].y
                print("{ecs_get_name(it.stage, ecs_iter_entity(it, i))}: \{{p[i].x:.6f}, {p[i].y:.6f}\}\n")
            }
        }
    }
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)
    ecs_id(ecs, type<Velocity>)

    // Create a system for Position, Velocity.
    var desc : ecs_system_desc_t
    // Systems are entities, and by initializing the .entity field we can
    // set some additional properties for the system like a name. While this
    // is not mandatory, it makes a system easier to find in tools like the
    // explorer (https://www.flecs.dev/explorer/).
    desc.entity = ecs_entity(ecs, "Move")
    desc.query.terms[0].id = ecs_id(ecs, type<Position>)
    desc.query.terms[1].id = ecs_id(ecs, type<Velocity>)
    desc.query.terms[1].inout = int16(ecs_inout_kind_t.EcsIn)
    let move = ecs_system_init(ecs, desc) @(it : ecs_iter_t const?) {
        Move(it)
    }

    // The flecs_boost shortcut does the same from a query expression:
    //   ecs_system(ecs, "Move", 0ul, "Position, [in] Velocity") @(it) { ... }

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

    // Run the system
    ecs_run(ecs, move, 0.0, null)

    flecs_fini(ecs)
}

// Output:
//  e1: {11.000000, 22.000000}
//  e2: {13.000000, 24.000000}
