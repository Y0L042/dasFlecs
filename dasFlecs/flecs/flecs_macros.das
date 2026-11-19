options gen2
options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module flecs_macros shared public

//! Typed-block query, system and observer macros, and the [ecs_component] annotation.
//! A block's typed arguments become the query: each component argument is a term and is
//! bound to the matched value, so no field indices or casts are written by hand.
//!
//!     ecs_query(world) $(e : FlecsEntity; var p : Position; v : Velocity) {
//!         p.x += v.x
//!     }
//!
//! Block arguments
//!     p : T                 read-only term ([in]); bound as T const&
//!     var p : T             read-write term ([inout]); bound as T&
//!     p : T?                optional term; null when the entity does not have T
//!     e : FlecsEntity       the matched entity as a handle (no term)
//!     e : ecs_entity_t      the matched entity id (no term)
//!     it : ecs_iter_t const?    the iterator: it.delta_time, it.world, ... (no term)
//!
//! Block annotations
//!     [CACHED]              cached query (EcsQueryCacheAuto)
//!     [REQUIRE(T, U)]       entities must have T and U (filter terms, no binding)
//!     [REQUIRE_NOT(T)]      entities must not have T
//!     [CASCADE(a)]          argument a reads from the parent, breadth-first (parents first)
//!     [CASCADE_DESC(a)]     same, children first
//!     [UP(a)]               argument a reads from the nearest ancestor that has it
//!     [SELF_UP(a)]          argument a reads from the entity, else from an ancestor
//!   Traversal follows ChildOf. A required traversal argument (a : T) drops entities without
//!   such an ancestor, roots included; declare it a : T? to keep them (a is then null).
//!
//! Macros
//!     ecs_query(world [, builder] [, "key"]) $(...) { }   iterate; the query is built once per
//!                               call site (and world), from the block plus an optional
//!                               FlecsQueryBuilder for extra terms. `return` = next entity.
//!     ecs_find_query(...) $(...) { return cond }          bool: true at the first entity where
//!                               cond holds
//!     ecs_each(query) $(...) { }                          iterate a FlecsQuery / ecs_query_t?
//!                               built elsewhere; component arguments bind fields 0, 1, ...
//!     ecs_system(world, "Name", phase) $(...) { }         a flecs system; returns FlecsSystem
//!     ecs_system(world.system("Name").kind(p)...) $(...) { }
//!     ecs_observer(world, event) $(...) { }               a flecs observer; returns FlecsEntity
//!     ecs_observer(world.observer().event(e)...) $(...) { }
//!   System and observer bodies run later, as lambdas: locals they use are captured by copy.
//!   The older forms ecs_query(world, "expr"), ecs_each(world, id) $(it),
//!   ecs_system(world, name, phase, "expr") @(it) and ecs_observer(world, event, "expr") @(it)
//!   still work: they are forwarded to ecs_query_expr / ecs_each_table / ecs_system_expr /
//!   ecs_observer_expr.
//!
//! [ecs_component] on a struct registers its flecs reflection data the first time the
//! component is registered (ecs_id), so JSON, expressions and the explorer see its members.

require daslib/ast_boost
require daslib/templates_boost
require daslib/strings_boost
require daslib/ast_block_to_loop
require daslib/macro_boost

require flecs public
require flecs/flecs_cpp public

// ── block annotations ──────────────────────────────────────────────────────────

[block_macro(name="CACHED")]
class FlecsCached : AstBlockAnnotation {
    //! the block's query is cached (EcsQueryCacheAuto)
}

[block_macro(name="REQUIRE")]
class FlecsRequire : AstBlockAnnotation {
    //! components / tags the entity must have, without binding them
}

[block_macro(name="REQUIRE_NOT")]
class FlecsRequireNot : AstBlockAnnotation {
    //! components / tags the entity must not have
}

[block_macro(name="CASCADE")]
class FlecsCascade : AstBlockAnnotation {
    //! arguments read from the parent, breadth-first, parents before children
}

[block_macro(name="CASCADE_DESC")]
class FlecsCascadeDesc : AstBlockAnnotation {
    //! like CASCADE, children before parents
}

[block_macro(name="UP")]
class FlecsUp : AstBlockAnnotation {
    //! arguments read from the nearest ancestor that has the component
}

[block_macro(name="SELF_UP")]
class FlecsSelfUp : AstBlockAnnotation {
    //! arguments read from the entity, or else from the nearest ancestor
}

// ── argument classification ────────────────────────────────────────────────────

