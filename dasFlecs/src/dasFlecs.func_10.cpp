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
void Module_dasFlecs::initFunctions_10() {
// from flecs/addons/script.h:873:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_script_reload , SimNode_ExtFuncCall >(lib,"ecs_script_reload","ecs_script_reload")
		->args({"world","script","code"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:891:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t) , ecs_script_undo , SimNode_ExtFuncCall >(lib,"ecs_script_undo","ecs_script_undo")
		->args({"world","script"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:902:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,ecs_entity_t) , ecs_script_clear , SimNode_ExtFuncCall >(lib,"ecs_script_clear","ecs_script_clear")
		->args({"world","script","instance"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:930:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t) , ecs_script_from_scene , SimNode_ExtFuncCall >(lib,"ecs_script_from_scene","ecs_script_from_scene")
		->args({"world","script"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:944:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t) , ecs_script_save , SimNode_ExtFuncCall >(lib,"ecs_script_save","ecs_script_save")
		->args({"world","script"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:969:20
	makeExtern< ecs_script_vars_t * (*)(ecs_world_t *) , ecs_script_vars_init , SimNode_ExtFuncCall >(lib,"ecs_script_vars_init","ecs_script_vars_init")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:979:6
	makeExtern< void (*)(ecs_script_vars_t *) , ecs_script_vars_fini , SimNode_ExtFuncCall >(lib,"ecs_script_vars_fini","ecs_script_vars_fini")
		->args({"vars"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:994:20
	makeExtern< ecs_script_vars_t * (*)(ecs_script_vars_t *) , ecs_script_vars_push , SimNode_ExtFuncCall >(lib,"ecs_script_vars_push","ecs_script_vars_push")
		->args({"parent"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1006:20
	makeExtern< ecs_script_vars_t * (*)(ecs_script_vars_t *) , ecs_script_vars_pop , SimNode_ExtFuncCall >(lib,"ecs_script_vars_pop","ecs_script_vars_pop")
		->args({"vars"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1022:19
	makeExtern< ecs_script_var_t * (*)(ecs_script_vars_t *,const char *) , ecs_script_vars_declare , SimNode_ExtFuncCall >(lib,"ecs_script_vars_declare","ecs_script_vars_declare")
		->args({"vars","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1042:19
	makeExtern< ecs_script_var_t * (*)(ecs_script_vars_t *,const char *,ecs_entity_t) , ecs_script_vars_define_id , SimNode_ExtFuncCall >(lib,"ecs_script_vars_define_id","ecs_script_vars_define_id")
		->args({"vars","name","type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1060:19
	makeExtern< ecs_script_var_t * (*)(const ecs_script_vars_t *,const char *) , ecs_script_vars_lookup , SimNode_ExtFuncCall >(lib,"ecs_script_vars_lookup","ecs_script_vars_lookup")
		->args({"vars","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1077:19
	makeExtern< ecs_script_var_t * (*)(const ecs_script_vars_t *,int) , ecs_script_vars_from_sp , SimNode_ExtFuncCall >(lib,"ecs_script_vars_from_sp","ecs_script_vars_from_sp")
		->args({"vars","sp"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1087:6
	makeExtern< void (*)(const ecs_script_vars_t *) , ecs_script_vars_print , SimNode_ExtFuncCall >(lib,"ecs_script_vars_print","ecs_script_vars_print")
		->args({"vars"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1099:6
	makeExtern< void (*)(ecs_script_vars_t *,int) , ecs_script_vars_set_size , SimNode_ExtFuncCall >(lib,"ecs_script_vars_set_size","ecs_script_vars_set_size")
		->args({"vars","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1136:6
	makeExtern< void (*)(const ecs_iter_t *,ecs_script_vars_t *,int) , ecs_script_vars_from_iter , SimNode_ExtFuncCall >(lib,"ecs_script_vars_from_iter","ecs_script_vars_from_iter")
		->args({"it","vars","offset"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1194:13
	makeExtern< const char * (*)(ecs_world_t *,const char *,ecs_value_t *,const ecs_expr_eval_desc_t *) , ecs_expr_run , SimNode_ExtFuncCall >(lib,"ecs_expr_run","ecs_expr_run")
		->args({"world","ptr","value","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1210:15
	makeExtern< ecs_script_t * (*)(ecs_world_t *,const char *,const ecs_expr_eval_desc_t *) , ecs_expr_parse , SimNode_ExtFuncCall >(lib,"ecs_expr_parse","ecs_expr_parse")
		->args({"world","expr","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1230:5
	makeExtern< int (*)(const ecs_script_t *,ecs_value_t *,const ecs_expr_eval_desc_t *) , ecs_expr_eval , SimNode_ExtFuncCall >(lib,"ecs_expr_eval","ecs_expr_eval")
		->args({"script","value","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1249:7
	makeExtern< char * (*)(ecs_world_t *,const char *,const ecs_script_vars_t *) , ecs_script_string_interpolate , SimNode_ExtFuncCall >(lib,"ecs_script_string_interpolate","ecs_script_string_interpolate")
		->args({"world","str","vars"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1280:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_const_var_desc_t *) , ecs_const_var_init , SimNode_ExtFuncCall >(lib,"ecs_const_var_init","ecs_const_var_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1297:13
	makeExtern< ecs_value_t (*)(const ecs_world_t *,ecs_entity_t) , ecs_const_var_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_const_var_get","ecs_const_var_get")
		->args({"world","var"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1320:7
	makeExtern< void * (*)(const ecs_world_t *,const char *,ecs_entity_t,int,void *) , ecs_const_var_get_w_type , SimNode_ExtFuncCall >(lib,"ecs_const_var_get_w_type","ecs_const_var_get_w_type")
		->args({"world","name","type","size","out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1376:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_mut_var_desc_t *) , ecs_mut_var_init , SimNode_ExtFuncCall >(lib,"ecs_mut_var_init","ecs_mut_var_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1393:13
	makeExtern< ecs_value_t (*)(const ecs_world_t *,ecs_entity_t) , ecs_mut_var_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_mut_var_get","ecs_mut_var_get")
		->args({"world","var"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1416:7
	makeExtern< void * (*)(const ecs_world_t *,const char *,ecs_entity_t,int,void *) , ecs_mut_var_get_w_type , SimNode_ExtFuncCall >(lib,"ecs_mut_var_get_w_type","ecs_mut_var_get_w_type")
		->args({"world","name","type","size","out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1465:5
	makeExtern< int (*)(ecs_world_t *,const char *,ecs_entity_t,int,const void *) , ecs_mut_var_set_w_type , SimNode_ExtFuncCall >(lib,"ecs_mut_var_set_w_type","ecs_mut_var_set_w_type")
		->args({"world","name","type","size","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1500:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_mut_var_modified , SimNode_ExtFuncCall >(lib,"ecs_mut_var_modified","ecs_mut_var_modified")
		->args({"world","var"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1592:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_function_desc_t *) , ecs_function_init , SimNode_ExtFuncCall >(lib,"ecs_function_init","ecs_function_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1600:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,int,const ecs_value_t *,ecs_value_t *) , ecs_function_call , SimNode_ExtFuncCall >(lib,"ecs_function_call","ecs_function_call")
		->args({"world","function","argc","argv","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1620:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_function_desc_t *) , ecs_method_init , SimNode_ExtFuncCall >(lib,"ecs_method_init","ecs_method_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1628:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,const ecs_value_t *,int,const ecs_value_t *,ecs_value_t *) , ecs_method_call , SimNode_ExtFuncCall >(lib,"ecs_method_call","ecs_method_call")
		->args({"world","method","instance","argc","argv","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1649:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_entity_t,const void *) , ecs_ptr_to_expr , SimNode_ExtFuncCall >(lib,"ecs_ptr_to_expr","ecs_ptr_to_expr")
		->args({"world","type","data"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1664:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,const void *,ecs_strbuf_t *) , ecs_ptr_to_expr_buf , SimNode_ExtFuncCall >(lib,"ecs_ptr_to_expr_buf","ecs_ptr_to_expr_buf")
		->args({"world","type","data","buf"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1682:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_entity_t,const void *) , ecs_ptr_to_str , SimNode_ExtFuncCall >(lib,"ecs_ptr_to_str","ecs_ptr_to_str")
		->args({"world","type","data"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1697:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,const void *,ecs_strbuf_t *) , ecs_ptr_to_str_buf , SimNode_ExtFuncCall >(lib,"ecs_ptr_to_str_buf","ecs_ptr_to_str_buf")
		->args({"world","type","data","buf"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:1719:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_type_to_script , SimNode_ExtFuncCall >(lib,"ecs_type_to_script","ecs_type_to_script")
		->args({"world","type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:83:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_doc_set_uuid , SimNode_ExtFuncCall >(lib,"ecs_doc_set_uuid","ecs_doc_set_uuid")
		->args({"world","entity","uuid"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:101:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_doc_set_name , SimNode_ExtFuncCall >(lib,"ecs_doc_set_name","ecs_doc_set_name")
		->args({"world","entity","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:117:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_doc_set_brief , SimNode_ExtFuncCall >(lib,"ecs_doc_set_brief","ecs_doc_set_brief")
		->args({"world","entity","description"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:133:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_doc_set_detail , SimNode_ExtFuncCall >(lib,"ecs_doc_set_detail","ecs_doc_set_detail")
		->args({"world","entity","description"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:149:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_doc_set_link , SimNode_ExtFuncCall >(lib,"ecs_doc_set_link","ecs_doc_set_link")
		->args({"world","entity","link"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:166:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_doc_set_color , SimNode_ExtFuncCall >(lib,"ecs_doc_set_color","ecs_doc_set_color")
		->args({"world","entity","color"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:181:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_doc_get_uuid , SimNode_ExtFuncCall >(lib,"ecs_doc_get_uuid","ecs_doc_get_uuid")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:210:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_doc_get_name , SimNode_ExtFuncCall >(lib,"ecs_doc_get_name","ecs_doc_get_name")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:225:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_doc_get_brief , SimNode_ExtFuncCall >(lib,"ecs_doc_get_brief","ecs_doc_get_brief")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:240:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_doc_get_detail , SimNode_ExtFuncCall >(lib,"ecs_doc_get_detail","ecs_doc_get_detail")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:255:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_doc_get_link , SimNode_ExtFuncCall >(lib,"ecs_doc_get_link","ecs_doc_get_link")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/doc.h:270:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_doc_get_color , SimNode_ExtFuncCall >(lib,"ecs_doc_get_color","ecs_doc_get_color")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:654:7
	makeExtern< char * (*)(ecs_world_t *,ecs_entity_t) , ecs_meta_serializer_to_str , SimNode_ExtFuncCall >(lib,"ecs_meta_serializer_to_str","ecs_meta_serializer_to_str")
		->args({"world","type"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

