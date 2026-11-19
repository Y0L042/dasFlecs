options gen2
require flecs/flecs_boost

// Components are plain das structs.
struct Position {
    x : float
    y : float
}

struct Velocity {
    x : float
    y : float
}

[export]
def main() {
    var world = FlecsWorld()

    // entities with components; components register on first use
    for (i in range(3)) {
        world.entity("mover{i}").set(Position(x = float(i), y = 0.0)).set(Velocity(x = 1.0, y = float(i + 1)))
    }
    let still = world.entity("still").set(Position(x = 10.0, y = 10.0))   // no Velocity: the system skips it

    // system: runs once per frame in the OnUpdate phase. The block's typed arguments are the
    // query (Position read-write, Velocity read-only); the body runs once per entity.
    ecs_system(world, "Move", EcsOnUpdate) $(var p : Position; v : Velocity) {
        p.x += v.x
        p.y += v.y
    }

    for (frame in range(3)) {
        world.progress()
    }

    // read back with a query
    ecs_query(world) $(e : FlecsEntity; p : Position) {
        print("{e.name()}: ({p.x}, {p.y})\n")
    }

    let pos = still.get(type<Position>)
    print("still has Velocity: {still.has(type<Velocity>)}, position ({pos.x}, {pos.y})\n")
    world.fini()
}
