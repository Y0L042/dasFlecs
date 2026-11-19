options gen2
require flecs/flecs_boost

// Port of flecs examples/c/entities/parent_hierarchy
//
// ChildOf hierarchies are optimized for scenarios with few parents that have
// lots of children. Parent hierarchies are optimized for scenarios with lots of
// parents that have a small number of children. See the documentation for more
// information:
//   https://www.flecs.dev/flecs/md_docs_2HierarchiesManual.html#hierarchy-storage
//
// This example is the same as the hierarchy example, but instead of using
// ChildOf hierarchies it uses Parent hierarchies.

struct Position {
    x : double
    y : double
}

def iterate_tree(world : ecs_world_t?; e : ecs_entity_t; p_parent : Position) {
    // Print hierarchical name of entity & the entity type
    let path_str = ecs_get_path(world, e)
    let type_str = ecs_take(ecs_type_str(world, ecs_get_type(world, e)))
    print("{path_str} [{type_str}]\n")

    // Get entity position
    let ptr = ecs_get(world, e, type<Position>)

    // Calculate actual position
    let p_actual = Position(x = ptr.x + p_parent.x, y = ptr.y + p_parent.y)
    print("\{{p_actual.x:.6f}, {p_actual.y:.6f}\}\n\n")

    // Iterate children recursively
    var it = ecs_children(world, e)
    while (ecs_children_next(unsafe(addr(it)))) {
        for (i in range(it.count)) {
            iterate_tree(world, ecs_iter_entity(unsafe(addr(it)), i), p_actual)
        }
    }
}

[export]
def main() {
    var world = ecs_init()

    ecs_id(world, type<Position>)
    let Star = ecs_tag(world, "Star")
    let Planet = ecs_tag(world, "Planet")
    let Moon = ecs_tag(world, "Moon")

    // Create a simple hierarchy.
    // Use the ecs_new_w_parent function to create entities that use Parent
    // hierarchies.
    //
    // Entities can be reparented afterwards by setting the Parent component:
    //   ecs_set(world, moon, EcsParent(value = mars))

    let sun = ecs_entity(world, "Sun")
    ecs_add_id(world, sun, Star)
    ecs_set(world, sun, Position(x = 1.0lf, y = 1.0lf))

    let mercury = ecs_new_w_parent(world, sun, "Mercury")
    ecs_add_id(world, mercury, Planet)
    ecs_set(world, mercury, Position(x = 1.0lf, y = 1.0lf))

    let venus = ecs_new_w_parent(world, sun, "Venus")
    ecs_add_id(world, venus, Planet)
    ecs_set(world, venus, Position(x = 2.0lf, y = 2.0lf))

    let earth = ecs_new_w_parent(world, sun, "Earth")
    ecs_add_id(world, earth, Planet)
    ecs_set(world, earth, Position(x = 3.0lf, y = 3.0lf))

    let moon = ecs_new_w_parent(world, earth, "Moon")
    ecs_add_id(world, moon, Moon)
    ecs_set(world, moon, Position(x = 0.1lf, y = 0.1lf))

    // Is the Moon a child of Earth?
    print("Child of Earth? {ecs_has_pair(world, moon, EcsChildOf, earth) ? 1 : 0}\n\n")

    // Lookup moon by name
    let e = ecs_lookup(world, "Sun.Earth.Moon")
    print("Moon found: {ecs_get_path(world, e)}\n\n")

    // Do a depth-first walk of the tree
    iterate_tree(world, sun, Position(x = 0.0lf, y = 0.0lf))

    flecs_fini(world)
}

// Output:
//  Child of Earth? 1
//
//  Moon found: Sun.Earth.Moon
//
//  Sun [Position, Star, (Identifier,Name)]
//  {1.000000, 1.000000}
//
//  Sun.Mercury [Parent, Position, Planet, (Identifier,Name), (ParentDepth,@1)]
//  {2.000000, 2.000000}
//
//  Sun.Venus [Parent, Position, Planet, (Identifier,Name), (ParentDepth,@1)]
//  {3.000000, 3.000000}
//
//  Sun.Earth [Parent, Position, Planet, (Identifier,Name), (ParentDepth,@1)]
//  {4.000000, 4.000000}
//
//  Sun.Earth.Moon [Parent, Position, Moon, (Identifier,Name), (ParentDepth,@2)]
//  {4.100000, 4.100000}
