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
    var world = ecs_init()
    let e = ecs_new(world)
    ecs_set(world, e, Position(x = 0.0, y = 0.0))
    ecs_set(world, e, Velocity(x = 1.0, y = 2.0))

    ecs_system(world, "Move", EcsOnUpdate, "Position, [in] Velocity") @(it : ecs_iter_t const?) {
        ecs_field_view(it, type<Position>, 0) $(var p) {
            ecs_field_view(it, type<Velocity>, 1) $(var v) {
                for (pi, vi in p, v) {
                    pi.x += vi.x
                    pi.y += vi.y
                }
            }
        }
    }
    ecs_progress(world, 0.0)
    print("{ecs_get(world, e, type<Position>).y}\n")    // 2
    flecs_fini(world)
}
```

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
| `ecs_query(world, "Position, Velocity")` | `ecs_query(world, { .expr = ... })` |
| `ecs_query_each(world, q) $(it) {...}` | `ecs_query_iter` / `ecs_query_next` loop |
| `ecs_field_view(it, type<T>, 0) $(var arr) {...}`, `ecs_field` | `ecs_field(it, T, 0)` |
| `ecs_system(world, "Name", EcsOnUpdate, "expr") @(it) {...}` | `ECS_SYSTEM` / `ecs_system` |
| `ecs_observer(world, EcsOnSet, "expr") @(it) {...}` | `ECS_OBSERVER` / `ecs_observer` |

A component is registered the first time a helper uses it, under the das type's name (`"Position"`).
**Register components with `ecs_id(world, type<T>)` before a query expression names them**, the same as
`ECS_COMPONENT` in C. Ids are cached per world, so finalize worlds with `flecs_fini(world)`: it drops the
world's cache entries and then calls `ecs_fini`.

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
- **Functions or fields that take any other C callback:** `ecs_set_ctx`, `ecs_atfini`, `ecs_import`,
  type hooks, `run` callbacks, and order-by/group-by.
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
descriptor registers both `flecs` and `flecs/flecs_boost`.

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

The generator parses `include/flecs.h` with the same defines the module uses in Release (`FLECS_NO_CPP`,
`flecs_STATIC`, `NDEBUG`), so struct layouts match the compiled library. Its output is deterministic and
contains no machine paths. Blocked symbols are listed at the top of `bind_flecs.das`, each with the reason.