// reports a macro error when cond is false; returns cond so callers can stop
[macro_function]
def private check(cond : bool; at : LineInfo; message : string) : bool {
    if (!cond) {
        macro_error(compiling_program(), at, message)
    }
    return cond
}

[macro_function]
def private type_name_is(t : TypeDeclPtr; name : string) : bool {
    if (t == null) {
        return false
    }
    if (t.baseType == Type.tStructure && t.structType != null) {
        return string(t.structType.name) == name
    }
    if (t.baseType == Type.tHandle && t.annotation != null) {
        return string(t.annotation.name) == name
    }
    return t.baseType == Type.alias && string(t.alias) == name
}

[macro_function]
def private is_handle_arg(a : VariablePtr) : bool {
    return type_name_is(a._type, "FlecsEntity")
}

[macro_function]
def private is_id_arg(a : VariablePtr) : bool {
    return a._type != null && a._type.baseType == Type.tUInt64
}

[macro_function]
def private is_iter_arg(a : VariablePtr) : bool {
    return a._type != null && a._type.baseType == Type.tPointer && type_name_is(a._type.firstType, "ecs_iter_t")
}

[macro_function]
def private is_component_type(t : TypeDeclPtr) : bool {
    return t != null && (t.baseType == Type.tStructure || t.baseType == Type.tHandle || t.baseType == Type.tEnumeration)
}

[macro_function]
def private block_has_annotation(blk : ExprBlock?; name : string) : bool {
    for (ann in blk.annotations) {
        if (ann.annotation.name == name) {
            return true
        }
    }
    return false
}

// bareword annotation arguments ([REQUIRE(Tag)]) parse as tBool true named after the word
[macro_function]
def private annotation_words(blk : ExprBlock?; name : string; var words : array<string>) {
    for (ann in blk.annotations) {
        if (ann.annotation.name == name) {
            for (arg in ann.arguments) {
                if (arg.basicType == Type.tBool && arg.bValue) {
                    words |> push(string(arg.name))
                }
            }
        }
    }
}

[macro_function]
def private block_of(expr : ExprCallMacro?) : ExprBlock? {
    let last = length(expr.arguments) - 1
    if (last < 0 || !(expr.arguments[last] is ExprMakeBlock)) {
        return null
    }
    let mb = expr.arguments[last] as ExprMakeBlock
    if (mb.mmFlags.isLambda) {
        return null
    }
    return mb._block as ExprBlock
}

// true when the call's last argument is a $ block whose arguments all have explicit types:
// the typed-block form. Anything else is an older call form, forwarded to a function.
[macro_function]
def private is_typed_block_form(expr : ExprCallMacro?) : bool {
    let blk = block_of(expr)
    if (blk == null || empty(blk.arguments)) {
        return false
    }
    for (a in blk.arguments) {
        if (a._type == null || a._type.isAuto) {
            return false
        }
    }
    return true
}

[macro_function]
def private forward_call(expr : ExprCallMacro?; fn_name : string) : ExpressionPtr {
    var call = new ExprCall(at = expr.at, name := fn_name)
    for (a in expr.arguments) {
        call.arguments |> push(clone_expression(a))
    }
    return call
}

// non-const component arguments are bound by reference; done before inference
[macro_function]
def private force_ref_on_block_args(var expr : ExprCallMacro?) {
    let last = length(expr.arguments) - 1
    if (last < 0 || !(expr.arguments[last] is ExprMakeBlock)) {
        return
    }
    var mb = expr.arguments[last] as ExprMakeBlock
    var blk = mb._block as ExprBlock
    for (a in blk.arguments) {
        if (a._type != null && !a._type.isAuto && !is_id_arg(a) && !is_handle_arg(a)
                && a._type.baseType != Type.tPointer && !a._type.flags.constant) {
            a._type.flags.ref = true
        }
    }
}

// ── lowering ───────────────────────────────────────────────────────────────────

enum private LowerMode {
    query      // ecs_query: cached per call site, iterate now
    find       // ecs_find_query: like query, yields bool
    each       // ecs_each: iterate a prebuilt query
    system     // ecs_system: flecs system
    observer   // ecs_observer: flecs observer
}

struct private Lowering {
    lead_chain : ExpressionPtr          // FlecsQueryBuilder(world = _w).with_(...)... (block terms)
    per_batch : ExprBlock?              // field getters + entity loop
    field_checks : array<ExpressionPtr> // ecs_each: flecs_check_field calls
    cached : bool
}

