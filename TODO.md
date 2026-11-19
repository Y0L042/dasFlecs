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

- [ ] Run the full suite: `manage.sh examples` and `manage.sh test`. The 33 tests haven't
      been re-run since the last few bridge changes.
- [ ] Update `README.md`:
  - [ ] Callback bridge: type hooks (`ecs_hooks_*`), query `order_by` / `group_by` / group
        create and delete, system and observer `run`, opaque serializers (`ecs_opaque_*`,
        `ecs_ser_value` / `ecs_ser_member`), script functions, async functions, modules
        (`ecs_import`), script event hooks
  - [ ] Helpers: logging (`ecs_trace` / `ecs_warn` / `ecs_err`, `ecs_log_push` / `ecs_log_pop`),
        `ecs_take` and `ecs_os_*`, `ecs_get_by_id`, the new `flecs_boost` macro replacements
  - [ ] The `manage.sh examples` command and the `// example:` markers
  - [ ] Fields named like daslang keywords get a leading underscore (`it._table`, `_type`, `_range`)
- [ ] Check that `manage.sh fmt --verify` passes on the new files

## Daslang quirks to document

- [ ] **Empty strings are null.** An empty daslang string `""` is a null pointer. So
      `ecs_os_free` skips empty strings, and `ecs_os_strdup("")` returns null.
- [ ] **Lambda pointer parameters are read-only.** A pointer parameter in a bridge lambda
      can't be stored in a variable directly; it takes a `reinterpret`, as in the async
      examples.
