# TODO

Status of porting the flecs C examples (`flecs/examples/c`) to daslang
(`dasFlecs/examples/<category>/`): 88 of 94 ported. All of them match the real C program
output in `manage.sh examples`, except four by design:

- `delta_time`, `target_fps` and `mutate_entity` run but aren't compared, because their
  output depends on timing.
- `time_interval` loops forever, so it is only dry-run compiled.

The checker compares against what the C examples actually print, not the comments in
their source: all 94 C examples were built and run to capture that output.

## Examples still to port

- [ ] `script/events`: `ecs_script_set_event_hooks` is bridged and builds. Next, generate
      the escaped script string from the C source (it has quotes, braces and its own `{...}`
      interpolation), then write the port.
- [ ] `script/async_await_c`: async functions called from daslang, with a cancel callback.
      The bridge already supports it.
- [ ] `modules/simple_module`: put the module in its own file next to the example (a
      sibling `require common/<module>` works).

## Written, not yet checked

- [ ] `script/async_await`
- [ ] `script/rest_call`: starts a REST server, marked `// example: no-run` (dry-run compile only)
- [ ] `explorer/explorer`: starts a REST server, marked `// example: no-run` (dry-run compile only)

## After the ports

- [x] Run the full suite: `manage.sh examples` (94 runnable pass, 3 compile-only) and
      `manage.sh test` (78 tests).
- [ ] Update `README.md`:
  - [x] Callback bridge: list what the bridge wraps (under "Not bound")
  - [ ] Callback bridge: a section with usage for type hooks, order_by / group_by, opaque
        serializers, script functions and async functions
  - [ ] Helpers: logging (`ecs_trace` / `ecs_warn` / `ecs_err`, `ecs_log_push` / `ecs_log_pop`),
        `ecs_take` and `ecs_os_*`, `ecs_get_by_id`
  - [x] `flecs_boost` C++-style layer: classes, typed-block macros, `[ecs_component]`
  - [ ] The `manage.sh examples` command and the `// example:` markers
  - [ ] Fields named like daslang keywords get a leading underscore (`it._table`, `_type`, `_range`)
- [x] `manage.sh fmt --verify` passes. The generated `flecs/flecs_cpp.das` is excluded: dasfmt
      turns `TT const?` return types into `TT const ?`.

## C++-style layer (flecs_cpp / flecs_macros)

- [ ] More `cpp_style/` re-ports (prefabs, relationships, observers/custom_event).
- [ ] `FlecsComponent.member` re-commits `ecs_struct_init` on every call; add an explicit
      `build()` if that becomes slow for large structs.
- [ ] The macros allow one entity argument per block (`FlecsEntity` or `ecs_entity_t`).

## Daslang quirks to document

- [ ] **Empty strings can be null or not.** A computed empty daslang string is a null pointer,
      but a `""` literal can arrive in C as a non-null pointer to an empty string. So
      `ecs_os_free` skips empty strings, and `ecs_os_strdup("")` returns null. An argument
      where null and `""` mean different things needs care. Example: `ecs_lookup_path_w_sep`
      with prefix `""` treats every path as absolute, so `FlecsEntity.lookup` passes `"::"`.
- [ ] **Lambda pointer parameters are read-only.** A pointer parameter in a bridge lambda
      can't be stored in a variable directly; it takes a `reinterpret`, as in the async
      examples.
- [ ] **`return` from a block inside nested loops.** In a block (not a function), `return`
      inside a `for` that is inside a `while` exits only the `for`, and the `while` condition
      runs again. `ecs_find_query` sets a hit flag before it returns and tests the flag in the
      `while` condition, so `ecs_query_next` doesn't run again on a finished iterator.
- [ ] **Generics resolve calls in their defining module.** To call a user overload from
      library generic code, use `_::name(...)`. `ecs_id` calls `_::flecs_reflect_component`
      so that the `[ecs_component]` overloads are found.
- [ ] **Passing `type<T>` on.** A function can't pass its `type<T>` argument on to another
      function. `tools/gen_flecs_cpp.py` resolves ids inline with `static_if` instead.
- [ ] **`elif` in `static_if` is a runtime branch.** Nest the `static_if`s so that untaken
      arms aren't instantiated.
