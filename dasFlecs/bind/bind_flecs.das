options gen2
require cbind/cbind_boost
require daslib/fio
require daslib/defer
require daslib/strings_boost
require daslib/safe_addr
require strings

// Generates dasFlecs/src/* from the flecs C headers (include/flecs.h and its addons).
//
// Run with a daslang that has dasClangBind built:
//   bash manage.sh gen
// Environment:
//   FLECS_INCLUDE  flecs include/ directory (must contain flecs.h)
//   LIBCLANG_DIR   LLVM/libclang root (default C:/Programs/libClang), used for clang resource headers
//
// The header is parsed with the defines the module is compiled with (FLECS_NO_CPP,
// flecs_STATIC, NDEBUG), so struct layouts and the exported symbol set match the Release build.

// Public API headers: flecs.h and every flecs/addons/*.h not in FLECS_SKIP_HEADERS.
// Functions, extern ids and flag macros come only from these; types are taken from every
// flecs header (datastructures, os_api, private), so fields of bound structs resolve.

// Headers nothing is taken from: C++ API, macro-only API, OS API implementation.
let FLECS_SKIP_HEADERS = fixed_array<string>(
    "flecs/addons/flecs_cpp.h",
    "flecs/addons/flecs_c.h",
    "flecs/addons/os_api_impl.h"
)

// das keywords and builtin type names a C field name may collide with
let DAS_KEYWORDS = fixed_array<string>(
    "table", "struct", "class", "variant", "tuple", "bitfield", "enum", "typedef", "def",
    "var", "let", "const", "in", "if", "else", "elif", "for", "while", "return", "break",
    "continue", "pass", "new", "delete", "true", "false", "null", "block", "lambda",
    "function", "iterator", "generator", "yield", "with", "assume", "cast", "upcast",
    "reinterpret", "is", "as", "operator", "module", "require", "options", "expect",
    "static_if", "label", "goto", "unsafe", "finally", "try", "recover", "typeinfo",
    "type", "string", "array", "range", "urange", "int", "uint", "float", "double", "bool",
    "void", "int8", "uint8", "int16", "uint16", "int64", "uint64", "explicit", "implicit",
    "shared", "private", "public", "sealed", "override", "abstract", "template", "inscope"
)

def is_skipped_header(rel : string) : bool {
    for (h in FLECS_SKIP_HEADERS) {
        if (rel == h) {
            return true
        }
    }
    return false
}

def env_or(name, def_value : string) : string {
    if (has_env_variable(name)) {
        let v = get_env_variable(name)
        if (!empty(v)) {
            return v |> replace("\\", "/")
        }
    }
    return def_value
}

def find_module_dir() : string {
    // dasFlecs/ is the parent of the directory holding this script
    var args : array<string>
    builtin_get_command_line_arguments(args)
    for (a in args) {
        let na = a |> replace("\\", "/")
        if (na |> ends_with("bind_flecs.das")) {
            return dir_name(dir_name(get_full_file_name(na) |> replace("\\", "/"))) |> replace("\\", "/")
        }
    }
    panic("can't locate bind_flecs.das on the command line")
    return ""
}

