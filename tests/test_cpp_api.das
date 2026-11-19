options gen2

// flecs_cpp: daslang ports of the flecs C++ classes (FlecsWorld, FlecsEntity, builders).
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

struct Mass {
    value : float
}

// counters the system / observer lambdas below update (lambdas copy captured locals)
var g_calls = 0
var g_seen = 0

[test]
def test_entity(t : T?) {
    t |> run("set / get / has / remove") @(t : T?) {
        var world = FlecsWorld()
        let e = world.entity("Bob").set(Position(x = 1.0, y = 2.0)).set(Velocity(x = 3.0, y = 4.0))
        t |> success(e.has(type<Position>))
        t |> equal(e.get(type<Position>).y, 2.0)
        e.get_mut(type<Velocity>).x = 5.0
        t |> equal(e.get(type<Velocity>).x, 5.0)
        e.remove(type<Velocity>)
        t |> success(!e.has(type<Velocity>))
        e.ensure(type<Mass>).value = 4.0
        t |> success(e.has(type<Mass>))
        t |> equal(e.name(), "Bob")
        world.fini()
    }
    t |> run("tags and pairs") @(t : T?) {
        var world = FlecsWorld()
        let likes = world.entity("Likes")
        let alice = world.entity("Alice")
        let tag = world.entity("Tag")
        let e = world.entity().add(tag).add(likes, alice)
        t |> success(e.has(tag))
        t |> success(e.has(likes, alice))
        t |> equal(e.target(likes).id, alice.id)
        e.remove(likes, alice)
        t |> success(!e.has(likes, alice))
        let eats = world.entity("Eats")
        e.set(Mass(value = 2.0), eats)
        t |> equal(e.get(type<Mass>, eats).value, 2.0)
        world.fini()
    }
    t |> run("hierarchy") @(t : T?) {
        var world = FlecsWorld()
        let parent = world.entity("parent")
        let child = world.entity("child").child_of(parent)
        world.entity("grandchild").child_of(child)
        t |> equal(child.parent().id, parent.id)
        t |> equal(child.path(), "parent.child")
        t |> equal(parent.lookup("child.grandchild").name(), "grandchild")
        t |> equal(world.lookup("parent.child").id, child.id)
        var names : array<string>
        parent.children_recursive() $(c) {
            names |> push(c.name())
        }
        t |> equal(length(names), 2)
        t |> equal(length(parent.children_array()), 1)
        world.fini()
    }
    t |> run("is_a and auto_override") @(t : T?) {
        var world = FlecsWorld()
        let base = world.prefab("Base").set(Mass(value = 10.0))
        let inst = world.entity().is_a(base)
        // flecs 4 default (OnInstantiate, Override): the instance gets its own copy
        t |> success(inst.has(type<Mass>))
        t |> success(inst.owns(type<Mass>))
        t |> equal(inst.get(type<Mass>).value, 10.0)
        // (OnInstantiate, Inherit): the instance shares the prefab's value
        world.component(type<Velocity>).entity().add(EcsOnInstantiate, EcsInherit)
        let base2 = world.prefab("Base2").set(Velocity(x = 1.0, y = 1.0))
        let inst2 = world.entity().is_a(base2)
        t |> success(inst2.has(type<Velocity>))
        t |> success(!inst2.owns(type<Velocity>))
        world.fini()
    }
    t |> run("enable / disable / clear / destruct") @(t : T?) {
        var world = FlecsWorld()
        let e = world.entity().set(Position())
        e.disable()
        t |> success(!e.enabled())
        e.enable()
        t |> success(e.enabled())
        e.clear()
        t |> success(!e.has(type<Position>))
        e.destruct()
        t |> success(!e.is_alive())
        world.fini()
    }
    t |> run("json") @(t : T?) {
        var world = FlecsWorld()
        world.component(type<Position>).member(type<float>, "x").member(type<float>, "y")
        let e = world.entity("j").set(Position(x = 1.0, y = 2.0))
        t |> equal(e.to_json(), "\{\"name\":\"j\", \"components\":\{\"Position\":\{\"x\":1, \"y\":2\}\}\}")
        e.from_json("\{\"components\":\{\"Position\":\{\"x\":7, \"y\":8\}\}\}")
        t |> equal(e.get(type<Position>).x, 7.0)
        world.fini()
    }
}

[test]
def test_world_api(t : T?) {
    t |> run("singletons") @(t : T?) {
        var world = FlecsWorld()
        world.set(Mass(value = 9.0))
        t |> success(world.has(type<Mass>))
        t |> equal(world.get(type<Mass>).value, 9.0)
        world.get_mut(type<Mass>).value = 3.0
        t |> equal(world.singleton(type<Mass>).get(type<Mass>).value, 3.0)
        world.remove(type<Mass>)
        t |> success(!world.has(type<Mass>))
        world.fini()
    }
    t |> run("count / each / scope") @(t : T?) {
        var world = FlecsWorld()
        let parent = world.entity("scope_parent")
        world.scope(parent) {
            world.entity("a").set(Position())
            world.entity("b").set(Position())
        }
        t |> equal(world.count(type<Position>), 2)
        var n = 0
        world.each(type<Position>) $(e) {
            t |> equal(e.parent().id, parent.id)
            n ++
        }
        t |> equal(n, 2)
        world.fini()
    }
}