// Find mode: marks each `return true` that convert_block_to_loop generated with
// `hit = true` first. A daslang block that returns from a `for` nested in a `while`
// leaves only the `for`: the `while` condition runs again. The find skeleton tests
// `!hit` in that condition, so the iterator is not advanced past the match.
class private FlecsMarkHit : AstVisitor {
    hit_var : string
    in_closure : int
    def override preVisitExprBlock(blk : ExprBlock?) : void {
        if (blk.blockFlags.isClosure) {
            in_closure ++
        }
    }
    def override visitExprBlock(var blk : ExprBlock?) : ExpressionPtr {
        if (blk.blockFlags.isClosure) {
            in_closure --
        }
        return <- blk
    }
    def override visitExprReturn(var expr : ExprReturn?) : ExpressionPtr {
        if (in_closure != 0 || expr.subexpr == null || !(expr.subexpr is ExprConstBool)) {
            return <- expr
        }
        var marked = new ExprBlock(at = expr.at)
        marked.list |> emplace_new() <| new ExprCopy(at = expr.at,
            left = new ExprVar(at = expr.at, name := hit_var),
            right = new ExprConstBool(at = expr.at, value = true))
        marked.list |> emplace(expr)
        return <- marked
    }
}

[macro_function]
def private mark_hits(var blk : Expression?; hit_var : string) {
    var visitor = new FlecsMarkHit(hit_var = hit_var)
    make_visitor(*visitor) $(adapter) {
        visit(blk, adapter)
    }
    unsafe {
        delete visitor
    }
}