class FlecsGen : CppGenBind {
    override func_to_stdout = false
    override include_local_parse_file = true
    override generate_constant_decl = true
    flecs_include_prefix : string   // "<FLECS_INCLUDE>/", stripped from paths
    flecs_skip_func : table<string; bool>
    flecs_skip_const : table<string; bool>
    flecs_skip_struct : table<string; bool>
    def FlecsGen(module_dir, flecs_include, clang_resource : string) {
        flecs_include_prefix = "{flecs_include}/"
        bind_root = "{module_dir}/src"
        bind_module = "dasFlecs"
        bind_das_module = "flecs"
        let pfn = "cb_dasFlecs.h"
        let pfp = "{module_dir}/src/"
        CONST_FILE_NAMES <- array<string>(
            "{flecs_include}/flecs.h",
            "{flecs_include}/flecs/private/api_flags.h",
            "{flecs_include}/flecs/addons/meta.h",
            "{flecs_include}/flecs/addons/http.h",
            "{flecs_include}/flecs/addons/log.h"
        )
        let args <- array<string>(
            "-xc++-header",
            "-std=c++17",
            "-I{flecs_include}",
            "-isystem{clang_resource}",
            "-DFLECS_NO_CPP",
            "-Dflecs_STATIC",
            "-DNDEBUG",
            "-DDAS_FLECS_BINDER_PARSE=1",      // hide the C++ glue in cb_dasFlecs.h from libclang
            "-D_ALLOW_COMPILER_AND_STL_VERSION_MISMATCH=1"
        )
        func_per_chunk = 50
        super(pfn, pfp, args)
        flecs_skip_func <- {
            "ecs_dummy_" => true
        }
        flecs_skip_const <- {
            "FLECS_H" => true,
            "FLECS_API" => true,
            "FLECS_DBG_API" => true
        }
        flecs_skip_struct <- {
            "ecs_dummy_" => true
        }
        openAllFiles()
    }
    // path relative to FLECS_INCLUDE, "" for files outside it
    def flecs_rel_path(fname : string) : string {
        // addons are included from private/addons.h, so libclang spells them "flecs/private/../addons/x.h"
        let nf = fname |> replace("\\", "/") |> replace("/private/../", "/")
        if (nf |> starts_with(flecs_include_prefix)) {
            return nf |> slice(length(flecs_include_prefix))
        }
        // libclang may report a different spelling of the same root; match on the flecs/ tail
        let pos = find(nf, "/include/flecs")
        if (pos >= 0) {
            return nf |> slice(pos + length("/include/"))
        }
        return ""
    }
    def is_flecs_header(fname : string) : bool {
        let rel = flecs_rel_path(fname)
        return !empty(rel) && !is_skipped_header(rel)
    }
    def is_api_header(fname : string) : bool {
        let rel = flecs_rel_path(fname)
        return rel == "flecs.h" || (rel |> starts_with("flecs/addons/") && is_flecs_header(fname))
    }
    def override clang_getCursorLocationDescription(var c : CXCursor) : string {
        let desc = AnyGenBind`clang_getCursorLocationDescription(self, c) |> replace("\\", "/") |> replace("/private/../", "/")
        return desc |> starts_with(flecs_include_prefix) ? desc |> slice(length(flecs_include_prefix)) : desc
    }
    // C has no nested scopes: `struct ecs_sparse_t { struct ecs_block_allocator_t *a; }`
    // declares a global ecs_block_allocator_t, not ecs_sparse_t::ecs_block_allocator_t.
    def override namespace_name(name : string; dash : string = "::") : string {
        return name
    }
    def override skip_file(fname : string) : bool {
        return !is_flecs_header(fname)
    }
    def override skip_const(name : string) : bool {
        return flecs_skip_const |> key_exists(name)
    }
    def override skip_struct(name : string) {
        return flecs_skip_struct |> key_exists(name)
    }
    def override skip_type(var _c : CXType) {
        var c = clang_getCanonicalType(_c)
        if (c.kind == CXTypeKind.Record) {
            // fields of anonymous struct / union type have no das-visible type
            let sp = string(clang_getTypeSpelling(c))
            if (find(sp, "(unnamed") >= 0 || find(sp, "(anonymous") >= 0) {
                return true
            }
        }
        return AnyGenBind`skip_type(self, _c)
    }
    def override skip_alias(var c : CXCursor) {
        // drop `typedef struct X X` self-aliases
        let tdn = string(clang_getCursorDisplayName(c))
        var tdt = clang_getCanonicalType(clang_getCursorType(c))
        let tdts = string(clang_getTypeSpelling(tdt))
        if (tdts == tdn || tdts == "struct {tdn}" || tdts == "enum {tdn}" || tdts == "union {tdn}") {
            return true
        }
        if (tdt.kind == CXTypeKind.Enum) {
            return true     // typedef enum {...} Name; is registered as the enum itself
        }
        if (tdt.kind == CXTypeKind.Pointer && clang_getPointeeType(tdt).kind == CXTypeKind.FunctionProto) {
            return true     // callback typedefs; functions taking them are skipped anyway
        }
        return !is_flecs_header(clang_getCursorLocationFileName(c))
    }
    // fields named like das keywords (it.table, ...) get a leading underscore: it._table
    def override getBindFldName(field_name : string) : string {
        for (kw in DAS_KEYWORDS) {
            if (field_name == kw) {
                return "_{field_name}"
            }
        }
        return CppGenBind`getBindFldName(self, field_name)
    }
    // `const char *` fields (desc.name, query.expr, ...) would be read-only `string const`
    // in das; descriptors are filled from das, so bind them as writable strings.
    def override substFieldType(var c : CXCursor) : string {
        var t = clang_getCanonicalType(clang_getCursorType(c))
        if (string(clang_getTypeSpelling(t)) == "const char *") {
            return "char *"
        }
        // same for other pointer-to-const fields (event_desc.ids, ...): writable pointers
        if (t.kind == CXTypeKind.Pointer) {
            var pt = clang_getPointeeType(t)
            if (clang_isConstQualifiedType(pt) != 0u && pt.kind != CXTypeKind.FunctionProto && pt.kind != CXTypeKind.Pointer) {
                var upt = clang_getUnqualifiedType(pt)
                let ps = string(clang_getTypeSpelling(clang_getCursorType(c)))
                // keep the typedef spelling (ecs_id_t), minus its const
                if (ps |> starts_with("const ")) {
                    return ps |> slice(6)
                }
                return "{string(clang_getTypeSpelling(upt))} *"
            }
        }
        return CppGenBind`substFieldType(self, c)
    }
    // flecs structs are plain C data: das code creates them as zero-initialized locals
    // (descriptors must start zeroed, _canary == 0) and copies them freely.
    def override isLocalType(name, cppname : string) {
        return true
    }
    def override isTrivialCtorType(name, cppname : string) {
        return true
    }
    def override isCopyableType(name, cppname : string) {
        return true
    }
    def override skip_function(var c : CXCursor) : bool {
        if (AnyGenBind`skip_function(self, c)) {
            return true
        }
        let function_name = string(clang_getCursorSpelling(c))
        if (flecs_skip_func |> key_exists(function_name)) {
            to_log(LOG_INFO, "skipping flecs blocked function {function_name}\n")
            return true
        }
        // flecs_* are internal helpers exported for the C macros and the C++ API
        if (!(function_name |> starts_with("ecs_"))) {
            return true
        }
        let fname = clang_getCursorLocationFileName(c)
        // ecs_map_* / ecs_vec_* are public too (ecs_query_get_groups returns a map,
        // opaque type serializers use vectors)
        let rel = flecs_rel_path(fname)
        if (rel == "flecs/datastructures/map.h" || rel == "flecs/datastructures/vec.h") {
            return false
        }
        return !is_api_header(fname)
    }
}

// ── extern entity ids and flag macros (dasFlecs.extern.*.inc) ──────────────────
// cbind_boost ignores VarDecl and only turns plain integer #defines into constants, so
// flecs' builtin ids (EcsOnUpdate, EcsChildOf, ECS_PAIR, ecs_id(EcsComponent), ...) and its
// flag macros (EcsSelf = (1llu << 63), EcsQueryMatchThis = (1u << 3), ...) are emitted here.
//   extern.add.inc   included from initMain(): addConstant / addExtern calls
//   extern.decl.inc  included at namespace scope in dasFlecs.main.cpp: getters for mutable ids
//
// const ids are compile-time constants in flecs (`FLECS_HI_COMPONENT_ID + 74`), so they become
// das constants. Non-const ids (units, stats/metrics/alerts components) are assigned when their
// addon is imported into a world, so they become zero-argument functions with the same name.

// `FLECS_IDEcsComponentID_` (what ecs_id(EcsComponent) expands to) -> `ecs_id_EcsComponent`
def das_extern_name(cname : string) : string {
    if (cname |> starts_with("FLECS_ID") && cname |> ends_with("ID_")) {
        return "ecs_id_{cname |> slice(8, length(cname) - 3)}"
    }
    return cname
}

def is_ident_char(ch : int) : bool {
    return is_alpha(ch) || is_number(ch) || ch == '_'
}

// identifier tokens of a macro body ("(EcsSelf|EcsUp)" -> ["EcsSelf","EcsUp"]); numeric literals excluded
def body_identifiers(body : string) : array<string> {
    var res : array<string>
    var i = 0
    let n = length(body)
    while (i < n) {
        let ch = character_at(body, i)
        if (is_alpha(ch) || ch == '_') {
            var j = i
            while (j < n && is_ident_char(character_at(body, j))) {
                j ++
            }
            res |> push(body |> slice(i, j))
            i = j
        } elif (is_number(ch)) {
            // skip a numeric literal including its suffix (1llu, 0xFFull)
            while (i < n && is_ident_char(character_at(body, i))) {
                i ++
            }
        } else {
            i ++
        }
    }
    return <- res
}

// a macro body is a constant flag expression: parenthesized, only literals, known flags
// and | << >> ~ operators
def is_flag_body(body : string; known : table<string; bool>) : bool {
    if (!(body |> starts_with("(")) || !(body |> ends_with(")"))) {
        return false
    }
    for (ch in body) {
        if (!(is_ident_char(ch) || ch == '(' || ch == ')' || ch == '|' || ch == '<' || ch == '>' || ch == '~' || ch == ' ')) {
            return false
        }
    }
    let ids <- body_identifiers(body)
    for (id in ids) {
        if (!known |> key_exists(id)) {
            return false
        }
    }
    return true
}

def strip_line_comment(line : string) : string {
    var res = line
    let c1 = find(res, "/*")
    if (c1 >= 0) {
        res = res |> slice(0, c1)
    }
    let c2 = find(res, "//")
    if (c2 >= 0) {
        res = res |> slice(0, c2)
    }
    return strip(res)
}

// clang_getCursorLocationFileName crashes on cursors without a file (compiler builtins).
// Uses the expansion location: ecs_id(T) declarations are spelled inside api_defines.h's
// macro, but expanded in the API header that declares them.
def cursor_file_name(var c : CXCursor) : string {
    var file : CXFile
    var line, column, offset : uint
    clang_getExpansionLocation(clang_getCursorLocation(c), safe_addr(file), safe_addr(line), safe_addr(column), safe_addr(offset))
    if (file == null) {
        return ""
    }
    var res = ""
    peek(clang_getFileName(file)) $(fn) {
        res := fn
    }
    return res
}

// declared in the headers but defined nowhere in flecs (would not link)
let FLECS_SKIP_EXTERN = fixed_array<string>(
    "FLECS_IDEcsPipelineQueryID_"   // flecs.h:1724, stale declaration in 4.2.0
)

struct ExternIds {
    const_ids : array<string>       // C names
    mutable_ids : array<string>
    imports : array<string>         // addon modules: "FlecsUnits" for FlecsUnitsImport
}

def collect_extern_ids(var gen : FlecsGen?) : ExternIds {
    var res : ExternIds
    var seen : table<string; bool>
    var index = clang_createIndex(1, 1)
    var unit = clang_parseTranslationUnit(
        index,
        gen->open_file_name(),
        unsafe(addr(gen.ARGV[0])), length(gen.ARGV),
        null, 0u,
        CXTranslationUnit_SkipFunctionBodies)
    if (unit == null) {
        panic("unable to parse translation unit {gen->open_file_name()}")
    }
    var cursor = clang_getTranslationUnitCursor(unit)
    clang_visitChildren(cursor) $(var c, parent) {
        let kind = clang_getCursorKind(c)
        if (kind == CXCursorKind.LinkageSpec || kind == CXCursorKind.UnexposedDecl) {
            return CXChildVisitResult.Recurse
        }
        if (kind != CXCursorKind.VarDecl && kind != CXCursorKind.FunctionDecl) {
            return CXChildVisitResult.Continue
        }
        if (!gen->is_api_header(cursor_file_name(c))) {
            return CXChildVisitResult.Continue
        }
        if (kind == CXCursorKind.FunctionDecl) {
            // `void FlecsUnitsImport(ecs_world_t *world)` — ECS_IMPORT's module action
            let fname = string(clang_getCursorSpelling(c))
            if (fname |> starts_with("Flecs") && fname |> ends_with("Import") && clang_Cursor_getNumArguments(c) == 1) {
                let mname = fname |> slice(0, length(fname) - 6)
                if (!seen |> key_exists(fname)) {
                    seen[fname] = true
                    res.imports |> push(mname)
                }
            }
            return CXChildVisitResult.Continue
        }
        if (clang_Cursor_getStorageClass(c) != CX_StorageClass.Extern) {
            return CXChildVisitResult.Continue
        }
        var t = clang_getCursorType(c)
        let tn = string(clang_getTypeSpelling(clang_getUnqualifiedType(t)))
        if (tn != "ecs_entity_t" && tn != "ecs_id_t") {
            return CXChildVisitResult.Continue
        }
        let name = string(clang_getCursorSpelling(c))
        if (seen |> key_exists(name)) {
            return CXChildVisitResult.Continue
        }
        for (skip in FLECS_SKIP_EXTERN) {
            if (name == skip) {
                return CXChildVisitResult.Continue
            }
        }
        seen[name] = true
        if (clang_isConstQualifiedType(t) != 0u) {
            res.const_ids |> push(name)
        } else {
            res.mutable_ids |> push(name)
        }
        return CXChildVisitResult.Continue
    }
    clang_disposeTranslationUnit(unit)
    clang_disposeIndex(index)
    return <- res
}

// flag macros, in header order, so a flag combining earlier flags is recognized
def collect_flag_macros(flecs_include : string; skip : table<string; bool>) : array<string> {
    var res : array<string>
    var known : table<string; bool>
    var all_files <- array<string>(
        "{flecs_include}/flecs/private/api_defines.h",
        "{flecs_include}/flecs/private/api_flags.h",
        "{flecs_include}/flecs.h")
    var addons : array<string>
    dir("{flecs_include}/flecs/addons") $(n) {
        if (n |> ends_with(".h") && !is_skipped_header("flecs/addons/{n}")) {
            addons |> push("{flecs_include}/flecs/addons/{n}")
        }
    }
    sort(addons)    // directory order differs per OS; keep the generated file stable
    for (f in addons) {
        all_files |> push(f)
    }
    for (fname in all_files) {
        fopen(fname, "rb") $(f) {
            if (f == null) {
                panic("can't read {fname}")
            }
            let data = fread(f)
            for (raw in split(data, "\n")) {
                let line = strip_line_comment(raw |> replace("\r", ""))
                if (!(line |> starts_with("#define "))) {
                    continue
                }
                let rest = strip(line |> slice(8))
                var sp = 0
                while (sp < length(rest) && is_ident_char(character_at(rest, sp))) {
                    sp ++
                }
                if (sp == 0 || sp >= length(rest) || character_at(rest, sp) != ' ') {
                    continue    // function-like macro or empty define
                }
                let name = rest |> slice(0, sp)
                let body = strip(rest |> slice(sp))
                if (!(name |> starts_with("Ecs") || name |> starts_with("ECS_"))) {
                    continue
                }
                if (skip |> key_exists(name) || known |> key_exists(name)) {
                    continue
                }
                if (is_flag_body(body, known)) {
                    known[name] = true
                    res |> push(name)
                }
            }
        }
    }
    return <- res
}

def write_extern_files(var gen : FlecsGen?; ids : ExternIds; flags : array<string>) {
    var add_file = gen->openFile("{gen.bind_root}/{gen.bind_module}.extern.add.inc")
    var decl_file = gen->openFile("{gen.bind_root}/{gen.bind_module}.extern.decl.inc")
    decl_file |> fwrite("#pragma once\n\n")
    add_file |> fwrite("// builtin ids that are compile-time constants in flecs\n")
    for (name in ids.const_ids) {
        add_file |> fwrite("addConstant(*this,\"{das_extern_name(name)}\",{name});\n")
    }
    add_file |> fwrite("// ids assigned when their addon is imported: functions, read on every call\n")
    for (name in ids.mutable_ids) {
        let dn = das_extern_name(name)
        decl_file |> fwrite("inline ecs_entity_t das_flecs_var_{dn}() \{ return {name}; \}\n")
        add_file |> fwrite("addExtern<DAS_BIND_FUN(das_flecs_var_{dn})>(*this,lib,\"{dn}\",SideEffects::accessExternal,\"das::das_flecs_var_{dn}\");\n")
    }
    add_file |> fwrite("// addon imports: ecs_import_FlecsUnits(world) == ECS_IMPORT(world, FlecsUnits)\n")
    for (mname in ids.imports) {
        decl_file |> fwrite("inline ecs_entity_t das_flecs_import_{mname}(ecs_world_t * world) \{ return ecs_import(world, {mname}Import, \"{mname}\"); \}\n")
        add_file |> fwrite("addExtern<DAS_BIND_FUN(das_flecs_import_{mname})>(*this,lib,\"ecs_import_{mname}\",SideEffects::worstDefault,\"das::das_flecs_import_{mname}\")->args(\{\"world\"\});\n")
    }
    add_file |> fwrite("// flag macros\n")
    for (name in flags) {
        add_file |> fwrite("addConstant(*this,\"{name}\",{name});\n")
    }
    gen->closeFile(add_file)
    gen->closeFile(decl_file)
}

[export]
def main {
    let module_dir = find_module_dir()
    let flecs_include = env_or("FLECS_INCLUDE", "")
    if (empty(flecs_include)) {
        panic("FLECS_INCLUDE is not set")
    }
    let libclang_dir = env_or("LIBCLANG_DIR", "C:/Programs/libClang")
    // clang resource headers (stdarg.h, stdbool.h, ...): pick the single version dir
    var clang_resource = ""
    dir("{libclang_dir}/lib/clang") $(n) {
        if (n != "." && n != ".." && empty(clang_resource)) {
            clang_resource = "{libclang_dir}/lib/clang/{n}/include"
        }
    }
    print("module dir     : {module_dir}\n")
    print("flecs include  : {flecs_include}\n")
    print("clang resource : {clang_resource}\n")
    var cgb = new FlecsGen(module_dir, flecs_include, clang_resource)
    defer() {
        unsafe {
            delete cgb
        }
    }
    cgb->generate()
    let ids <- collect_extern_ids(cgb)
    // names cbind_boost already emitted into dasFlecs.const.inc
    var skip_flags : table<string; bool>
    let flags <- collect_flag_macros(flecs_include, skip_flags)
    write_extern_files(cgb, ids, flags)
    print("generated {cgb.func_chunk_index} function chunk(s) into {module_dir}/src\n")
    print("{length(ids.const_ids)} constant id(s), {length(ids.mutable_ids)} import-time id(s), {length(ids.imports)} addon import(s), {length(flags)} flag macro(s)\n")
}
