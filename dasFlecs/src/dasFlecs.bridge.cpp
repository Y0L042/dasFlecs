// Hand-written part of the dasFlecs module (not touched by bind/bind_flecs.das):
// das lambdas as flecs callbacks, strings, logging and OS helpers.
//
// Where a callback receives a context pointer, the lambdas live in a heap "holder" stored
// in that context and freed by the matching flecs free callback (or at world fini).
// Callbacks without any context (order_by, on_validate, opaque type callbacks) go through
// a fixed pool of template trampolines; each pool slot is released with its owner.

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/bind_enum.h"
#include "dasFlecs.h"
#include "need_dasFlecs.h"

#include <array>
#include <atomic>
#include <mutex>
#include <utility>

namespace das {

static std::atomic<int32_t> g_holder_count{0};

int32_t das_flecs_callback_count () {
    return g_holder_count.load();
}

static void das_flecs_null_lambda ( const Lambda & lambda, Context * context, LineInfoArg * at, const char * what ) {
    if ( !lambda.capture ) context->throw_error_at(at, "%s: lambda is null", what);
}

// ── strings, memory, logging ───────────────────────────────────────────────────

char * das_flecs_take ( char * str, Context * context, LineInfoArg * at ) {
    if ( !str ) return nullptr;
    if ( !*str ) { ecs_os_free(str); return nullptr; }
    char * res = context->allocateString(str, uint64_t(strlen(str)), at);
    ecs_os_free(str);
    return res;
}

void   das_ecs_os_free ( void * ptr )                   { ecs_os_free(ptr); }
// das passes a null string as a pointer to a static "", so empty strings are never freed;
// das_ecs_os_strdup returns null for "" to match (das reads null as "").
void   das_ecs_os_free_str ( char * ptr )               { if ( ptr && *ptr ) ecs_os_free(ptr); }
void * das_ecs_os_malloc ( int64_t size )               { return ecs_os_malloc((ecs_size_t)size); }
void * das_ecs_os_calloc ( int64_t size )               { return ecs_os_calloc((ecs_size_t)size); }
void * das_ecs_os_realloc ( void * ptr, int64_t size )  { return ecs_os_realloc(ptr, (ecs_size_t)size); }
char * das_ecs_os_strdup ( const char * str )           { return (str && *str) ? ecs_os_strdup(str) : nullptr; }
void   das_ecs_os_sleep ( int32_t sec, int32_t nanosec ) { ecs_os_sleep(sec, nanosec); }
double das_ecs_os_now ()                                 { ecs_time_t t; ecs_os_get_time(&t); return (double)t.sec + (double)t.nanosec * 1e-9; }

void das_ecs_log ( int32_t level, const char * msg, LineInfoArg * at ) {
    const char * file = (at && at->fileInfo) ? at->fileInfo->name.c_str() : "";
    ecs_log_(level, file, at ? (int32_t)at->line : 0, "%s", msg ? msg : "");
}
void das_ecs_trace ( const char * msg, LineInfoArg * at ) { das_ecs_log(0, msg, at); }
void das_ecs_warn ( const char * msg, LineInfoArg * at )  { das_ecs_log(-2, msg, at); }
void das_ecs_err ( const char * msg, LineInfoArg * at )   { das_ecs_log(-3, msg, at); }
void das_ecs_fatal ( const char * msg, LineInfoArg * at ) { das_ecs_log(-4, msg, at); }

// ── generic iterator callbacks (systems, observers, hooks, run) ────────────────

struct DasFlecsIterCallback {
    Lambda    lambda;
    Context * context = nullptr;
};

static DasFlecsIterCallback * das_flecs_make_iter_cb ( const Lambda & lambda, Context * context, LineInfoArg * at, const char * what ) {
    das_flecs_null_lambda(lambda, context, at, what);
    auto cb = new DasFlecsIterCallback();
    cb->lambda = lambda;
    cb->context = context;
    g_holder_count++;
    return cb;
}

static void das_flecs_iter_cb_free ( void * ptr ) {
    delete (DasFlecsIterCallback *) ptr;
    g_holder_count--;
}

static void das_flecs_iter_cb ( ecs_iter_t * it ) {
    auto cb = (DasFlecsIterCallback *) it->callback_ctx;
    das_invoke_lambda<void>::invoke<const ecs_iter_t *>(cb->context, nullptr, cb->lambda, it);
}

static void das_flecs_run_cb ( ecs_iter_t * it ) {
    auto cb = (DasFlecsIterCallback *) it->run_ctx;
    das_invoke_lambda<void>::invoke<ecs_iter_t *>(cb->context, nullptr, cb->lambda, it);
}

void das_ecs_system_desc_callback ( ecs_system_desc_t & desc, TLambda<void,const ecs_iter_t *> callback, Context * context, LineInfoArg * at ) {
    if ( desc.callback_ctx_free == das_flecs_iter_cb_free ) das_flecs_iter_cb_free(desc.callback_ctx);
    desc.callback = das_flecs_iter_cb;
    desc.callback_ctx = das_flecs_make_iter_cb(callback, context, at, "ecs_system_desc_callback");
    desc.callback_ctx_free = das_flecs_iter_cb_free;
    desc.multi_threaded = false;   // das contexts are single-threaded
}

void das_ecs_system_desc_run ( ecs_system_desc_t & desc, TLambda<void,ecs_iter_t * const> callback, Context * context, LineInfoArg * at ) {
    if ( desc.run_ctx_free == das_flecs_iter_cb_free ) das_flecs_iter_cb_free(desc.run_ctx);
    desc.run = das_flecs_run_cb;
    desc.run_ctx = das_flecs_make_iter_cb(callback, context, at, "ecs_system_desc_run");
    desc.run_ctx_free = das_flecs_iter_cb_free;
    desc.multi_threaded = false;
}

void das_ecs_observer_desc_callback ( ecs_observer_desc_t & desc, TLambda<void,const ecs_iter_t *> callback, Context * context, LineInfoArg * at ) {
    if ( desc.callback_ctx_free == das_flecs_iter_cb_free ) das_flecs_iter_cb_free(desc.callback_ctx);
    desc.callback = das_flecs_iter_cb;
    desc.callback_ctx = das_flecs_make_iter_cb(callback, context, at, "ecs_observer_desc_callback");
    desc.callback_ctx_free = das_flecs_iter_cb_free;
}

void das_ecs_observer_desc_run ( ecs_observer_desc_t & desc, TLambda<void,ecs_iter_t * const> callback, Context * context, LineInfoArg * at ) {
    if ( desc.run_ctx_free == das_flecs_iter_cb_free ) das_flecs_iter_cb_free(desc.run_ctx);
    desc.run = das_flecs_run_cb;
    desc.run_ctx = das_flecs_make_iter_cb(callback, context, at, "ecs_observer_desc_run");
    desc.run_ctx_free = das_flecs_iter_cb_free;
}

// On failure flecs may or may not have taken ownership of the holder (it frees it when it
// deletes a half-created system), so it is never freed here: a failed init can leak one
// small holder, but never double-frees.
ecs_entity_t das_ecs_system_init ( ecs_world_t * world, ecs_system_desc_t & desc,
        TLambda<void,const ecs_iter_t *> callback, Context * context, LineInfoArg * at ) {
    if ( !world ) context->throw_error_at(at, "ecs_system_init: world is null");
    ecs_system_desc_t d = desc;
    das_ecs_system_desc_callback(d, callback, context, at);
    return ecs_system_init(world, &d);
}

ecs_entity_t das_ecs_observer_init ( ecs_world_t * world, ecs_observer_desc_t & desc,
        TLambda<void,const ecs_iter_t *> callback, Context * context, LineInfoArg * at ) {
    if ( !world ) context->throw_error_at(at, "ecs_observer_init: world is null");
    ecs_observer_desc_t d = desc;
    das_ecs_observer_desc_callback(d, callback, context, at);
    return ecs_observer_init(world, &d);
}

// ── trampoline pool (callbacks without a context argument) ─────────────────────

enum DasFlecsSlotKind {
    K_ORDER_BY, K_VALIDATE,
    K_SERIALIZE, K_SERIALIZE_MEMBER, K_SERIALIZE_ELEMENT,
    K_ASSIGN_BOOL, K_ASSIGN_CHAR, K_ASSIGN_INT, K_ASSIGN_UINT, K_ASSIGN_FLOAT,
    K_ASSIGN_STRING, K_ASSIGN_ENTITY, K_ASSIGN_ID, K_ASSIGN_NULL, K_CLEAR,
    K_ENSURE_ELEMENT, K_ENSURE_MEMBER, K_COUNT, K_RESIZE,
    K_NUM
};

constexpr int DAS_FLECS_SLOTS = 64;

struct DasFlecsSlot {
    bool      used = false;
    Context * context = nullptr;
    Lambda    lambda[K_NUM];
};

static DasFlecsSlot g_slots[DAS_FLECS_SLOTS];
static std::mutex   g_slots_mutex;

static int das_flecs_slot_alloc ( Context * context, LineInfoArg * at ) {
    std::lock_guard<std::mutex> lock(g_slots_mutex);
    for ( int i = 0; i != DAS_FLECS_SLOTS; ++i ) {
        if ( !g_slots[i].used ) {
            g_slots[i] = DasFlecsSlot();
            g_slots[i].used = true;
            g_slots[i].context = context;
            g_holder_count++;
            return i;
        }
    }
    context->throw_error_at(at, "dasFlecs: out of callback slots (%d order_by / on_validate / opaque types alive)", DAS_FLECS_SLOTS);
    return -1;
}

static void das_flecs_slot_free ( int slot ) {
    if ( slot < 0 || slot >= DAS_FLECS_SLOTS ) return;
    std::lock_guard<std::mutex> lock(g_slots_mutex);
    if ( g_slots[slot].used ) {
        g_slots[slot] = DasFlecsSlot();
        g_holder_count--;
    }
}

template <int S> struct DasFlecsTramp {
    static DasFlecsSlot & slot() { return g_slots[S]; }
    static int order_by ( ecs_entity_t e1, const void * p1, ecs_entity_t e2, const void * p2 ) {
        return das_invoke_lambda<int32_t>::invoke<ecs_entity_t,const void *,ecs_entity_t,const void *>(
            slot().context, nullptr, slot().lambda[K_ORDER_BY], e1, p1, e2, p2);
    }
    static bool validate ( ecs_world_t * world, ecs_entity_t e, void * ptr ) {
        return das_invoke_lambda<bool>::invoke<ecs_world_t *,ecs_entity_t,void *>(
            slot().context, nullptr, slot().lambda[K_VALIDATE], world, e, ptr);
    }
    static int serialize ( const ecs_serializer_t * ser, const void * src ) {
        return das_invoke_lambda<int32_t>::invoke<const ecs_serializer_t *,const void *>(
            slot().context, nullptr, slot().lambda[K_SERIALIZE], ser, src);
    }
    static int serialize_member ( const ecs_serializer_t * ser, const void * src, const char * name ) {
        return das_invoke_lambda<int32_t>::invoke<const ecs_serializer_t *,const void *,const char *>(
            slot().context, nullptr, slot().lambda[K_SERIALIZE_MEMBER], ser, src, name);
    }
    static int serialize_element ( const ecs_serializer_t * ser, const void * src, size_t elem ) {
        return das_invoke_lambda<int32_t>::invoke<const ecs_serializer_t *,const void *,uint64_t>(
            slot().context, nullptr, slot().lambda[K_SERIALIZE_ELEMENT], ser, src, uint64_t(elem));
    }
    static void assign_bool ( void * dst, bool v ) {
        das_invoke_lambda<void>::invoke<void *,bool>(slot().context, nullptr, slot().lambda[K_ASSIGN_BOOL], dst, v);
    }
    static void assign_char ( void * dst, char v ) {
        das_invoke_lambda<void>::invoke<void *,int8_t>(slot().context, nullptr, slot().lambda[K_ASSIGN_CHAR], dst, int8_t(v));
    }
    static void assign_int ( void * dst, int64_t v ) {
        das_invoke_lambda<void>::invoke<void *,int64_t>(slot().context, nullptr, slot().lambda[K_ASSIGN_INT], dst, v);
    }
    static void assign_uint ( void * dst, uint64_t v ) {
        das_invoke_lambda<void>::invoke<void *,uint64_t>(slot().context, nullptr, slot().lambda[K_ASSIGN_UINT], dst, v);
    }
    static void assign_float ( void * dst, double v ) {
        das_invoke_lambda<void>::invoke<void *,double>(slot().context, nullptr, slot().lambda[K_ASSIGN_FLOAT], dst, v);
    }
    static void assign_string ( void * dst, const char * v ) {
        das_invoke_lambda<void>::invoke<void *,const char *>(slot().context, nullptr, slot().lambda[K_ASSIGN_STRING], dst, v);
    }
    static void assign_entity ( void * dst, ecs_world_t * world, ecs_entity_t e ) {
        das_invoke_lambda<void>::invoke<void *,ecs_world_t *,ecs_entity_t>(slot().context, nullptr, slot().lambda[K_ASSIGN_ENTITY], dst, world, e);
    }
    static void assign_id ( void * dst, ecs_world_t * world, ecs_id_t id ) {
        das_invoke_lambda<void>::invoke<void *,ecs_world_t *,ecs_id_t>(slot().context, nullptr, slot().lambda[K_ASSIGN_ID], dst, world, id);
    }
    static void assign_null ( void * dst ) {
        das_invoke_lambda<void>::invoke<void *>(slot().context, nullptr, slot().lambda[K_ASSIGN_NULL], dst);
    }
    static void clear ( void * dst ) {
        das_invoke_lambda<void>::invoke<void *>(slot().context, nullptr, slot().lambda[K_CLEAR], dst);
    }
    static void * ensure_element ( void * dst, size_t elem ) {
        return das_invoke_lambda<void *>::invoke<void *,uint64_t>(slot().context, nullptr, slot().lambda[K_ENSURE_ELEMENT], dst, uint64_t(elem));
    }
    static void * ensure_member ( void * dst, const char * member ) {
        return das_invoke_lambda<void *>::invoke<void *,const char *>(slot().context, nullptr, slot().lambda[K_ENSURE_MEMBER], dst, member);
    }
    static size_t count ( const void * src ) {
        return (size_t) das_invoke_lambda<uint64_t>::invoke<const void *>(slot().context, nullptr, slot().lambda[K_COUNT], src);
    }
    static void resize ( void * dst, size_t count ) {
        das_invoke_lambda<void>::invoke<void *,uint64_t>(slot().context, nullptr, slot().lambda[K_RESIZE], dst, uint64_t(count));
    }
};

#define DAS_FLECS_TABLE(NAME, FN) \
    template <size_t... I> static auto das_flecs_make_##NAME ( std::index_sequence<I...> ) { \
        return std::array<decltype(&DasFlecsTramp<0>::FN), DAS_FLECS_SLOTS>{ &DasFlecsTramp<I>::FN... }; } \
    static const auto g_tbl_##NAME = das_flecs_make_##NAME(std::make_index_sequence<DAS_FLECS_SLOTS>{});