// Builds the block's terms (lead_chain, starting from `builder_world_expr`) and the
// per-batch body that binds the block arguments, reading the iterator pointer `itp`.
[macro_function]
def private lower_block(var expr : ExprCallMacro?; query_block : ExprBlock?; mode : LowerMode;
                        builder_world_expr : ExpressionPtr; itp : string; suffix : string; var res : Lowering) : bool {
    let index_var = "_flecs_i{suffix}"
    var traversal : table<string; string>
    for (kind in fixed_array("CASCADE", "CASCADE_DESC", "UP", "SELF_UP")) {
        var words : array<string>
        annotation_words(query_block, kind, words)
        for (w in words) {
            traversal[w] = kind
        }
    }
    var traversal_seen : table<string; bool>
    var per_entity = new ExprBlock(at = query_block.at)
    res.per_batch = new ExprBlock(at = query_block.at)
    unsafe {
        res.lead_chain = qmacro(FlecsQueryBuilder(world = $e(builder_world_expr)))
    }
    var have_entity = false
    var field_count = 0
    for (a in query_block.arguments) {
        let arg_name = string(a.name)
        if (!check(a._type != null && !a._type.isAuto, a.at, "argument {arg_name} needs an explicit type")) {
            return false
        }
        // entity, id and iterator arguments: bound per entity, no query term
        if (is_handle_arg(a) || is_id_arg(a) || is_iter_arg(a)) {
            var init : ExpressionPtr
            unsafe {
                if (is_iter_arg(a)) {
                    init = qmacro(reinterpret<$t(a._type)>($i(itp)))
                } else {
                    var raw = qmacro($i(itp).entities[$i(index_var)])
                    raw.genFlags.alwaysSafe = true
                    force_generated(raw, true)
                    if (is_handle_arg(a)) {
                        if (!check(!have_entity, a.at, "only one entity argument is allowed")) {
                            return false
                        }
                        have_entity = true
                        init = qmacro(flecs_entity($i(itp).world, $e(raw)))
                    } else {
                        if (!check(!have_entity, a.at, "only one entity argument is allowed")) {
                            return false
                        }
                        have_entity = true
                        init = raw
                    }
                }
            }
            init.genFlags.alwaysSafe = true
            force_generated(init, true)
            var t = clone_type(a._type)
            t.flags.ref = false
            var decl = new ExprLet(at = a.at, atInit = a.at)
            decl.genFlags.alwaysSafe = true
            decl.variables |> emplace_new() <| new Variable(at = a.at, name := arg_name, _type <- t, init <- init,
                flags = VariableFlags.can_shadow | VariableFlags.generated)
            per_entity.list |> emplace(decl)
            continue
        }
        // component argument: T / var T / T?
        let optional = a._type.baseType == Type.tPointer
        let comp_type_src = optional ? a._type.firstType : a._type
        if (!check(is_component_type(comp_type_src), a.at,
                "argument {arg_name} must be a component (struct, handled type or enum), T? for an optional one, FlecsEntity, ecs_entity_t or ecs_iter_t const?")) {
            return false
        }
        let readonly = optional ? comp_type_src.flags.constant : a._type.flags.constant
        let k = field_count
        field_count ++
        var term_type = clone_type(comp_type_src)
        term_type.flags.constant = false
        term_type.flags.ref = false
        let kind = traversal?[arg_name] ?? ""
        if (!empty(kind)) {
            traversal_seen[arg_name] = true
        }
        unsafe {
            res.lead_chain = qmacro($e(res.lead_chain).with_(type<$t(term_type)>))
            res.lead_chain = readonly ? qmacro($e(res.lead_chain).in_()) : qmacro($e(res.lead_chain).inout())
            if (kind == "CASCADE") {
                res.lead_chain = qmacro($e(res.lead_chain).cascade())
            } elif (kind == "CASCADE_DESC") {
                res.lead_chain = qmacro($e(res.lead_chain).cascade().desc())
            } elif (kind == "UP") {
                res.lead_chain = qmacro($e(res.lead_chain).up())
            } elif (kind == "SELF_UP") {
                res.lead_chain = qmacro($e(res.lead_chain).self_().up())
            }
            if (optional) {
                res.lead_chain = qmacro($e(res.lead_chain).optional())
            }
        }
        // per batch: var _flecs_fK = ecs_field(itp, type<T>, K); let _flecs_sK = is_self
        let field_var = "_flecs_f{k}{suffix}"
        let self_var = "_flecs_s{k}{suffix}"
        var field_get : ExpressionPtr
        var self_get : ExpressionPtr
        unsafe {
            field_get = qmacro(ecs_field($i(itp), type<$t(term_type)>, $v(k)))
            self_get = qmacro(ecs_field_is_self($i(itp), int8($v(k))))
        }
        field_get.genFlags.alwaysSafe = true
        force_generated(field_get, true)
        force_generated(self_get, true)
        var field_ptr_type = new TypeDecl(at = a.at, baseType = Type.tPointer)
        field_ptr_type.firstType = clone_type(term_type)
        var fdecl = new ExprLet(at = a.at, atInit = a.at)
        fdecl.genFlags.alwaysSafe = true
        fdecl.variables |> emplace_new() <| new Variable(at = a.at, name := field_var, _type <- field_ptr_type, init <- field_get,
            flags = VariableFlags.can_shadow | VariableFlags.generated)
        fdecl.variables |> emplace_new() <| new Variable(at = a.at, name := self_var, _type <- new TypeDecl(at = a.at, baseType = Type.tBool), init <- self_get,
            flags = VariableFlags.can_shadow | VariableFlags.generated)
        res.per_batch.list |> emplace(fdecl)
        if (mode == LowerMode.each) {
            unsafe {
                res.field_checks |> push(qmacro(flecs_check_field($i(itp), $v(k), typeinfo sizeof(type<$t(term_type)>), $v(arg_name))))
            }
        }
        // per entity: shared fields (inherited, traversed, singleton) hold one value
        var elem : ExpressionPtr
        var binding_type : TypeDeclPtr
        unsafe {
            elem = qmacro($i(field_var)[$i(self_var) ? $i(index_var) : 0])
            elem.genFlags.alwaysSafe = true
            force_generated(elem, true)
            if (optional) {
                var opt = qmacro(flecs_field_ptr($i(field_var), $i(self_var), $i(index_var)))
                force_generated(opt, true)
                elem = opt
                binding_type = clone_type(a._type)
                binding_type.flags.ref = false
            } else {
                binding_type = clone_type(a._type)
                binding_type.flags.ref = true
            }
        }
        var bdecl = new ExprLet(at = a.at, atInit = a.at)
        bdecl.genFlags.alwaysSafe = true
        bdecl.variables |> emplace_new() <| new Variable(at = a.at, name := arg_name, _type <- binding_type, init <- elem,
            flags = VariableFlags.can_shadow | VariableFlags.generated)
        per_entity.list |> emplace(bdecl)
    }
    if (!check(field_count > 0 || mode != LowerMode.each, expr.at, "ecs_each: the block needs at least one component argument")) {
        return false
    }
    for (name, kind in keys(traversal), values(traversal)) {
        if (!check(key_exists(traversal_seen, name), expr.at, "{kind} names unknown block argument '{name}'")) {
            return false
        }
    }
    // filter-only terms and options
    unsafe {
        var required : array<string>
        annotation_words(query_block, "REQUIRE", required)
        for (tag in required) {
            var tag_type = new TypeDecl(at = expr.at, baseType = Type.alias, alias := tag)
            res.lead_chain = qmacro($e(res.lead_chain).with_(type<$t(tag_type)>).inout_none())
        }
        var excluded : array<string>
        annotation_words(query_block, "REQUIRE_NOT", excluded)
        for (tag in excluded) {
            var tag_type = new TypeDecl(at = expr.at, baseType = Type.alias, alias := tag)
            res.lead_chain = qmacro($e(res.lead_chain).without(type<$t(tag_type)>))
        }
    }
    res.cached = block_has_annotation(query_block, "CACHED")
    // the user's statements run after the bindings; `return` moves to the next entity
    // (find mode: `return cond` stops with true when cond holds)
    for (stmt in query_block.list) {
        per_entity.list |> push(clone_expression(stmt))
    }
    for (stmt in query_block.finalList) {
        per_entity.finalList |> push(clone_expression(stmt))
    }
    convert_block_to_loop(per_entity, false, true, mode == LowerMode.find)
    if (mode == LowerMode.find) {
        mark_hits(per_entity, "_flecs_hit{suffix}")
    }
    var loop = new ExprFor(at = query_block.at, visibility = query_block.at)
    loop.allowIteratorOptimization = true
    loop.canShadow = true
    loop.iterators |> resize(1)
    loop.iterators[0] := index_var
    loop.iteratorsAka |> resize(1)
    loop.iteratorsAka[0] := ""
    loop.iteratorsAt |> push(query_block.at)
    loop.iteratorsTags |> resize(1)
    unsafe {
        loop.sources |> emplace_new() <| qmacro(range($i(itp).count))
    }
    loop.body = per_entity
    res.per_batch.list |> emplace(loop)
    return true
}

