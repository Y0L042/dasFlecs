#pragma once

// Parse/compile entry point for the dasClangBind flecs binder (hand-written).
//
// libclang parses this header with FLECS_NO_CPP, flecs_STATIC and NDEBUG, which are the
// same settings the module is compiled with in Release (see dasFlecs/CMakeLists.txt).
#include <flecs.h>

// Everything below is C++ glue for the compiled module; libclang parses this
// header too, so keep it out of the binder's view.
#if !defined(DAS_FLECS_BINDER_PARSE)

#include "daScript/simulate/simulate.h"

namespace das {

// "4.2.0" — the flecs version the module was compiled against
const char * das_flecs_version();

// ── strings, memory, logging (dasFlecs.bridge.cpp) ─────────────────────────────
char * das_flecs_take ( char * str, Context * context, LineInfoArg * at );   // copy to das heap, free
void   das_ecs_os_free ( void * ptr );
void   das_ecs_os_free_str ( char * ptr );
void * das_ecs_os_malloc ( int64_t size );
void * das_ecs_os_calloc ( int64_t size );
void * das_ecs_os_realloc ( void * ptr, int64_t size );
char * das_ecs_os_strdup ( const char * str );
void   das_ecs_os_sleep ( int32_t sec, int32_t nanosec );
double das_ecs_os_now ();
void   das_ecs_log ( int32_t level, const char * msg, LineInfoArg * at );
void   das_ecs_trace ( const char * msg, LineInfoArg * at );   // ecs_trace: level 0
void   das_ecs_warn ( const char * msg, LineInfoArg * at );    // ecs_warn: level -2
void   das_ecs_err ( const char * msg, LineInfoArg * at );     // ecs_err: level -3
void   das_ecs_fatal ( const char * msg, LineInfoArg * at );   // ecs_fatal: level -4

// ── callback bridge (dasFlecs.bridge.cpp) ──────────────────────────────────────
// The generated API skips every function and field that takes a C callback. These
// install das lambdas instead. A lambda lives in the das context that created it: that
// context must outlive the world. Callbacks run on the thread that triggers them; systems
// are forced single-threaded.
int32_t das_flecs_callback_count ();

ecs_entity_t das_ecs_system_init ( ecs_world_t * world, ecs_system_desc_t & desc,
    TLambda<void,const ecs_iter_t *> callback, Context * context, LineInfoArg * at );
ecs_entity_t das_ecs_observer_init ( ecs_world_t * world, ecs_observer_desc_t & desc,
    TLambda<void,const ecs_iter_t *> callback, Context * context, LineInfoArg * at );
void das_ecs_system_desc_callback ( ecs_system_desc_t & desc, TLambda<void,const ecs_iter_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_system_desc_run ( ecs_system_desc_t & desc, TLambda<void,ecs_iter_t * const> cb, Context * context, LineInfoArg * at );
void das_ecs_observer_desc_callback ( ecs_observer_desc_t & desc, TLambda<void,const ecs_iter_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_observer_desc_run ( ecs_observer_desc_t & desc, TLambda<void,ecs_iter_t * const> cb, Context * context, LineInfoArg * at );

// type hooks: set on an ecs_type_hooks_t, then ecs_set_hooks_id(world, component, &hooks)
void das_ecs_hooks_ctor ( ecs_type_hooks_t & hooks, TLambda<void,void * const,const int32_t,const ecs_type_info_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_hooks_dtor ( ecs_type_hooks_t & hooks, TLambda<void,void * const,const int32_t,const ecs_type_info_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_hooks_copy ( ecs_type_hooks_t & hooks, TLambda<void,void * const,const void *,const int32_t,const ecs_type_info_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_hooks_move ( ecs_type_hooks_t & hooks, TLambda<void,void * const,void * const,const int32_t,const ecs_type_info_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_hooks_on_add ( ecs_type_hooks_t & hooks, TLambda<void,const ecs_iter_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_hooks_on_set ( ecs_type_hooks_t & hooks, TLambda<void,const ecs_iter_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_hooks_on_remove ( ecs_type_hooks_t & hooks, TLambda<void,const ecs_iter_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_hooks_on_replace ( ecs_type_hooks_t & hooks, TLambda<void,const ecs_iter_t *> cb, Context * context, LineInfoArg * at );
void das_ecs_hooks_on_validate ( ecs_type_hooks_t & hooks, TLambda<bool,ecs_world_t * const,const ecs_entity_t,void * const> cb, Context * context, LineInfoArg * at );

// query callbacks: set on an ecs_query_desc_t (standalone or system/observer .query)
void das_ecs_query_desc_order_by ( ecs_query_desc_t & desc, TLambda<int32_t,const ecs_entity_t,const void *,const ecs_entity_t,const void *> cb, Context * context, LineInfoArg * at );
void das_ecs_query_desc_group_by ( ecs_query_desc_t & desc, TLambda<uint64_t,ecs_world_t * const,ecs_table_t * const,const ecs_id_t> cb, Context * context, LineInfoArg * at );
void das_ecs_query_desc_on_group_create ( ecs_query_desc_t & desc, TLambda<void *,ecs_world_t * const,const uint64_t> cb, Context * context, LineInfoArg * at );
void das_ecs_query_desc_on_group_delete ( ecs_query_desc_t & desc, TLambda<void,ecs_world_t * const,const uint64_t,void * const> cb, Context * context, LineInfoArg * at );

// opaque types: set on an ecs_opaque_desc_t, then das_ecs_opaque_init
void das_ecs_opaque_serialize ( ecs_opaque_desc_t & desc, TLambda<int32_t,const ecs_serializer_t *,const void *> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_serialize_member ( ecs_opaque_desc_t & desc, TLambda<int32_t,const ecs_serializer_t *,const void *,const char *> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_serialize_element ( ecs_opaque_desc_t & desc, TLambda<int32_t,const ecs_serializer_t *,const void *,const uint64_t> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_bool ( ecs_opaque_desc_t & desc, TLambda<void,void * const,const bool> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_char ( ecs_opaque_desc_t & desc, TLambda<void,void * const,const int8_t> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_int ( ecs_opaque_desc_t & desc, TLambda<void,void * const,const int64_t> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_uint ( ecs_opaque_desc_t & desc, TLambda<void,void * const,const uint64_t> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_float ( ecs_opaque_desc_t & desc, TLambda<void,void * const,const double> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_string ( ecs_opaque_desc_t & desc, TLambda<void,void * const,const char *> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_entity ( ecs_opaque_desc_t & desc, TLambda<void,void * const,ecs_world_t * const,const ecs_entity_t> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_id ( ecs_opaque_desc_t & desc, TLambda<void,void * const,ecs_world_t * const,const ecs_id_t> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_assign_null ( ecs_opaque_desc_t & desc, TLambda<void,void * const> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_clear ( ecs_opaque_desc_t & desc, TLambda<void,void * const> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_ensure_element ( ecs_opaque_desc_t & desc, TLambda<void *,void * const,const uint64_t> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_ensure_member ( ecs_opaque_desc_t & desc, TLambda<void *,void * const,const char *> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_count ( ecs_opaque_desc_t & desc, TLambda<uint64_t,const void *> cb, Context * context, LineInfoArg * at );
void das_ecs_opaque_resize ( ecs_opaque_desc_t & desc, TLambda<void,void * const,const uint64_t> cb, Context * context, LineInfoArg * at );
ecs_entity_t das_ecs_opaque_init ( ecs_world_t * world, ecs_opaque_desc_t & desc, Context * context, LineInfoArg * at );
const ecs_map_t * das_ecs_meta_op_constants ( const ecs_meta_op_t * op );   // op->is.constants
int32_t das_ecs_ser_value ( const ecs_serializer_t * ser, ecs_entity_t type, const void * value );
int32_t das_ecs_ser_member ( const ecs_serializer_t * ser, const char * name );

// script functions
ecs_entity_t das_ecs_function_init ( ecs_world_t * world, ecs_function_desc_t & desc,
    TLambda<void,const ecs_function_ctx_t *,const int32_t,const ecs_value_t *,ecs_value_t * const> cb, Context * context, LineInfoArg * at );
ecs_entity_t das_ecs_method_init ( ecs_world_t * world, ecs_function_desc_t & desc,
    TLambda<void,const ecs_function_ctx_t *,const int32_t,const ecs_value_t *,ecs_value_t * const> cb, Context * context, LineInfoArg * at );
ecs_entity_t das_ecs_async_function_init ( ecs_world_t * world, ecs_async_function_desc_t & desc,
    TLambda<void,const ecs_function_ctx_t *,const int32_t,const ecs_value_t *,ecs_script_future_t * const> cb,
    TLambda<void,const ecs_function_ctx_t *,ecs_script_future_t * const> cancel, Context * context, LineInfoArg * at );
ecs_entity_t das_ecs_async_method_init ( ecs_world_t * world, ecs_async_function_desc_t & desc,
    TLambda<void,const ecs_function_ctx_t *,const int32_t,const ecs_value_t *,ecs_script_future_t * const> cb,
    TLambda<void,const ecs_function_ctx_t *,ecs_script_future_t * const> cancel, Context * context, LineInfoArg * at );

// script input: to_local / to_focus hooks (either lambda may be null; to_screen is not bridged)
void das_ecs_script_set_event_hooks ( ecs_world_t * world,
    TLambda<void,ecs_world_t * const,const ecs_entity_t,const float,const float,float * const,float * const> to_local,
    TLambda<ecs_entity_t,ecs_world_t * const,const ecs_entity_t,const ecs_entity_t,const ecs_script_focus_source_t> to_focus,
    Context * context, LineInfoArg * at );

// modules: ECS_IMPORT with a das lambda as the module action
ecs_entity_t das_ecs_import ( ecs_world_t * world, const char * module_name, TLambda<void,ecs_world_t * const> action, Context * context, LineInfoArg * at );

}

#endif
