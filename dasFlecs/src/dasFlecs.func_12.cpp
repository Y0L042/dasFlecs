// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/simulate/bind_enum.h"
#include "dasFlecs.h"
#include "need_dasFlecs.h"
namespace das {
#include "dasFlecs.func.aot.decl.inc"
void Module_dasFlecs::initFunctions_12() {
// from flecs/addons/meta.h:1255:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,void *,void *) , ecs_ptr_move , SimNode_ExtFuncCall >(lib,"ecs_ptr_move","ecs_ptr_move")
		->args({"world","type","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1270:5
	makeExtern< int (*)(const ecs_world_t *,const ecs_type_info_t *,void *,void *) , ecs_ptr_move_ctor_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_ptr_move_ctor_w_type_info","ecs_ptr_move_ctor_w_type_info")
		->args({"world","ti","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1285:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,void *,void *) , ecs_ptr_move_ctor , SimNode_ExtFuncCall >(lib,"ecs_ptr_move_ctor","ecs_ptr_move_ctor")
		->args({"world","type","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1309:6
	makeExtern< void (*)(const ecs_world_t *,ecs_value_t *,ecs_entity_t,const void *) , ecs_value_set , SimNode_ExtFuncCall >(lib,"ecs_value_set","ecs_value_set")
		->args({"world","v","type","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1322:13
	makeExtern< ecs_value_t (*)(const ecs_world_t *,ecs_entity_t) , ecs_value_new , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_value_new","ecs_value_new")
		->args({"world","type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1334:13
	makeExtern< ecs_value_t (*)(const ecs_world_t *,ecs_entity_t,const void *) , ecs_value_init , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_value_init","ecs_value_init")
		->args({"world","type","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1346:6
	makeExtern< void (*)(const ecs_world_t *,ecs_value_t *) , ecs_value_fini , SimNode_ExtFuncCall >(lib,"ecs_value_fini","ecs_value_fini")
		->args({"world","v"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1358:6
	makeExtern< void (*)(const ecs_world_t *,ecs_value_t *,const ecs_value_t *) , ecs_value_copy , SimNode_ExtFuncCall >(lib,"ecs_value_copy","ecs_value_copy")
		->args({"world","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1371:6
	makeExtern< void (*)(const ecs_world_t *,ecs_value_t *,const ecs_value_t *) , ecs_value_copy_ctor , SimNode_ExtFuncCall >(lib,"ecs_value_copy_ctor","ecs_value_copy_ctor")
		->args({"world","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1385:6
	makeExtern< void (*)(const ecs_world_t *,ecs_value_t *,ecs_value_t *) , ecs_value_move , SimNode_ExtFuncCall >(lib,"ecs_value_move","ecs_value_move")
		->args({"world","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1398:6
	makeExtern< void (*)(const ecs_world_t *,ecs_value_t *,ecs_value_t *) , ecs_value_move_ctor , SimNode_ExtFuncCall >(lib,"ecs_value_move_ctor","ecs_value_move_ctor")
		->args({"world","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1411:5
	makeExtern< int (*)(const ecs_world_t *,const ecs_value_t *,const ecs_value_t *) , ecs_value_compare , SimNode_ExtFuncCall >(lib,"ecs_value_compare","ecs_value_compare")
		->args({"world","a","b"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1424:6
	makeExtern< bool (*)(const ecs_world_t *,const ecs_value_t *,const ecs_value_t *) , ecs_value_equals , SimNode_ExtFuncCall >(lib,"ecs_value_equals","ecs_value_equals")
		->args({"world","a","b"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1443:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t) , ecs_set_rtt_compare , SimNode_ExtFuncCall >(lib,"ecs_set_rtt_compare","ecs_set_rtt_compare")
		->args({"world","type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1461:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t) , ecs_set_rtt_equals , SimNode_ExtFuncCall >(lib,"ecs_set_rtt_equals","ecs_set_rtt_equals")
		->args({"world","type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1480:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_primitive_desc_t *) , ecs_primitive_init , SimNode_ExtFuncCall >(lib,"ecs_primitive_init","ecs_primitive_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1499:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_enum_desc_t *) , ecs_enum_init , SimNode_ExtFuncCall >(lib,"ecs_enum_init","ecs_enum_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1517:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_bitmask_desc_t *) , ecs_bitmask_init , SimNode_ExtFuncCall >(lib,"ecs_bitmask_init","ecs_bitmask_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1536:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_array_desc_t *) , ecs_array_init , SimNode_ExtFuncCall >(lib,"ecs_array_init","ecs_array_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1554:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_vector_desc_t *) , ecs_vector_init , SimNode_ExtFuncCall >(lib,"ecs_vector_init","ecs_vector_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1573:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_map_desc_t *) , ecs_map_type_init , SimNode_ExtFuncCall >(lib,"ecs_map_type_init","ecs_map_type_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1592:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_struct_desc_t *) , ecs_struct_init , SimNode_ExtFuncCall >(lib,"ecs_struct_init","ecs_struct_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1605:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,const ecs_member_t *) , ecs_struct_add_member , SimNode_ExtFuncCall >(lib,"ecs_struct_add_member","ecs_struct_add_member")
		->args({"world","type","member"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1618:15
	makeExtern< ecs_member_t * (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_struct_get_member , SimNode_ExtFuncCall >(lib,"ecs_struct_get_member","ecs_struct_get_member")
		->args({"world","type","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1631:15
	makeExtern< ecs_member_t * (*)(ecs_world_t *,ecs_entity_t,int) , ecs_struct_get_nth_member , SimNode_ExtFuncCall >(lib,"ecs_struct_get_nth_member","ecs_struct_get_nth_member")
		->args({"world","type","i"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1665:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_opaque_desc_t *) , ecs_opaque_init , SimNode_ExtFuncCall >(lib,"ecs_opaque_init","ecs_opaque_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1706:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_unit_desc_t *) , ecs_unit_init , SimNode_ExtFuncCall >(lib,"ecs_unit_init","ecs_unit_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1730:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_unit_prefix_desc_t *) , ecs_unit_prefix_init , SimNode_ExtFuncCall >(lib,"ecs_unit_prefix_init","ecs_unit_prefix_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1742:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_entity_desc_t *) , ecs_quantity_init , SimNode_ExtFuncCall >(lib,"ecs_quantity_init","ecs_quantity_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta_c.h:71:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,ecs_type_kind_t,const char *) , ecs_meta_from_desc , SimNode_ExtFuncCall >(lib,"ecs_meta_from_desc","ecs_meta_from_desc")
		->args({"world","component","kind","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/module.h:85:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const char *,const char *) , ecs_import_from_library , SimNode_ExtFuncCall >(lib,"ecs_import_from_library","ecs_import_from_library")
		->args({"world","library_name","module_name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/module.h:98:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const char *,const ecs_component_desc_t *) , ecs_module_init , SimNode_ExtFuncCall >(lib,"ecs_module_init","ecs_module_init")
		->args({"world","c_name","desc"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