[macro_function]
def private site_suffix(expr : ExprCallMacro?) : string {
    return "_{expr.at.line}_{expr.at.column}"
}

[macro_function]
def private finish(var skeleton : ExpressionPtr; expr : ExprCallMacro?) : ExpressionPtr {
    var expansion = move_unquote_block(skeleton)
    expansion |> force_at(expr.at)
    expansion.genFlags.alwaysSafe = true
    return expansion
}

// ecs_query / ecs_find_query: (world [, builder] [, "key"]) $(...)
[macro_function]
def private lower_query(var expr : ExprCallMacro?; find : bool) : ExpressionPtr {
    let nargs = length(expr.arguments) - 1    // without the block
    let what = find ? "ecs_find_query" : "ecs_query"
    if (!check(nargs >= 1 && nargs <= 3, expr.at, "expecting {what}(world [, builder] [, \"key\"]) $(typed arguments) \{ ... \}")) {
        return null
    }
    var site_key = "{compiling_module().name}:{expr.at.line}:{expr.at.column}"
    var builder_expr : ExpressionPtr
    for (i in range(1, nargs)) {
        let a = expr.arguments[i]
        if (a is ExprConstString) {
            site_key = "{(a as ExprConstString).value}"
        } else {
            if (!check(builder_expr == null, a.at, "{what}: expecting at most one builder argument")) {
                return null
            }
            builder_expr = clone_expression(a)
        }
    }
    let suffix = site_suffix(expr)
    let itp = "_flecs_itp{suffix}"
    let world_var = "_flecs_w{suffix}"
    var low : Lowering
    var world_ref : ExpressionPtr
    unsafe {
        world_ref = qmacro($i(world_var))
    }
    if (!lower_block(expr, block_of(expr), find ? LowerMode.find : LowerMode.query, world_ref, itp, suffix, low)) {
        return null
    }
    var user_builder : ExpressionPtr
    unsafe {
        user_builder = builder_expr != null ? qmacro(flecs_qb($e(builder_expr))) : qmacro(FlecsQueryBuilder(world = $i(world_var)))
    }
    var built : ExpressionPtr
    unsafe {
        built = qmacro(flecs_qb_prepend($e(user_builder), $e(low.lead_chain)))
        if (low.cached) {
            built = qmacro($e(built).cached())
        }
        built = qmacro($e(built).build().query)
    }
    var skeleton : ExpressionPtr
    unsafe {
        if (find) {
            skeleton = quote() {
                invoke() $() : bool {
                    var tag_world_var = flecs_world_ptr(tag_world)
                    var _flecs_q = _flecs_query_get(tag_world_var, tag_key) $() : ecs_query_t? {
                        return tag_built
                    }
                    var _flecs_it = ecs_query_iter(tag_world_var, _flecs_q)
                    // a match stops the loop early: finish the iterator then
                    var _flecs_hit = false
                    let _flecs_found = invoke() $() : bool {
                        while (!_flecs_hit && ecs_query_next(unsafe(addr(_flecs_it)))) {
                            var tag_itp = unsafe(addr(_flecs_it))
                            tag_batch
                        }
                        return _flecs_hit
                    }
                    if (_flecs_found) {
                        ecs_iter_fini(unsafe(addr(_flecs_it)))
                    }
                    return _flecs_found
                }
            }
        } else {
            skeleton = quote() {
                var tag_world_var = flecs_world_ptr(tag_world)
                var _flecs_q = _flecs_query_get(tag_world_var, tag_key) $() : ecs_query_t? {
                    return tag_built
                }
                var _flecs_it = ecs_query_iter(tag_world_var, _flecs_q)
                while (ecs_query_next(unsafe(addr(_flecs_it)))) {
                    var tag_itp = unsafe(addr(_flecs_it))
                    tag_batch
                }
            }
        }
    }
    skeleton |> force_at(expr.at)
    apply_template(skeleton) $(rules) {
        rules |> replaceVariable("tag_world") <| clone_expression(expr.arguments[0])
        rules |> replaceVariable("tag_key") <| new ExprConstString(at = expr.at, value := site_key)
        rules |> replaceVariable("tag_built") <| built
        rules |> replaceVariable("tag_batch") <| low.per_batch
        rules |> renameVariable("tag_world_var", world_var)
        rules |> renameVariable("tag_itp", itp)
        rules |> renameVariable("_flecs_q", "_flecs_q{suffix}")
        rules |> renameVariable("_flecs_it", "_flecs_it{suffix}")
        rules |> renameVariable("_flecs_found", "_flecs_found{suffix}")
        rules |> renameVariable("_flecs_hit", "_flecs_hit{suffix}")
    }
    var expansion = finish(skeleton, expr)
    if (find) {
        var single = (expansion as ExprBlock).list[0]
        single.genFlags.alwaysSafe = true
        return single
    }
    return expansion
}

