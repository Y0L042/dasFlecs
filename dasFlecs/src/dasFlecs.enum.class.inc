// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

// from flecs.h:727:14
class Enumeration_ecs_inout_kind_t : public das::Enumeration {
public:
	Enumeration_ecs_inout_kind_t() : das::Enumeration("ecs_inout_kind_t") {
		external = true;
		cppName = "ecs_inout_kind_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsInOutDefault", "EcsInOutDefault", int64_t(ecs_inout_kind_t::EcsInOutDefault), das::LineInfo());
		addIEx("EcsInOutNone", "EcsInOutNone", int64_t(ecs_inout_kind_t::EcsInOutNone), das::LineInfo());
		addIEx("EcsInOutFilter", "EcsInOutFilter", int64_t(ecs_inout_kind_t::EcsInOutFilter), das::LineInfo());
		addIEx("EcsInOut", "EcsInOut", int64_t(ecs_inout_kind_t::EcsInOut), das::LineInfo());
		addIEx("EcsIn", "EcsIn", int64_t(ecs_inout_kind_t::EcsIn), das::LineInfo());
		addIEx("EcsOut", "EcsOut", int64_t(ecs_inout_kind_t::EcsOut), das::LineInfo());
	}
};

// from flecs.h:737:14
class Enumeration_ecs_oper_kind_t : public das::Enumeration {
public:
	Enumeration_ecs_oper_kind_t() : das::Enumeration("ecs_oper_kind_t") {
		external = true;
		cppName = "ecs_oper_kind_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsAnd", "EcsAnd", int64_t(ecs_oper_kind_t::EcsAnd), das::LineInfo());
		addIEx("EcsOr", "EcsOr", int64_t(ecs_oper_kind_t::EcsOr), das::LineInfo());
		addIEx("EcsNot", "EcsNot", int64_t(ecs_oper_kind_t::EcsNot), das::LineInfo());
		addIEx("EcsOptional", "EcsOptional", int64_t(ecs_oper_kind_t::EcsOptional), das::LineInfo());
		addIEx("EcsAndFrom", "EcsAndFrom", int64_t(ecs_oper_kind_t::EcsAndFrom), das::LineInfo());
		addIEx("EcsOrFrom", "EcsOrFrom", int64_t(ecs_oper_kind_t::EcsOrFrom), das::LineInfo());
		addIEx("EcsNotFrom", "EcsNotFrom", int64_t(ecs_oper_kind_t::EcsNotFrom), das::LineInfo());
	}
};

// from flecs.h:748:14
class Enumeration_ecs_query_cache_kind_t : public das::Enumeration {
public:
	Enumeration_ecs_query_cache_kind_t() : das::Enumeration("ecs_query_cache_kind_t") {
		external = true;
		cppName = "ecs_query_cache_kind_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsQueryCacheDefault", "EcsQueryCacheDefault", int64_t(ecs_query_cache_kind_t::EcsQueryCacheDefault), das::LineInfo());
		addIEx("EcsQueryCacheAuto", "EcsQueryCacheAuto", int64_t(ecs_query_cache_kind_t::EcsQueryCacheAuto), das::LineInfo());
		addIEx("EcsQueryCacheAll", "EcsQueryCacheAll", int64_t(ecs_query_cache_kind_t::EcsQueryCacheAll), das::LineInfo());
		addIEx("EcsQueryCacheNone", "EcsQueryCacheNone", int64_t(ecs_query_cache_kind_t::EcsQueryCacheNone), das::LineInfo());
	}
};

// from flecs/addons/http.h:66:9
class Enumeration_ecs_http_method_t : public das::Enumeration {
public:
	Enumeration_ecs_http_method_t() : das::Enumeration("ecs_http_method_t") {
		external = true;
		cppName = "ecs_http_method_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsHttpGet", "EcsHttpGet", int64_t(ecs_http_method_t::EcsHttpGet), das::LineInfo());
		addIEx("EcsHttpPost", "EcsHttpPost", int64_t(ecs_http_method_t::EcsHttpPost), das::LineInfo());
		addIEx("EcsHttpPut", "EcsHttpPut", int64_t(ecs_http_method_t::EcsHttpPut), das::LineInfo());
		addIEx("EcsHttpDelete", "EcsHttpDelete", int64_t(ecs_http_method_t::EcsHttpDelete), das::LineInfo());
		addIEx("EcsHttpOptions", "EcsHttpOptions", int64_t(ecs_http_method_t::EcsHttpOptions), das::LineInfo());
		addIEx("EcsHttpMethodUnsupported", "EcsHttpMethodUnsupported", int64_t(ecs_http_method_t::EcsHttpMethodUnsupported), das::LineInfo());
	}
};

