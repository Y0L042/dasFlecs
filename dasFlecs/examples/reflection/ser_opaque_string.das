options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/ser_opaque_string

// Simple string type
struct String {
    value : string
}

[export]
def main() {
    var ecs = ecs_init()

    // Register type as component so the size is known
    ecs_id(ecs, type<String>)

    // Register String as opaque type. An opaque type is a type of which the
    // reflection framework doesn't know the layout, but which it can serialize.
    var desc : ecs_opaque_desc_t
    // Link reflection with component
    desc.entity = ecs_id(ecs, type<String>)
    // Let reflection framework know the type represents a string
    desc._type.as_type = ecs_id_ecs_string_t
    // Register functions for de/serializing vector contents
    ecs_opaque_serialize(desc) @(ser : ecs_serializer_t const?; ptr : void const?) : int {
        let data = unsafe(reinterpret<String const?>(ptr))
        return ecs_ser_value(ser, ecs_id_ecs_string_t, unsafe(addr(data.value)))
    }
    ecs_opaque_assign_string(desc) @(ptr : void?; value : string) {
        var data = unsafe(reinterpret<String?>(ptr))
        ecs_os_free(data.value)    // no-op for an empty (null) string
        data.value = ecs_os_strdup(value)
    }
    ecs_opaque_init(ecs, desc)

    var v : String

    // Deserialize new value into string
    ecs_ptr_from_json(ecs, ecs_id(ecs, type<String>), unsafe(addr(v)), "\"Hello World\"", null)

    // Print string contents
    print("{v.value}\n")

    // Serialize string contents to JSON
    print("{ecs_take(ecs_ptr_to_json(ecs, ecs_id(ecs, type<String>), unsafe(addr(v))))}\n")

    // Free string. If this type were used as a component, we could
    // register a dtor to do this for us (see the entity/hooks example).
    ecs_os_free(v.value)

    flecs_fini(ecs)
}

// Output:
//  Hello World
//  "Hello World"