// ecs_each: (query) $(...)
[macro_function]
def private lower_each(var expr : ExprCallMacro?) : ExpressionPtr {
    if (!check(length(expr.arguments) == 2, expr.at, "expecting ecs_each(query) $(typed arguments) \{ ... \}")) {
        return null
    }
    let suffix = site_suffix(expr)
    let itp = "_flecs_itp{suffix}"
    var low : Lowering
    var dummy_world : ExpressionPtr
    unsafe {
        dummy_world = qmacro(null)
    }
    if (!lower_block(expr, block_of(expr), LowerMode.each, dummy_world, itp, suffix, low)) {
        return null
    }
    var checks = new ExprBlock(at = expr.at)
    for (c in low.field_checks) {
        checks.list |> push(c)
    }
    var skeleton : ExpressionPtr
    unsafe {
        skeleton = quote() {
            var _flecs_qq = tag_query
            var _flecs_it = ecs_query_iter(flecs_query_world(_flecs_qq), flecs_query_ptr(_flecs_qq))
            var _flecs_checked = false
            while (ecs_query_next(unsafe(addr(_flecs_it)))) {
                var tag_itp = unsafe(addr(_flecs_it))
                if (!_flecs_checked) {
                    tag_checks
                    _flecs_checked = true
                }
                tag_batch
            }
        }
    }
    skeleton |> force_at(expr.at)
    apply_template(skeleton) $(rules) {
        rules |> replaceVariable("tag_query") <| clone_expression(expr.arguments[0])
        rules |> replaceVariable("tag_checks") <| checks
        rules |> replaceVariable("tag_batch") <| low.per_batch
        rules |> renameVariable("tag_itp", itp)
        rules |> renameVariable("_flecs_qq", "_flecs_qq{suffix}")
        rules |> renameVariable("_flecs_it", "_flecs_it{suffix}")
        rules |> renameVariable("_flecs_checked", "_flecs_checked{suffix}")
    }
    return finish(skeleton, expr)
}