// from flecs/addons/script_input.h:129:14
class Enumeration_ecs_script_focus_source_t : public das::Enumeration {
public:
	Enumeration_ecs_script_focus_source_t() : das::Enumeration("ecs_script_focus_source_t") {
		external = true;
		cppName = "ecs_script_focus_source_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsScriptFocusPress", "EcsScriptFocusPress", int64_t(ecs_script_focus_source_t::EcsScriptFocusPress), das::LineInfo());
		addIEx("EcsScriptFocusSet", "EcsScriptFocusSet", int64_t(ecs_script_focus_source_t::EcsScriptFocusSet), das::LineInfo());
		addIEx("EcsScriptFocusScript", "EcsScriptFocusScript", int64_t(ecs_script_focus_source_t::EcsScriptFocusScript), das::LineInfo());
	}
};

// from flecs/addons/script_async.h:90:14
class Enumeration_ecs_script_task_status_t : public das::Enumeration {
public:
	Enumeration_ecs_script_task_status_t() : das::Enumeration("ecs_script_task_status_t") {
		external = true;
		cppName = "ecs_script_task_status_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsScriptTaskPending", "EcsScriptTaskPending", int64_t(ecs_script_task_status_t::EcsScriptTaskPending), das::LineInfo());
		addIEx("EcsScriptTaskDone", "EcsScriptTaskDone", int64_t(ecs_script_task_status_t::EcsScriptTaskDone), das::LineInfo());
		addIEx("EcsScriptTaskError", "EcsScriptTaskError", int64_t(ecs_script_task_status_t::EcsScriptTaskError), das::LineInfo());
		addIEx("EcsScriptTaskCancelled", "EcsScriptTaskCancelled", int64_t(ecs_script_task_status_t::EcsScriptTaskCancelled), das::LineInfo());
	}
};

// from flecs/addons/script_async.h:98:14
class Enumeration_ecs_script_future_status_t : public das::Enumeration {
public:
	Enumeration_ecs_script_future_status_t() : das::Enumeration("ecs_script_future_status_t") {
		external = true;
		cppName = "ecs_script_future_status_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsScriptFuturePending", "EcsScriptFuturePending", int64_t(ecs_script_future_status_t::EcsScriptFuturePending), das::LineInfo());
		addIEx("EcsScriptFutureResolved", "EcsScriptFutureResolved", int64_t(ecs_script_future_status_t::EcsScriptFutureResolved), das::LineInfo());
		addIEx("EcsScriptFutureRejected", "EcsScriptFutureRejected", int64_t(ecs_script_future_status_t::EcsScriptFutureRejected), das::LineInfo());
		addIEx("EcsScriptFutureCancelled", "EcsScriptFutureCancelled", int64_t(ecs_script_future_status_t::EcsScriptFutureCancelled), das::LineInfo());
	}
};

// from flecs/addons/script_async.h:106:14
class Enumeration_ecs_script_task_loop_t : public das::Enumeration {
public:
	Enumeration_ecs_script_task_loop_t() : das::Enumeration("ecs_script_task_loop_t") {
		external = true;
		cppName = "ecs_script_task_loop_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsScriptTaskLoopOnce", "EcsScriptTaskLoopOnce", int64_t(ecs_script_task_loop_t::EcsScriptTaskLoopOnce), das::LineInfo());
		addIEx("EcsScriptTaskLoopCount", "EcsScriptTaskLoopCount", int64_t(ecs_script_task_loop_t::EcsScriptTaskLoopCount), das::LineInfo());
		addIEx("EcsScriptTaskLoopForever", "EcsScriptTaskLoopForever", int64_t(ecs_script_task_loop_t::EcsScriptTaskLoopForever), das::LineInfo());
	}
};

// from flecs/addons/meta.h:156:14
class Enumeration_ecs_type_kind_t : public das::Enumeration {
public:
	Enumeration_ecs_type_kind_t() : das::Enumeration("ecs_type_kind_t") {
		external = true;
		cppName = "ecs_type_kind_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsPrimitiveType", "EcsPrimitiveType", int64_t(ecs_type_kind_t::EcsPrimitiveType), das::LineInfo());
		addIEx("EcsBitmaskType", "EcsBitmaskType", int64_t(ecs_type_kind_t::EcsBitmaskType), das::LineInfo());
		addIEx("EcsEnumType", "EcsEnumType", int64_t(ecs_type_kind_t::EcsEnumType), das::LineInfo());
		addIEx("EcsStructType", "EcsStructType", int64_t(ecs_type_kind_t::EcsStructType), das::LineInfo());
		addIEx("EcsArrayType", "EcsArrayType", int64_t(ecs_type_kind_t::EcsArrayType), das::LineInfo());
		addIEx("EcsVectorType", "EcsVectorType", int64_t(ecs_type_kind_t::EcsVectorType), das::LineInfo());
		addIEx("EcsOpaqueType", "EcsOpaqueType", int64_t(ecs_type_kind_t::EcsOpaqueType), das::LineInfo());
		addIEx("EcsMapType", "EcsMapType", int64_t(ecs_type_kind_t::EcsMapType), das::LineInfo());
		addIEx("EcsValueType", "EcsValueType", int64_t(ecs_type_kind_t::EcsValueType), das::LineInfo());
		addIEx("EcsTypeKindLast", "EcsTypeKindLast", int64_t(ecs_type_kind_t::EcsTypeKindLast), das::LineInfo());
	}
};

