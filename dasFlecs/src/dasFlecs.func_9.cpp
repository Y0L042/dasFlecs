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
void Module_dasFlecs::initFunctions_9() {
// from flecs/addons/script_shell.h:301:6
	makeExtern< void (*)(ecs_world_t *,ecs_shell_result_t *) , ecs_shell_result_fini , SimNode_ExtFuncCall >(lib,"ecs_shell_result_fini","ecs_shell_result_fini")
		->args({"world","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_shell.h:312:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *) , ecs_shell_get_session , SimNode_ExtFuncCall >(lib,"ecs_shell_get_session","ecs_shell_get_session")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_shell.h:337:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,const char *,const void *,int,ecs_shell_resource_t *) , ecs_shell_resource_create , SimNode_ExtFuncCall >(lib,"ecs_shell_resource_create","ecs_shell_resource_create")
		->args({"world","session","content_type","data","size","resource"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_shell.h:358:7
	makeExtern< void * (*)(const ecs_world_t *,ecs_entity_t,const char *,int *,const char **) , ecs_shell_resource_read , SimNode_ExtFuncCall >(lib,"ecs_shell_resource_read","ecs_shell_resource_read")
		->args({"world","session","name","size","content_type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:62:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,ecs_entity_t) , ecs_script_template_update , SimNode_ExtFuncCall >(lib,"ecs_script_template_update","ecs_script_template_update")
		->args({"world","instance","template_entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:140:20
	makeExtern< ecs_script_task_t * (*)(const ecs_script_t *,const ecs_script_task_desc_t *) , ecs_script_task_new , SimNode_ExtFuncCall >(lib,"ecs_script_task_new","ecs_script_task_new")
		->args({"script","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:165:26
	makeExtern< ecs_script_task_status_t (*)(ecs_script_task_t *,ecs_script_eval_result_t *) , ecs_script_task_resume , SimNode_ExtFuncCall >(lib,"ecs_script_task_resume","ecs_script_task_resume")
		->args({"task","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:180:6
	makeExtern< bool (*)(const ecs_script_task_t *) , ecs_script_task_is_ready , SimNode_ExtFuncCall >(lib,"ecs_script_task_is_ready","ecs_script_task_is_ready")
		->args({"task"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:192:6
	makeExtern< void (*)(ecs_script_task_t *) , ecs_script_task_cancel , SimNode_ExtFuncCall >(lib,"ecs_script_task_cancel","ecs_script_task_cancel")
		->args({"task"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:202:6
	makeExtern< void (*)(ecs_script_task_t *) , ecs_script_task_free , SimNode_ExtFuncCall >(lib,"ecs_script_task_free","ecs_script_task_free")
		->args({"task"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:225:9
	makeExtern< int (*)(ecs_world_t *) , ecs_script_tasks_progress , SimNode_ExtFuncCall >(lib,"ecs_script_tasks_progress","ecs_script_tasks_progress")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:242:5
	makeExtern< int (*)(ecs_script_future_t *,const ecs_value_t *) , ecs_script_future_resolve , SimNode_ExtFuncCall >(lib,"ecs_script_future_resolve","ecs_script_future_resolve")
		->args({"future","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:259:5
	makeExtern< int (*)(ecs_script_future_t *,const char *) , ecs_script_future_reject , SimNode_ExtFuncCall >(lib,"ecs_script_future_reject","ecs_script_future_reject")
		->args({"future","error"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:292:5
	makeExtern< int (*)(ecs_script_future_t *,ecs_entity_t,const char *) , ecs_script_future_reject_id , SimNode_ExtFuncCall >(lib,"ecs_script_future_reject_id","ecs_script_future_reject_id")
		->args({"future","error","msg"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:309:28
	makeExtern< ecs_script_future_status_t (*)(const ecs_script_future_t *) , ecs_script_future_status , SimNode_ExtFuncCall >(lib,"ecs_script_future_status","ecs_script_future_status")
		->args({"future"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:322:20
	makeExtern< const ecs_value_t * (*)(const ecs_script_future_t *) , ecs_script_future_get_value , SimNode_ExtFuncCall >(lib,"ecs_script_future_get_value","ecs_script_future_get_value")
		->args({"future"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:335:13
	makeExtern< const char * (*)(const ecs_script_future_t *) , ecs_script_future_get_error , SimNode_ExtFuncCall >(lib,"ecs_script_future_get_error","ecs_script_future_get_error")
		->args({"future"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:349:14
	makeExtern< ecs_entity_t (*)(const ecs_script_future_t *) , ecs_script_future_get_error_id , SimNode_ExtFuncCall >(lib,"ecs_script_future_get_error_id","ecs_script_future_get_error_id")
		->args({"future"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:364:6
	makeExtern< void (*)(ecs_script_future_t *) , ecs_script_future_cancel , SimNode_ExtFuncCall >(lib,"ecs_script_future_cancel","ecs_script_future_cancel")
		->args({"future"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:383:22
	makeExtern< ecs_script_future_t * (*)(ecs_script_future_t *) , ecs_script_future_retain , SimNode_ExtFuncCall >(lib,"ecs_script_future_retain","ecs_script_future_retain")
		->args({"future"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:395:6
	makeExtern< void (*)(ecs_script_future_t *) , ecs_script_future_release , SimNode_ExtFuncCall >(lib,"ecs_script_future_release","ecs_script_future_release")
		->args({"future"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:422:7
	makeExtern< void * (*)(const ecs_script_future_t *) , ecs_script_future_get_ctx , SimNode_ExtFuncCall >(lib,"ecs_script_future_get_ctx","ecs_script_future_get_ctx")
		->args({"future"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:465:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_async_function_desc_t *) , ecs_async_function_init , SimNode_ExtFuncCall >(lib,"ecs_async_function_init","ecs_async_function_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:481:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_async_function_desc_t *) , ecs_async_method_init , SimNode_ExtFuncCall >(lib,"ecs_async_method_init","ecs_async_method_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_async.h:508:22
	makeExtern< ecs_script_future_t * (*)(ecs_world_t *,ecs_entity_t,int,const ecs_value_t *) , ecs_async_function_call , SimNode_ExtFuncCall >(lib,"ecs_async_function_call","ecs_async_function_call")
		->args({"world","function","argc","argv"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:299:15
	makeExtern< ecs_script_t * (*)(ecs_world_t *,const char *,const char *,const ecs_script_eval_desc_t *,ecs_script_eval_result_t *) , ecs_script_parse , SimNode_ExtFuncCall >(lib,"ecs_script_parse","ecs_script_parse")
		->args({"world","name","code","desc","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:319:5
	makeExtern< int (*)(const ecs_script_t *,const ecs_script_eval_desc_t *,ecs_script_eval_result_t *) , ecs_script_eval , SimNode_ExtFuncCall >(lib,"ecs_script_eval","ecs_script_eval")
		->args({"script","desc","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:334:6
	makeExtern< void (*)(ecs_script_t *) , ecs_script_free , SimNode_ExtFuncCall >(lib,"ecs_script_free","ecs_script_free")
		->args({"script"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:354:5
	makeExtern< int (*)(ecs_world_t *,const char *,const char *,ecs_script_eval_result_t *) , ecs_script_run , SimNode_ExtFuncCall >(lib,"ecs_script_run","ecs_script_run")
		->args({"world","name","code","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:372:5
	makeExtern< int (*)(ecs_world_t *,const char *,const char *,const ecs_script_eval_desc_t *,ecs_script_eval_result_t *) , ecs_script_run_w_desc , SimNode_ExtFuncCall >(lib,"ecs_script_run_w_desc","ecs_script_run_w_desc")
		->args({"world","name","code","desc","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:389:5
	makeExtern< int (*)(ecs_world_t *,const char *) , ecs_script_run_file , SimNode_ExtFuncCall >(lib,"ecs_script_run_file","ecs_script_run_file")
		->args({"world","filename"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:403:5
	makeExtern< int (*)(ecs_world_t *,const char *,const ecs_script_eval_desc_t *) , ecs_script_run_file_w_desc , SimNode_ExtFuncCall >(lib,"ecs_script_run_file_w_desc","ecs_script_run_file_w_desc")
		->args({"world","filename","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:416:7
	makeExtern< char * (*)(const ecs_script_t *) , ecs_script_ir_to_str , SimNode_ExtFuncCall >(lib,"ecs_script_ir_to_str","ecs_script_ir_to_str")
		->args({"script"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:445:23
	makeExtern< ecs_script_runtime_t * (*)() , ecs_script_runtime_new , SimNode_ExtFuncCall >(lib,"ecs_script_runtime_new","ecs_script_runtime_new")
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:453:6
	makeExtern< void (*)(ecs_script_runtime_t *) , ecs_script_runtime_free , SimNode_ExtFuncCall >(lib,"ecs_script_runtime_free","ecs_script_runtime_free")
		->args({"runtime"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:466:5
	makeExtern< int (*)(ecs_script_t *,ecs_strbuf_t *,bool) , ecs_script_ast_to_buf , SimNode_ExtFuncCall >(lib,"ecs_script_ast_to_buf","ecs_script_ast_to_buf")
		->args({"script","buf","colors"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:480:7
	makeExtern< char * (*)(ecs_script_t *,bool) , ecs_script_ast_to_str , SimNode_ExtFuncCall >(lib,"ecs_script_ast_to_str","ecs_script_ast_to_str")
		->args({"script","colors"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:547:6
	makeExtern< bool (*)(const ecs_script_t *,ecs_entity_t,ecs_script_source_t *) , ecs_script_entity_source , SimNode_ExtFuncCall >(lib,"ecs_script_entity_source","ecs_script_entity_source")
		->args({"script","entity","source"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:580:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t) , ecs_script_entity_owner , SimNode_ExtFuncCall >(lib,"ecs_script_entity_owner","ecs_script_entity_owner")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:622:21
	makeExtern< ecs_script_edits_t * (*)(ecs_script_t *) , ecs_script_edits_new , SimNode_ExtFuncCall >(lib,"ecs_script_edits_new","ecs_script_edits_new")
		->args({"script"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:630:6
	makeExtern< void (*)(ecs_script_edits_t *) , ecs_script_edits_free , SimNode_ExtFuncCall >(lib,"ecs_script_edits_free","ecs_script_edits_free")
		->args({"edits"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:681:5
	makeExtern< int (*)(ecs_script_edits_t *,ecs_entity_t,ecs_id_t,const void *) , ecs_script_edits_set , SimNode_ExtFuncCall >(lib,"ecs_script_edits_set","ecs_script_edits_set")
		->args({"edits","entity","component","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:699:5
	makeExtern< int (*)(ecs_script_edits_t *,ecs_entity_t,ecs_id_t,const char *) , ecs_script_edits_set_expr , SimNode_ExtFuncCall >(lib,"ecs_script_edits_set_expr","ecs_script_edits_set_expr")
		->args({"edits","entity","component","expr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:719:5
	makeExtern< int (*)(ecs_script_edits_t *,ecs_entity_t,ecs_id_t) , ecs_script_edits_remove , SimNode_ExtFuncCall >(lib,"ecs_script_edits_remove","ecs_script_edits_remove")
		->args({"edits","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:752:5
	makeExtern< int (*)(ecs_script_edits_t *,ecs_entity_t) , ecs_script_edits_delete , SimNode_ExtFuncCall >(lib,"ecs_script_edits_delete","ecs_script_edits_delete")
		->args({"edits","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:776:5
	makeExtern< int (*)(ecs_script_edits_t *,ecs_entity_t,ecs_id_t) , ecs_script_edits_clear , SimNode_ExtFuncCall >(lib,"ecs_script_edits_clear","ecs_script_edits_clear")
		->args({"edits","entity","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:789:9
	makeExtern< int (*)(const ecs_script_edits_t *) , ecs_script_edits_count , SimNode_ExtFuncCall >(lib,"ecs_script_edits_count","ecs_script_edits_count")
		->args({"edits"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:805:7
	makeExtern< char * (*)(const ecs_script_edits_t *) , ecs_script_edits_apply , SimNode_ExtFuncCall >(lib,"ecs_script_edits_apply","ecs_script_edits_apply")
		->args({"edits"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:832:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_script_desc_t *) , ecs_script_init , SimNode_ExtFuncCall >(lib,"ecs_script_init","ecs_script_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script.h:848:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,ecs_entity_t,const char *) , ecs_script_update , SimNode_ExtFuncCall >(lib,"ecs_script_update","ecs_script_update")
		->args({"world","script","instance","code"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

