options gen2

// Runs every example under dasFlecs/examples/<category>/ and compares its output with the
// "// Output:" comment block at the end of the file (copied from the flecs C example).
//
//   daslang tools/check_examples.das -- [--root <dasFlecs repo>] [--daslang <daslang.exe>] [filter]
//
// Markers an example may carry in a comment line:
//   // example: no-run           do not run (servers, endless loops); only compile-checked
//   // example: output-varies    run, but do not compare (timing, addresses)
// Comparison ignores blank lines and leading/trailing whitespace on each line.

require daslib/fio
require daslib/strings_boost
require strings
require math

def normalize_path(p : string) : string {
    return p |> replace("\\", "/")
}

def collect(dirname : string; var files : array<string>) {
    var names : array<string>
    dir(dirname) $(n) {
        if (n != "." && n != "..") {
            names |> push(n)
        }
    }
    sort(names)
    for (n in names) {
        let full = "{dirname}/{n}"
        if (n |> ends_with(".das")) {
            files |> push(full)
        } else {
            var st : FStat
            if (stat(full, st) && st.is_dir) {
                collect(full, files)
            }
        }
    }
}

def read_text(fname : string) : string {
    var res = ""
    fopen(fname, "rb") $(f) {
        if (f != null) {
            res = fread(f)
        }
    }
    return res
}

def significant_lines(text : string) : array<string> {
    var res : array<string>
    for (raw in split(text |> replace("\r", ""), "\n")) {
        let line = strip(raw)
        if (!empty(line)) {
            res |> push(line)
        }
    }
    return <- res
}

// lines of the "// Output:" block(s): comment lines following the marker, comment prefix removed
def expected_output(source : string; var found : bool&) : array<string> {
    var res : array<string>
    var inside = false
    found = false
    for (raw in split(source |> replace("\r", ""), "\n")) {
        let line = strip(raw)
        if (line == "// Output" || line |> starts_with("// Output:")) {
            inside = true
            found = true
            continue
        }
        if (inside) {
            if (line |> starts_with("//")) {
                let body = strip(line |> slice(2))
                if (!empty(body)) {
                    res |> push(body)
                }
            } else {
                inside = false
            }
        }
    }
    return <- res
}

[export]
def main() {
    var args : array<string>
    builtin_get_command_line_arguments(args)
    var root = "."
    var daslang_exe = normalize_path(get_command_line_arguments()[0])
    var filter = ""
    var after_dashdash = false
    var i = 0
    while (i < length(args)) {
        let a = args[i]
        if (a == "--") {
            after_dashdash = true
        } elif (after_dashdash) {
            if (a == "--root" && i + 1 < length(args)) {
                root = normalize_path(args[i + 1])
                i ++
            } elif (a == "--daslang" && i + 1 < length(args)) {
                daslang_exe = normalize_path(args[i + 1])
                i ++
            } else {
                filter = a
            }
        }
        i ++
    }
    var files : array<string>
    var categories : array<string>
    let examples_dir = "{root}/dasFlecs/examples"
    dir(examples_dir) $(n) {
        if (n != "." && n != "..") {
            categories |> push(n)
        }
    }
    sort(categories)
    for (c in categories) {
        var st : FStat
        if (stat("{examples_dir}/{c}", st) && st.is_dir) {
            collect("{examples_dir}/{c}", files)
        }
    }
    var passed = 0
    var failed = 0
    var skipped = 0
    var failures : array<string>
    for (fname in files) {
        let rel = fname |> slice(length(examples_dir) + 1)
        if (!empty(filter) && find(rel, filter) < 0) {
            continue
        }
        let source = read_text(fname)
        if (find(rel, "/common/") >= 0) {
            continue    // helper modules, not examples
        }
        let no_run = find(source, "// example: no-run") >= 0
        let varies = find(source, "// example: output-varies") >= 0
        var output : string
        var cmd <- [daslang_exe, "-load_module", root, fname]
        if (no_run) {
            // compile only
            cmd <- [daslang_exe, "-load_module", root, "-dry-run", fname]
        }
        let code = run_and_capture(cmd, output, 60.0)
        if (code != 0) {
            print("FAIL {rel} (exit code {code})\n{output}\n")
            failures |> push(rel)
            failed ++
            continue
        }
        if (no_run) {
            print("ok   {rel} (dry run only)\n")
            skipped ++
            continue
        }
        var has_expected = false
        let expected <- expected_output(source, has_expected)
        if (varies || !has_expected) {
            print("ok   {rel} (ran{varies ? ", output varies" : ", no expected output"})\n")
            passed ++
            continue
        }
        let actual <- significant_lines(output)
        var same = length(actual) == length(expected)
        if (same) {
            for (a, e in actual, expected) {
                if (a != e) {
                    same = false
                    break
                }
            }
        }
        if (same) {
            print("ok   {rel}\n")
            passed ++
        } else {
            print("FAIL {rel} (output differs)\n")
            let n = max(length(actual), length(expected))
            for (k in range(n)) {
                let a = k < length(actual) ? actual[k] : "<missing>"
                let e = k < length(expected) ? expected[k] : "<missing>"
                print("  {a == e ? " " : "!"} got: {a}\n")
                if (a != e) {
                    print("    want: {e}\n")
                }
            }
            failures |> push(rel)
            failed ++
        }
    }
    print("\n{passed + failed + skipped} example(s): {passed} passed, {failed} failed, {skipped} compile-only\n")
    for (f in failures) {
        print("  FAILED {f}\n")
    }
    if (failed != 0) {
        unsafe {
            fio::exit(1)
        }
    }
}
