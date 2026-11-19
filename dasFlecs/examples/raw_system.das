options gen2
require flecs

// A system and an observer with das lambda callbacks, using only the raw API
// (the generated functions plus the callback bridge). flecs_boost wraps all of this.

struct Position {
    x : float
    y : float
}

struct Velocity {
    x : float
    y : float
}

// das lambdas capture locals by copy, so counters the callbacks update live at module level
var set_count = 0
var calls = 0
var moved = 0

def register_component(world : ecs_world_t?; name : string; size, alignment : int) : ecs_entity_t {
    var edesc : ecs_entity_desc_t
    edesc.name = name
    edesc.use_low_id = true
    var cdesc : ecs_component_desc_t
    cdesc.entity = ecs_entity_init(world, unsafe(addr(edesc)))
    cdesc._type.size = size
    cdesc._type.alignment = alignment
    return ecs_component_init(world, unsafe(addr(cdesc)))
}

[export]
def main() {
    var world = ecs_init()
    let pos_id = register_component(world, "Position", typeinfo sizeof(type<Position>), typeinfo alignof(type<Position>))
    let vel_id = register_component(world, "Velocity", typeinfo sizeof(type<Velocity>), typeinfo alignof(type<Velocity>))
    print("Position = {pos_id}, Velocity = {vel_id}\n")

    // observer: fires on every Position set
    var odesc : ecs_observer_desc_t
    odesc.query.terms[0].id = pos_id
    odesc.events[0] = EcsOnSet
    let obs = ecs_observer_init(world, odesc) @(it : ecs_iter_t const?) {
        set_count += it.count
    }
    print("observer = {obs}\n")

    for (i in range(3)) {
        let e = ecs_new(world)
        var p = Position(x = float(i), y = 0.0)
        var v = Velocity(x = 1.0, y = 2.0)
        unsafe {
            ecs_set_id(world, e, pos_id, uint64(typeinfo sizeof(p)), addr(p))
            ecs_set_id(world, e, vel_id, uint64(typeinfo sizeof(v)), addr(v))
        }
    }
    print("OnSet observer fired for {set_count} entities\n")

    // system: Position += Velocity, once per frame in OnUpdate
    var sdesc : ecs_system_desc_t
    sdesc.query.expr = "Position, [in] Velocity"
    sdesc.phase = EcsOnUpdate
    let sys = ecs_system_init(world, sdesc) @(it : ecs_iter_t const?) {
        calls ++
        unsafe {
            var p = reinterpret<Position?>(ecs_field_w_size(it, uint64(typeinfo sizeof(type<Position>)), int8(0)))
            var v = reinterpret<Velocity?>(ecs_field_w_size(it, uint64(typeinfo sizeof(type<Velocity>)), int8(1)))
            for (i in range(it.count)) {
                p[i].x += v[i].x
                p[i].y += v[i].y
                moved ++
            }
        }
    }
    print("system = {sys}, callbacks alive = {flecs_callback_count()}\n")

    for (frame in range(3)) {
        ecs_progress(world, 0.0)
    }
    print("system ran {calls} time(s), moved {moved} entity-frames\n")

    // read back through a query
    var qdesc : ecs_query_desc_t
    qdesc.expr = "Position"
    var q = ecs_query_init(world, unsafe(addr(qdesc)))
    var it = ecs_query_iter(world, q)
    while (ecs_query_next(unsafe(addr(it)))) {
        unsafe {
            var p = reinterpret<Position?>(ecs_field_w_size(addr(it), uint64(typeinfo sizeof(type<Position>)), int8(0)))
            for (i in range(it.count)) {
                print("  entity {it.entities[i]}: ({p[i].x}, {p[i].y})\n")
            }
        }
    }
    ecs_query_fini(q)

    ecs_fini(world)
    print("callbacks alive after ecs_fini = {flecs_callback_count()}\n")
}