DAS_FLECS_TABLE(order_by, order_by)
DAS_FLECS_TABLE(validate, validate)
DAS_FLECS_TABLE(serialize, serialize)
DAS_FLECS_TABLE(serialize_member, serialize_member)
DAS_FLECS_TABLE(serialize_element, serialize_element)
DAS_FLECS_TABLE(assign_bool, assign_bool)
DAS_FLECS_TABLE(assign_char, assign_char)
DAS_FLECS_TABLE(assign_int, assign_int)
DAS_FLECS_TABLE(assign_uint, assign_uint)
DAS_FLECS_TABLE(assign_float, assign_float)
DAS_FLECS_TABLE(assign_string, assign_string)
DAS_FLECS_TABLE(assign_entity, assign_entity)
DAS_FLECS_TABLE(assign_id, assign_id)
DAS_FLECS_TABLE(assign_null, assign_null)
DAS_FLECS_TABLE(clear, clear)
DAS_FLECS_TABLE(ensure_element, ensure_element)
DAS_FLECS_TABLE(ensure_member, ensure_member)
DAS_FLECS_TABLE(count, count)
DAS_FLECS_TABLE(resize, resize)

// ── type hooks ─────────────────────────────────────────────────────────────────
// Holder in hooks.binding_ctx: flecs passes it to on_add/on_set/on_remove/on_replace as
// it->callback_ctx and to ctor/dtor/copy/move through type_info->hooks.binding_ctx, and
// frees it with binding_ctx_free when the type info goes away (world fini).

