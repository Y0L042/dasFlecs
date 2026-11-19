options gen2
require flecs/flecs_boost
require strings

// Port of flecs examples/c/reflection/custom_serializer
//
// This example demonstrates how to create a serializer for a custom format.

var indent = 0

def printIndented(s : string) {
    print("\n{repeat(" ", indent * 2)}{s}")
}

def offset(ptr : void const?; bytes : int) : void const? {
    unsafe {
        return reinterpret<void const?>(reinterpret<uint8 const?>(ptr) + bytes)
    }
}

// Serialize a pointer of a specified type.
def serialize(world : ecs_world_t?; t : ecs_entity_t; ptr : void const?) : int {
    // The TypeSerializer component contains a vector of instructions that tells
    // us how to serialize the type.
    let s = ecs_get_by_id(world, t, ecs_id_EcsTypeSerializer, type<EcsTypeSerializer>)
    if (s == null) {
        print("type does not have reflection data\n")
        return -1
    }

    unsafe {
        let ops = reinterpret<ecs_meta_op_t?>(ecs_vec_first(addr(s.ops)))
        serializeOps(world, ops, ecs_vec_count(addr(s.ops)), ptr)
    }
    return 0
}

// Serialize contents of struct or collection scope
def serializeScope(world : ecs_world_t?; ops : ecs_meta_op_t?; ptr : void const?) {
    // A scope starts with a Push and ends with a Pop, so trim the first and
    // last instruction before forwarding.
    serializeOps(world, unsafe(ops + 1), int(ops.op_count) - 2, ptr)
}

// Serialize a struct scope
def serializeStruct(world : ecs_world_t?; ops : ecs_meta_op_t?; ptr : void const?) {
    print("\{")
    indent ++
    serializeScope(world, ops, ptr)
    indent --
    printIndented("\}")
}

// Serialize an array scope
def serializeArray(world : ecs_world_t?; ops : ecs_meta_op_t?; elem_count : int; ptr : void const?) {
    print("[")

    // Iterate elements of the array. Skip the first and last instruction
    // since they are PushStruct and Pop.
    var p = ptr
    for (i in range(elem_count)) {
        if (i != 0) {
            print(", ")
        }
        serializeScope(world, ops, p)
        p = offset(p, ops.elem_size)
    }

    print("]")
}

// Serialize a vector scope
def serializeVector(world : ecs_world_t?; ops : ecs_meta_op_t?; ptr : void const?) {
    let vec = unsafe(reinterpret<ecs_vec_t const?>(ptr))
    serializeArray(world, ops, vec.count, vec._array)
}

// Serialize enum
def serializeEnum(op : ecs_meta_op_t?; ptr : void const?) {
    var value : uint64
    let kind = op.underlying_kind
    unsafe {
        if (kind == ecs_meta_op_kind_t.EcsOpU8 || kind == ecs_meta_op_kind_t.EcsOpI8) {
            value = uint64(*reinterpret<uint8 const?>(ptr))
        } elif (kind == ecs_meta_op_kind_t.EcsOpU16 || kind == ecs_meta_op_kind_t.EcsOpI16) {
            value = uint64(*reinterpret<uint16 const?>(ptr))
        } elif (kind == ecs_meta_op_kind_t.EcsOpU32 || kind == ecs_meta_op_kind_t.EcsOpI32) {
            value = uint64(*reinterpret<uint const?>(ptr))
        } elif (kind == ecs_meta_op_kind_t.EcsOpUPtr || kind == ecs_meta_op_kind_t.EcsOpIPtr || kind == ecs_meta_op_kind_t.EcsOpU64 || kind == ecs_meta_op_kind_t.EcsOpI64) {
            value = *reinterpret<uint64 const?>(ptr)
        } else {
            print("<<invalid underlying enum type>>")
            return
        }
        // ecs_map_get_deref(op->is.constants, ecs_enum_constant_t, value)
        let c = reinterpret<ecs_enum_constant_t const?>(ecs_map_get_deref_(ecs_meta_op_constants(op), value))
        print("{c.name}")
    }
}

