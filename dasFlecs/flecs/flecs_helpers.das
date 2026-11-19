options gen2
options indenting = 4

module flecs_helpers shared public

//! Free-function helpers over the generated flecs bindings (`require flecs`); part of
//! flecs_boost, which also re-exports the C++-style classes (flecs_cpp) and the typed query /
//! system / observer macros (flecs_macros).
//!
//! Mirrors the flecs C macro API with das types standing in for C types:
//!
//!     ecs_id(world, type<Position>)            ECS_COMPONENT / ecs_id(Position)
//!     ecs_set(world, e, Position(x = 1.0))     ecs_set(world, e, Position, {1})
//!     ecs_get(world, e, type<Position>)        ecs_get(world, e, Position)
//!     ecs_add / ecs_remove / ecs_has           ecs_add(world, e, Position) ...
//!     ecs_pair(EcsChildOf, parent)             ecs_pair(EcsChildOf, parent)
//!     ecs_system(world, "Move", EcsOnUpdate, "Position, Velocity") @(it) {...}
//!     ecs_observer(world, EcsOnSet, "Position") @(it) {...}
//!     ecs_query_each(world, q) $(it) {...}     ecs_query_iter / ecs_query_next loop
//!     ecs_field_view(it, type<Position>, 0) $(var p) {...}   ecs_field(it, Position, 0)
//!
//! Components are registered on first use, named after the das type. Ids are cached per
//! world; finalize worlds that used the typed helpers with `flecs_fini(world)`, which drops
//! that world's cache entries before calling ecs_fini.

require flecs public
require daslib/array_boost
require daslib/enum_trait
require strings

// ── pairs ──────────────────────────────────────────────────────────────────────

def ecs_pair(rel, tgt : ecs_entity_t) : ecs_id_t {
    //! (relationship, target) pair id, same as the C ecs_pair macro
    return ECS_PAIR | ((rel & 0xFFFFFFFFul) << 32ul) | (tgt & 0xFFFFFFFFul)
}

def ecs_is_pair(id : ecs_id_t) : bool {
    //! true when id is a (relationship, target) pair
    return (id & ECS_ID_FLAGS_MASK) == ECS_PAIR
}

def ecs_pair_first_raw(pair : ecs_id_t) : ecs_entity_t {
    //! relationship of a pair, without generation bits (use ecs_get_alive to restore them)
    return ((pair & ECS_COMPONENT_MASK) >> 32ul) & 0xFFFFFFFFul
}

def ecs_pair_second_raw(pair : ecs_id_t) : ecs_entity_t {
    //! target of a pair, without generation bits (use ecs_get_alive to restore them)
    return pair & 0xFFFFFFFFul
}

def ecs_add_pair(world : ecs_world_t?; e, rel, tgt : ecs_entity_t) {
    ecs_add_id(world, e, ecs_pair(rel, tgt))
}

def ecs_remove_pair(world : ecs_world_t?; e, rel, tgt : ecs_entity_t) {
    ecs_remove_id(world, e, ecs_pair(rel, tgt))
}

def ecs_has_pair(world : ecs_world_t?; e, rel, tgt : ecs_entity_t) : bool {
    return ecs_has_id(world, e, ecs_pair(rel, tgt))
}

// ── components ─────────────────────────────────────────────────────────────────

// "<world pointer>|<type name>" -> component id
var private g_component_ids : table<string; ecs_entity_t>

def private cache_key(world : ecs_world_t?; name : string) : string {
    return "{intptr(world)}|{name}"
}

def ecs_component_name(t : auto(TT)) : string {
    //! flecs entity name used for the das type TT ("Position"; module prefix dropped)
    let full = typeinfo stripped_typename(type<TT>)
    let sep = rfind(full, "::")
    return sep >= 0 ? slice(full, sep + 2) : full
}

def ecs_component_register(world : ecs_world_t?; name : string; size, alignment : int) : ecs_entity_t {
    //! registers (or finds) a component by name with the given layout
    var edesc : ecs_entity_desc_t
    edesc.name = name
    edesc.symbol = name
    edesc.use_low_id = true
    var cdesc : ecs_component_desc_t
    cdesc.entity = ecs_entity_init(world, unsafe(addr(edesc)))
    cdesc._type.size = size
    cdesc._type.alignment = alignment
    return ecs_component_init(world, unsafe(addr(cdesc)))
}