struct DasFlecsHooks {
    Context * context = nullptr;
    Lambda ctor, dtor, copy, move, on_add, on_set, on_remove, on_replace;
    int validate_slot = -1;
};

static void das_flecs_hooks_free ( void * ptr ) {
    auto h = (DasFlecsHooks *) ptr;
    das_flecs_slot_free(h->validate_slot);
    delete h;
    g_holder_count--;
}

static DasFlecsHooks * das_flecs_hooks ( ecs_type_hooks_t & hooks, Context * context, LineInfoArg * at ) {
    if ( hooks.binding_ctx_free == das_flecs_hooks_free ) {
        auto h = (DasFlecsHooks *) hooks.binding_ctx;
        if ( h->context != context ) context->throw_error_at(at, "ecs_type_hooks_t was started from another context");
        return h;
    }
    if ( hooks.binding_ctx ) context->throw_error_at(at, "ecs_type_hooks_t.binding_ctx is already in use");
    auto h = new DasFlecsHooks();
    h->context = context;
    g_holder_count++;
    hooks.binding_ctx = h;
    hooks.binding_ctx_free = das_flecs_hooks_free;
    return h;
}

static DasFlecsHooks * das_flecs_hooks_of ( const ecs_type_info_t * ti ) {
    return (DasFlecsHooks *) ti->hooks.binding_ctx;
}

