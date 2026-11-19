options gen2
require flecs/flecs_boost

// Port of flecs examples/c/script/script_run
//
// This example shows how to run a script once. To see how to parse a script and
// run it multiple times, see the script_parse_eval example.

// (braces are escaped in das string literals: \{ \})
let script = "Sun \{
  Mercury \{\}
  Venus \{\}
  Earth \{\}
  Mars \{\}
  Jupiter \{\}
  Saturn \{\}
  Neptune \{\}
  Uranus \{\}
\}
"

[export]
def main() {
    var world = ecs_init()

    if (ecs_script_run(world, "My script", script, null) != 0) {
        print("script failed to run\n")
    }

    let sun = ecs_lookup(world, "Sun")
    var it = ecs_children(world, sun)
    while (ecs_children_next(unsafe(addr(it)))) {
        for (i in range(it.count)) {
            print(" - {ecs_get_name(world, ecs_iter_entity(unsafe(addr(it)), i))}\n")
        }
    }

    flecs_fini(world)
}

// Output:
//   - Mercury
//   - Venus
//   - Earth
//   - Mars
//   - Jupiter
//   - Saturn
//   - Neptune
//   - Uranus