def flecs_reflect_component(world : ecs_world_t?; id : ecs_entity_t; dummy : auto(TT)?) {
    //! reflection hook called when a component is first registered. [ecs_component]
    //! (flecs_macros) generates a non-generic overload per annotated struct; ecs_id calls
    //! it as _::flecs_reflect_component, so overloads in the calling module (and what it
    //! requires) are visible and preferred over this no-op fallback.
    pass
}

def ecs_id(world : ecs_world_t?; t : auto(TT)) : ecs_entity_t {
    //! component id of das type TT in world, registering it on first use
    let name = ecs_component_name(type<TT>)
    let key = cache_key(world, name)
    let cached = g_component_ids?[key] ?? 0ul
    if (cached != 0ul && ecs_is_alive(world, cached)) {
        return cached
    }
    let id = ecs_component_register(world, name, typeinfo sizeof(type<TT>), typeinfo alignof(type<TT>))
    g_component_ids[key] = id
    static_if (typeinfo is_struct(type<TT>)) {
        if (!ecs_has_id(world, id, ecs_id_EcsStruct)) {
            var dummy : TT -const? = null
            _::flecs_reflect_component(world, id, dummy)
        }
    }
    return id
}

// ── per-call-site query cache (flecs_macros ecs_query / ecs_find_query) ───────────

// "<world pointer>#<site key>" -> query
var private g_query_cache : table<string; ecs_query_t?>

def _flecs_query_get(world : ecs_world_t?; site_key : string; builder : block<() : ecs_query_t?>) : ecs_query_t? {
    //! the query cached for (world, site key), built with `builder` on first use
    let key = "{intptr(world)}#{site_key}"
    var cached = g_query_cache?[key] ?? null
    if (cached != null) {
        return cached
    }
    var q = invoke(builder)
    g_query_cache[key] = q
    return q
}

def flecs_query_cache_count() : int {
    //! number of cached call-site queries, over all worlds (for tests)
    return length(g_query_cache)
}

def flecs_forget_world(world : ecs_world_t?) {
    //! drops the world's cached component ids and frees its cached call-site queries;
    //! flecs_fini calls it before ecs_fini
    let prefix = "{intptr(world)}|"
    var stale : array<string>
    for (k in keys(g_component_ids)) {
        if (k |> starts_with(prefix)) {
            stale |> push(k)
        }
    }
    for (k in stale) {
        g_component_ids |> erase(k)
    }
    let qprefix = "{intptr(world)}#"
    var stale_q : array<string>
    for (k, q in keys(g_query_cache), values(g_query_cache)) {
        if (k |> starts_with(qprefix)) {
            stale_q |> push(k)
            if (q != null) {
                ecs_query_fini(q)
            }
        }
    }
    for (k in stale_q) {
        g_query_cache |> erase(k)
    }
}

def flecs_fini(var world : ecs_world_t?&) : int {
    //! ecs_fini that also forgets the world's cached component ids and call-site queries;
    //! sets world to null
    flecs_forget_world(world)
    let res = ecs_fini(world)
    world = null
    return res
}

def ecs_set(world : ecs_world_t?; e : ecs_entity_t; value : auto(TT)) {
    //! sets component TT on e (adds it if missing), triggering OnSet observers
    let id = ecs_id(world, type<TT>)
    unsafe {
        ecs_set_id(world, e, id, uint64(typeinfo sizeof(type<TT>)), addr(value))
    }
}

def ecs_get(world : ecs_world_t?; e : ecs_entity_t; t : auto(TT)) : TT const? {
    //! read-only pointer to component TT of e, null if e does not have it.
    //! Valid until the next operation that changes the entity's components.
    unsafe {
        return reinterpret<TT const?>(ecs_get_id(world, e, ecs_id(world, type<TT>)))
    }
}

def ecs_get_mut(world : ecs_world_t?; e : ecs_entity_t; t : auto(TT)) : TT -const? {
    //! mutable pointer to component TT of e, null if e does not have it.
    //! Call ecs_modified(world, e, type<TT>) afterwards to trigger OnSet observers.
    unsafe {
        return reinterpret<TT -const?>(ecs_get_mut_id(world, e, ecs_id(world, type<TT>)))
    }
}

