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
void Module_dasFlecs::initFunctions_8() {
// from flecs/addons/stats.h:363:6
	makeExtern< void (*)(ecs_pipeline_stats_t *) , ecs_pipeline_stats_fini , SimNode_ExtFuncCall >(lib,"ecs_pipeline_stats_fini","ecs_pipeline_stats_fini")
		->args({"stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:368:6
	makeExtern< void (*)(ecs_pipeline_stats_t *,const ecs_pipeline_stats_t *) , ecs_pipeline_stats_reduce , SimNode_ExtFuncCall >(lib,"ecs_pipeline_stats_reduce","ecs_pipeline_stats_reduce")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:374:6
	makeExtern< void (*)(ecs_pipeline_stats_t *,const ecs_pipeline_stats_t *,int) , ecs_pipeline_stats_reduce_last , SimNode_ExtFuncCall >(lib,"ecs_pipeline_stats_reduce_last","ecs_pipeline_stats_reduce_last")
		->args({"stats","old","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:381:6
	makeExtern< void (*)(ecs_pipeline_stats_t *) , ecs_pipeline_stats_repeat_last , SimNode_ExtFuncCall >(lib,"ecs_pipeline_stats_repeat_last","ecs_pipeline_stats_repeat_last")
		->args({"stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:392:6
	makeExtern< void (*)(ecs_pipeline_stats_t *,const ecs_pipeline_stats_t *) , ecs_pipeline_stats_copy_last , SimNode_ExtFuncCall >(lib,"ecs_pipeline_stats_copy_last","ecs_pipeline_stats_copy_last")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:398:6
	makeExtern< void (*)(ecs_metric_t *,const ecs_metric_t *,int,int) , ecs_metric_reduce , SimNode_ExtFuncCall >(lib,"ecs_metric_reduce","ecs_metric_reduce")
		->args({"dst","src","t_dst","t_src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:406:6
	makeExtern< void (*)(ecs_metric_t *,int,int) , ecs_metric_reduce_last , SimNode_ExtFuncCall >(lib,"ecs_metric_reduce_last","ecs_metric_reduce_last")
		->args({"m","t","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:413:6
	makeExtern< void (*)(ecs_metric_t *,int,int) , ecs_metric_copy , SimNode_ExtFuncCall >(lib,"ecs_metric_copy","ecs_metric_copy")
		->args({"m","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:626:23
	makeExtern< ecs_entities_memory_t (*)(const ecs_world_t *) , ecs_entity_memory_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_entity_memory_get","ecs_entity_memory_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:634:6
	makeExtern< void (*)(const ecs_component_record_t *,ecs_component_index_memory_t *) , ecs_component_record_memory_get , SimNode_ExtFuncCall >(lib,"ecs_component_record_memory_get","ecs_component_record_memory_get")
		->args({"cr","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:644:30
	makeExtern< ecs_component_index_memory_t (*)(const ecs_world_t *) , ecs_component_index_memory_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_component_index_memory_get","ecs_component_index_memory_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:653:6
	makeExtern< void (*)(const ecs_query_t *,ecs_query_memory_t *) , ecs_query_memory_get , SimNode_ExtFuncCall >(lib,"ecs_query_memory_get","ecs_query_memory_get")
		->args({"query","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:663:20
	makeExtern< ecs_query_memory_t (*)(const ecs_world_t *) , ecs_queries_memory_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_queries_memory_get","ecs_queries_memory_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:671:6
	makeExtern< void (*)(const ecs_table_t *,ecs_component_memory_t *) , ecs_table_component_memory_get , SimNode_ExtFuncCall >(lib,"ecs_table_component_memory_get","ecs_table_component_memory_get")
		->args({"table","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:681:24
	makeExtern< ecs_component_memory_t (*)(const ecs_world_t *) , ecs_component_memory_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_component_memory_get","ecs_component_memory_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:689:6
	makeExtern< void (*)(const ecs_table_t *,ecs_table_memory_t *) , ecs_table_memory_get , SimNode_ExtFuncCall >(lib,"ecs_table_memory_get","ecs_table_memory_get")
		->args({"table","result"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:699:20
	makeExtern< ecs_table_memory_t (*)(const ecs_world_t *) , ecs_tables_memory_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_tables_memory_get","ecs_tables_memory_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:708:23
	makeExtern< ecs_table_histogram_t (*)(const ecs_world_t *) , ecs_table_histogram_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_table_histogram_get","ecs_table_histogram_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:717:19
	makeExtern< ecs_misc_memory_t (*)(const ecs_world_t *) , ecs_misc_memory_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_misc_memory_get","ecs_misc_memory_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:726:24
	makeExtern< ecs_allocator_memory_t (*)(const ecs_world_t *) , ecs_allocator_memory_get , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_allocator_memory_get","ecs_allocator_memory_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:735:12
	makeExtern< int (*)(const ecs_world_t *) , ecs_memory_get , SimNode_ExtFuncCall >(lib,"ecs_memory_get","ecs_memory_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/metrics.h:148:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_metric_desc_t *) , ecs_metric_init , SimNode_ExtFuncCall >(lib,"ecs_metric_init","ecs_metric_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/alerts.h:162:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_alert_desc_t *) , ecs_alert_init , SimNode_ExtFuncCall >(lib,"ecs_alert_init","ecs_alert_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/alerts.h:184:9
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,ecs_entity_t) , ecs_get_alert_count , SimNode_ExtFuncCall >(lib,"ecs_get_alert_count","ecs_get_alert_count")
		->args({"world","entity","alert"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/alerts.h:199:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t,ecs_entity_t) , ecs_get_alert , SimNode_ExtFuncCall >(lib,"ecs_get_alert","ecs_get_alert")
		->args({"world","entity","alert"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:70:13
	makeExtern< const char * (*)(const ecs_world_t *,ecs_entity_t,void *,const char *,const ecs_from_json_desc_t *) , ecs_ptr_from_json , SimNode_ExtFuncCall >(lib,"ecs_ptr_from_json","ecs_ptr_from_json")
		->args({"world","type","ptr","json","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:88:13
	makeExtern< const char * (*)(ecs_world_t *,ecs_entity_t,const char *,const ecs_from_json_desc_t *) , ecs_entity_from_json , SimNode_ExtFuncCall >(lib,"ecs_entity_from_json","ecs_entity_from_json")
		->args({"world","entity","json","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:103:13
	makeExtern< const char * (*)(ecs_world_t *,const char *,const ecs_from_json_desc_t *) , ecs_world_from_json , SimNode_ExtFuncCall >(lib,"ecs_world_from_json","ecs_world_from_json")
		->args({"world","json","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:116:13
	makeExtern< const char * (*)(ecs_world_t *,const char *,const ecs_from_json_desc_t *) , ecs_world_from_json_file , SimNode_ExtFuncCall >(lib,"ecs_world_from_json_file","ecs_world_from_json_file")
		->args({"world","filename","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:136:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_entity_t,const void *,int) , ecs_array_to_json , SimNode_ExtFuncCall >(lib,"ecs_array_to_json","ecs_array_to_json")
		->args({"world","type","data","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:153:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,const void *,int,ecs_strbuf_t *) , ecs_array_to_json_buf , SimNode_ExtFuncCall >(lib,"ecs_array_to_json_buf","ecs_array_to_json_buf")
		->args({"world","type","data","count","buf_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:169:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_entity_t,const void *) , ecs_ptr_to_json , SimNode_ExtFuncCall >(lib,"ecs_ptr_to_json","ecs_ptr_to_json")
		->args({"world","type","data"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:184:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,const void *,ecs_strbuf_t *) , ecs_ptr_to_json_buf , SimNode_ExtFuncCall >(lib,"ecs_ptr_to_json_buf","ecs_ptr_to_json_buf")
		->args({"world","type","data","buf_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:201:7
	makeExtern< char * (*)(const ecs_world_t *,ecs_entity_t) , ecs_type_info_to_json , SimNode_ExtFuncCall >(lib,"ecs_type_info_to_json","ecs_type_info_to_json")
		->args({"world","type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:214:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,ecs_strbuf_t *) , ecs_type_info_to_json_buf , SimNode_ExtFuncCall >(lib,"ecs_type_info_to_json_buf","ecs_type_info_to_json_buf")
		->args({"world","type","buf_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:279:7
	makeExtern< char * (*)(ecs_world_t *,ecs_entity_t,const ecs_entity_to_json_desc_t *) , ecs_entity_to_json , SimNode_ExtFuncCall >(lib,"ecs_entity_to_json","ecs_entity_to_json")
		->args({"world","entity","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:294:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,ecs_strbuf_t *,const ecs_entity_to_json_desc_t *) , ecs_entity_to_json_buf , SimNode_ExtFuncCall >(lib,"ecs_entity_to_json_buf","ecs_entity_to_json_buf")
		->args({"world","entity","buf_out","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:385:7
	makeExtern< char * (*)(ecs_iter_t *,const ecs_iter_to_json_desc_t *) , ecs_iter_to_json , SimNode_ExtFuncCall >(lib,"ecs_iter_to_json","ecs_iter_to_json")
		->args({"iter","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:398:5
	makeExtern< int (*)(ecs_iter_t *,ecs_strbuf_t *,const ecs_iter_to_json_desc_t *) , ecs_iter_to_json_buf , SimNode_ExtFuncCall >(lib,"ecs_iter_to_json_buf","ecs_iter_to_json_buf")
		->args({"iter","buf_out","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:428:7
	makeExtern< char * (*)(ecs_world_t *,const ecs_world_to_json_desc_t *) , ecs_world_to_json , SimNode_ExtFuncCall >(lib,"ecs_world_to_json","ecs_world_to_json")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/json.h:441:5
	makeExtern< int (*)(ecs_world_t *,ecs_strbuf_t *,const ecs_world_to_json_desc_t *) , ecs_world_to_json_buf , SimNode_ExtFuncCall >(lib,"ecs_world_to_json_buf","ecs_world_to_json_buf")
		->args({"world","buf_out","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_input.h:240:27
	makeExtern< ecs_script_event_result_t (*)(ecs_world_t *,const EcsScriptMouseEvent *) , ecs_script_mouse_event , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_script_mouse_event","ecs_script_mouse_event")
		->args({"world","evt"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_input.h:255:27
	makeExtern< ecs_script_event_result_t (*)(ecs_world_t *,const EcsScriptKeyboardEvent *) , ecs_script_keyboard_event , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_script_keyboard_event","ecs_script_keyboard_event")
		->args({"world","evt"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_input.h:266:6
	makeExtern< void (*)(ecs_world_t *,const ecs_script_event_hooks_t *) , ecs_script_set_event_hooks , SimNode_ExtFuncCall >(lib,"ecs_script_set_event_hooks","ecs_script_set_event_hooks")
		->args({"world","hooks"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_input.h:278:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t) , ecs_script_set_focus , SimNode_ExtFuncCall >(lib,"ecs_script_set_focus","ecs_script_set_focus")
		->args({"world","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_input.h:288:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *) , ecs_script_get_focus , SimNode_ExtFuncCall >(lib,"ecs_script_get_focus","ecs_script_get_focus")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_input.h:302:6
	makeExtern< bool (*)(const ecs_world_t *,EcsScriptMouseEvent *,ecs_entity_t *) , ecs_script_get_mouse_state , SimNode_ExtFuncCall >(lib,"ecs_script_get_mouse_state","ecs_script_get_mouse_state")
		->args({"world","last_out","pressed_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_input.h:319:9
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,const char **,int) , ecs_script_event_listeners , SimNode_ExtFuncCall >(lib,"ecs_script_event_listeners","ecs_script_event_listeners")
		->args({"world","entity","kinds_out","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_shell.h:273:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_shell_session_desc_t *) , ecs_shell_session_init , SimNode_ExtFuncCall >(lib,"ecs_shell_session_init","ecs_shell_session_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/script_shell.h:290:20
	makeExtern< ecs_shell_result_t (*)(ecs_world_t *,ecs_entity_t,const char *) , ecs_shell_run , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_shell_run","ecs_shell_run")
		->args({"world","session","cmd"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

