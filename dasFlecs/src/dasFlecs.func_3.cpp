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
void Module_dasFlecs::initFunctions_3() {
// from flecs.h:3119:11
	makeExtern< ecs_ref_t (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t,void *) , ecs_ref_from_ptr , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_ref_from_ptr","ecs_ref_from_ptr")
		->args({"world","entity","component","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3136:7
	makeExtern< void * (*)(const ecs_world_t *,ecs_ref_t *,ecs_id_t) , ecs_ref_get_id , SimNode_ExtFuncCall >(lib,"ecs_ref_get_id","ecs_ref_get_id")
		->args({"world","ref","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3150:6
	makeExtern< void (*)(const ecs_world_t *,ecs_ref_t *,ecs_id_t) , ecs_ref_update , SimNode_ExtFuncCall >(lib,"ecs_ref_update","ecs_ref_update")
		->args({"world","ref","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3176:7
	makeExtern< void * (*)(ecs_world_t *,ecs_entity_t,ecs_id_t,size_t,bool *) , ecs_emplace_id , SimNode_ExtFuncCall >(lib,"ecs_emplace_id","ecs_emplace_id")
		->args({"world","entity","component","size","is_new"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3193:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_modified_id , SimNode_ExtFuncCall >(lib,"ecs_modified_id","ecs_modified_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3214:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,ecs_id_t,size_t,const void *) , ecs_set_id , SimNode_ExtFuncCall >(lib,"ecs_set_id","ecs_set_id")
		->args({"world","entity","component","size","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3250:6
	makeExtern< bool (*)(const ecs_world_t *,ecs_entity_t) , ecs_is_valid , SimNode_ExtFuncCall >(lib,"ecs_is_valid","ecs_is_valid")
		->args({"world","e"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3284:6
	makeExtern< bool (*)(const ecs_world_t *,ecs_entity_t) , ecs_is_alive , SimNode_ExtFuncCall >(lib,"ecs_is_alive","ecs_is_alive")
		->args({"world","e"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3294:10
	makeExtern< ecs_id_t (*)(ecs_entity_t) , ecs_strip_generation , SimNode_ExtFuncCall >(lib,"ecs_strip_generation","ecs_strip_generation")
		->args({"e"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3314:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_alive , SimNode_ExtFuncCall >(lib,"ecs_get_alive","ecs_get_alive")
		->args({"world","e"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3341:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_make_alive , SimNode_ExtFuncCall >(lib,"ecs_make_alive","ecs_make_alive")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3364:6
	makeExtern< void (*)(ecs_world_t *,ecs_id_t) , ecs_make_alive_id , SimNode_ExtFuncCall >(lib,"ecs_make_alive_id","ecs_make_alive_id")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3376:6
	makeExtern< bool (*)(const ecs_world_t *,ecs_entity_t) , ecs_exists , SimNode_ExtFuncCall >(lib,"ecs_exists","ecs_exists")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3395:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_set_version , SimNode_ExtFuncCall >(lib,"ecs_set_version","ecs_set_version")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3405:10
	makeExtern< unsigned int (*)(ecs_entity_t) , ecs_get_version , SimNode_ExtFuncCall >(lib,"ecs_get_version","ecs_get_version")
		->args({"entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3424:19
	makeExtern< const ecs_type_t * (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_type , SimNode_ExtFuncCall >(lib,"ecs_get_type","ecs_get_type")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3435:14
	makeExtern< ecs_table_t * (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_table , SimNode_ExtFuncCall >(lib,"ecs_get_table","ecs_get_table")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3447:7
	makeExtern< char * (*)(const ecs_world_t *,const ecs_type_t *) , ecs_type_str , SimNode_ExtFuncCall >(lib,"ecs_type_str","ecs_type_str")
		->args({"world","type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3463:7
	makeExtern< char * (*)(const ecs_world_t *,const ecs_table_t *) , ecs_table_str , SimNode_ExtFuncCall >(lib,"ecs_table_str","ecs_table_str")
		->args({"world","table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3482:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_entity_str , SimNode_ExtFuncCall >(lib,"ecs_entity_str","ecs_entity_str")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3497:26
	makeExtern< bool (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_has_id , SimNode_ExtFuncCall >(lib,"ecs_has_id","ecs_has_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3513:26
	makeExtern< bool (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t) , ecs_owns_id , SimNode_ExtFuncCall >(lib,"ecs_owns_id","ecs_owns_id")
		->args({"world","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3533:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t,ecs_entity_t,int) , ecs_get_target , SimNode_ExtFuncCall >(lib,"ecs_get_target","ecs_get_target")
		->args({"world","entity","rel","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3553:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_parent , SimNode_ExtFuncCall >(lib,"ecs_get_parent","ecs_get_parent")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3571:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_new_w_parent , SimNode_ExtFuncCall >(lib,"ecs_new_w_parent","ecs_new_w_parent")
		->args({"world","parent","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3597:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t,ecs_entity_t,ecs_id_t) , ecs_get_target_for_id , SimNode_ExtFuncCall >(lib,"ecs_get_target_for_id","ecs_get_target_for_id")
		->args({"world","entity","rel","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3614:9
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,ecs_entity_t) , ecs_get_depth , SimNode_ExtFuncCall >(lib,"ecs_get_depth","ecs_get_depth")
		->args({"world","entity","rel"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3627:9
	makeExtern< int (*)(const ecs_world_t *,ecs_id_t) , ecs_count_id , SimNode_ExtFuncCall >(lib,"ecs_count_id","ecs_count_id")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3651:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_name , SimNode_ExtFuncCall >(lib,"ecs_get_name","ecs_get_name")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3665:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_symbol , SimNode_ExtFuncCall >(lib,"ecs_get_symbol","ecs_get_symbol")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3683:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_set_name , SimNode_ExtFuncCall >(lib,"ecs_set_name","ecs_set_name")
		->args({"world","entity","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3702:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_set_symbol , SimNode_ExtFuncCall >(lib,"ecs_set_symbol","ecs_set_symbol")
		->args({"world","entity","symbol"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3719:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_set_alias , SimNode_ExtFuncCall >(lib,"ecs_set_alias","ecs_set_alias")
		->args({"world","entity","alias"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3740:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,const char *) , ecs_lookup , SimNode_ExtFuncCall >(lib,"ecs_lookup","ecs_lookup")
		->args({"world","path"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3759:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t,const char *) , ecs_lookup_child , SimNode_ExtFuncCall >(lib,"ecs_lookup_child","ecs_lookup_child")
		->args({"world","parent","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3787:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t,const char *,const char *,const char *,bool) , ecs_lookup_path_w_sep , SimNode_ExtFuncCall >(lib,"ecs_lookup_path_w_sep","ecs_lookup_path_w_sep")
		->args({"world","parent","path","sep","prefix","recursive"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3813:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,const char *,bool,bool) , ecs_lookup_symbol , SimNode_ExtFuncCall >(lib,"ecs_lookup_symbol","ecs_lookup_symbol")
		->args({"world","symbol","lookup_as_path","recursive"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3841:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_entity_t,ecs_entity_t,const char *,const char *) , ecs_get_path_w_sep , SimNode_ExtFuncCall >(lib,"ecs_get_path_w_sep","ecs_get_path_w_sep")
		->args({"world","parent","child","sep","prefix"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3862:6
	makeExtern< void (*)(const ecs_world_t *,ecs_entity_t,ecs_entity_t,const char *,const char *,ecs_strbuf_t *,bool) , ecs_get_path_w_sep_buf , SimNode_ExtFuncCall >(lib,"ecs_get_path_w_sep_buf","ecs_get_path_w_sep_buf")
		->args({"world","parent","child","sep","prefix","buf","escape"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3887:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,const char *,const char *,const char *) , ecs_new_from_path_w_sep , SimNode_ExtFuncCall >(lib,"ecs_new_from_path_w_sep","ecs_new_from_path_w_sep")
		->args({"world","parent","path","sep","prefix"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3909:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,ecs_entity_t,const char *,const char *,const char *) , ecs_add_path_w_sep , SimNode_ExtFuncCall >(lib,"ecs_add_path_w_sep","ecs_add_path_w_sep")
		->args({"world","entity","parent","path","sep","prefix"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3931:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t) , ecs_set_scope , SimNode_ExtFuncCall >(lib,"ecs_set_scope","ecs_set_scope")
		->args({"world","scope"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3943:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *) , ecs_get_scope , SimNode_ExtFuncCall >(lib,"ecs_get_scope","ecs_get_scope")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3956:13
	makeExtern< const char * (*)(ecs_world_t *,const char *) , ecs_set_name_prefix , SimNode_ExtFuncCall >(lib,"ecs_set_name_prefix","ecs_set_name_prefix")
		->args({"world","prefix"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3987:15
	makeExtern< ecs_entity_t * (*)(ecs_world_t *,const ecs_entity_t *) , ecs_set_lookup_path , SimNode_ExtFuncCall >(lib,"ecs_set_lookup_path","ecs_set_lookup_path")
		->args({"world","lookup_path"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:3998:15
	makeExtern< ecs_entity_t * (*)(const ecs_world_t *) , ecs_get_lookup_path , SimNode_ExtFuncCall >(lib,"ecs_get_lookup_path","ecs_get_lookup_path")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4026:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_component_desc_t *) , ecs_component_init , SimNode_ExtFuncCall >(lib,"ecs_component_init","ecs_component_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4040:24
	makeExtern< const ecs_type_info_t * (*)(const ecs_world_t *,ecs_id_t) , ecs_get_type_info , SimNode_ExtFuncCall >(lib,"ecs_get_type_info","ecs_get_type_info")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4056:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const ecs_type_hooks_t *) , ecs_set_hooks_id , SimNode_ExtFuncCall >(lib,"ecs_set_hooks_id","ecs_set_hooks_id")
		->args({"world","component","hooks"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:4068:25
	makeExtern< const ecs_type_hooks_t * (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_hooks_id , SimNode_ExtFuncCall >(lib,"ecs_get_hooks_id","ecs_get_hooks_id")
		->args({"world","component"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

