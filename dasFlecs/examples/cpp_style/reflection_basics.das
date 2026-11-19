options gen2
require flecs/flecs_boost

// flecs examples/c/reflection/basics in the C++-style API: [ecs_component] generates the
// reflection data (x : f32, y : f32) when the component is first registered.

[ecs_component]
struct Position {
    x : float
    y : float
}

[export]
def main() {
    var world = FlecsWorld()

    // Create entity with Position as usual
    let ent = world.entity().set(Position(x = 10.0, y = 20.0))

    // Convert position component to flecs expression string
    let ptr = ent.get(type<Position>)
    let str = ecs_take(ecs_ptr_to_expr(world.c_ptr(), ecs_id(world.c_ptr(), type<Position>), ptr))
    print("{str}\n")    // {x: 10, y: 20}

    world.fini()
}

// Output:
//  {x: 10, y: 20}