static void das_flecs_hook_ctor ( void * ptr, int32_t count, const ecs_type_info_t * ti ) {
    auto h = das_flecs_hooks_of(ti);
    das_invoke_lambda<void>::invoke<void *,int32_t,const ecs_type_info_t *>(h->context, nullptr, h->ctor, ptr, count, ti);
}
static void das_flecs_hook_dtor ( void * ptr, int32_t count, const ecs_type_info_t * ti ) {
    auto h = das_flecs_hooks_of(ti);
    das_invoke_lambda<void>::invoke<void *,int32_t,const ecs_type_info_t *>(h->context, nullptr, h->dtor, ptr, count, ti);
}
static void das_flecs_hook_copy ( void * dst, const void * src, int32_t count, const ecs_type_info_t * ti ) {
    auto h = das_flecs_hooks_of(ti);
    das_invoke_lambda<void>::invoke<void *,const void *,int32_t,const ecs_type_info_t *>(h->context, nullptr, h->copy, dst, src, count, ti);
}
static void das_flecs_hook_move ( void * dst, void * src, int32_t count, const ecs_type_info_t * ti ) {
    auto h = das_flecs_hooks_of(ti);
    das_invoke_lambda<void>::invoke<void *,void *,int32_t,const ecs_type_info_t *>(h->context, nullptr, h->move, dst, src, count, ti);
}
#define DAS_FLECS_ITER_HOOK(NAME) \
    static void das_flecs_hook_##NAME ( ecs_iter_t * it ) { \
        auto h = (DasFlecsHooks *) it->callback_ctx; \
        das_invoke_lambda<void>::invoke<const ecs_iter_t *>(h->context, nullptr, h->NAME, it); \
    }
DAS_FLECS_ITER_HOOK(on_add)
DAS_FLECS_ITER_HOOK(on_set)
DAS_FLECS_ITER_HOOK(on_remove)
DAS_FLECS_ITER_HOOK(on_replace)

typedef TLambda<void,void * const,const int32_t,const ecs_type_info_t *> DasXtorLambda;

