options gen2
require flecs/flecs_boost

// Port of flecs examples/c/reflection/ser_opaque_vector

struct IntVector {
    count : uint64
    _array : int?    // memory from ecs_os_realloc
}

def IntVector_resize(var data : IntVector?; size : uint64) {
    if (data.count != size) {
        data.count = size
        if (data.count == 0ul) {
            ecs_os_free(data._array)
            data._array = null
        } else {
            data._array = unsafe(reinterpret<int?>(ecs_os_realloc(data._array, int64(size) * int64(typeinfo sizeof(type<int>)))))
        }
    }
}

[export]
def main() {
    var ecs = ecs_init()

    ecs_id(ecs, type<IntVector>)

    var vdesc : ecs_vector_desc_t
    vdesc._type = ecs_id_ecs_i32_t

    var desc : ecs_opaque_desc_t
    desc.entity = ecs_id(ecs, type<IntVector>)
    desc._type.as_type = ecs_vector_init(ecs, unsafe(addr(vdesc)))
    ecs_opaque_serialize(desc) @(ser : ecs_serializer_t const?; ptr : void const?) : int {
        let data = unsafe(reinterpret<IntVector const?>(ptr))
        for (i in range(int(data.count))) {
            unsafe {
                ecs_ser_value(ser, ecs_id_ecs_i32_t, addr(data._array[i]))
            }
        }
        return 0
    }
    ecs_opaque_count(desc) @(ptr : void const?) : uint64 {
        let data = unsafe(reinterpret<IntVector const?>(ptr))
        return data.count
    }
    ecs_opaque_resize(desc) @(ptr : void?; size : uint64) {
        IntVector_resize(unsafe(reinterpret<IntVector?>(ptr)), size)
    }
    ecs_opaque_ensure_element(desc) @(ptr : void?; index : uint64) : void? {
        var data = unsafe(reinterpret<IntVector?>(ptr))
        if (data.count <= index) {
            IntVector_resize(data, index + 1ul)
        }
        unsafe {
            return addr(data._array[int(index)])
        }
    }
    ecs_opaque_init(ecs, desc)

    var v : IntVector
    ecs_ptr_from_json(ecs, ecs_id(ecs, type<IntVector>), unsafe(addr(v)), "[10, 20, 30]", null)

    print("[")
    for (i in range(int(v.count))) {
        if (i != 0) {
            print(", ")
        }
        print("{unsafe(v._array[i])}")
    }
    print("]\n")

    print("{ecs_take(ecs_ptr_to_json(ecs, ecs_id(ecs, type<IntVector>), unsafe(addr(v))))}\n")

    ecs_os_free(v._array)

    flecs_fini(ecs)
}

// Output:
//  [10, 20, 30]
//  [10, 20, 30]
