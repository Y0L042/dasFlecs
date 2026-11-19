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
void Module_dasFlecs::initFunctions_7() {
// from flecs/addons/http.h:181:6
	makeExtern< void (*)(ecs_http_server_t *) , ecs_http_server_stop , SimNode_ExtFuncCall >(lib,"ecs_http_server_stop","ecs_http_server_stop")
		->args({"server"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:196:5
	makeExtern< int (*)(ecs_http_server_t *,const char *,int,ecs_http_reply_t *) , ecs_http_server_http_request , SimNode_ExtFuncCall >(lib,"ecs_http_server_http_request","ecs_http_server_http_request")
		->args({"srv","req","len","reply_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:212:5
	makeExtern< int (*)(ecs_http_server_t *,const char *,const char *,const char *,ecs_http_reply_t *) , ecs_http_server_request , SimNode_ExtFuncCall >(lib,"ecs_http_server_request","ecs_http_server_request")
		->args({"srv","method","req","body","reply_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:225:7
	makeExtern< void * (*)(ecs_http_server_t *) , ecs_http_server_ctx , SimNode_ExtFuncCall >(lib,"ecs_http_server_ctx","ecs_http_server_ctx")
		->args({"srv"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:235:13
	makeExtern< const char * (*)(const ecs_http_request_t *,const char *) , ecs_http_get_header , SimNode_ExtFuncCall >(lib,"ecs_http_get_header","ecs_http_get_header")
		->args({"req","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:246:13
	makeExtern< const char * (*)(const ecs_http_request_t *,const char *) , ecs_http_get_param , SimNode_ExtFuncCall >(lib,"ecs_http_get_param","ecs_http_get_param")
		->args({"req","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/rest.h:76:20
	makeExtern< ecs_http_server_t * (*)(ecs_world_t *,const ecs_http_server_desc_t *) , ecs_rest_server_init , SimNode_ExtFuncCall >(lib,"ecs_rest_server_init","ecs_rest_server_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/rest.h:86:6
	makeExtern< void (*)(ecs_http_server_t *) , ecs_rest_server_fini , SimNode_ExtFuncCall >(lib,"ecs_rest_server_fini","ecs_rest_server_fini")
		->args({"srv"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:72:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,float) , ecs_set_timeout , SimNode_ExtFuncCall >(lib,"ecs_set_timeout","ecs_set_timeout")
		->args({"world","tick_source","timeout"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:90:13
	makeExtern< float (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_timeout , SimNode_ExtFuncCall >(lib,"ecs_get_timeout","ecs_get_timeout")
		->args({"world","tick_source"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:112:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,float) , ecs_set_interval , SimNode_ExtFuncCall >(lib,"ecs_set_interval","ecs_set_interval")
		->args({"world","tick_source","interval"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:126:13
	makeExtern< float (*)(const ecs_world_t *,ecs_entity_t) , ecs_get_interval , SimNode_ExtFuncCall >(lib,"ecs_get_interval","ecs_get_interval")
		->args({"world","tick_source"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:137:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_start_timer , SimNode_ExtFuncCall >(lib,"ecs_start_timer","ecs_start_timer")
		->args({"world","tick_source"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:148:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_stop_timer , SimNode_ExtFuncCall >(lib,"ecs_stop_timer","ecs_stop_timer")
		->args({"world","tick_source"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:159:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_reset_timer , SimNode_ExtFuncCall >(lib,"ecs_reset_timer","ecs_reset_timer")
		->args({"world","tick_source"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:170:6
	makeExtern< void (*)(ecs_world_t *) , ecs_randomize_timers , SimNode_ExtFuncCall >(lib,"ecs_randomize_timers","ecs_randomize_timers")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:204:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,int,ecs_entity_t) , ecs_set_rate , SimNode_ExtFuncCall >(lib,"ecs_set_rate","ecs_set_rate")
		->args({"world","tick_source","rate","source"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/timer.h:233:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,ecs_entity_t) , ecs_set_tick_source , SimNode_ExtFuncCall >(lib,"ecs_set_tick_source","ecs_set_tick_source")
		->args({"world","system","tick_source"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:129:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_pipeline_desc_t *) , ecs_pipeline_init , SimNode_ExtFuncCall >(lib,"ecs_pipeline_init","ecs_pipeline_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:143:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,const ecs_pipeline_desc_t *) , ecs_pipeline_update , SimNode_ExtFuncCall >(lib,"ecs_pipeline_update","ecs_pipeline_update")
		->args({"world","pipeline","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:155:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t) , ecs_set_pipeline , SimNode_ExtFuncCall >(lib,"ecs_set_pipeline","ecs_set_pipeline")
		->args({"world","pipeline"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:166:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *) , ecs_get_pipeline , SimNode_ExtFuncCall >(lib,"ecs_get_pipeline","ecs_get_pipeline")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:188:6
	makeExtern< bool (*)(ecs_world_t *,float) , ecs_progress , SimNode_ExtFuncCall >(lib,"ecs_progress","ecs_progress")
		->args({"world","delta_time"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:209:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,float) , ecs_run_pipeline , SimNode_ExtFuncCall >(lib,"ecs_run_pipeline","ecs_run_pipeline")
		->args({"world","pipeline","delta_time"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:231:6
	makeExtern< void (*)(ecs_world_t *,int) , ecs_set_threads , SimNode_ExtFuncCall >(lib,"ecs_set_threads","ecs_set_threads")
		->args({"world","threads"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:252:6
	makeExtern< void (*)(ecs_world_t *,int) , ecs_set_task_threads , SimNode_ExtFuncCall >(lib,"ecs_set_task_threads","ecs_set_task_threads")
		->args({"world","task_threads"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/pipeline.h:262:6
	makeExtern< bool (*)(ecs_world_t *) , ecs_using_task_threads , SimNode_ExtFuncCall >(lib,"ecs_using_task_threads","ecs_using_task_threads")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/system.h:114:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_system_desc_t *) , ecs_system_init , SimNode_ExtFuncCall >(lib,"ecs_system_init","ecs_system_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/system.h:133:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,const ecs_system_desc_t *) , ecs_system_update , SimNode_ExtFuncCall >(lib,"ecs_system_update","ecs_system_update")
		->args({"world","system","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/system.h:209:21
	makeExtern< const ecs_system_t * (*)(const ecs_world_t *,ecs_entity_t) , ecs_system_get , SimNode_ExtFuncCall >(lib,"ecs_system_get","ecs_system_get")
		->args({"world","system"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/system.h:223:6
	makeExtern< void (*)(ecs_world_t *,ecs_entity_t,uint64_t) , ecs_system_set_group , SimNode_ExtFuncCall >(lib,"ecs_system_set_group","ecs_system_set_group")
		->args({"world","system","group_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/system.h:319:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,float,void *) , ecs_run , SimNode_ExtFuncCall >(lib,"ecs_run","ecs_run")
		->args({"world","system","delta_time","param"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/system.h:336:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,int,int,float,void *) , ecs_run_worker , SimNode_ExtFuncCall >(lib,"ecs_run_worker","ecs_run_worker")
		->args({"world","system","stage_current","stage_count","delta_time","param"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:231:6
	makeExtern< void (*)(const ecs_world_t *,ecs_world_stats_t *) , ecs_world_stats_get , SimNode_ExtFuncCall >(lib,"ecs_world_stats_get","ecs_world_stats_get")
		->args({"world","stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:237:6
	makeExtern< void (*)(ecs_world_stats_t *,const ecs_world_stats_t *) , ecs_world_stats_reduce , SimNode_ExtFuncCall >(lib,"ecs_world_stats_reduce","ecs_world_stats_reduce")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:243:6
	makeExtern< void (*)(ecs_world_stats_t *,const ecs_world_stats_t *,int) , ecs_world_stats_reduce_last , SimNode_ExtFuncCall >(lib,"ecs_world_stats_reduce_last","ecs_world_stats_reduce_last")
		->args({"stats","old","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:250:6
	makeExtern< void (*)(ecs_world_stats_t *) , ecs_world_stats_repeat_last , SimNode_ExtFuncCall >(lib,"ecs_world_stats_repeat_last","ecs_world_stats_repeat_last")
		->args({"stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:255:6
	makeExtern< void (*)(ecs_world_stats_t *,const ecs_world_stats_t *) , ecs_world_stats_copy_last , SimNode_ExtFuncCall >(lib,"ecs_world_stats_copy_last","ecs_world_stats_copy_last")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:265:6
	makeExtern< void (*)(const ecs_world_t *,const ecs_world_stats_t *) , ecs_world_stats_log , SimNode_ExtFuncCall >(lib,"ecs_world_stats_log","ecs_world_stats_log")
		->args({"world","stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:277:6
	makeExtern< void (*)(const ecs_world_t *,const ecs_query_t *,ecs_query_stats_t *) , ecs_query_stats_get , SimNode_ExtFuncCall >(lib,"ecs_query_stats_get","ecs_query_stats_get")
		->args({"world","query","stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:284:6
	makeExtern< void (*)(ecs_query_stats_t *,const ecs_query_stats_t *) , ecs_query_cache_stats_reduce , SimNode_ExtFuncCall >(lib,"ecs_query_cache_stats_reduce","ecs_query_cache_stats_reduce")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:290:6
	makeExtern< void (*)(ecs_query_stats_t *,const ecs_query_stats_t *,int) , ecs_query_cache_stats_reduce_last , SimNode_ExtFuncCall >(lib,"ecs_query_cache_stats_reduce_last","ecs_query_cache_stats_reduce_last")
		->args({"stats","old","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:297:6
	makeExtern< void (*)(ecs_query_stats_t *) , ecs_query_cache_stats_repeat_last , SimNode_ExtFuncCall >(lib,"ecs_query_cache_stats_repeat_last","ecs_query_cache_stats_repeat_last")
		->args({"stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:302:6
	makeExtern< void (*)(ecs_query_stats_t *,const ecs_query_stats_t *) , ecs_query_cache_stats_copy_last , SimNode_ExtFuncCall >(lib,"ecs_query_cache_stats_copy_last","ecs_query_cache_stats_copy_last")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:315:6
	makeExtern< bool (*)(const ecs_world_t *,ecs_entity_t,ecs_system_stats_t *) , ecs_system_stats_get , SimNode_ExtFuncCall >(lib,"ecs_system_stats_get","ecs_system_stats_get")
		->args({"world","system","stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:322:6
	makeExtern< void (*)(ecs_system_stats_t *,const ecs_system_stats_t *) , ecs_system_stats_reduce , SimNode_ExtFuncCall >(lib,"ecs_system_stats_reduce","ecs_system_stats_reduce")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:328:6
	makeExtern< void (*)(ecs_system_stats_t *,const ecs_system_stats_t *,int) , ecs_system_stats_reduce_last , SimNode_ExtFuncCall >(lib,"ecs_system_stats_reduce_last","ecs_system_stats_reduce_last")
		->args({"stats","old","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:335:6
	makeExtern< void (*)(ecs_system_stats_t *) , ecs_system_stats_repeat_last , SimNode_ExtFuncCall >(lib,"ecs_system_stats_repeat_last","ecs_system_stats_repeat_last")
		->args({"stats"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:340:6
	makeExtern< void (*)(ecs_system_stats_t *,const ecs_system_stats_t *) , ecs_system_stats_copy_last , SimNode_ExtFuncCall >(lib,"ecs_system_stats_copy_last","ecs_system_stats_copy_last")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/stats.h:353:6
	makeExtern< bool (*)(ecs_world_t *,ecs_entity_t,ecs_pipeline_stats_t *) , ecs_pipeline_stats_get , SimNode_ExtFuncCall >(lib,"ecs_pipeline_stats_get","ecs_pipeline_stats_get")
		->args({"world","pipeline","stats"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

