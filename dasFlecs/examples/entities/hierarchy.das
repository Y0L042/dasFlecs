options gen2
require flecs/flecs_boost

// Port of flecs examples/c/entities/hierarchy

struct Position {
    x : double
    y : double
}

def iterate_tree(ecs : ecs_world_t?; e : ecs_entity_t; p_parent : Position) {
    // Print hierarchical name of entity & the entity type
    let path_str = ecs_get_path(ecs, e)
    let type_str = ecs_take(ecs_type_str(ecs, ecs_get_type(ecs, e)))
    print("{path_str} [{type_str}]\n")

    // Get entity position
    let ptr = ecs_get(ecs, e, type<Position>)

    // Calculate actual position
    let p_actual = Position(x = ptr.x + p_parent.x, y = ptr.y + p_parent.y)
    print("\{{p_actual.x:.6f}, {p_actual.y:.6f}\}\n\n")

    // Iterate children recursively
    var it = ecs_children(ecs, e)
    while (ecs_children_next(unsafe(addr(it)))) {
        for (i in range(it.count)) {
            iterate_tree(ecs, ecs_iter_entity(unsafe(addr(it)), i), p_actual)
        }
    }
}

def child(ecs : ecs_world_t?; parent : ecs_entity_t; name : string) : ecs_entity_t {
    // ecs_entity(ecs, { .parent = parent, .name = name })
    var desc : ecs_entity_desc_t
    desc.parent = parent
    desc.name = name
    return ecs_entity_init(ecs, unsafe(addr(desc)))
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<Position>)
    let Star = ecs_tag(ecs, "Star")
    let Planet = ecs_tag(ecs, "Planet")
    let Moon = ecs_tag(ecs, "Moon")

    // Create a simple hierarchy.
    // Hierarchies use ECS relationships and the builtin flecs::ChildOf relationship to
    // create entities as children of other entities.

    let sun = ecs_entity(ecs, "Sun")
    ecs_add_id(ecs, sun, Star)
    ecs_set(ecs, sun, Position(x = 1.0lf, y = 1.0lf))

    let mercury = child(ecs, sun, "Mercury")
    ecs_add_id(ecs, mercury, Planet)
    ecs_set(ecs, mercury, Position(x = 1.0lf, y = 1.0lf))

    let venus = child(ecs, sun, "Venus")
    ecs_add_id(ecs, venus, Planet)
    ecs_set(ecs, venus, Position(x = 2.0lf, y = 2.0lf))

    let earth = child(ecs, sun, "Earth")
    ecs_add_id(ecs, earth, Planet)
    ecs_set(ecs, earth, Position(x = 3.0lf, y = 3.0lf))

    let moon = child(ecs, earth, "Moon")
    ecs_add_id(ecs, moon, Moon)
    ecs_set(ecs, moon, Position(x = 0.1lf, y = 0.1lf))

    // Is the Moon a child of Earth?
    print("Child of Earth? {ecs_has_pair(ecs, moon, EcsChildOf, earth) ? 1 : 0}\n\n")

    // Lookup moon by name
    let e = ecs_lookup(ecs, "Sun.Earth.Moon")
    print("Moon found: {ecs_get_path(ecs, e)}\n\n")

    // Do a depth-first walk of the tree
    iterate_tree(ecs, sun, Position(x = 0.0lf, y = 0.0lf))

    flecs_fini(ecs)
}

// Output:
//  Child of Earth? 1
//
//  Moon found: Sun.Earth.Moon
//
//  Sun [Position, Star, (Identifier,Name)]
//  {1.000000, 1.000000}
//
//  Sun.Mercury [Position, Planet, (Identifier,Name), (ChildOf,Sun)]
//  {2.000000, 2.000000}
//
//  Sun.Venus [Position, Planet, (Identifier,Name), (ChildOf,Sun)]
//  {3.000000, 3.000000}
//
//  Sun.Earth [Position, Planet, (Identifier,Name), (ChildOf,Sun)]
//  {4.000000, 4.000000}
//
//  Sun.Earth.Moon [Position, Moon, (Identifier,Name), (ChildOf,Sun.Earth)]
//  {4.100000, 4.100000}
