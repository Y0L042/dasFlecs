# Generates dasFlecs/flecs/flecs_cpp.das from tools/flecs_cpp.das.in:
#
#     python tools/gen_flecs_cpp.py
#
# Two things are generated:
#   * The term-builder methods (with_, in_, up, cached, ...) are written once below and
#     emitted for FlecsQueryBuilder (acting on qdesc) and for FlecsSystemBuilder and
#     FlecsObserverBuilder (acting on their qb), like the C++ term/query builder mixins.
#   * Arguments that name an id (x, rel, tgt, parent, ...) accept an ecs_entity_t, a
#     FlecsEntity / FlecsComponent / FlecsSystem or `type<T>`. daslang rejects passing a
#     `type<T>` argument on to another function, so each method resolves its id arguments
#     inline: a parameter `p : auto` used as flecs_id_of(world, p) becomes `p : auto(P_T)`,
#     and a marker line `@ID(_p, p, P_T)` is expanded into a static_if dispatch on the
#     argument's type.
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "dasFlecs", "flecs", "flecs_cpp.das")
TEMPLATE = os.path.join(ROOT, "tools", "flecs_cpp.das.in")

# (signature, doc, body) — the body uses QD for the query desc, CUR for the current term
# index and TC for the term count
TERM_METHODS = [
    ("with_(x : auto)", "adds a term for a component type, tag or id (C++ with<T>() / with(id))",
     "QD.terms[TC].id = flecs_id_of(world, x)\nCUR = TC\nTC ++"),
    ("with_(rel : auto; tgt : auto)", "adds a (rel, tgt) pair term",
     "QD.terms[TC].id = ecs_pair(flecs_id_of(world, rel), flecs_id_of(world, tgt))\nCUR = TC\nTC ++"),
    ("without(x : auto)", "adds a Not term (C++ without<T>())",
     "QD.terms[TC].id = flecs_id_of(world, x)\nQD.terms[TC].oper = int16(ecs_oper_kind_t.EcsNot)\nCUR = TC\nTC ++"),
    ("without(rel : auto; tgt : auto)", "adds a Not term for a pair",
     "QD.terms[TC].id = ecs_pair(flecs_id_of(world, rel), flecs_id_of(world, tgt))\nQD.terms[TC].oper = int16(ecs_oper_kind_t.EcsNot)\nCUR = TC\nTC ++"),
    ("term_at(index : int)", "makes term `index` the current term",
     "CUR = index"),
    ("in_()", "current term is read-only (C++ in())", "QD.terms[CUR].inout = int16(ecs_inout_kind_t.EcsIn)"),
    ("out()", "current term is write-only", "QD.terms[CUR].inout = int16(ecs_inout_kind_t.EcsOut)"),
    ("inout()", "current term is read-write", "QD.terms[CUR].inout = int16(ecs_inout_kind_t.EcsInOut)"),
    ("inout_none()", "current term is neither read nor written (filter only)", "QD.terms[CUR].inout = int16(ecs_inout_kind_t.EcsInOutNone)"),
    ("optional()", "current term is optional", "QD.terms[CUR].oper = int16(ecs_oper_kind_t.EcsOptional)"),
    ("not_()", "current term must not match (C++ not_())", "QD.terms[CUR].oper = int16(ecs_oper_kind_t.EcsNot)"),
    ("or_()", "current term is OR-ed with the next one (C++ or_())", "QD.terms[CUR].oper = int16(ecs_oper_kind_t.EcsOr)"),
    ("and_()", "current term is a plain And term", "QD.terms[CUR].oper = int16(ecs_oper_kind_t.EcsAnd)"),
    ("src(e : auto)", "current term matches on a fixed source entity", "QD.terms[CUR].src.id = flecs_id_of(world, e)"),
    ("src(variable : string)", "current term matches on a query variable (\"$var\") or a named entity", "QD.terms[CUR].src.name = variable"),
    ("second(e : auto)", "sets the target of the current term's pair", "QD.terms[CUR].second.id = flecs_id_of(world, e)"),
    ("second(variable : string)", "sets the target of the current term's pair to a variable (\"$var\")", "QD.terms[CUR].second.name = variable"),
    ("self_()", "current term also matches on the entity itself (C++ self())", "QD.terms[CUR].src.id |= EcsSelf"),
    ("up()", "current term matches on an ancestor (ChildOf)", "QD.terms[CUR].src.id |= EcsUp"),
    ("up(rel : auto)", "current term matches by traversing `rel` upwards", "QD.terms[CUR].src.id |= EcsUp\nQD.terms[CUR].trav = flecs_id_of(world, rel)"),
    ("cascade()", "like up(), iterated breadth-first, parents before children", "QD.terms[CUR].src.id |= EcsCascade"),
    ("cascade(rel : auto)", "like up(rel), iterated breadth-first", "QD.terms[CUR].src.id |= EcsCascade\nQD.terms[CUR].trav = flecs_id_of(world, rel)"),
    ("desc()", "with cascade(): iterate children before parents", "QD.terms[CUR].src.id |= EcsDesc"),
    ("trav(rel : auto)", "relationship traversed by up() / cascade()", "QD.terms[CUR].trav = flecs_id_of(world, rel)"),
    ("expr(text : string)", "query DSL expression (\"Position, [in] Velocity\"), combined with the terms", "QD.expr = text"),
    ("cached()", "caches the query (EcsQueryCacheAuto)", "QD.cache_kind = ecs_query_cache_kind_t.EcsQueryCacheAuto"),
    ("cache_kind(kind : ecs_query_cache_kind_t)", "sets the cache kind", "QD.cache_kind = kind"),
    ("detect_changes()", "enables change detection (FlecsQuery.changed)", "QD.flags |= EcsQueryDetectChanges"),
    ("query_flags(flags : uint)", "adds query flags (EcsQueryMatchPrefab, ...)", "QD.flags |= flags"),
    ("group_by(rel : auto)", "groups tables by the target of rel", "QD.group_by = flecs_id_of(world, rel)"),
    ("group_by(rel : auto; var callback : lambda<(world : ecs_world_t?; tbl : ecs_table_t?; id : ecs_id_t) : uint64>)",
     "groups tables with a custom group id callback", "QD.group_by = flecs_id_of(world, rel)\necs_query_desc_group_by(*QD, callback)"),
    ("order_by(t : auto(TT); var compare : lambda<(e1 : ecs_entity_t; p1 : void const?; e2 : ecs_entity_t; p2 : void const?) : int>)",
     "sorts the results by component TT", "QD.order_by = ecs_id(world, type<TT>)\necs_query_desc_order_by(*QD, compare)"),
]