// ecs_system: (world, "Name", phase) $(...) or (system builder) $(...)
// ecs_observer: (world, event) $(...) or (observer builder) $(...)
[macro_function]
def private lower_callback(var expr : ExprCallMacro?; is_system : bool) : ExpressionPtr {
    let nargs = length(expr.arguments) - 1
    let what = is_system ? "ecs_system" : "ecs_observer"
    let usage = is_system ? "ecs_system(world, \"Name\", phase) or ecs_system(world.system(\"Name\")...)" : "ecs_observer(world, event) or ecs_observer(world.observer()...)"
    if (!check(is_system ? (nargs == 1 || nargs == 3) : (nargs == 1 || nargs == 2), expr.at, "expecting {usage} followed by $(typed arguments) \{ ... \}")) {
        return null
    }
    let suffix = site_suffix(expr)
    let itp = "_flecs_itp{suffix}"
    let builder_var = "_flecs_b{suffix}"
    var low : Lowering
    var builder_world : ExpressionPtr
    unsafe {
        builder_world = qmacro($i(builder_var).world)
    }
    if (!lower_block(expr, block_of(expr), is_system ? LowerMode.system : LowerMode.observer, builder_world, itp, suffix, low)) {
        return null
    }
    var make_builder = new ExprCall(at = expr.at, name := is_system ? "flecs_sb" : "flecs_ob")
    for (i in range(nargs)) {
        make_builder.arguments |> push(clone_expression(expr.arguments[i]))
    }
    var merged : ExpressionPtr
    unsafe {
        merged = qmacro(flecs_qb_prepend($i(builder_var).qb, $e(low.lead_chain)))
        if (low.cached) {
            merged = qmacro($e(merged).cached())
        }
    }
    var skeleton : ExpressionPtr
    unsafe {
        if (is_system) {
            skeleton = quote() {
                invoke() $() : FlecsSystem {
                    var tag_builder = tag_make_builder
                    tag_builder.qb = tag_merged
                    return tag_builder.iter() @(tag_itp : ecs_iter_t const?) {
                        tag_batch
                    }
                }
            }
        } else {
            skeleton = quote() {
                invoke() $() : FlecsEntity {
                    var tag_builder = tag_make_builder
                    tag_builder.qb = tag_merged
                    return tag_builder.iter() @(tag_itp : ecs_iter_t const?) {
                        tag_batch
                    }
                }
            }
        }
    }
    skeleton |> force_at(expr.at)
    apply_template(skeleton) $(rules) {
        rules |> replaceVariable("tag_make_builder") <| make_builder
        rules |> replaceVariable("tag_merged") <| merged
        rules |> replaceVariable("tag_batch") <| low.per_batch
        rules |> renameVariable("tag_builder", builder_var)
        rules |> renameVariable("tag_itp", itp)
    }
    var expansion = finish(skeleton, expr)
    var single = (expansion as ExprBlock).list[0]
    single.genFlags.alwaysSafe = true
    return single
}

// ── call macros ────────────────────────────────────────────────────────────────

class private FlecsBlockMacro : AstCallMacro {
    // older call forms carry untyped blocks ($(it)) or lambdas (@(it)); leave those arguments
    // uninferred so the call can be forwarded to the matching function as written
    def override canVisitArgument(expr : ExprCallMacro?; argIndex : int) : bool {
        let last = length(expr.arguments) - 1
        if (argIndex == last && expr.arguments[last] is ExprMakeBlock) {
            return is_typed_block_form(expr)
        }
        return true
    }
    def override preVisit(prog : ProgramPtr; mod : Module?; var expr : ExprCallMacro?) : void {
        if (is_typed_block_form(expr)) {
            force_ref_on_block_args(expr)
        }
    }
}

[call_macro(name="ecs_query")]
class FlecsQueryMacro : FlecsBlockMacro {
    //! ecs_query(world [, builder] [, "key"]) $(typed arguments) { ... }; also forwards
    //! ecs_query(world, "expr") to ecs_query_expr
    def override visit(prog : ProgramPtr; mod : Module?; var expr : ExprCallMacro?) : ExpressionPtr {
        if (!is_typed_block_form(expr)) {
            return forward_call(expr, "ecs_query_expr")
        }
        return lower_query(expr, false)
    }
}

[call_macro(name="ecs_find_query")]
class FlecsFindQueryMacro : FlecsBlockMacro {
    //! ecs_find_query(world [, builder] [, "key"]) $(typed arguments) { return cond }: bool
    def override visit(prog : ProgramPtr; mod : Module?; var expr : ExprCallMacro?) : ExpressionPtr {
        if (!check(is_typed_block_form(expr), expr.at, "expecting ecs_find_query(world) $(typed arguments) \{ return cond \}")) {
            return null
        }
        return lower_query(expr, true)
    }
}