def ecs_modified(world : ecs_world_t?; e : ecs_entity_t; t : auto(TT)) {
    ecs_modified_id(world, e, ecs_id(world, type<TT>))
}

def ecs_add(world : ecs_world_t?; e : ecs_entity_t; t : auto(TT)) {
    ecs_add_id(world, e, ecs_id(world, type<TT>))
}

def ecs_remove(world : ecs_world_t?; e : ecs_entity_t; t : auto(TT)) {
    ecs_remove_id(world, e, ecs_id(world, type<TT>))
}

def ecs_has(world : ecs_world_t?; e : ecs_entity_t; t : auto(TT)) : bool {
    return ecs_has_id(world, e, ecs_id(world, type<TT>))
}

def ecs_entity(world : ecs_world_t?; name : string) : ecs_entity_t {
    //! finds or creates the entity with the given name (tags are plain entities)
    var edesc : ecs_entity_desc_t
    edesc.name = name
    return ecs_entity_init(world, unsafe(addr(edesc)))
}

// ── iteration ──────────────────────────────────────────────────────────────────

[unsafe_operation]
def ecs_field(it : ecs_iter_t const?; t : auto(TT); index : int) : TT -const? {
    //! raw pointer to field `index` as TT (it.count elements when owned, 1 when shared)
    unsafe {
        return reinterpret<TT -const?>(ecs_field_w_size(it, uint64(typeinfo sizeof(type<TT>)), int8(index)))
    }
}

def ecs_field_view(it : ecs_iter_t const?; t : auto(TT); index : int; blk : block<(var data : array<TT -const>) : void>) {
    //! calls blk with field `index` as a temporary array: it.count elements for an owned
    //! field, one element for a shared one (inherited / singleton / fixed source),
    //! empty for an optional field that is not set
    let count = ecs_field_is_self(it, int8(index)) ? it.count : 1
    unsafe {
        var ptr = reinterpret<TT -const?>(ecs_field_w_size(it, uint64(typeinfo sizeof(type<TT>)), int8(index)))
        var data <- temp_array(ptr, ptr == null ? 0 : count, type<TT>)
        invoke(blk, data)
    }
}

def ecs_iter_entity(it : ecs_iter_t const?; index : int) : ecs_entity_t {
    //! it.entities[index], bounds-checked against it.count
    if (index < 0 || index >= it.count) {
        panic("ecs_iter_entity: index {index} out of range 0..{it.count}")
    }
    unsafe {
        return it.entities[index]
    }
}

def ecs_query_expr(world : ecs_world_t?; expr : string) : ecs_query_t? {
    //! creates a query from a flecs query-language expression; free with ecs_query_fini
    var qdesc : ecs_query_desc_t
    qdesc.expr = expr
    return ecs_query_init(world, unsafe(addr(qdesc)))
}

def ecs_query_each(world : ecs_world_t?; q : ecs_query_t?; blk : block<(var it : ecs_iter_t?) : void>) {
    //! runs blk once per matched table (ecs_query_iter / ecs_query_next loop); the iterator
    //! is mutable, for ecs_iter_get_var, ecs_iter_skip, ecs_iter_changed, ...
    var it = ecs_query_iter(world, q)
    while (ecs_query_next(unsafe(addr(it)))) {
        invoke(blk, unsafe(addr(it)))
    }
}

def ecs_query_count_entities(world : ecs_world_t?; q : ecs_query_t?) : int {
    //! number of entities the query currently matches
    var total = 0
    ecs_query_each(world, q) $(it) {
        total += it.count
    }
    return total
}

// ── systems and observers ──────────────────────────────────────────────────────

def ecs_system_expr(world : ecs_world_t?; name : string; phase : ecs_entity_t; expr : string;
                    var callback : lambda<(it : ecs_iter_t const?) : void>) : ecs_entity_t {
    //! creates a system running `callback` once per matched table in `phase`
    //! (0 = not in the pipeline; run it with ecs_run). See ecs_system_init for lifetime rules.
    var sdesc : ecs_system_desc_t
    if (!empty(name)) {
        sdesc.entity = ecs_entity(world, name)
    }
    sdesc.query.expr = expr
    sdesc.phase = phase
    return ecs_system_init(world, sdesc, callback)
}

