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
void Module_dasFlecs::initFunctions_4() {
// from flecs.h:4096:6
	makeExtern< bool (*)(const ecs_world_t *,ecs_id_t) , ecs_id_is_tag , SimNode_ExtFuncCall >(lib,"ecs_id_is_tag","ecs_id_is_tag")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4109:6
	makeExtern< bool (*)(const ecs_world_t *,ecs_id_t) , ecs_id_in_use , SimNode_ExtFuncCall >(lib,"ecs_id_in_use","ecs_id_in_use")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4133:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_id_t) , ecs_get_typeid , SimNode_ExtFuncCall >(lib,"ecs_get_typeid","ecs_get_typeid")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4146:6
	makeExtern< bool (*)(ecs_id_t,ecs_id_t) , ecs_id_match , SimNode_ExtFuncCall >(lib,"ecs_id_match","ecs_id_match")
		->args({"component","pattern"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4156:6
	makeExtern< bool (*)(ecs_id_t) , ecs_id_is_pair , SimNode_ExtFuncCall >(lib,"ecs_id_is_pair","ecs_id_is_pair")
		->args({"component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4165:6
	makeExtern< bool (*)(ecs_id_t) , ecs_id_is_wildcard , SimNode_ExtFuncCall >(lib,"ecs_id_is_wildcard","ecs_id_is_wildcard")
		->args({"component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4173:6
	makeExtern< bool (*)(ecs_id_t) , ecs_id_is_any , SimNode_ExtFuncCall >(lib,"ecs_id_is_any","ecs_id_is_any")
		->args({"component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4190:6
	makeExtern< bool (*)(const ecs_world_t *,ecs_id_t) , ecs_id_is_valid , SimNode_ExtFuncCall >(lib,"ecs_id_is_valid","ecs_id_is_valid")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4203:15
	makeExtern< unsigned int (*)(const ecs_world_t *,ecs_id_t) , ecs_id_get_flags , SimNode_ExtFuncCall >(lib,"ecs_id_get_flags","ecs_id_get_flags")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4218:13
	makeExtern< const char * (*)(uint64_t) , ecs_id_flag_str , SimNode_ExtFuncCall >(lib,"ecs_id_flag_str","ecs_id_flag_str")
		->args({"component_flags"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4237:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_id_t) , ecs_id_str , SimNode_ExtFuncCall >(lib,"ecs_id_str","ecs_id_str")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4249:6
	makeExtern< void (*)(const ecs_world_t *,ecs_id_t,ecs_strbuf_t *) , ecs_id_str_buf , SimNode_ExtFuncCall >(lib,"ecs_id_str_buf","ecs_id_str_buf")
		->args({"world","component","buf"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4263:10
	makeExtern< ecs_id_t (*)(const ecs_world_t *,const char *) , ecs_id_from_str , SimNode_ExtFuncCall >(lib,"ecs_id_from_str","ecs_id_from_str")
		->args({"world","expr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4283:6
	makeExtern< bool (*)(const ecs_term_ref_t *) , ecs_term_ref_is_set , SimNode_ExtFuncCall >(lib,"ecs_term_ref_is_set","ecs_term_ref_is_set")
		->args({"ref"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4298:6
	makeExtern< bool (*)(const ecs_term_t *) , ecs_term_is_initialized , SimNode_ExtFuncCall >(lib,"ecs_term_is_initialized","ecs_term_is_initialized")
		->args({"term"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4316:6
	makeExtern< bool (*)(const ecs_term_t *) , ecs_term_match_this , SimNode_ExtFuncCall >(lib,"ecs_term_match_this","ecs_term_match_this")
		->args({"term"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4332:6
	makeExtern< bool (*)(const ecs_term_t *) , ecs_term_match_0 , SimNode_ExtFuncCall >(lib,"ecs_term_match_0","ecs_term_match_0")
		->args({"term"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4344:7
	makeExtern< char * (*)(const ecs_world_t *,const ecs_term_t *) , ecs_term_str , SimNode_ExtFuncCall >(lib,"ecs_term_str","ecs_term_str")
		->args({"world","term"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4356:7
	makeExtern< char * (*)(const ecs_query_t *) , ecs_query_str , SimNode_ExtFuncCall >(lib,"ecs_query_str","ecs_query_str")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4400:12
	makeExtern< ecs_iter_t (*)(const ecs_world_t *,ecs_id_t) , ecs_each_id , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_each_id","ecs_each_id")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4410:6
	makeExtern< bool (*)(ecs_iter_t *) , ecs_each_next , SimNode_ExtFuncCall >(lib,"ecs_each_next","ecs_each_next")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4436:32
	makeExtern< ecs_iter_t (*)(const ecs_world_t *,ecs_entity_t) , ecs_children , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_children","ecs_children")
		->args({"world","parent"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4448:32
	makeExtern< ecs_iter_t (*)(const ecs_world_t *,ecs_entity_t,ecs_entity_t) , ecs_children_w_rel , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_children_w_rel","ecs_children_w_rel")
		->args({"world","relationship","parent"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4459:6
	makeExtern< bool (*)(ecs_iter_t *) , ecs_children_next , SimNode_ExtFuncCall >(lib,"ecs_children_next","ecs_children_next")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4481:14
	makeExtern< ecs_query_t * (*)(ecs_world_t *,const ecs_query_desc_t *) , ecs_query_init , SimNode_ExtFuncCall >(lib,"ecs_query_init","ecs_query_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4496:14
	makeExtern< ecs_query_t * (*)(ecs_world_t *,ecs_entity_t,const ecs_query_desc_t *) , ecs_query_update , SimNode_ExtFuncCall >(lib,"ecs_query_update","ecs_query_update")
		->args({"world","entity","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4506:6
	makeExtern< void (*)(ecs_query_t *) , ecs_query_fini , SimNode_ExtFuncCall >(lib,"ecs_query_fini","ecs_query_fini")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4520:9
	makeExtern< int (*)(const ecs_query_t *,const char *) , ecs_query_find_var , SimNode_ExtFuncCall >(lib,"ecs_query_find_var","ecs_query_find_var")
		->args({"query","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4532:13
	makeExtern< const char * (*)(const ecs_query_t *,int) , ecs_query_var_name , SimNode_ExtFuncCall >(lib,"ecs_query_var_name","ecs_query_var_name")
		->args({"query","var_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4547:6
	makeExtern< bool (*)(const ecs_query_t *,int) , ecs_query_var_is_entity , SimNode_ExtFuncCall >(lib,"ecs_query_var_is_entity","ecs_query_var_is_entity")
		->args({"query","var_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4605:12
	makeExtern< ecs_iter_t (*)(const ecs_world_t *,const ecs_query_t *) , ecs_query_iter , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_query_iter","ecs_query_iter")
		->args({"world","query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4617:6
	makeExtern< bool (*)(ecs_iter_t *) , ecs_query_next , SimNode_ExtFuncCall >(lib,"ecs_query_next","ecs_query_next")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4639:6
	makeExtern< bool (*)(const ecs_query_t *,ecs_entity_t,ecs_iter_t *) , ecs_query_has , SimNode_ExtFuncCall >(lib,"ecs_query_has","ecs_query_has")
		->args({"query","entity","it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4663:6
	makeExtern< bool (*)(const ecs_query_t *,ecs_table_t *,ecs_iter_t *) , ecs_query_has_table , SimNode_ExtFuncCall >(lib,"ecs_query_has_table","ecs_query_has_table")
		->args({"query","table","it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4695:6
	makeExtern< bool (*)(const ecs_query_t *,ecs_table_range_t *,ecs_iter_t *) , ecs_query_has_range , SimNode_ExtFuncCall >(lib,"ecs_query_has_range","ecs_query_has_range")
		->args({"query","range","it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4710:9
	makeExtern< int (*)(const ecs_query_t *) , ecs_query_match_count , SimNode_ExtFuncCall >(lib,"ecs_query_match_count","ecs_query_match_count")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4740:7
	makeExtern< char * (*)(const ecs_query_t *) , ecs_query_plan , SimNode_ExtFuncCall >(lib,"ecs_query_plan","ecs_query_plan")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4758:7
	makeExtern< char * (*)(const ecs_query_t *,const ecs_iter_t *) , ecs_query_plan_w_profile , SimNode_ExtFuncCall >(lib,"ecs_query_plan_w_profile","ecs_query_plan_w_profile")
		->args({"query","it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4768:7
	makeExtern< char * (*)(const ecs_query_t *) , ecs_query_plans , SimNode_ExtFuncCall >(lib,"ecs_query_plans","ecs_query_plans")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4789:13
	makeExtern< const char * (*)(ecs_query_t *,ecs_iter_t *,const char *) , ecs_query_args_parse , SimNode_ExtFuncCall >(lib,"ecs_query_args_parse","ecs_query_args_parse")
		->args({"query","it","expr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4820:6
	makeExtern< bool (*)(ecs_query_t *) , ecs_query_changed , SimNode_ExtFuncCall >(lib,"ecs_query_changed","ecs_query_changed")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4833:20
	makeExtern< const ecs_query_t * (*)(const ecs_world_t *,ecs_entity_t) , ecs_query_get , SimNode_ExtFuncCall >(lib,"ecs_query_get","ecs_query_get")
		->args({"world","query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4849:6
	makeExtern< void (*)(ecs_iter_t *) , ecs_iter_skip , SimNode_ExtFuncCall >(lib,"ecs_iter_skip","ecs_iter_skip")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4875:6
	makeExtern< void (*)(ecs_iter_t *,uint64_t) , ecs_iter_set_group , SimNode_ExtFuncCall >(lib,"ecs_iter_set_group","ecs_iter_set_group")
		->args({"it","group_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4905:18
	makeExtern< const ecs_map_t * (*)(const ecs_query_t *) , ecs_query_get_groups , SimNode_ExtFuncCall >(lib,"ecs_query_get_groups","ecs_query_get_groups")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4917:7
	makeExtern< void * (*)(const ecs_query_t *,uint64_t) , ecs_query_get_group_ctx , SimNode_ExtFuncCall >(lib,"ecs_query_get_group_ctx","ecs_query_get_group_ctx")
		->args({"query","group_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4930:31
	makeExtern< const ecs_query_group_info_t * (*)(const ecs_query_t *,uint64_t) , ecs_query_get_group_info , SimNode_ExtFuncCall >(lib,"ecs_query_get_group_info","ecs_query_get_group_info")
		->args({"query","group_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4952:19
	makeExtern< ecs_query_count_t (*)(const ecs_query_t *) , ecs_query_count , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_query_count","ecs_query_count")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4961:6
	makeExtern< bool (*)(const ecs_query_t *) , ecs_query_is_true , SimNode_ExtFuncCall >(lib,"ecs_query_is_true","ecs_query_is_true")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4975:20
	makeExtern< const ecs_query_t * (*)(const ecs_query_t *) , ecs_query_get_cache_query , SimNode_ExtFuncCall >(lib,"ecs_query_get_cache_query","ecs_query_get_cache_query")
		->args({"query"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