// Iterate over instruction array
def serializeOps(world : ecs_world_t?; ops : ecs_meta_op_t?; op_count : int; base : void const?) {
    var i = 0
    while (i < op_count) {
        let op = unsafe(ops + i)

        // Member name
        if (!empty(op.name)) {
            if (i != 0) {
                print(",")
            }
            printIndented("{op.name}: ")
        }

        // Get pointer for current field
        let ptr = offset(base, op.offset)

        unsafe {
            let k = op.kind
            // Instructions that forward to a type scope, like a (nested) struct or
            // collection
            if (k == ecs_meta_op_kind_t.EcsOpPushStruct) {
                serializeStruct(world, op, ptr)
            } elif (k == ecs_meta_op_kind_t.EcsOpPushArray) {
                serializeArray(world, op, ecs_meta_op_get_elem_count(ops, ptr), ptr)
            } elif (k == ecs_meta_op_kind_t.EcsOpPushVector) {
                serializeVector(world, op, ptr)
            } elif (k == ecs_meta_op_kind_t.EcsOpForward) {
                // Forward to type. Used for members of array/vector types.
                serialize(world, op._type, ptr)
            } elif (k == ecs_meta_op_kind_t.EcsOpEnum) {
                // Serialize single values
                serializeEnum(op, ptr)
            } elif (k == ecs_meta_op_kind_t.EcsOpBool) {
                print(*reinterpret<bool const?>(ptr) ? "true" : "false")
            } elif (k == ecs_meta_op_kind_t.EcsOpChar) {
                print("'{to_char(int(*reinterpret<int8 const?>(ptr)))}'")
            } elif (k == ecs_meta_op_kind_t.EcsOpByte || k == ecs_meta_op_kind_t.EcsOpU8) {
                print("{int(*reinterpret<uint8 const?>(ptr))}")
            } elif (k == ecs_meta_op_kind_t.EcsOpU16) {
                print("{int(*reinterpret<uint16 const?>(ptr))}")
            } elif (k == ecs_meta_op_kind_t.EcsOpU32) {
                print("{int64(*reinterpret<uint const?>(ptr))}")
            } elif (k == ecs_meta_op_kind_t.EcsOpU64 || k == ecs_meta_op_kind_t.EcsOpUPtr) {
                print("{*reinterpret<uint64 const?>(ptr)}")
            } elif (k == ecs_meta_op_kind_t.EcsOpI8) {
                print("{int(*reinterpret<int8 const?>(ptr))}")
            } elif (k == ecs_meta_op_kind_t.EcsOpI16) {
                print("{int(*reinterpret<int16 const?>(ptr))}")
            } elif (k == ecs_meta_op_kind_t.EcsOpI32) {
                print("{*reinterpret<int const?>(ptr)}")
            } elif (k == ecs_meta_op_kind_t.EcsOpI64 || k == ecs_meta_op_kind_t.EcsOpIPtr) {
                print("{*reinterpret<int64 const?>(ptr)}")
            } elif (k == ecs_meta_op_kind_t.EcsOpF32) {
                print("{double(*reinterpret<float const?>(ptr)):.2f}")
            } elif (k == ecs_meta_op_kind_t.EcsOpF64) {
                print("{*reinterpret<double const?>(ptr):.2f}")
            } elif (k == ecs_meta_op_kind_t.EcsOpString) {
                print("\"{*reinterpret<string const?>(ptr)}\"")
            } elif (k == ecs_meta_op_kind_t.EcsOpEntity) {
                print("{ecs_get_path(world, *reinterpret<ecs_entity_t const?>(ptr))}\n")
            } elif (k == ecs_meta_op_kind_t.EcsOpId) {
                print("{ecs_take(ecs_id_str(world, *reinterpret<ecs_id_t const?>(ptr)))}\n")
            }
            // EcsOpPushMap, EcsOpPushValue, opaque ops, EcsOpBitmask: not handled by
            // this example (see src/addons/script/serialize.c in flecs).
            // EcsOpPop, EcsOpScope, EcsOpPrimitive: not serializable.
        }

        i += int(op.op_count)    // Skip over already processed instructions
    }
}

// Some types to test the serializer with
struct Rgb {
    red : uint8
    green : uint8
    blue : uint8
}