def ecs_observer_expr(world : ecs_world_t?; event : ecs_entity_t; expr : string;
                      var callback : lambda<(it : ecs_iter_t const?) : void>) : ecs_entity_t {
    //! creates an observer for `event` (EcsOnAdd, EcsOnSet, EcsOnRemove, ...) on `expr`
    var odesc : ecs_observer_desc_t
    odesc.query.expr = expr
    odesc.events[0] = event
    return ecs_observer_init(world, odesc, callback)
}

def ecs_observer_expr(world : ecs_world_t?; name : string; event : ecs_entity_t; expr : string;
                      var callback : lambda<(it : ecs_iter_t const?) : void>) : ecs_entity_t {
    //! named observer (ECS_OBSERVER(world, Name, Event, expr))
    var odesc : ecs_observer_desc_t
    if (!empty(name)) {
        odesc.entity = ecs_entity(world, name)
    }
    odesc.query.expr = expr
    odesc.events[0] = event
    return ecs_observer_init(world, odesc, callback)
}

// ── replacements for the remaining C convenience macros ────────────────────────

def ecs_log_push() {
    //! indents subsequent log messages (ecs_log_push())
    ecs_log_push_(0)
}

def ecs_log_pop() {
    ecs_log_pop_(0)
}

def ecs_get_path(world : ecs_world_t?; e : ecs_entity_t) : string {
    //! full path of e ("parent.child"), as a das string (ecs_get_path + ecs_os_free)
    return ecs_take(ecs_get_path_w_sep(world, 0ul, e, ".", ""))
}

def ecs_get_path(world : ecs_world_t?; parent, e : ecs_entity_t) : string {
    //! path of e relative to parent
    return ecs_take(ecs_get_path_w_sep(world, parent, e, ".", ""))
}

def ecs_new_w_pair(world : ecs_world_t?; rel, tgt : ecs_entity_t) : ecs_entity_t {
    return ecs_new_w_id(world, ecs_pair(rel, tgt))
}

def ecs_new_w(world : ecs_world_t?; t : auto(TT)) : ecs_entity_t {
    //! new entity with component / tag TT
    return ecs_new_w_id(world, ecs_id(world, type<TT>))
}

def ecs_insert(world : ecs_world_t?; a : auto(A)) : ecs_entity_t {
    //! new entity with the given component values (ecs_insert(world, ecs_value(T, {...})))
    let e = ecs_new(world)
    ecs_set(world, e, a)
    return e
}

def ecs_insert(world : ecs_world_t?; a : auto(A); b : auto(B)) : ecs_entity_t {
    let e = ecs_new(world)
    ecs_set(world, e, a)
    ecs_set(world, e, b)
    return e
}

def ecs_insert(world : ecs_world_t?; a : auto(A); b : auto(B); c : auto(C)) : ecs_entity_t {
    let e = ecs_new(world)
    ecs_set(world, e, a)
    ecs_set(world, e, b)
    ecs_set(world, e, c)
    return e
}

def ecs_pair_first(world : ecs_world_t?; pair : ecs_id_t) : ecs_entity_t {
    //! relationship of a pair, with generation (ecs_pair_first)
    return ecs_get_alive(world, ecs_pair_first_raw(pair))
}

def ecs_pair_second(world : ecs_world_t?; pair : ecs_id_t) : ecs_entity_t {
    //! target of a pair, with generation (ecs_pair_second)
    return ecs_get_alive(world, ecs_pair_second_raw(pair))
}

def ecs_set_pair(world : ecs_world_t?; e : ecs_entity_t; value : auto(TT); tgt : ecs_entity_t) {
    //! sets pair (TT, tgt) with value as the relationship's data (ecs_set_pair)
    let id = ecs_pair(ecs_id(world, type<TT>), tgt)
    unsafe {
        ecs_set_id(world, e, id, uint64(typeinfo sizeof(type<TT>)), addr(value))
    }
}

def ecs_set_pair_second(world : ecs_world_t?; e : ecs_entity_t; rel : ecs_entity_t; value : auto(TT)) {
    //! sets pair (rel, TT) with value as the target's data (ecs_set_pair_second)
    let id = ecs_pair(rel, ecs_id(world, type<TT>))
    unsafe {
        ecs_set_id(world, e, id, uint64(typeinfo sizeof(type<TT>)), addr(value))
    }
}