[call_macro(name="ecs_each")]
class FlecsEachMacro : FlecsBlockMacro {
    //! ecs_each(query) $(typed arguments) { ... }; also forwards ecs_each(world, id) $(it)
    //! to ecs_each_table
    def override visit(prog : ProgramPtr; mod : Module?; var expr : ExprCallMacro?) : ExpressionPtr {
        if (!is_typed_block_form(expr) || length(expr.arguments) != 2) {
            return forward_call(expr, "ecs_each_table")
        }
        return lower_each(expr)
    }
}

[call_macro(name="ecs_system")]
class FlecsSystemMacro : FlecsBlockMacro {
    //! ecs_system(world, "Name", phase) $(typed arguments) { ... }: FlecsSystem; also forwards
    //! ecs_system(world, name, phase, "expr") @(it) to ecs_system_expr
    def override visit(prog : ProgramPtr; mod : Module?; var expr : ExprCallMacro?) : ExpressionPtr {
        if (!is_typed_block_form(expr)) {
            return forward_call(expr, "ecs_system_expr")
        }
        return lower_callback(expr, true)
    }
}

[call_macro(name="ecs_observer")]
class FlecsObserverMacro : FlecsBlockMacro {
    //! ecs_observer(world, event) $(typed arguments) { ... }: FlecsEntity; also forwards
    //! ecs_observer(world, [name,] event, "expr") @(it) to ecs_observer_expr
    def override visit(prog : ProgramPtr; mod : Module?; var expr : ExprCallMacro?) : ExpressionPtr {
        if (!is_typed_block_form(expr)) {
            return forward_call(expr, "ecs_observer_expr")
        }
        return lower_callback(expr, false)
    }
}

// ── [ecs_component] ────────────────────────────────────────────────────────────

[macro_function]
def private reflectable_field(t : TypeDeclPtr) : bool {
    if (t == null) {
        return false
    }
    let bt = t.baseType
    return !(bt == Type.tPointer || bt == Type.tArray || bt == Type.tTable || bt == Type.tLambda
        || bt == Type.tBlock || bt == Type.tFunction || bt == Type.tIterator || bt == Type.tTuple
        || bt == Type.tVariant || bt == Type.tBitfield)
}

[structure_macro(name="ecs_component")]
class FlecsComponentAnnotation : AstStructureAnnotation {
    //! registers the struct's flecs reflection data (members, their types and offsets) when
    //! the component is first registered with ecs_id / FlecsWorld.component / ecs_set / ...
    //! Supported member types: bool, int8..int64, uint8..uint64, float, double, string,
    //! float2/3/4, int2/3/4, uint2/3/4, fixed arrays, enums, and [ecs_component] structs.
    def override apply(var st : StructurePtr; var group : ModuleGroup; var args : AnnotationArgumentList; var errors : das_string) : bool {
        if (length(st.fields) > 32) {
            errors := "[ecs_component] {st.name}: flecs reflection supports at most 32 members"
            return false
        }
        var members : array<ExpressionPtr>
        for (index, fld in iter_range(st.fields), st.fields) {
            if (!reflectable_field(fld._type)) {
                errors := "[ecs_component] {st.name}.{fld.name}: member type {describe(fld._type)} can't be reflected (pointers, dynamic arrays, tables, lambdas and tuples have no flecs equivalent)"
                return false
            }
            var ftype = clone_type(fld._type)
            ftype.flags.constant = false
            ftype.flags.ref = false
            unsafe {
                members |> push(qmacro(flecs_struct_member(world, desc, $v(index), $v(string(fld.name)), type<$t(ftype)>,
                    int(intptr(addr(tmp.$f(fld.name))) - intptr(addr(tmp))))))
            }
        }
        var fn = qmacro_function("flecs_reflect_component") $(world : ecs_world_t?; id : ecs_entity_t; dummy : $t(st)?) {
            var desc : ecs_struct_desc_t
            var tmp : $t(st)
            desc.entity = id
            unsafe {
                $b(members)
            }
            ecs_struct_init(world, unsafe(addr(desc)))
        }
        fn.flags |= FunctionFlags.generated
        if (!(compiling_module() |> add_function(fn))) {
            errors := "[ecs_component] {st.name}: can't add flecs_reflect_component"
            return false
        }
        return true
    }
}
