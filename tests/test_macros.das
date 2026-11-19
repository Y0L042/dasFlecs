options gen2

// flecs_macros: typed-block ecs_query / ecs_find_query / ecs_each / ecs_system / ecs_observer.
require dastest/testing_boost public
require flecs/flecs_boost

struct Position {
    x : float
    y : float
}

struct Velocity {
    x : float
    y : float
}

struct Enemy {
    hp : int
}

struct Frozen {
    dummy : int
}

// system / observer bodies are lambdas: locals are copied, so they report through globals
var g_order : array<string>
var g_observed = 0
var g_dt = 0.0

[test]
def test_query_arguments(t : T?) {
    t |> run("in / inout / entity / handle / iterator") @(t : T?) {
        var w = FlecsWorld()
        let a = w.entity("a").set(Position(x = 1.0, y = 1.0)).set(Velocity(x = 2.0, y = 3.0))
        w.entity("b").set(Position(x = 5.0, y = 5.0))
        var n = 0
        ecs_query(w) $(id : ecs_entity_t; v : Velocity) {
            t |> equal(id, a.id)
        }
        ecs_query(w) $(h : FlecsEntity; it : ecs_iter_t const?; var p : Position; v : Velocity) {
            t |> equal(h.name(), "a")
            t |> success(it.world != null)
            p.x += v.x
            p.y += v.y
            n ++
        }
        t |> equal(n, 1)
        t |> equal(a.get(type<Position>).x, 3.0)
        t |> equal(a.get(type<Position>).y, 4.0)
        w.fini()
    }
    t |> run("optional argument") @(t : T?) {
        var w = FlecsWorld()
        w.entity("a").set(Position()).set(Velocity(x = 7.0))
        w.entity("b").set(Position())
        var with_v = 0
        var without_v = 0
        ecs_query(w) $(p : Position; v : Velocity?) {
            if (v != null) {
                t |> equal(v.x, 7.0)
                with_v ++
            } else {
                without_v ++
            }
        }
        t |> equal(with_v, 1)
        t |> equal(without_v, 1)
        w.fini()
    }
    t |> run("raw world pointer") @(t : T?) {
        var world = ecs_init()
        ecs_set(world, ecs_new(world), Position(x = 4.0))
        var sum = 0.0
        ecs_query(world) $(p : Position) {
            sum += p.x
        }
        t |> equal(sum, 4.0)
        flecs_fini(world)
    }
    t |> run("return skips to the next entity") @(t : T?) {
        var w = FlecsWorld()
        for (i in range(5)) {
            w.entity().set(Position(x = float(i)))
        }
        var n = 0
        ecs_query(w) $(p : Position) {
            if (p.x < 2.0) {
                return
            }
            n ++
        }
        t |> equal(n, 3)
        w.fini()
    }
}

[test]
def test_block_annotations(t : T?) {
    t |> run("REQUIRE / REQUIRE_NOT / CACHED") @(t : T?) {
        var w = FlecsWorld()
        w.entity("e1").set(Position()).set(Enemy(hp = 1))
        w.entity("e2").set(Position()).set(Enemy(hp = 2)).set(Frozen())
        w.entity("p").set(Position())
        var hp = 0
        ecs_query(w) $ [CACHED, REQUIRE(Enemy), REQUIRE_NOT(Frozen)] (e : FlecsEntity; p : Position) {
            hp += e.get(type<Enemy>).hp
        }
        t |> equal(hp, 1)
        w.fini()
    }
    t |> run("UP / SELF_UP / CASCADE") @(t : T?) {
        var w = FlecsWorld()
        let root = w.entity("root").set(Velocity(x = 1.0))
        let mid = w.entity("mid").child_of(root).set(Position())
        w.entity("leaf").child_of(mid).set(Position()).set(Velocity(x = 5.0))
        var up_sum = 0.0
        ecs_query(w) $ [UP(v)] (p : Position; v : Velocity) {
            up_sum += v.x
        }
        t |> equal(up_sum, 2.0)    // mid and leaf both read root's: up skips the entity itself
        var self_up_sum = 0.0
        ecs_query(w) $ [SELF_UP(v)] (p : Position; v : Velocity) {
            self_up_sum += v.x
        }
        t |> equal(self_up_sum, 6.0)    // mid: root's 1, leaf: its own 5
        var order : array<string>
        ecs_query(w) $ [CASCADE(parent)] (e : FlecsEntity; p : Position; parent : Position?) {
            order |> push(e.name())
        }
        t |> equal(length(order), 2)
        t |> equal(order[0], "mid")
        t |> equal(order[1], "leaf")
        w.fini()
    }
}

[test]
def test_query_composition(t : T?) {
    t |> run("builder terms come first") @(t : T?) {
        var w = FlecsWorld()
        let team = w.entity("Team")
        let red = w.entity("Red")
        w.entity("a").set(Position(x = 1.0)).add(team, red)
        w.entity("b").set(Position(x = 2.0))
        var sum = 0.0
        ecs_query(w, w.query_builder().with_(team, red)) $(p : Position) {
            sum += p.x
        }
        t |> equal(sum, 1.0)
        w.fini()
    }
    t |> run("one query per call site and world") @(t : T?) {
        var w = FlecsWorld()
        w.entity().set(Position())
        let before = flecs_query_cache_count()
        for (i in range(3)) {
            ecs_query(w) $(p : Position) {
                pass
            }
        }
        t |> equal(flecs_query_cache_count(), before + 1)
        ecs_query(w, "shared_key") $(p : Position) {
            pass
        }
        ecs_query(w, "shared_key") $(p : Position) {
            pass
        }
        t |> equal(flecs_query_cache_count(), before + 2)
        w.fini()
        t |> equal(flecs_query_cache_count(), 0)
    }
}