HANDLE_TYPES = ["flecs_cpp::FlecsEntity", "flecs_cpp::FlecsComponent", "flecs_cpp::FlecsSystem"]


def emit_methods(selftype, qd, cur, tc):
    lines = []
    for sig, doc, body in TERM_METHODS:
        lines.append("    [class_method]")
        lines.append(f"    def static {sig} : {selftype} {{")
        lines.append(f"        //! {doc}")
        for l in body.split("\n"):
            lines.append("        " + l.replace("QD", qd).replace("CUR", cur).replace("TC", tc))
        lines.append("        return self")
        lines.append("    }")
        lines.append("")
    return "\n".join(lines)


def id_dispatch(indent, var, param, typ):
    tn = f"typeinfo stripped_typename(type<{typ}>)"
    handles = " || ".join(f'{tn} == "{h}"' for h in HANDLE_TYPES)
    return "\n".join([
        f"{indent}var {var} : ecs_entity_t",
        f'{indent}static_if ({tn} == "uint64") {{',
        f"{indent}    {var} = {param}",
        f"{indent}}} else {{",
        f"{indent}    static_if ({handles}) {{",
        f"{indent}        {var} = {param}.id",
        f"{indent}    }} else {{",
        f"{indent}        {var} = ecs_id(flecs_unconst(world), type<{typ}>)",
        f"{indent}    }}",
        f"{indent}}}",
    ])


def transform_methods(src):
    out = []
    lines = src.split("\n")
    i = 0
    while i < len(lines):
        line = lines[i]
        m = re.match(r"^(\s*)def static (const )?(\w+)\((.*)\)(.*)\{$", line)
        if not m:
            out.append(line)
            i += 1
            continue
        indent = m.group(1)
        j = i + 1
        while not lines[j].startswith(indent + "}"):
            j += 1
        body = lines[i + 1:j]
        params = m.group(4)
        auto_params = re.findall(r"(\w+) : auto(?![\w(])", params)
        used = [p for p in auto_params if any(f"flecs_id_of(world, {p})" in b for b in body)]
        if not used:
            out.extend(lines[i:j + 1])
            i = j + 1
            continue
        for p in used:
            params = re.sub(rf"\b{p} : auto(?![\w(])", f"{p} : auto({p.upper()}_T)", params)
        out.append(f"{indent}def static {m.group(2) or ''}{m.group(3)}({params}){m.group(5)}{{")
        k = 0
        while k < len(body) and body[k].strip().startswith("//!"):
            out.append(body[k])
            k += 1
        for p in used:
            out.append(f"{indent}    @ID(_{p}, {p}, {p.upper()}_T)")
        for b in body[k:]:
            for p in used:
                b = b.replace(f"flecs_id_of(world, {p})", f"_{p}")
            out.append(b)
        out.append(lines[j])
        i = j + 1
    return "\n".join(out)


def expand_ids(src):
    return re.sub(r"^(\s*)@ID\((\w+), (\w+), (\w+)\)$",
                  lambda m: id_dispatch(m.group(1), m.group(2), m.group(3), m.group(4)),
                  src, flags=re.M)


src = open(TEMPLATE, encoding="utf-8").read()
src = src.replace("//@QUERY_TERMS@", emit_methods("FlecsQueryBuilder", "qdesc", "cur", "term_count"))
src = src.replace("//@SYSTEM_TERMS@", emit_methods("FlecsSystemBuilder", "qb.qdesc", "qb.cur", "qb.term_count"))
src = src.replace("//@OBSERVER_TERMS@", emit_methods("FlecsObserverBuilder", "qb.qdesc", "qb.cur", "qb.term_count"))
src = expand_ids(transform_methods(src))
open(OUT, "w", encoding="utf-8", newline="\n").write(src)
print("wrote", OUT)