[test]
def test_query_builder(t : T?) {
    t |> run("terms and operators") @(t : T?) {
        var world = FlecsWorld()
        let tag = world.entity("Tag")
        world.entity("a").set(Position()).set(Velocity())
        world.entity("b").set(Position()).add(tag)
        world.entity("c").set(Position()).set(Mass())
        var q = world.query_builder().with_(type<Position>).in_().with_(type<Velocity>).optional().build()
        t |> equal(q.count(), 3)
        q.destruct()
        var q2 = world.query_builder().with_(type<Position>).without(tag).build()
        t |> equal(q2.count(), 2)
        q2.destruct()
        var q3 = world.query_builder().with_(type<Velocity>).or_().with_(type<Mass>).build()
        t |> equal(q3.count(), 2)
        q3.destruct()
        var q4 = world.query_builder().with_(tag).build()
        t |> equal(q4.first().name(), "b")
        t |> success(q4.is_true())
        q4.destruct()
        world.fini()
    }
    t |> run("up / cascade / src") @(t : T?) {
        var world = FlecsWorld()
        let parent = world.entity("p").set(Mass(value = 5.0))
        world.entity("c1").child_of(parent).set(Position())
        world.entity("c2").child_of(parent).set(Position())
        var q = world.query_builder().with_(type<Position>).with_(type<Mass>).up().build()
        var total = 0.0
        q.run() $(it) {
            let m = unsafe(ecs_field(it, type<Mass>, 1))
            total += float(it.count) * unsafe(m[0]).value
        }
        t |> equal(total, 10.0)
        q.destruct()
        var qc = world.query_builder().with_(type<Mass>).cascade().optional().with_(type<Position>).build()
        t |> equal(qc.count(), 2)
        qc.destruct()
        var qs = world.query_builder().with_(type<Mass>).src(parent).with_(type<Position>).build()
        t |> equal(qs.count(), 2)
        qs.destruct()
        world.fini()
    }
    t |> run("each / expr / order_by") @(t : T?) {
        var world = FlecsWorld()
        world.entity("z").set(Mass(value = 3.0))
        world.entity("y").set(Mass(value = 1.0))
        world.entity("x").set(Mass(value = 2.0))
        var q = world.query_builder().with_(type<Mass>).order_by(type<Mass>) @(e1 : ecs_entity_t; p1 : void const?; e2 : ecs_entity_t; p2 : void const?) : int {
            let a = unsafe(reinterpret<Mass const?>(p1)).value
            let b = unsafe(reinterpret<Mass const?>(p2)).value
            return a < b ? -1 : (a > b ? 1 : 0)
        }.build()
        var names : array<string>
        q.each() $(e) {
            names |> push(e.name())
        }
        t |> equal(length(names), 3)
        t |> equal(names[0], "y")
        t |> equal(names[2], "z")
        q.destruct()
        var qe = world.query("Mass")
        t |> equal(qe.count(), 3)
        qe.destruct()
        world.fini()
    }
}

[test]
def test_system_observer_builders(t : T?) {
    t |> run("system iter / run") @(t : T?) {
        var world = FlecsWorld()
        world.entity().set(Position()).set(Velocity(x = 1.0, y = 2.0))
        let sys = world.system("Move").kind(EcsOnUpdate).with_(type<Position>).with_(type<Velocity>).in_().iter() @(it : ecs_iter_t const?) {
            var p = unsafe(ecs_field(it, type<Position>, 0))
            var v = unsafe(ecs_field(it, type<Velocity>, 1))
            for (i in range(it.count)) {
                unsafe(p[i]).x += unsafe(v[i]).x
            }
        }
        world.progress()
        sys.run()
        var x = 0.0
        world.each(type<Position>) $(e) {
            x = e.get(type<Position>).x
        }
        t |> equal(x, 2.0)
        t |> equal(sys.entity().name(), "Move")
        world.fini()
    }
    t |> run("system interval") @(t : T?) {
        var world = FlecsWorld()
        g_calls = 0
        let sys = world.system("Slow").interval(1.0).run() @(it : ecs_iter_t?) {
            g_calls ++
            while (ecs_iter_next(it)) {
                pass
            }
        }
        t |> equal(sys.get_interval(), 1.0)
        world.progress(0.4)
        world.progress(0.4)
        t |> equal(g_calls, 0)
        world.progress(0.4)
        t |> equal(g_calls, 1)
        world.fini()
    }
    t |> run("observer event / yield_existing") @(t : T?) {
        var world = FlecsWorld()
        world.entity().set(Mass(value = 1.0))
        g_seen = 0
        world.observer("OnMass").with_(type<Mass>).event(EcsOnSet).yield_existing().iter() @(it : ecs_iter_t const?) {
            g_seen += it.count
        }
        t |> equal(g_seen, 1)
        world.entity().set(Mass(value = 2.0))
        t |> equal(g_seen, 2)
        world.fini()
    }
}
