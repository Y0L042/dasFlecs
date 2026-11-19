options gen2
require flecs/flecs_boost

// Port of flecs examples/c/script/script_managed
//
// This example shows how to create a managed script. A managed script remains
// in memory after it is ran, and makes it possible to inspect and modify the
// script. Managed scripts can be inspected and modified from the explorer.
//
// Updating a script will delete any entities or components that are no longer
// described by the script.

def print_planets(world : ecs_world_t?) {
    let sun = ecs_lookup(world, "Sun")
    var it = ecs_children(world, sun)
    while (ecs_children_next(unsafe(addr(it)))) {
        for (i in range(it.count)) {
            print(" - {ecs_get_name(world, ecs_iter_entity(unsafe(addr(it)), i))}\n")
        }
    }
}

[export]
def main() {
    var world = ecs_init()

    var desc : ecs_script_desc_t
    desc.code = "Sun \{
  Mercury \{\}
  Venus \{\}
  Earth \{\}
  Mars \{\}
  Jupiter \{\}
  Saturn \{\}
  Neptune \{\}
  Uranus \{\}
  Pluto \{\}
\}
"
    let script = ecs_script_init(world, unsafe(addr(desc)))

    if (script == 0ul) {
        print("script failed to run\n")
    }

    print("Before updating script:\n")
    print_planets(world)

    // The updated script drops Pluto {} - not a planet :(
    ecs_script_update(world, script, 0ul, "Sun \{
  Mercury \{\}
  Venus \{\}
  Earth \{\}
  Mars \{\}
  Jupiter \{\}
  Saturn \{\}
  Neptune \{\}
  Uranus \{\}
\}
")

    print("\nAfter updating script:\n")
    print_planets(world)

    flecs_fini(world)
}

// Output:
//  Before updating script:
//   - Mercury
//   - Venus
//   - Earth
//   - Mars
//   - Jupiter
//   - Saturn
//   - Neptune
//   - Uranus
//   - Pluto
//
//  After updating script:
//   - Mercury
//   - Venus
//   - Earth
//   - Mars
//   - Jupiter
//   - Saturn
//   - Neptune
//   - Uranus
