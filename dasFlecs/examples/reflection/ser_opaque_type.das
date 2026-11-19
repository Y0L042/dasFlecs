options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/ser_opaque_type
//
// Use opaque reflection support to add a computed 'result' member to type

struct Sum {
    a : int
    b : int
}

[export]
def main() {
    var ecs = ecs_init()

    // Register type as component so the size is known
    ecs_id(ecs, type<Sum>)

    // Create struct type that describes the structure of Sum
    var sdesc : ecs_struct_desc_t
    sdesc.members[0].name = "a"
    sdesc.members[0]._type = ecs_id_ecs_i32_t
    sdesc.members[1].name = "b"
    sdesc.members[1]._type = ecs_id_ecs_i32_t
    sdesc.members[2].name = "result"
    sdesc.members[2]._type = ecs_id_ecs_i32_t
    let sum_type_descriptor = ecs_struct_init(ecs, unsafe(addr(sdesc)))

    // Register Sum as opaque type. An opaque type is a type of which the
    // reflection framework doesn't know the layout, but which it can serialize.
    var desc : ecs_opaque_desc_t
    // Link reflection with component
    desc.entity = ecs_id(ecs, type<Sum>)
    // Let reflection framework know the type represents a struct
    desc._type.as_type = sum_type_descriptor
    // Register function for serializing sum contents
    ecs_opaque_serialize(desc) @(ser : ecs_serializer_t const?; ptr : void const?) : int {
        let data = unsafe(reinterpret<Sum const?>(ptr))
        ecs_ser_member(ser, "a")
        ecs_ser_value(ser, ecs_id_ecs_i32_t, unsafe(addr(data.a)))
        ecs_ser_member(ser, "b")
        ecs_ser_value(ser, ecs_id_ecs_i32_t, unsafe(addr(data.b)))

        var result = data.a + data.b    // Serialize fake member
        ecs_ser_member(ser, "result")
        ecs_ser_value(ser, ecs_id_ecs_i32_t, unsafe(addr(result)))
        return 0
    }
    // Register function for getting access to members
    ecs_opaque_ensure_member(desc) @(ptr : void?; member : string) : void? {
        var data = unsafe(reinterpret<Sum?>(ptr))
        if (member == "a") {
            return unsafe(addr(data.a))
        } elif (member == "b") {
            return unsafe(addr(data.b))
        } else {
            return null    // We can't serialize into fake result member
        }
    }
    ecs_opaque_init(ecs, desc)

    var v = Sum(a = 10, b = 20)

    // Serialize value of Sum to JSON
    print("{ecs_take(ecs_ptr_to_json(ecs, ecs_id(ecs, type<Sum>), unsafe(addr(v))))}\n")

    // Deserialize new value into Sum
    ecs_ptr_from_json(ecs, ecs_id(ecs, type<Sum>), unsafe(addr(v)), "\{\"a\": 20, \"b\": 22\}", null)

    // Serialize value again
    print("{ecs_take(ecs_ptr_to_json(ecs, ecs_id(ecs, type<Sum>), unsafe(addr(v))))}\n")

    flecs_fini(ecs)
}

// Output:
//  {"a":10, "b":20, "result":30}
//  {"a":20, "b":22, "result":42}