// from flecs/addons/meta.h:177:14
class Enumeration_ecs_primitive_kind_t : public das::Enumeration {
public:
	Enumeration_ecs_primitive_kind_t() : das::Enumeration("ecs_primitive_kind_t") {
		external = true;
		cppName = "ecs_primitive_kind_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsBool", "EcsBool", int64_t(ecs_primitive_kind_t::EcsBool), das::LineInfo());
		addIEx("EcsChar", "EcsChar", int64_t(ecs_primitive_kind_t::EcsChar), das::LineInfo());
		addIEx("EcsByte", "EcsByte", int64_t(ecs_primitive_kind_t::EcsByte), das::LineInfo());
		addIEx("EcsU8", "EcsU8", int64_t(ecs_primitive_kind_t::EcsU8), das::LineInfo());
		addIEx("EcsU16", "EcsU16", int64_t(ecs_primitive_kind_t::EcsU16), das::LineInfo());
		addIEx("EcsU32", "EcsU32", int64_t(ecs_primitive_kind_t::EcsU32), das::LineInfo());
		addIEx("EcsU64", "EcsU64", int64_t(ecs_primitive_kind_t::EcsU64), das::LineInfo());
		addIEx("EcsI8", "EcsI8", int64_t(ecs_primitive_kind_t::EcsI8), das::LineInfo());
		addIEx("EcsI16", "EcsI16", int64_t(ecs_primitive_kind_t::EcsI16), das::LineInfo());
		addIEx("EcsI32", "EcsI32", int64_t(ecs_primitive_kind_t::EcsI32), das::LineInfo());
		addIEx("EcsI64", "EcsI64", int64_t(ecs_primitive_kind_t::EcsI64), das::LineInfo());
		addIEx("EcsF32", "EcsF32", int64_t(ecs_primitive_kind_t::EcsF32), das::LineInfo());
		addIEx("EcsF64", "EcsF64", int64_t(ecs_primitive_kind_t::EcsF64), das::LineInfo());
		addIEx("EcsUPtr", "EcsUPtr", int64_t(ecs_primitive_kind_t::EcsUPtr), das::LineInfo());
		addIEx("EcsIPtr", "EcsIPtr", int64_t(ecs_primitive_kind_t::EcsIPtr), das::LineInfo());
		addIEx("EcsString", "EcsString", int64_t(ecs_primitive_kind_t::EcsString), das::LineInfo());
		addIEx("EcsEntity", "EcsEntity", int64_t(ecs_primitive_kind_t::EcsEntity), das::LineInfo());
		addIEx("EcsId", "EcsId", int64_t(ecs_primitive_kind_t::EcsId), das::LineInfo());
		addIEx("EcsPrimitiveKindLast", "EcsPrimitiveKindLast", int64_t(ecs_primitive_kind_t::EcsPrimitiveKindLast), das::LineInfo());
	}
};