def ecs_get_pair(world : ecs_world_t?; e : ecs_entity_t; t : auto(TT); tgt : ecs_entity_t) : TT const? {
    //! data of pair (TT, tgt), null if missing (ecs_get_pair)
    unsafe {
        return reinterpret<TT const?>(ecs_get_id(world, e, ecs_pair(ecs_id(world, type<TT>), tgt)))
    }
}

def ecs_get_pair_second(world : ecs_world_t?; e : ecs_entity_t; rel : ecs_entity_t; t : auto(TT)) : TT const? {
    //! data of pair (rel, TT), null if missing (ecs_get_pair_second)
    unsafe {
        return reinterpret<TT const?>(ecs_get_id(world, e, ecs_pair(rel, ecs_id(world, type<TT>))))
    }
}

def ecs_ensure(world : ecs_world_t?; e : ecs_entity_t; t : auto(TT)) : TT -const? {
    //! pointer to component TT of e, adding it first if missing (ecs_ensure)
    unsafe {
        return reinterpret<TT -const?>(ecs_ensure_id(world, e, ecs_id(world, type<TT>), uint64(typeinfo sizeof(type<TT>))))
    }
}

def ecs_singleton_set(world : ecs_world_t?; value : auto(TT)) {
    //! sets TT on its own component entity (ecs_singleton_set)
    ecs_set(world, ecs_id(world, type<TT>), value)
}

def ecs_singleton_get(world : ecs_world_t?; t : auto(TT)) : TT const? {
    return ecs_get(world, ecs_id(world, type<TT>), type<TT>)
}

def ecs_singleton_ensure(world : ecs_world_t?; t : auto(TT)) : TT -const? {
    return ecs_ensure(world, ecs_id(world, type<TT>), type<TT>)
}

def ecs_singleton_modified(world : ecs_world_t?; t : auto(TT)) {
    ecs_modified(world, ecs_id(world, type<TT>), type<TT>)
}

def ecs_count(world : ecs_world_t?; t : auto(TT)) : int {
    //! number of entities with TT (ecs_count)
    return ecs_count_id(world, ecs_id(world, type<TT>))
}

def ecs_each_table(world : ecs_world_t?; id : ecs_id_t; blk : block<(var it : ecs_iter_t?) : void>) {
    //! runs blk once per table with id (ecs_each_id / ecs_each_next loop)
    var it = ecs_each_id(world, id)
    while (ecs_each_next(unsafe(addr(it)))) {
        invoke(blk, unsafe(addr(it)))
    }
}

def ecs_each_table(world : ecs_world_t?; t : auto(TT); blk : block<(var it : ecs_iter_t?) : void>) {
    ecs_each_table(world, ecs_id(world, type<TT>), blk)
}

def ecs_tag(world : ecs_world_t?; name : string) : ecs_entity_t {
    //! ECS_TAG(world, Name): named entity, usable as a tag
    return ecs_entity(world, name)
}

def ecs_prefab(world : ecs_world_t?; name : string) : ecs_entity_t {
    //! ECS_PREFAB(world, Name): named prefab entity
    let e = ecs_entity(world, name)
    ecs_add_id(world, e, EcsPrefab)
    return e
}

def ecs_module(world : ecs_world_t?; c_name : string) : ecs_entity_t {
    //! ECS_MODULE(world, Name), called from an import action: creates the module entity
    //! ("SimpleModule" -> simple.module) and makes it the scope for what the action creates
    var cdesc : ecs_component_desc_t
    let m = ecs_module_init(world, c_name, unsafe(addr(cdesc)))
    ecs_set_scope(world, m)
    return m
}

def ecs_set_hooks(world : ecs_world_t?; t : auto(TT); var hooks : ecs_type_hooks_t) {
    //! ecs_set_hooks(world, T, {...}): install hooks built with ecs_hooks_* on component TT
    ecs_set_hooks_id(world, ecs_id(world, type<TT>), unsafe(addr(hooks)))
}

def ecs_is_pair_or_flag(id : ecs_id_t; flag : ecs_id_t) : bool {
    //! ECS_HAS_ID_FLAG(id, FLAG): id has the given id flag (ECS_PAIR, ECS_AUTO_OVERRIDE, ...)
    return (id & flag) == flag
}

