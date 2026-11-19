# dasFlecs

[flecs](https://github.com/SanderMertens/flecs) 4.2.0 ECS bindings for [daslang](https://github.com/GaijinEntertainment/daScript),
generated from the flecs C headers with daslang's `dasClangBind`.

```das
options gen2
require flecs/flecs_boost

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
    let e = world.entity("Bob").set(Position(x = 0.0, y = 0.0)).set(Velocity(x = 1.0, y = 2.0))

    // the block's typed arguments are the query: Position (read-write), Velocity (read-only)
    ecs_system(world, "Move", EcsOnUpdate) $(var p : Position; v : Velocity) {
        p.x += v.x
        p.y += v.y
    }
    world.progress()
    print("{e.get(type<Position>).y}\n")    // 2
    world.fini()
}
```

The same program can be written against the plain C API (`ecs_init`, `ecs_system_init`,
`ecs_field`, ...). The 88 ports of the flecs C examples in `dasFlecs/examples/<category>/`
use that API.

## What you get

**`require flecs`: the generated C API.** About 540 flecs functions with their C names and signatures
(`ecs_init`, `ecs_new`, `ecs_set_id`, `ecs_query_init`, `ecs_query_next`, `ecs_progress`, ...). It also
includes the structs (`ecs_iter_t`, `ecs_query_desc_t`, `ecs_system_desc_t`, ...), the enums and the
integer constants. A few extra pieces are generated as well:

- **Built-in ids** are das constants: `EcsOnUpdate`, `EcsChildOf`, `EcsWildcard`, `ECS_PAIR`.
  The `ecs_id(T)` ids of built-in components are named `ecs_id_EcsComponent`, `ecs_id_ecs_f32_t`, and so on.
- **Ids assigned when an addon is imported** are functions that return the current value:
  `EcsMeters()`, `ecs_id_EcsWorldStats()`.
- **Addon imports** are written `ecs_import_FlecsUnits(world)`; it does the same as `ECS_IMPORT(world, FlecsUnits)`.
  `ecs_init` does not import units, stats, metrics or alerts.
- **Flag macros** are constants: `EcsSelf`, `EcsUp`, `EcsTraverseFlags`, `EcsQueryMatchThis`, ...
- **Callbacks.** `ecs_system_init(world, desc, lambda)` and `ecs_observer_init(world, desc, lambda)` take a
  das lambda in place of `desc.callback` (see "Callbacks" below).

Descriptor structs are plain das locals and start zeroed, as flecs requires. Their string fields
(`desc.name`, `query.expr`) can be assigned. Functions that take a descriptor pointer need
`unsafe(addr(desc))`.

**`require flecs/flecs_boost`: typed helpers.** This module re-exports `flecs` and adds helpers named after the C macros:

| das | flecs C |
|---|---|
| `ecs_id(world, type<Position>)` | `ECS_COMPONENT` + `ecs_id(Position)` |
| `ecs_set(world, e, Position(x = 1.0))` | `ecs_set(world, e, Position, {1})` |
| `ecs_get(world, e, type<Position>)` / `ecs_get_mut` / `ecs_modified` | `ecs_get` / `ecs_get_mut` / `ecs_modified` |
| `ecs_add` / `ecs_remove` / `ecs_has(world, e, type<T>)` | `ecs_add` / `ecs_remove` / `ecs_has` |
| `ecs_pair(EcsChildOf, parent)`, `ecs_add_pair`, `ecs_has_pair` | `ecs_pair`, `ecs_add_pair`, `ecs_has_pair` |
| `ecs_entity(world, "name")` | `ecs_entity(world, { .name = "name" })` |
| `ecs_query_expr(world, "Position, Velocity")` (or `ecs_query(world, "...")`) | `ecs_query(world, { .expr = ... })` |
| `ecs_query_each(world, q) $(it) {...}` | `ecs_query_iter` / `ecs_query_next` loop |
| `ecs_each_table(world, type<T>) $(it) {...}` (or `ecs_each`) | `ecs_each(world, T)` |
| `ecs_field_view(it, type<T>, 0) $(var arr) {...}`, `ecs_field` | `ecs_field(it, T, 0)` |
| `ecs_system_expr(world, "Name", EcsOnUpdate, "expr") @(it) {...}` (or `ecs_system`) | `ECS_SYSTEM` / `ecs_system` |
| `ecs_observer_expr(world, EcsOnSet, "expr") @(it) {...}` (or `ecs_observer`) | `ECS_OBSERVER` / `ecs_observer` |
| `ecs_children_each(world, parent) $(child)`, `ecs_children_array`, `ecs_children_count`, `ecs_children_each_recursive`, `ecs_entity_each(world, e) $(id)` | `ecs_children` / `ecs_children_next`, `ecs_get_type` |

A component is registered the first time a helper uses it, under the das type's name (`"Position"`).
**Register components with `ecs_id(world, type<T>)` before a query expression names them**, the same as
`ECS_COMPONENT` in C. Ids are cached per world, so finalize worlds with `flecs_fini(world)`: it drops the
world's cache entries and then calls `ecs_fini`.

## C++-style API

`flecs_boost` also re-exports two modules modelled on the flecs C++ API
(`include/flecs/addons/cpp`). They are thin layers over the C functions. A `FlecsWorld` holds
only a world pointer, and a `FlecsEntity` a world pointer and an id. Both styles can be used
in the same code (`world.c_ptr()`, `e.id`).

**Classes (`flecs/flecs_cpp`).** Template arguments become `type<T>` arguments:
`e.add(type<Tag>)` is C++ `e.add<Tag>()`. An argument that names an id takes an
`ecs_entity_t`, a `FlecsEntity` / `FlecsComponent` / `FlecsSystem`, or a `type<T>`. Names
that are daslang keywords get an underscore, as in C++: `with_`, `in_`, `not_`, `or_`,
`self_`, `module_`.

| das | flecs C++ |
|---|---|
| `FlecsWorld()`, `world.fini()`, `world.progress(dt)`, `world.set(T(...))`, `world.get(type<T>)`, `world.count(type<T>)`, `world.each(type<T>) $(e)`, `world.scope(parent) $() {...}`, `world.lookup("a.b")` | `flecs::world` |
| `world.entity("name").set(T(...)).add(type<Tag>).add(rel, tgt).child_of(p)`, `e.get(type<T>)`, `e.get_mut`, `e.ensure`, `e.has`, `e.owns`, `e.remove`, `e.is_a(base)`, `e.parent()`, `e.target(rel)`, `e.children() $(c)`, `e.lookup("a.b")`, `e.path()`, `e.to_json()`, `e.emit(event)`, `e.destruct()` | `flecs::entity` |
| `world.component(type<T>).member(type<float>, "x").member(type<float>, "y")`, `.on_set(lambda)` | `flecs::component<T>` |
| `world.query_builder().with_(type<T>).in_().with_(rel, tgt).optional().up().cascade().without(x).or_().src(e).cached().order_by(type<T>, lambda).group_by(rel).build()` | `flecs::query_builder` |
| `q.each() $(e)`, `q.run() $(it)`, `q.count()`, `q.first()`, `q.is_true()`, `q.changed()`, `q.destruct()` | `flecs::query` |
| `world.system("Name").kind(EcsOnUpdate).interval(1.0).with_(...).iter(lambda)` / `.run(lambda)`; `sys.run()` | `flecs::system_builder`, `flecs::system` |
| `world.observer("Name").event(EcsOnSet).yield_existing().with_(...).iter(lambda)` | `flecs::observer_builder` |

A system builder runs in `EcsOnUpdate` unless `kind()` sets another phase. With `kind(0ul)`,
the system runs only when you call `sys.run()`. flecs 4.2 has no defer API, so there is no
`defer()`.

**Typed-block macros (`flecs/flecs_macros`).** The block's typed arguments become the query,
and each argument is bound to the matched value. You don't write field indices, casts or
nested `ecs_field_view` blocks.

```das
ecs_query(world) $(e : FlecsEntity; var p : Position; v : Velocity; parent : Position?) {
    p.x += v.x      // runs once per matched entity; `return` moves to the next one
}
let found = ecs_find_query(world) $(p : Position) { return p.x > 10.0; }
ecs_each(q) $(e : FlecsEntity; p : Position) { ... }         // a query built elsewhere
ecs_system(world.system("Move").kind(EcsOnUpdate)) $(it : ecs_iter_t const?; var p : Position) { ... }
ecs_observer(world, EcsOnSet) $(e : FlecsEntity; p : Position) { ... }
ecs_query(world) $ [CACHED, REQUIRE(Enemy), REQUIRE_NOT(Frozen), CASCADE(parent)] (...) { ... }
```

- **Arguments:**
  - `p : T` is a read-only term.
  - `var p : T` is a read-write term.
  - `p : T?` is an optional term; `p` is null when the entity doesn't have `T`.
  - `e : FlecsEntity` or `e : ecs_entity_t` binds the entity. It adds no term.
  - `it : ecs_iter_t const?` binds the iterator. It adds no term.
- **Block annotations:** `[CACHED]`, `[REQUIRE(T, ...)]`, `[REQUIRE_NOT(T, ...)]`, and the
  ChildOf traversals `[UP(a)]`, `[SELF_UP(a)]`, `[CASCADE(a)]`, `[CASCADE_DESC(a)]`.
- **Extra terms:** for terms that a block argument can't express, pass a builder:
  `ecs_query(world, world.query_builder().with_(Likes, alice)) $(p : Position) {...}`.
  The builder's terms come first.
- **Query cache:** `ecs_query` and `ecs_find_query` build their query once for each call
  site and world. A `"key"` string argument shares one query between call sites.
  `flecs_fini` and `world.fini()` delete the cached queries.
- **System and observer bodies** run later, as lambdas, so the locals they use are copied.
- **The older forms still compile:** the macros forward `ecs_query(world, "expr")`,
  `ecs_each(world, type<T>) $(it)`, `ecs_system(world, name, phase, "expr") @(it)` and
  `ecs_observer(world, event, "expr") @(it)` to `ecs_query_expr`, `ecs_each_table`,
  `ecs_system_expr` and `ecs_observer_expr`.

**`[ecs_component]` reflection.** When a struct has `[ecs_component]`, flecs gets its members
the first time the component is registered. The result is the same as declaring each member
with `ecs_struct_init`. JSON, `ecs_ptr_to_expr`, scripts and the explorer then show the values.

```das
[ecs_component]
struct Unit {
    name : string
    faction : Faction       // enum: registered with its constants
    stats : Stats           // nested struct: must be [ecs_component] too
    pos : float3            // vector and fixed-array fields become arrays
    ammo : int[3]
}
```

Supported member types:
- `bool`, the integer types, `float`, `double` and `string`
- enums and nested `[ecs_component]` structs
- `float2/3/4`, `int2/3/4`, and fixed arrays of the supported types

Pointers, dynamic arrays, tables, lambdas and tuples cause a compile error. A `uint64` field
becomes `u64`, because daslang doesn't keep the `ecs_entity_t` alias.

`dasFlecs/examples/cpp_style/` has six C examples rewritten in the C++-style API. They print
the same output as the C programs.

## Callbacks

Systems and observers run das lambdas through a small hand-written bridge (`src/dasFlecs.main.cpp`):

- **Context lifetime.** The lambda belongs to the das context that created it, and that context must outlive the world.
- **Threads.** Callbacks run on the thread that calls `ecs_progress`, `ecs_run` or the operation that triggered them.
  The bridge forces systems to be single-threaded, so do not run das callbacks from `ecs_set_threads` worker threads.
- **Captures.** das lambdas capture locals **by copy**. Keep state that callbacks update at module level or behind a pointer.
- **Cleanup.** flecs frees each callback holder when its system or observer is deleted, or when the world is finalized.
  `flecs_callback_count()` reports how many holders are still alive.

## Not bound

- **Variadic or `va_list` functions:** the logging functions such as `ecs_log_` and `ecs_print_`.
- **C callbacks that the bridge does not wrap:** for example `ecs_set_ctx` free callbacks,
  `ecs_atfini` and `ecs_run_post_frame`.
  - The bridge wraps these: system and observer callbacks and `run`; type hooks
    (`ecs_hooks_*`); query `order_by` / `group_by` and group create and delete; opaque
    serializers (`ecs_opaque_*`); script functions and methods, sync and async; script event
    hooks; and `ecs_import`.
- **C macros:** `ECS_COMPONENT`, `ecs_set` and the others are replaced by `flecs_boost`.
- **Struct fields of anonymous struct or union type, and bitfields.**

## Building

Requirements: a daslang install with dasClangBind (default `C:/Programs/daslang`), Visual Studio 2026,
and, for `gen` only, libclang resource headers (default `C:/Programs/libClang`).

```
manage.sh build        # or manage.bat build: fetches flecs v4.2.0, builds _build/Release/dasModuleFlecsGen.shared_module
manage.sh test         # dastest over tests/
manage.sh run [file]   # default dasFlecs/examples/hello_flecs.das
```

Scripts load the module with `daslang -load_module <this folder> script.das`. The `.das_module`
descriptor registers `flecs` and `flecs/flecs_boost`, plus the modules that `flecs_boost`
re-exports: `flecs/flecs_helpers`, `flecs/flecs_cpp` and `flecs/flecs_macros`.

Environment variables:

| Variable | Default | Purpose |
|---|---|---|
| `DASLANG_DIR` | `C:/Programs/daslang` | daslang to build against and to run with |
| `LIBCLANG_DIR` | `C:/Programs/libClang` | clang resource headers, used by `gen` |
| `FLECS_DIR` | (empty: fetch tag `v4.2.0`) | use a local flecs checkout instead |
| `CMAKE_GENERATOR_NAME` | `Visual Studio 18 2026` | CMake generator |

## Regenerating

Almost everything in `dasFlecs/src` is generated by `dasFlecs/bind/bind_flecs.das`. Only two files are
written by hand:

- `cb_dasFlecs.h`: the header libclang parses, plus the C++ glue it hides from libclang.
- `dasFlecs.main.cpp`: the callback bridge, `initMain` and `aotRequire`.

To update flecs:

1. Change `GIT_TAG` in `dasFlecs/CMakeLists.txt`.
2. Run `manage.sh gen`, then `manage.sh build`, then `manage.sh test`.

`dasFlecs/flecs/flecs_cpp.das` is also generated. To regenerate it from
`tools/flecs_cpp.das.in`, run `python tools/gen_flecs_cpp.py`. The script does two things:
- It writes the term-builder methods (`with_`, `in_`, `up`, ...) once for each of the query,
  system and observer builders.
- It expands each id argument into a `static_if` on the argument's type, because daslang
  can't pass a `type<T>` argument on to another function.

Edit the template, not the generated file.

The generator parses `include/flecs.h` with the same defines the module uses in Release (`FLECS_NO_CPP`,
`flecs_STATIC`, `NDEBUG`), so struct layouts match the compiled library. Its output is deterministic and
contains no machine paths. Blocked symbols are listed at the top of `bind_flecs.das`, each with the reason.
