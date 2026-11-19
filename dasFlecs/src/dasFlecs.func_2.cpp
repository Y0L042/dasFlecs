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
void Module_dasFlecs::initFunctions_2() {
// from flecs.h:2174:6
	makeExtern< void (*)(ecs_world_t *) , ecs_readonly_end , SimNode_ExtFuncCall >(lib,"ecs_readonly_end","ecs_readonly_end")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2183:6
	makeExtern< void (*)(ecs_world_t *) , ecs_merge , SimNode_ExtFuncCall >(lib,"ecs_merge","ecs_merge")
		->args({"stage"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2193:6
	makeExtern< bool (*)(const ecs_world_t *) , ecs_is_stage , SimNode_ExtFuncCall >(lib,"ecs_is_stage","ecs_is_stage")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2210:6
	makeExtern< void (*)(ecs_world_t *,int) , ecs_set_stage_count , SimNode_ExtFuncCall >(lib,"ecs_set_stage_count","ecs_set_stage_count")
		->args({"world","stages"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2221:9
	makeExtern< int (*)(const ecs_world_t *) , ecs_get_stage_count , SimNode_ExtFuncCall >(lib,"ecs_get_stage_count","ecs_get_stage_count")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2240:14
	makeExtern< ecs_world_t * (*)(const ecs_world_t *,int) , ecs_get_stage , SimNode_ExtFuncCall >(lib,"ecs_get_stage","ecs_get_stage")
		->args({"world","stage_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2252:6
	makeExtern< bool (*)(const ecs_world_t *) , ecs_stage_is_readonly , SimNode_ExtFuncCall >(lib,"ecs_stage_is_readonly","ecs_stage_is_readonly")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2263:14
	makeExtern< ecs_world_t * (*)(ecs_world_t *) , ecs_stage_new , SimNode_ExtFuncCall >(lib,"ecs_stage_new","ecs_stage_new")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2271:6
	makeExtern< void (*)(ecs_world_t *) , ecs_stage_free , SimNode_ExtFuncCall >(lib,"ecs_stage_free","ecs_stage_free")
		->args({"stage"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2282:9
	makeExtern< int (*)(const ecs_world_t *) , ecs_stage_get_id , SimNode_ExtFuncCall >(lib,"ecs_stage_get_id","ecs_stage_get_id")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2328:7
	makeExtern< void * (*)(const ecs_world_t *) , ecs_get_ctx , SimNode_ExtFuncCall >(lib,"ecs_get_ctx","ecs_get_ctx")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2339:7
	makeExtern< void * (*)(const ecs_world_t *) , ecs_get_binding_ctx , SimNode_ExtFuncCall >(lib,"ecs_get_binding_ctx","ecs_get_binding_ctx")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2348:25
	makeExtern< const ecs_build_info_t * (*)() , ecs_get_build_info , SimNode_ExtFuncCall >(lib,"ecs_get_build_info","ecs_get_build_info")
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2356:25
	makeExtern< const ecs_world_info_t * (*)(const ecs_world_t *) , ecs_get_world_info , SimNode_ExtFuncCall >(lib,"ecs_get_world_info","ecs_get_world_info")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2368:6
	makeExtern< void (*)(ecs_world_t *,int) , ecs_dim , SimNode_ExtFuncCall >(lib,"ecs_dim","ecs_dim")
		->args({"world","entity_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2387:6
	makeExtern< void (*)(ecs_world_t *) , ecs_shrink , SimNode_ExtFuncCall >(lib,"ecs_shrink","ecs_shrink")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2396:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *) , ecs_get_max_id , SimNode_ExtFuncCall >(lib,"ecs_get_max_id","ecs_get_max_id")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2413:6
	makeExtern< void (*)(ecs_world_t *,unsigned int) , ecs_run_aperiodic , SimNode_ExtFuncCall >(lib,"ecs_run_aperiodic","ecs_run_aperiodic")
		->args({"world","flags"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2469:9
	makeExtern< int (*)(ecs_world_t *,const ecs_delete_empty_tables_desc_t *) , ecs_delete_empty_tables , SimNode_ExtFuncCall >(lib,"ecs_delete_empty_tables","ecs_delete_empty_tables")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2479:20
	makeExtern< const ecs_world_t * (*)(const void *) , ecs_get_world , SimNode_ExtFuncCall >(lib,"ecs_get_world","ecs_get_world")
		->args({"poly"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2488:14
	makeExtern< ecs_entity_t (*)(const void *) , ecs_get_entity , SimNode_ExtFuncCall >(lib,"ecs_get_entity","ecs_get_entity")
		->args({"poly"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2524:10
	makeExtern< ecs_id_t (*)(ecs_entity_t,ecs_entity_t) , ecs_make_pair , SimNode_ExtFuncCall >(lib,"ecs_make_pair","ecs_make_pair")
		->args({"first","second"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2551:6
	makeExtern< void (*)(ecs_world_t *,const char *) , ecs_exclusive_access_begin , SimNode_ExtFuncCall >(lib,"ecs_exclusive_access_begin","ecs_exclusive_access_begin")
		->args({"world","thread_name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2578:6
	makeExtern< void (*)(ecs_world_t *,bool) , ecs_exclusive_access_end , SimNode_ExtFuncCall >(lib,"ecs_exclusive_access_end","ecs_exclusive_access_end")
		->args({"world","lock_world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2608:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *) , ecs_new , SimNode_ExtFuncCall >(lib,"ecs_new","ecs_new")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2629:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *) , ecs_new_low_id , SimNode_ExtFuncCall >(lib,"ecs_new_low_id","ecs_new_low_id")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2640:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_id_t) , ecs_new_w_id , SimNode_ExtFuncCall >(lib,"ecs_new_w_id","ecs_new_w_id")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2652:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_table_t *) , ecs_new_w_table , SimNode_ExtFuncCall >(lib,"ecs_new_w_table","ecs_new_w_table")
		->args({"world","table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2675:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_entity_desc_t *) , ecs_entity_init , SimNode_ExtFuncCall >(lib,"ecs_entity_init","ecs_entity_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2690:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_value_t *) , ecs_insert_w_values , SimNode_ExtFuncCall >(lib,"ecs_insert_w_values","ecs_insert_w_values")
		->args({"world","values"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2721:21
	makeExtern< const ecs_entity_t * (*)(ecs_world_t *,const ecs_bulk_desc_t *) , ecs_bulk_init , SimNode_ExtFuncCall >(lib,"ecs_bulk_init","ecs_bulk_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2735:21
	makeExtern< const ecs_entity_t * (*)(ecs_world_t *,ecs_id_t,int) , ecs_bulk_new_w_id , SimNode_ExtFuncCall >(lib,"ecs_bulk_new_w_id","ecs_bulk_new_w_id")
		->args({"world","component","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2756:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,ecs_entity_t,bool) , ecs_clone , SimNode_ExtFuncCall >(lib,"ecs_clone","ecs_clone")
		->args({"world","dst","src","copy_value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2771:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_delete , SimNode_ExtFuncCall >(lib,"ecs_delete","ecs_delete")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2783:6
	makeExtern< void (*)(ecs_world_t *,ecs_id_t) , ecs_delete_with , SimNode_ExtFuncCall >(lib,"ecs_delete_with","ecs_delete_with")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2805:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const ecs_entity_t *,int) , ecs_set_child_order , SimNode_ExtFuncCall >(lib,"ecs_set_child_order","ecs_set_child_order")
		->args({"world","parent","children","child_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2821:16
	makeExtern< ecs_entities_t (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_ordered_children , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_get_ordered_children","ecs_get_ordered_children")
		->args({"world","parent"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2843:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_add_id , SimNode_ExtFuncCall >(lib,"ecs_add_id","ecs_add_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2857:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_remove_id , SimNode_ExtFuncCall >(lib,"ecs_remove_id","ecs_remove_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2914:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_auto_override_id , SimNode_ExtFuncCall >(lib,"ecs_auto_override_id","ecs_auto_override_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2926:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_clear , SimNode_ExtFuncCall >(lib,"ecs_clear","ecs_clear")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2938:6
	makeExtern< void (*)(ecs_world_t *,ecs_id_t) , ecs_remove_all , SimNode_ExtFuncCall >(lib,"ecs_remove_all","ecs_remove_all")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2961:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,bool) , ecs_enable , SimNode_ExtFuncCall >(lib,"ecs_enable","ecs_enable")
		->args({"world","entity","enabled"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2980:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,ecs_id_t,bool) , ecs_enable_id , SimNode_ExtFuncCall >(lib,"ecs_enable_id","ecs_enable_id")
		->args({"world","entity","component","enable"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2997:6
	makeExtern< bool (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_is_enabled_id , SimNode_ExtFuncCall >(lib,"ecs_is_enabled_id","ecs_is_enabled_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3026:33
	makeExtern< const void * (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_get_id , SimNode_ExtFuncCall >(lib,"ecs_get_id","ecs_get_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3046:27
	makeExtern< void * (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_get_mut_id , SimNode_ExtFuncCall >(lib,"ecs_get_mut_id","ecs_get_mut_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3066:27
	makeExtern< void * (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t,size_t) , ecs_get_sparse_id , SimNode_ExtFuncCall >(lib,"ecs_get_sparse_id","ecs_get_sparse_id")
		->args({"world","entity","component","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3085:7
	makeExtern< void * (*)(ecs_world_t *,ecs_entity_t,ecs_id_t,size_t) , ecs_ensure_id , SimNode_ExtFuncCall >(lib,"ecs_ensure_id","ecs_ensure_id")
		->args({"world","entity","component","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3102:11
	makeExtern< ecs_ref_t (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_ref_init_id , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_ref_init_id","ecs_ref_init_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