def ecs_get_by_id(world : ecs_world_t?; e : ecs_entity_t; id : ecs_id_t; t : auto(TT)) : TT const? {
    //! component `id` of e as a TT pointer, for builtin components whose id is not a das
    //! type (ecs_get_by_id(world, u, ecs_id_EcsUnit(), type<EcsUnit>)); null if missing
    unsafe {
        return reinterpret<TT const?>(ecs_get_id(world, e, id))
    }
}

// ── hierarchy ──────────────────────────────────────────────────────────────────

def ecs_children_each(world : ecs_world_t?; parent : ecs_entity_t; blk : block<(child : ecs_entity_t) : void>) {
    //! calls blk for each direct child of parent (ChildOf or Parent storage); parent 0 = roots
    var it = ecs_children(world, parent)
    while (ecs_children_next(unsafe(addr(it)))) {
        for (i in range(it.count)) {
            invoke(blk, ecs_iter_entity(unsafe(addr(it)), i))
        }
    }
}

def ecs_children_each(world : ecs_world_t?; blk : block<(child : ecs_entity_t) : void>) {
    //! calls blk for each root entity
    ecs_children_each(world, 0ul, blk)
}

def ecs_children_array(world : ecs_world_t?; parent : ecs_entity_t) : array<ecs_entity_t> {
    //! direct children of parent as an array
    var res : array<ecs_entity_t>
    ecs_children_each(world, parent) $(child) {
        res |> push(child)
    }
    return <- res
}

def ecs_children_count(world : ecs_world_t?; parent : ecs_entity_t) : int {
    //! number of direct children of parent
    var n = 0
    ecs_children_each(world, parent) $(child) {
        n ++
    }
    return n
}

def ecs_children_each_recursive(world : ecs_world_t?; parent : ecs_entity_t; blk : block<(child : ecs_entity_t) : void>) {
    //! depth-first walk of all descendants of parent; each node is visited before its
    //! children. A level is collected before recursing, so no two flecs iterators are open.
    let level <- ecs_children_array(world, parent)
    for (child in level) {
        invoke(blk, child)
        ecs_children_each_recursive(world, child, blk)
    }
}

def ecs_ordered_children_array(world : ecs_world_t?; parent : ecs_entity_t) : array<ecs_entity_t> {
    //! children of parent in stable order; parent needs the EcsOrderedChildren trait
    //! (Parent-storage children are always ordered)
    var res : array<ecs_entity_t>
    let children = ecs_get_ordered_children(world, parent)
    for (i in range(children.count)) {
        unsafe {
            res |> push(children.ids[i])
        }
    }
    return <- res
}

def ecs_set_children_order(world : ecs_world_t?; parent : ecs_entity_t; var children : array<ecs_entity_t>) {
    //! sets an explicit child order; children must be exactly parent's children
    if (empty(children)) {
        return
    }
    ecs_set_child_order(world, parent, unsafe(addr(children[0])), length(children))
}

def ecs_entity_each(world : ecs_world_t?; e : ecs_entity_t; blk : block<(id : ecs_id_t) : void>) {
    //! calls blk for each id (component, tag, pair) in the entity's type
    let t = ecs_get_type(world, e)
    if (t == null) {
        return
    }
    for (i in range(t.count)) {
        invoke(blk, unsafe(t._array[i]))
    }
}

// ── reflection members (FlecsComponent.member, [ecs_component]) ────────────────

def flecs_primitive_id(name : string) : ecs_entity_t {
    //! flecs primitive type for a das scalar type name ("float" -> ecs_f32_t), 0 if none
    if (name == "bool") {
        return ecs_id_ecs_bool_t
    } elif (name == "int8") {
        return ecs_id_ecs_i8_t
    } elif (name == "int16") {
        return ecs_id_ecs_i16_t
    } elif (name == "int") {
        return ecs_id_ecs_i32_t
    } elif (name == "int64") {
        return ecs_id_ecs_i64_t
    } elif (name == "uint8") {
        return ecs_id_ecs_u8_t
    } elif (name == "uint16") {
        return ecs_id_ecs_u16_t
    } elif (name == "uint") {
        return ecs_id_ecs_u32_t
    } elif (name == "uint64") {
        return ecs_id_ecs_u64_t
    } elif (name == "float") {
        return ecs_id_ecs_f32_t
    } elif (name == "double") {
        return ecs_id_ecs_f64_t
    } elif (name == "string") {
        return ecs_id_ecs_string_t
    }
    return 0ul
}