[test]
def test_find_query(t : T?) {
    t |> run("first match") @(t : T?) {
        var w = FlecsWorld()
        w.entity().set(Position(x = 1.0))
        w.entity().set(Position(x = 3.0))
        w.entity().set(Position(x = 8.0)).set(Velocity())
        t |> success(ecs_find_query(w) $(p : Position) { return p.x > 2.5; })
        t |> success(!ecs_find_query(w) $(p : Position) { return p.x > 100.0; })
        // a match in the first of several tables stops iteration and finishes the iterator
        t |> success(ecs_find_query(w) $(p : Position) { return p.x < 2.0; })
        var visited = 0
        let found = ecs_find_query(w) $(p : Position) {
            visited ++
            return p.x == 3.0
        }
        t |> success(found)
        t |> equal(visited, 2)
        w.fini()
    }
}

[test]
def test_each(t : T?) {
    t |> run("prebuilt query") @(t : T?) {
        var w = FlecsWorld()
        w.entity("a").set(Position(x = 1.0)).set(Velocity(x = 1.0))
        w.entity("b").set(Position(x = 2.0)).set(Velocity(x = 1.0))
        var q = w.query_builder().with_(type<Position>).with_(type<Velocity>).in_().build()
        ecs_each(q) $(var p : Position; v : Velocity) {
            p.x += v.x
        }
        var sum = 0.0
        ecs_each(q.query) $(e : FlecsEntity; p : Position) {
            sum += p.x
        }
        t |> equal(sum, 5.0)
        q.destruct()
        w.fini()
    }
    t |> run("field size mismatch panics") @(t : T?) {
        var w = FlecsWorld()
        w.entity().set(Enemy(hp = 1))
        var q = w.query_builder().with_(type<Enemy>).build()
        var failed = false
        try {
            ecs_each(q) $(p : Position) {
                pass
            }
        } recover {
            failed = true
        }
        t |> success(failed)
        q.destruct()
        w.fini()
    }
}

[test]
def test_system_observer(t : T?) {
    t |> run("systems run in phase order") @(t : T?) {
        var w = FlecsWorld()
        w.entity().set(Position()).set(Velocity(x = 2.0))
        g_order |> clear()
        ecs_system(w, "Late", EcsPostUpdate) $(p : Position) {
            g_order |> push("late {p.x}")
        }
        ecs_system(w.system("Early").kind(EcsOnUpdate)) $(var p : Position; v : Velocity; it : ecs_iter_t const?) {
            p.x += v.x * it.delta_time
            g_dt = it.delta_time
            g_order |> push("early")
        }
        w.progress(0.5)
        t |> equal(length(g_order), 2)
        t |> equal(g_order[0], "early")
        t |> equal(g_order[1], "late 1")
        t |> equal(g_dt, 0.5)
        w.fini()
    }
    t |> run("manual system with run()") @(t : T?) {
        var w = FlecsWorld()
        w.entity().set(Position())
        g_order |> clear()
        let sys = ecs_system(w.system("Manual").kind(0ul)) $(p : Position) {
            g_order |> push("manual")
        }
        w.progress()
        t |> equal(length(g_order), 0)
        sys.run()
        t |> equal(length(g_order), 1)
        w.fini()
    }
    t |> run("observer") @(t : T?) {
        var w = FlecsWorld()
        g_observed = 0
        ecs_observer(w, EcsOnSet) $(e : FlecsEntity; p : Position) {
            g_observed += int(p.x)
        }
        let e = w.entity().set(Position(x = 3.0))
        ecs_set(w.c_ptr(), e.id, Position(x = 4.0))
        t |> equal(g_observed, 7)
        ecs_observer(w.observer("OnRemoveEnemy").event(EcsOnRemove)) $(en : Enemy) {
            g_observed = -en.hp
        }
        e.set(Enemy(hp = 9)).remove(type<Enemy>)
        t |> equal(g_observed, -9)
        w.fini()
    }
}

[test]
def test_forwarded_forms(t : T?) {
    t |> run("expression query, table each, expression system") @(t : T?) {
        var w = ecs_init()
        ecs_set(w, ecs_new(w), Position(x = 1.0))
        var q = ecs_query(w, "Position")
        var n = 0
        ecs_query_each(w, q) $(it) {
            n += it.count
        }
        ecs_query_fini(q)
        ecs_each(w, type<Position>) $(it) {
            n += it.count
        }
        t |> equal(n, 2)
        g_observed = 0
        ecs_system(w, "Expr", EcsOnUpdate, "Position") @(it : ecs_iter_t const?) {
            g_observed += it.count
        }
        ecs_progress(w, 0.0)
        t |> equal(g_observed, 1)
        flecs_fini(w)
    }
}