void das_ecs_hooks_ctor ( ecs_type_hooks_t & hooks, DasXtorLambda cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_hooks_ctor");
    das_flecs_hooks(hooks, context, at)->ctor = cb;
    hooks.ctor = das_flecs_hook_ctor;
}
void das_ecs_hooks_dtor ( ecs_type_hooks_t & hooks, DasXtorLambda cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_hooks_dtor");
    das_flecs_hooks(hooks, context, at)->dtor = cb;
    hooks.dtor = das_flecs_hook_dtor;
}
void das_ecs_hooks_copy ( ecs_type_hooks_t & hooks, TLambda<void,void * const,const void *,const int32_t,const ecs_type_info_t *> cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_hooks_copy");
    das_flecs_hooks(hooks, context, at)->copy = cb;
    hooks.copy = das_flecs_hook_copy;
}
void das_ecs_hooks_move ( ecs_type_hooks_t & hooks, TLambda<void,void * const,void * const,const int32_t,const ecs_type_info_t *> cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_hooks_move");
    das_flecs_hooks(hooks, context, at)->move = cb;
    hooks.move = das_flecs_hook_move;
}
#define DAS_FLECS_ITER_HOOK_SETTER(NAME) \
    void das_ecs_hooks_##NAME ( ecs_type_hooks_t & hooks, TLambda<void,const ecs_iter_t *> cb, Context * context, LineInfoArg * at ) { \
        das_flecs_null_lambda(cb, context, at, "ecs_hooks_" #NAME); \
        das_flecs_hooks(hooks, context, at)->NAME = cb; \
        hooks.NAME = das_flecs_hook_##NAME; \
    }
DAS_FLECS_ITER_HOOK_SETTER(on_add)
DAS_FLECS_ITER_HOOK_SETTER(on_set)
DAS_FLECS_ITER_HOOK_SETTER(on_remove)
DAS_FLECS_ITER_HOOK_SETTER(on_replace)

void das_ecs_hooks_on_validate ( ecs_type_hooks_t & hooks, TLambda<bool,ecs_world_t * const,const ecs_entity_t,void * const> cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_hooks_on_validate");
    auto h = das_flecs_hooks(hooks, context, at);
    if ( h->validate_slot < 0 ) h->validate_slot = das_flecs_slot_alloc(context, at);
    g_slots[h->validate_slot].lambda[K_VALIDATE] = cb;
    hooks.on_validate = g_tbl_validate[h->validate_slot];
}

// ── query callbacks: order_by, group_by, group create / delete ─────────────────
// Holder in desc.binding_ctx (freed by ecs_query_fini through binding_ctx_free) and in
// desc.group_by_ctx (passed to the group callbacks).

struct DasFlecsQueryCb {
    Context * context = nullptr;
    Lambda group_by, group_create, group_delete;
    int order_slot = -1;
};

static void das_flecs_query_cb_free ( void * ptr ) {
    auto q = (DasFlecsQueryCb *) ptr;
    das_flecs_slot_free(q->order_slot);
    delete q;
    g_holder_count--;
}

static DasFlecsQueryCb * das_flecs_query_cb ( ecs_query_desc_t & desc, Context * context, LineInfoArg * at ) {
    if ( desc.binding_ctx_free == das_flecs_query_cb_free ) {
        return (DasFlecsQueryCb *) desc.binding_ctx;
    }
    if ( desc.binding_ctx ) context->throw_error_at(at, "ecs_query_desc_t.binding_ctx is already in use");
    auto q = new DasFlecsQueryCb();
    q->context = context;
    g_holder_count++;
    desc.binding_ctx = q;
    desc.binding_ctx_free = das_flecs_query_cb_free;
    return q;
}

static uint64_t das_flecs_group_by ( ecs_world_t * world, ecs_table_t * table, ecs_id_t id, void * ctx ) {
    auto q = (DasFlecsQueryCb *) ctx;
    return das_invoke_lambda<uint64_t>::invoke<ecs_world_t *,ecs_table_t *,ecs_id_t>(q->context, nullptr, q->group_by, world, table, id);
}
static void * das_flecs_group_create ( ecs_world_t * world, uint64_t group_id, void * ctx ) {
    auto q = (DasFlecsQueryCb *) ctx;
    return das_invoke_lambda<void *>::invoke<ecs_world_t *,uint64_t>(q->context, nullptr, q->group_create, world, group_id);
}
static void das_flecs_group_delete ( ecs_world_t * world, uint64_t group_id, void * group_ctx, void * ctx ) {
    auto q = (DasFlecsQueryCb *) ctx;
    das_invoke_lambda<void>::invoke<ecs_world_t *,uint64_t,void *>(q->context, nullptr, q->group_delete, world, group_id, group_ctx);
}