def private vector_element(name : string) : string {
    // "float3" -> "float", "int2" -> "int", "uint4" -> "uint"
    if (name |> starts_with("float")) {
        return "float"
    } elif (name |> starts_with("uint")) {
        return "uint"
    } elif (name |> starts_with("int")) {
        return "int"
    }
    return ""
}

def flecs_enum_id(world : ecs_world_t?; t : auto(TT)) : ecs_entity_t {
    //! component id of enum TT, with its constants registered (once per world)
    let id = ecs_id(world, type<TT>)
    if (!ecs_has_id(world, id, ecs_id_EcsEnum)) {
        var desc : ecs_enum_desc_t
        desc.entity = id
        var i = 0
        for (v in each(type<TT>)) {
            desc.constants[i].name = string(v)
            desc.constants[i].value = int64(v)
            i ++
        }
        ecs_enum_init(world, unsafe(addr(desc)))
    }
    return id
}

def flecs_meta_type(world : ecs_world_t?; t : auto(TT); var count : int&) : ecs_entity_t {
    //! flecs type entity describing das type TT, for struct members; sets count for
    //! vectors (float3 -> f32 x 3) and fixed arrays (int[4] -> i32 x 4)
    count = 1
    // nested static_if: the elif arms of a static_if are not compile-time branches
    static_if (typeinfo is_dim(type<TT>)) {
        var tmp : TT
        var inner = 1
        let elem = flecs_meta_type(world, tmp[0], inner)
        count = typeinfo dim(type<TT>) * inner
        return elem
    } else {
        static_if (typeinfo is_enum(type<TT>)) {
            return flecs_enum_id(world, type<TT>)
        } else {
            static_if (typeinfo is_struct(type<TT>)) {
                let id = ecs_id(world, type<TT>)
                if (!ecs_has_id(world, id, ecs_id_EcsStruct)) {
                    panic("flecs reflection: member type {typeinfo stripped_typename(type<TT>)} has no reflection data; annotate it with [ecs_component] or describe it with world.component(type<...>).member(...)")
                }
                return id
            } else {
                static_if (typeinfo is_vector(type<TT>)) {
                    count = typeinfo vector_dim(type<TT>)
                    return flecs_primitive_id(vector_element(typeinfo stripped_typename(type<TT>)))
                } else {
                    let id = flecs_primitive_id(typeinfo stripped_typename(type<TT>))
                    if (id == 0ul) {
                        panic("flecs reflection: no flecs type for {typeinfo stripped_typename(type<TT>)}")
                    }
                    return id
                }
            }
        }
    }
}

def flecs_struct_member(world : ecs_world_t?; var desc : ecs_struct_desc_t; index : int; name : string; t : auto(TT); offset : int) {
    //! fills desc.members[index] for a member of das type TT at offset (-1 = let flecs lay it out)
    var count = 1
    desc.members[index].name = name
    desc.members[index]._type = flecs_meta_type(world, type<TT>, count)
    if (count > 1) {
        desc.members[index].count = count
    }
    if (offset >= 0) {
        desc.members[index].offset = offset
        desc.members[index].use_offset = true
    }
}

def flecs_check_field(it : ecs_iter_t const?; index : int; size : int; name : string) {
    //! used by the ecs_each macro: block argument `name` binds field `index` of a prebuilt
    //! query; panics when the query has fewer fields or the field's size differs
    if (index >= int(it.field_count)) {
        panic("ecs_each: argument {name} binds field {index}, but the query has {int(it.field_count)} field(s)")
    }
    let fs = ecs_field_size(it, int8(index))
    if (fs != 0ul && fs != uint64(size)) {
        panic("ecs_each: argument {name} has size {size}, but query field {index} has size {int(fs)}")
    }
}

def flecs_field_ptr(field : auto(TT)?; is_self : bool; index : int) : TT? {
    //! used by the query macros: pointer to the index-th value of a field, or to its single
    //! value when the field is shared (is_self false); null for an unset optional field
    if (field == null) {
        return null
    }
    unsafe {
        return reinterpret<TT?>(field + (is_self ? index : 0))
    }
}
