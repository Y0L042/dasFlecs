options gen2
require flecs/flecs_boost

// Port of flecs examples/c/entities/hooks
//
// Component hooks are callbacks that can be registered for a type that are
// invoked during different parts of the component lifecycle.

struct String {
    value : string    // Pointer to external memory (owned by the component, freed by the dtor)
}

// This callback is used for the add, remove and set hooks. Note that the
// signature is the same as systems, triggers, observers.
def hook_callback(it : ecs_iter_t const?) {
    let world = it.stage
    let event = it.event

    for (i in range(it.count)) {
        let e = ecs_iter_entity(it, i)
        ecs_trace("{ecs_get_name(world, event)}: {ecs_get_name(world, e)}")
    }
}

[export]
def main() {
    var world = ecs_init()

    ecs_id(world, type<String>)
    let Tag = ecs_tag(world, "Tag")

    var hooks : ecs_type_hooks_t

    // Resource management hooks. These hooks should primarily be used for
    // managing memory used by the component.

    // The constructor should initialize the component value.
    ecs_hooks_ctor(hooks) @(ptr : void?; count : int; ti : ecs_type_info_t const?) {
        ecs_trace("Ctor")
        unsafe {
            // hooks receive a pointer to `count` consecutive component values
            var p = reinterpret<String?>(ptr)
            for (i in range(count)) {
                p[i].value = ""    // "" is a null string pointer, like NULL in C
            }
        }
    }

    // The destructor should free resources.
    ecs_hooks_dtor(hooks) @(ptr : void?; count : int; ti : ecs_type_info_t const?) {
        ecs_trace("Dtor")
        unsafe {
            var p = reinterpret<String?>(ptr)
            for (i in range(count)) {
                ecs_os_free(p[i].value)
            }
        }
    }

    // The move hook should move resources from one location to another.
    ecs_hooks_move(hooks) @(dst : void?; src : void?; count : int; ti : ecs_type_info_t const?) {
        ecs_trace("Move")
        unsafe {
            var d = reinterpret<String?>(dst)
            var s = reinterpret<String?>(src)
            for (i in range(count)) {
                ecs_os_free(d[i].value)
                d[i].value = s[i].value
                s[i].value = ""      // This makes sure the value doesn't get deleted twice,
                                     // as the destructor is still invoked after a move.
            }
        }
    }

    // The copy hook should copy resources from one location to another.
    ecs_hooks_copy(hooks) @(dst : void?; src : void? const; count : int; ti : ecs_type_info_t const?) {
        ecs_trace("Copy")
        unsafe {
            var d = reinterpret<String?>(dst)
            let s = reinterpret<String const?>(src)
            for (i in range(count)) {
                ecs_os_free(d[i].value)
                d[i].value = ecs_os_strdup(s[i].value)
            }
        }
    }

    // Lifecycle hooks. These hooks should be used for application logic.
    ecs_hooks_on_add(hooks) @(it : ecs_iter_t const?) {
        hook_callback(it)
    }
    ecs_hooks_on_remove(hooks) @(it : ecs_iter_t const?) {
        hook_callback(it)
    }
    ecs_hooks_on_set(hooks) @(it : ecs_iter_t const?) {
        hook_callback(it)
    }

    ecs_set_hooks(world, type<String>, hooks)

    ecs_log_set_level(0)

    let e = ecs_entity(world, "Entity")

    ecs_trace("ecs_add(world, e, String)")
    ecs_log_push()
    ecs_add(world, e, type<String>)
    ecs_log_pop()

    ecs_trace("ecs_set(world, e, String, \{\"Hello World\"\})")
    ecs_log_push()
    ecs_set(world, e, String(value = "Hello World"))
    ecs_log_pop()

    // This operation changes the entity's archetype, which invokes a move
    ecs_trace("ecs_add(world, e, Tag)")
    ecs_log_push()
    ecs_add_id(world, e, Tag)
    ecs_log_pop()

    ecs_trace("ecs_delete(world, e)")
    ecs_log_push()
    ecs_delete(world, e)
    ecs_log_pop()

    ecs_log_set_level(-1)

    flecs_fini(world)
}

// Output:
//  [0;35minfo[0;49m: ecs_add(world, e, String)
//  [0;35minfo[0;49m: | Ctor
//  [0;35minfo[0;49m: | OnAdd: Entity
//  [0;35minfo[0;49m: ecs_set(world, e, String, {[0;36m"Hello World"[0;49m})
//  [0;35minfo[0;49m: | Copy
//  [0;35minfo[0;49m: | OnSet: Entity
//  [0;35minfo[0;49m: ecs_add(world, e, Tag)
//  [0;35minfo[0;49m: | Ctor
//  [0;35minfo[0;49m: | Move
//  [0;35minfo[0;49m: | Dtor
//  [0;35minfo[0;49m: ecs_delete(world, e)
//  [0;35minfo[0;49m: | OnRemove: Entity
//  [0;35minfo[0;49m: | Dtor