enum StrokeKind {
    Solid
    Dashed
}

struct Point {
    x : float
    y : float
}

struct Polygon {
    color : Rgb
    stroke_color : Rgb
    stroke_kind : StrokeKind
    points : ecs_vec_t
}

[export]
def main() {
    var world = ecs_init()

    // We need to register reflection data for our types before we can use them
    // with the serializer code. We'll do it manually here, but for an easier
    // way to insert reflection data see the auto_* examples.
    ecs_id(world, type<Rgb>)
    ecs_id(world, type<StrokeKind>)
    ecs_id(world, type<Point>)
    ecs_id(world, type<Polygon>)

    var rgb : ecs_struct_desc_t
    rgb.entity = ecs_id(world, type<Rgb>)
    rgb.members[0].name = "r"
    rgb.members[0]._type = ecs_id_ecs_u8_t
    rgb.members[1].name = "g"
    rgb.members[1]._type = ecs_id_ecs_u8_t
    rgb.members[2].name = "b"
    rgb.members[2]._type = ecs_id_ecs_u8_t
    ecs_struct_init(world, unsafe(addr(rgb)))

    var sk : ecs_enum_desc_t
    sk.entity = ecs_id(world, type<StrokeKind>)
    sk.constants[0].name = "Solid"
    sk.constants[0].value = int64(StrokeKind.Solid)
    sk.constants[1].name = "Dashed"
    sk.constants[1].value = int64(StrokeKind.Dashed)
    ecs_enum_init(world, unsafe(addr(sk)))

    var pt : ecs_struct_desc_t
    pt.entity = ecs_id(world, type<Point>)
    pt.members[0].name = "x"
    pt.members[0]._type = ecs_id_ecs_f32_t
    pt.members[1].name = "y"
    pt.members[1]._type = ecs_id_ecs_f32_t
    ecs_struct_init(world, unsafe(addr(pt)))

    var pv : ecs_vector_desc_t
    pv._type = ecs_id(world, type<Point>)
    let PointVector = ecs_vector_init(world, unsafe(addr(pv)))

    var poly : ecs_struct_desc_t
    poly.entity = ecs_id(world, type<Polygon>)
    poly.members[0].name = "color"
    poly.members[0]._type = ecs_id(world, type<Rgb>)
    poly.members[1].name = "stroke_color"
    poly.members[1]._type = ecs_id(world, type<Rgb>)
    poly.members[2].name = "stroke_kind"
    poly.members[2]._type = ecs_id(world, type<StrokeKind>)
    poly.members[3].name = "points"
    poly.members[3]._type = PointVector
    ecs_struct_init(world, unsafe(addr(poly)))

    // Create the value
    var p = Polygon(
        color = Rgb(red = 0u8, green = 0u8, blue = 255u8),
        stroke_color = Rgb(red = 255u8, green = 0u8, blue = 0u8),
        stroke_kind = StrokeKind.Dashed)
    let point_size = typeinfo sizeof(type<Point>)
    unsafe {
        ecs_vec_init(null, addr(p.points), point_size, 0)
        *reinterpret<Point?>(ecs_vec_append(null, addr(p.points), point_size)) = Point(x = 0.0, y = 0.0)
        *reinterpret<Point?>(ecs_vec_append(null, addr(p.points), point_size)) = Point(x = 1.0, y = 1.0)
        *reinterpret<Point?>(ecs_vec_append(null, addr(p.points), point_size)) = Point(x = -1.0, y = 1.0)
    }

    // Serialize value
    serialize(world, ecs_id(world, type<Polygon>), unsafe(addr(p)))
    print("\n")

    // Free memory
    ecs_vec_fini(null, unsafe(addr(p.points)), point_size)

    flecs_fini(world)
}

// Output:
//  {
//    color: {
//      r: 0,
//      g: 0,
//      b: 255
//    },
//    stroke_color: {
//      r: 255,
//      g: 0,
//      b: 0
//    },
//    stroke_kind: Dashed,
//    points: [{
//      x: 0.00,
//      y: 0.00
//    }, {
//      x: 1.00,
//      y: 1.00
//    }, {
//      x: -1.00,
//      y: 1.00
//    }]
//  }