// from flecs/addons/meta.h:541:14
class Enumeration_ecs_meta_op_kind_t : public das::Enumeration {
public:
	Enumeration_ecs_meta_op_kind_t() : das::Enumeration("ecs_meta_op_kind_t") {
		external = true;
		cppName = "ecs_meta_op_kind_t";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EcsOpPushStruct", "EcsOpPushStruct", int64_t(ecs_meta_op_kind_t::EcsOpPushStruct), das::LineInfo());
		addIEx("EcsOpPushArray", "EcsOpPushArray", int64_t(ecs_meta_op_kind_t::EcsOpPushArray), das::LineInfo());
		addIEx("EcsOpPushVector", "EcsOpPushVector", int64_t(ecs_meta_op_kind_t::EcsOpPushVector), das::LineInfo());
		addIEx("EcsOpPushMap", "EcsOpPushMap", int64_t(ecs_meta_op_kind_t::EcsOpPushMap), das::LineInfo());
		addIEx("EcsOpPushValue", "EcsOpPushValue", int64_t(ecs_meta_op_kind_t::EcsOpPushValue), das::LineInfo());
		addIEx("EcsOpPop", "EcsOpPop", int64_t(ecs_meta_op_kind_t::EcsOpPop), das::LineInfo());
		addIEx("EcsOpOpaqueStruct", "EcsOpOpaqueStruct", int64_t(ecs_meta_op_kind_t::EcsOpOpaqueStruct), das::LineInfo());
		addIEx("EcsOpOpaqueArray", "EcsOpOpaqueArray", int64_t(ecs_meta_op_kind_t::EcsOpOpaqueArray), das::LineInfo());
		addIEx("EcsOpOpaqueVector", "EcsOpOpaqueVector", int64_t(ecs_meta_op_kind_t::EcsOpOpaqueVector), das::LineInfo());
		addIEx("EcsOpForward", "EcsOpForward", int64_t(ecs_meta_op_kind_t::EcsOpForward), das::LineInfo());
		addIEx("EcsOpScope", "EcsOpScope", int64_t(ecs_meta_op_kind_t::EcsOpScope), das::LineInfo());
		addIEx("EcsOpOpaqueValue", "EcsOpOpaqueValue", int64_t(ecs_meta_op_kind_t::EcsOpOpaqueValue), das::LineInfo());
		addIEx("EcsOpEnum", "EcsOpEnum", int64_t(ecs_meta_op_kind_t::EcsOpEnum), das::LineInfo());
		addIEx("EcsOpBitmask", "EcsOpBitmask", int64_t(ecs_meta_op_kind_t::EcsOpBitmask), das::LineInfo());
		addIEx("EcsOpPrimitive", "EcsOpPrimitive", int64_t(ecs_meta_op_kind_t::EcsOpPrimitive), das::LineInfo());
		addIEx("EcsOpBool", "EcsOpBool", int64_t(ecs_meta_op_kind_t::EcsOpBool), das::LineInfo());
		addIEx("EcsOpChar", "EcsOpChar", int64_t(ecs_meta_op_kind_t::EcsOpChar), das::LineInfo());
		addIEx("EcsOpByte", "EcsOpByte", int64_t(ecs_meta_op_kind_t::EcsOpByte), das::LineInfo());
		addIEx("EcsOpU8", "EcsOpU8", int64_t(ecs_meta_op_kind_t::EcsOpU8), das::LineInfo());
		addIEx("EcsOpU16", "EcsOpU16", int64_t(ecs_meta_op_kind_t::EcsOpU16), das::LineInfo());
		addIEx("EcsOpU32", "EcsOpU32", int64_t(ecs_meta_op_kind_t::EcsOpU32), das::LineInfo());
		addIEx("EcsOpU64", "EcsOpU64", int64_t(ecs_meta_op_kind_t::EcsOpU64), das::LineInfo());
		addIEx("EcsOpI8", "EcsOpI8", int64_t(ecs_meta_op_kind_t::EcsOpI8), das::LineInfo());
		addIEx("EcsOpI16", "EcsOpI16", int64_t(ecs_meta_op_kind_t::EcsOpI16), das::LineInfo());
		addIEx("EcsOpI32", "EcsOpI32", int64_t(ecs_meta_op_kind_t::EcsOpI32), das::LineInfo());
		addIEx("EcsOpI64", "EcsOpI64", int64_t(ecs_meta_op_kind_t::EcsOpI64), das::LineInfo());
		addIEx("EcsOpF32", "EcsOpF32", int64_t(ecs_meta_op_kind_t::EcsOpF32), das::LineInfo());
		addIEx("EcsOpF64", "EcsOpF64", int64_t(ecs_meta_op_kind_t::EcsOpF64), das::LineInfo());
		addIEx("EcsOpUPtr", "EcsOpUPtr", int64_t(ecs_meta_op_kind_t::EcsOpUPtr), das::LineInfo());
		addIEx("EcsOpIPtr", "EcsOpIPtr", int64_t(ecs_meta_op_kind_t::EcsOpIPtr), das::LineInfo());
		addIEx("EcsOpString", "EcsOpString", int64_t(ecs_meta_op_kind_t::EcsOpString), das::LineInfo());
		addIEx("EcsOpEntity", "EcsOpEntity", int64_t(ecs_meta_op_kind_t::EcsOpEntity), das::LineInfo());
		addIEx("EcsOpId", "EcsOpId", int64_t(ecs_meta_op_kind_t::EcsOpId), das::LineInfo());
		addIEx("EcsMetaTypeOpKindLast", "EcsMetaTypeOpKindLast", int64_t(ecs_meta_op_kind_t::EcsMetaTypeOpKindLast), das::LineInfo());
	}
};