void das_ecs_query_desc_order_by ( ecs_query_desc_t & desc, TLambda<int32_t,const ecs_entity_t,const void *,const ecs_entity_t,const void *> cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_query_desc_order_by");
    auto q = das_flecs_query_cb(desc, context, at);
    if ( q->order_slot < 0 ) q->order_slot = das_flecs_slot_alloc(context, at);
    g_slots[q->order_slot].lambda[K_ORDER_BY] = cb;
    desc.order_by_callback = g_tbl_order_by[q->order_slot];
}
void das_ecs_query_desc_group_by ( ecs_query_desc_t & desc, TLambda<uint64_t,ecs_world_t * const,ecs_table_t * const,const ecs_id_t> cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_query_desc_group_by");
    auto q = das_flecs_query_cb(desc, context, at);
    q->group_by = cb;
    desc.group_by_callback = das_flecs_group_by;
    desc.group_by_ctx = q;
}
void das_ecs_query_desc_on_group_create ( ecs_query_desc_t & desc, TLambda<void *,ecs_world_t * const,const uint64_t> cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_query_desc_on_group_create");
    auto q = das_flecs_query_cb(desc, context, at);
    q->group_create = cb;
    desc.on_group_create = das_flecs_group_create;
    desc.group_by_ctx = q;
}
void das_ecs_query_desc_on_group_delete ( ecs_query_desc_t & desc, TLambda<void,ecs_world_t * const,const uint64_t,void * const> cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_query_desc_on_group_delete");
    auto q = das_flecs_query_cb(desc, context, at);
    q->group_delete = cb;
    desc.on_group_delete = das_flecs_group_delete;
    desc.group_by_ctx = q;
}

// ── opaque types ───────────────────────────────────────────────────────────────
// The slot of an opaque desc is found from any callback already installed in it.

static int das_flecs_opaque_slot ( const EcsOpaque & t ) {
    for ( int s = 0; s != DAS_FLECS_SLOTS; ++s ) {
        if ( (t.serialize && t.serialize == g_tbl_serialize[s])
          || (t.serialize_member && t.serialize_member == g_tbl_serialize_member[s])
          || (t.serialize_element && t.serialize_element == g_tbl_serialize_element[s])
          || (t.assign_bool && t.assign_bool == g_tbl_assign_bool[s])
          || (t.assign_char && t.assign_char == g_tbl_assign_char[s])
          || (t.assign_int && t.assign_int == g_tbl_assign_int[s])
          || (t.assign_uint && t.assign_uint == g_tbl_assign_uint[s])
          || (t.assign_float && t.assign_float == g_tbl_assign_float[s])
          || (t.assign_string && t.assign_string == g_tbl_assign_string[s])
          || (t.assign_entity && t.assign_entity == g_tbl_assign_entity[s])
          || (t.assign_id && t.assign_id == g_tbl_assign_id[s])
          || (t.assign_null && t.assign_null == g_tbl_assign_null[s])
          || (t.clear && t.clear == g_tbl_clear[s])
          || (t.ensure_element && t.ensure_element == g_tbl_ensure_element[s])
          || (t.ensure_member && t.ensure_member == g_tbl_ensure_member[s])
          || (t.count && t.count == g_tbl_count[s])
          || (t.resize && t.resize == g_tbl_resize[s]) ) {
            return s;
        }
    }
    return -1;
}

static int das_flecs_opaque_slot_or_alloc ( const EcsOpaque & t, Context * context, LineInfoArg * at ) {
    int s = das_flecs_opaque_slot(t);
    if ( s < 0 ) s = das_flecs_slot_alloc(context, at);
    if ( g_slots[s].context != context ) context->throw_error_at(at, "opaque desc was started from another context");
    return s;
}

#define DAS_FLECS_OPAQUE_SETTER(NAME, KIND, ...) \
    void das_ecs_opaque_##NAME ( ecs_opaque_desc_t & desc, TLambda<__VA_ARGS__> cb, Context * context, LineInfoArg * at ) { \
        das_flecs_null_lambda(cb, context, at, "ecs_opaque_" #NAME); \
        int s = das_flecs_opaque_slot_or_alloc(desc.type, context, at); \
        g_slots[s].lambda[KIND] = cb; \
        desc.type.NAME = g_tbl_##NAME[s]; \
    }

DAS_FLECS_OPAQUE_SETTER(serialize, K_SERIALIZE, int32_t, const ecs_serializer_t *, const void *)
DAS_FLECS_OPAQUE_SETTER(serialize_member, K_SERIALIZE_MEMBER, int32_t, const ecs_serializer_t *, const void *, const char *)
DAS_FLECS_OPAQUE_SETTER(serialize_element, K_SERIALIZE_ELEMENT, int32_t, const ecs_serializer_t *, const void *, const uint64_t)
DAS_FLECS_OPAQUE_SETTER(assign_bool, K_ASSIGN_BOOL, void, void * const, const bool)
DAS_FLECS_OPAQUE_SETTER(assign_char, K_ASSIGN_CHAR, void, void * const, const int8_t)
DAS_FLECS_OPAQUE_SETTER(assign_int, K_ASSIGN_INT, void, void * const, const int64_t)
DAS_FLECS_OPAQUE_SETTER(assign_uint, K_ASSIGN_UINT, void, void * const, const uint64_t)
DAS_FLECS_OPAQUE_SETTER(assign_float, K_ASSIGN_FLOAT, void, void * const, const double)
DAS_FLECS_OPAQUE_SETTER(assign_string, K_ASSIGN_STRING, void, void * const, const char *)
DAS_FLECS_OPAQUE_SETTER(assign_entity, K_ASSIGN_ENTITY, void, void * const, ecs_world_t * const, const ecs_entity_t)
DAS_FLECS_OPAQUE_SETTER(assign_id, K_ASSIGN_ID, void, void * const, ecs_world_t * const, const ecs_id_t)
DAS_FLECS_OPAQUE_SETTER(assign_null, K_ASSIGN_NULL, void, void * const)
DAS_FLECS_OPAQUE_SETTER(clear, K_CLEAR, void, void * const)
DAS_FLECS_OPAQUE_SETTER(ensure_element, K_ENSURE_ELEMENT, void *, void * const, const uint64_t)
DAS_FLECS_OPAQUE_SETTER(ensure_member, K_ENSURE_MEMBER, void *, void * const, const char *)
DAS_FLECS_OPAQUE_SETTER(count, K_COUNT, uint64_t, const void *)
DAS_FLECS_OPAQUE_SETTER(resize, K_RESIZE, void, void * const, const uint64_t)

