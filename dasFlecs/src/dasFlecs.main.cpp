// Hand-written part of the dasFlecs module (not touched by bind/bind_flecs.das):
// registration of the generated extern ids and of everything in dasFlecs.bridge.cpp.

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/simulate/bind_enum.h"
#include "dasFlecs.h"
#include "need_dasFlecs.h"

namespace das {

// getters for ids flecs assigns at import time, addon import wrappers (generated)
#include "dasFlecs.extern.decl.inc"

const char * das_flecs_version() {
    return FLECS_VERSION;
}

#define DAS_FLECS_FN(FN, NAME, SE, ...) \
    addExtern<DAS_BIND_FUN(FN)>(*this, lib, NAME, SideEffects::SE, "das::" #FN)->args({__VA_ARGS__})
#define DAS_FLECS_FN0(FN, NAME, SE) \
    addExtern<DAS_BIND_FUN(FN)>(*this, lib, NAME, SideEffects::SE, "das::" #FN)

void Module_dasFlecs::initMain() {
    // builtin entity ids, addon imports and flag macros (generated)
    #include "dasFlecs.extern.add.inc"

    DAS_FLECS_FN0(das_flecs_version, "flecs_version", none);
    DAS_FLECS_FN0(das_flecs_callback_count, "flecs_callback_count", accessExternal);

    // strings, memory, logging
    DAS_FLECS_FN(das_flecs_take, "ecs_take", worstDefault, "str", "context", "at");
    DAS_FLECS_FN(das_ecs_os_free, "ecs_os_free", worstDefault, "ptr");
    DAS_FLECS_FN(das_ecs_os_free_str, "ecs_os_free", worstDefault, "str");
    DAS_FLECS_FN(das_ecs_os_malloc, "ecs_os_malloc", worstDefault, "size");
    DAS_FLECS_FN(das_ecs_os_calloc, "ecs_os_calloc", worstDefault, "size");
    DAS_FLECS_FN(das_ecs_os_realloc, "ecs_os_realloc", worstDefault, "ptr", "size");
    DAS_FLECS_FN(das_ecs_os_strdup, "ecs_os_strdup", worstDefault, "str");
    DAS_FLECS_FN(das_ecs_os_sleep, "ecs_os_sleep", worstDefault, "sec", "nanosec");
    DAS_FLECS_FN0(das_ecs_os_now, "ecs_os_now", accessExternal);
    DAS_FLECS_FN(das_ecs_log, "ecs_log", worstDefault, "level", "msg", "at");
    DAS_FLECS_FN(das_ecs_trace, "ecs_trace", worstDefault, "msg", "at");
    DAS_FLECS_FN(das_ecs_warn, "ecs_warn", worstDefault, "msg", "at");
    DAS_FLECS_FN(das_ecs_err, "ecs_err", worstDefault, "msg", "at");
    DAS_FLECS_FN(das_ecs_fatal, "ecs_fatal", worstDefault, "msg", "at");

    // systems and observers (same names as the C functions, with a das lambda)
    DAS_FLECS_FN(das_ecs_system_init, "ecs_system_init", worstDefault, "world", "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_observer_init, "ecs_observer_init", worstDefault, "world", "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_system_desc_callback, "ecs_system_desc_callback", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_system_desc_run, "ecs_system_desc_run", worstDefault, "desc", "run", "context", "at");
    DAS_FLECS_FN(das_ecs_observer_desc_callback, "ecs_observer_desc_callback", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_observer_desc_run, "ecs_observer_desc_run", worstDefault, "desc", "run", "context", "at");

    // type hooks
    DAS_FLECS_FN(das_ecs_hooks_ctor, "ecs_hooks_ctor", worstDefault, "hooks", "ctor", "context", "at");
    DAS_FLECS_FN(das_ecs_hooks_dtor, "ecs_hooks_dtor", worstDefault, "hooks", "dtor", "context", "at");
    DAS_FLECS_FN(das_ecs_hooks_copy, "ecs_hooks_copy", worstDefault, "hooks", "copy", "context", "at");
    DAS_FLECS_FN(das_ecs_hooks_move, "ecs_hooks_move", worstDefault, "hooks", "move", "context", "at");
    DAS_FLECS_FN(das_ecs_hooks_on_add, "ecs_hooks_on_add", worstDefault, "hooks", "on_add", "context", "at");
    DAS_FLECS_FN(das_ecs_hooks_on_set, "ecs_hooks_on_set", worstDefault, "hooks", "on_set", "context", "at");
    DAS_FLECS_FN(das_ecs_hooks_on_remove, "ecs_hooks_on_remove", worstDefault, "hooks", "on_remove", "context", "at");
    DAS_FLECS_FN(das_ecs_hooks_on_replace, "ecs_hooks_on_replace", worstDefault, "hooks", "on_replace", "context", "at");
    DAS_FLECS_FN(das_ecs_hooks_on_validate, "ecs_hooks_on_validate", worstDefault, "hooks", "on_validate", "context", "at");

    // query callbacks
    DAS_FLECS_FN(das_ecs_query_desc_order_by, "ecs_query_desc_order_by", worstDefault, "desc", "compare", "context", "at");
    DAS_FLECS_FN(das_ecs_query_desc_group_by, "ecs_query_desc_group_by", worstDefault, "desc", "group_by", "context", "at");
    DAS_FLECS_FN(das_ecs_query_desc_on_group_create, "ecs_query_desc_on_group_create", worstDefault, "desc", "on_create", "context", "at");
    DAS_FLECS_FN(das_ecs_query_desc_on_group_delete, "ecs_query_desc_on_group_delete", worstDefault, "desc", "on_delete", "context", "at");

    // opaque types
    DAS_FLECS_FN(das_ecs_opaque_serialize, "ecs_opaque_serialize", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_serialize_member, "ecs_opaque_serialize_member", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_serialize_element, "ecs_opaque_serialize_element", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_bool, "ecs_opaque_assign_bool", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_char, "ecs_opaque_assign_char", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_int, "ecs_opaque_assign_int", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_uint, "ecs_opaque_assign_uint", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_float, "ecs_opaque_assign_float", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_string, "ecs_opaque_assign_string", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_entity, "ecs_opaque_assign_entity", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_id, "ecs_opaque_assign_id", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_assign_null, "ecs_opaque_assign_null", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_clear, "ecs_opaque_clear", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_ensure_element, "ecs_opaque_ensure_element", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_ensure_member, "ecs_opaque_ensure_member", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_count, "ecs_opaque_count", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_resize, "ecs_opaque_resize", worstDefault, "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_opaque_init, "ecs_opaque_init", worstDefault, "world", "desc", "context", "at");
    DAS_FLECS_FN(das_ecs_ser_value, "ecs_ser_value", worstDefault, "ser", "type", "value");
    DAS_FLECS_FN(das_ecs_ser_member, "ecs_ser_member", worstDefault, "ser", "name");
    DAS_FLECS_FN(das_ecs_meta_op_constants, "ecs_meta_op_constants", none, "op");

    // script functions
    DAS_FLECS_FN(das_ecs_function_init, "ecs_function_init", worstDefault, "world", "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_method_init, "ecs_method_init", worstDefault, "world", "desc", "callback", "context", "at");
    DAS_FLECS_FN(das_ecs_async_function_init, "ecs_async_function_init", worstDefault, "world", "desc", "callback", "cancel", "context", "at");
    DAS_FLECS_FN(das_ecs_async_method_init, "ecs_async_method_init", worstDefault, "world", "desc", "callback", "cancel", "context", "at");

    // script input event hooks
    DAS_FLECS_FN(das_ecs_script_set_event_hooks, "ecs_script_set_event_hooks", worstDefault, "world", "to_local", "to_focus", "context", "at");

    // modules
    DAS_FLECS_FN(das_ecs_import, "ecs_import", worstDefault, "world", "module_name", "action", "context", "at");
}

ModuleAotType Module_dasFlecs::aotRequire ( TextWriter & tw ) const {
    tw << "#include \"need_dasFlecs.h\"\n";
    return ModuleAotType::cpp;
}

}