static void das_flecs_slot_atfini ( ecs_world_t *, void * ctx ) {
    das_flecs_slot_free((int)(intptr_t)ctx);
}

ecs_entity_t das_ecs_opaque_init ( ecs_world_t * world, ecs_opaque_desc_t & desc, Context * context, LineInfoArg * at ) {
    if ( !world ) context->throw_error_at(at, "ecs_opaque_init: world is null");
    ecs_entity_t res = ecs_opaque_init(world, &desc);
    int s = das_flecs_opaque_slot(desc.type);
    if ( s >= 0 ) {
        if ( res ) ecs_atfini(world, das_flecs_slot_atfini, (void *)(intptr_t)s);
        else das_flecs_slot_free(s);
    }
    return res;
}

// ecs_meta_op_t::is is an anonymous union, which the generator skips
const ecs_map_t * das_ecs_meta_op_constants ( const ecs_meta_op_t * op ) {
    return op ? op->is.constants : nullptr;
}

int32_t das_ecs_ser_value ( const ecs_serializer_t * ser, ecs_entity_t type, const void * value ) {
    return ser->value(ser, type, value);
}
int32_t das_ecs_ser_member ( const ecs_serializer_t * ser, const char * name ) {
    return ser->member(ser, name ? name : "");
}

// ── script functions ───────────────────────────────────────────────────────────
// Holder in desc.ctx (passed back as ecs_function_ctx_t.ctx), freed at world fini.

struct DasFlecsFunction {
    Context * context = nullptr;
    Lambda    callback, cancel;
};

static void das_flecs_function_atfini ( ecs_world_t *, void * ctx ) {
    delete (DasFlecsFunction *) ctx;
    g_holder_count--;
}

static DasFlecsFunction * das_flecs_function ( void *& ctx, Context * context, LineInfoArg * at ) {
    if ( ctx ) return (DasFlecsFunction *) ctx;   // set by an earlier das_* call on this desc
    auto f = new DasFlecsFunction();
    f->context = context;
    g_holder_count++;
    ctx = f;
    return f;
}

static void das_flecs_function_cb ( const ecs_function_ctx_t * ctx, int32_t argc, const ecs_value_t * argv, ecs_value_t * result ) {
    auto f = (DasFlecsFunction *) ctx->ctx;
    das_invoke_lambda<void>::invoke<const ecs_function_ctx_t *,int32_t,const ecs_value_t *,ecs_value_t *>(
        f->context, nullptr, f->callback, ctx, argc, argv, result);
}
static void das_flecs_async_cb ( const ecs_function_ctx_t * ctx, int32_t argc, const ecs_value_t * argv, ecs_script_future_t * future ) {
    auto f = (DasFlecsFunction *) ctx->ctx;
    das_invoke_lambda<void>::invoke<const ecs_function_ctx_t *,int32_t,const ecs_value_t *,ecs_script_future_t *>(
        f->context, nullptr, f->callback, ctx, argc, argv, future);
}
static void das_flecs_async_cancel ( const ecs_function_ctx_t * ctx, ecs_script_future_t * future ) {
    auto f = (DasFlecsFunction *) ctx->ctx;
    das_invoke_lambda<void>::invoke<const ecs_function_ctx_t *,ecs_script_future_t *>(
        f->context, nullptr, f->cancel, ctx, future);
}

typedef TLambda<void,const ecs_function_ctx_t *,const int32_t,const ecs_value_t *,ecs_value_t * const> DasFunctionLambda;
typedef TLambda<void,const ecs_function_ctx_t *,const int32_t,const ecs_value_t *,ecs_script_future_t * const> DasAsyncLambda;
typedef TLambda<void,const ecs_function_ctx_t *,ecs_script_future_t * const> DasCancelLambda;

ecs_entity_t das_ecs_function_init ( ecs_world_t * world, ecs_function_desc_t & desc, DasFunctionLambda cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_function_init");
    ecs_function_desc_t d = desc;
    d.ctx = nullptr;
    auto f = das_flecs_function(d.ctx, context, at);
    f->callback = cb;
    d.callback = das_flecs_function_cb;
    ecs_entity_t res = ecs_function_init(world, &d);
    ecs_atfini(world, das_flecs_function_atfini, f);
    return res;
}
ecs_entity_t das_ecs_method_init ( ecs_world_t * world, ecs_function_desc_t & desc, DasFunctionLambda cb, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_method_init");
    ecs_function_desc_t d = desc;
    d.ctx = nullptr;
    auto f = das_flecs_function(d.ctx, context, at);
    f->callback = cb;
    d.callback = das_flecs_function_cb;
    ecs_entity_t res = ecs_method_init(world, &d);
    ecs_atfini(world, das_flecs_function_atfini, f);
    return res;
}
ecs_entity_t das_ecs_async_function_init ( ecs_world_t * world, ecs_async_function_desc_t & desc, DasAsyncLambda cb, DasCancelLambda cancel, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_async_function_init");
    ecs_async_function_desc_t d = desc;
    d.ctx = nullptr;
    auto f = das_flecs_function(d.ctx, context, at);
    f->callback = cb;
    d.callback = das_flecs_async_cb;
    if ( cancel.capture ) {
        f->cancel = cancel;
        d.cancel = das_flecs_async_cancel;
    }
    ecs_entity_t res = ecs_async_function_init(world, &d);
    ecs_atfini(world, das_flecs_function_atfini, f);
    return res;
}
ecs_entity_t das_ecs_async_method_init ( ecs_world_t * world, ecs_async_function_desc_t & desc, DasAsyncLambda cb, DasCancelLambda cancel, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(cb, context, at, "ecs_async_method_init");
    ecs_async_function_desc_t d = desc;
    d.ctx = nullptr;
    auto f = das_flecs_function(d.ctx, context, at);
    f->callback = cb;
    d.callback = das_flecs_async_cb;
    if ( cancel.capture ) {
        f->cancel = cancel;
        d.cancel = das_flecs_async_cancel;
    }
    ecs_entity_t res = ecs_async_method_init(world, &d);
    ecs_atfini(world, das_flecs_function_atfini, f);
    return res;
}

// ── script input event hooks ───────────────────────────────────────────────────
// Holder in hooks.ctx, freed at world fini.

struct DasFlecsEventHooks {
    Context * context = nullptr;
    Lambda    to_local, to_focus;
};

static void das_flecs_event_hooks_atfini ( ecs_world_t *, void * ctx ) {
    delete (DasFlecsEventHooks *) ctx;
    g_holder_count--;
}

static void das_flecs_to_local ( ecs_world_t * world, ecs_entity_t entity, float screen_x, float screen_y,
        float * local_x, float * local_y, void * ctx ) {
    auto h = (DasFlecsEventHooks *) ctx;
    das_invoke_lambda<void>::invoke<ecs_world_t *,ecs_entity_t,float,float,float *,float *>(
        h->context, nullptr, h->to_local, world, entity, screen_x, screen_y, local_x, local_y);
}

static ecs_entity_t das_flecs_to_focus ( ecs_world_t * world, ecs_entity_t entity, ecs_entity_t current,
        ecs_script_focus_source_t source, void * ctx ) {
    auto h = (DasFlecsEventHooks *) ctx;
    return das_invoke_lambda<ecs_entity_t>::invoke<ecs_world_t *,ecs_entity_t,ecs_entity_t,ecs_script_focus_source_t>(
        h->context, nullptr, h->to_focus, world, entity, current, source);
}

void das_ecs_script_set_event_hooks ( ecs_world_t * world,
        TLambda<void,ecs_world_t * const,const ecs_entity_t,const float,const float,float * const,float * const> to_local,
        TLambda<ecs_entity_t,ecs_world_t * const,const ecs_entity_t,const ecs_entity_t,const ecs_script_focus_source_t> to_focus,
        Context * context, LineInfoArg * at ) {
    if ( !world ) context->throw_error_at(at, "ecs_script_set_event_hooks: world is null");
    auto h = new DasFlecsEventHooks();
    h->context = context;
    g_holder_count++;
    ecs_script_event_hooks_t hooks = {};
    if ( to_local.capture ) { h->to_local = to_local; hooks.to_local = das_flecs_to_local; }
    if ( to_focus.capture ) { h->to_focus = to_focus; hooks.to_focus = das_flecs_to_focus; }
    hooks.ctx = h;
    ecs_script_set_event_hooks(world, &hooks);
    ecs_atfini(world, das_flecs_event_hooks_atfini, h);
}

// ── modules ────────────────────────────────────────────────────────────────────
// ecs_import calls the module action synchronously (and only the first time), so the
// lambda is handed over through a thread-local.

struct DasFlecsImport {
    const Lambda * lambda = nullptr;
    Context *      context = nullptr;
};
static thread_local DasFlecsImport g_import;

static void das_flecs_import_action ( ecs_world_t * world ) {
    DasFlecsImport imp = g_import;
    g_import = DasFlecsImport();
    das_invoke_lambda<void>::invoke<ecs_world_t *>(imp.context, nullptr, *imp.lambda, world);
}

ecs_entity_t das_ecs_import ( ecs_world_t * world, const char * module_name, TLambda<void,ecs_world_t * const> action, Context * context, LineInfoArg * at ) {
    das_flecs_null_lambda(action, context, at, "ecs_import");
    if ( !module_name ) context->throw_error_at(at, "ecs_import: module name is null");
    DasFlecsImport saved = g_import;
    g_import.lambda = &action;
    g_import.context = context;
    ecs_entity_t res = ecs_import(world, das_flecs_import_action, module_name);
    g_import = saved;
    return res;
}

}
