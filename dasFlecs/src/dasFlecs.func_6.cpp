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
void Module_dasFlecs::initFunctions_6() {
// from flecs.h:5819:6
	makeExtern< bool (*)(const ecs_world_t *,const ecs_table_t *,ecs_id_t) , ecs_table_has_id , SimNode_ExtFuncCall >(lib,"ecs_table_has_id","ecs_table_has_id")
		->args({"world","table","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5835:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,const ecs_table_t *,ecs_entity_t,int) , ecs_table_get_target , SimNode_ExtFuncCall >(lib,"ecs_table_get_target","ecs_table_get_target")
		->args({"world","table","relationship","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5852:9
	makeExtern< int (*)(const ecs_world_t *,const ecs_table_t *,ecs_entity_t) , ecs_table_get_depth , SimNode_ExtFuncCall >(lib,"ecs_table_get_depth","ecs_table_get_depth")
		->args({"world","table","rel"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5867:14
	makeExtern< ecs_table_t * (*)(ecs_world_t *,ecs_table_t *,ecs_id_t) , ecs_table_add_id , SimNode_ExtFuncCall >(lib,"ecs_table_add_id","ecs_table_add_id")
		->args({"world","table","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5883:14
	makeExtern< ecs_table_t * (*)(ecs_world_t *,const ecs_id_t *,int) , ecs_table_find , SimNode_ExtFuncCall >(lib,"ecs_table_find","ecs_table_find")
		->args({"world","ids","id_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5898:14
	makeExtern< ecs_table_t * (*)(ecs_world_t *,ecs_table_t *,ecs_id_t) , ecs_table_remove_id , SimNode_ExtFuncCall >(lib,"ecs_table_remove_id","ecs_table_remove_id")
		->args({"world","table","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5919:6
	makeExtern< void (*)(ecs_world_t *,ecs_table_t *) , ecs_table_lock , SimNode_ExtFuncCall >(lib,"ecs_table_lock","ecs_table_lock")
		->args({"world","table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5930:6
	makeExtern< void (*)(ecs_world_t *,ecs_table_t *) , ecs_table_unlock , SimNode_ExtFuncCall >(lib,"ecs_table_unlock","ecs_table_unlock")
		->args({"world","table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5944:6
	makeExtern< bool (*)(ecs_table_t *,unsigned int) , ecs_table_has_flags , SimNode_ExtFuncCall >(lib,"ecs_table_has_flags","ecs_table_has_flags")
		->args({"table","flags"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5956:6
	makeExtern< bool (*)(const ecs_table_t *) , ecs_table_has_traversable , SimNode_ExtFuncCall >(lib,"ecs_table_has_traversable","ecs_table_has_traversable")
		->args({"table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5969:6
	makeExtern< void (*)(ecs_world_t *,ecs_table_t *,int,int) , ecs_table_swap_rows , SimNode_ExtFuncCall >(lib,"ecs_table_swap_rows","ecs_table_swap_rows")
		->args({"world","table","row_1","row_2"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5995:9
	makeExtern< int (*)(const ecs_world_t *,const ecs_table_t *,ecs_id_t,ecs_id_t *) , ecs_search , SimNode_ExtFuncCall >(lib,"ecs_search","ecs_search")
		->args({"world","table","component","component_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:6037:9
	makeExtern< int (*)(const ecs_world_t *,const ecs_table_t *,int,ecs_id_t,ecs_id_t *) , ecs_search_offset , SimNode_ExtFuncCall >(lib,"ecs_search_offset","ecs_search_offset")
		->args({"world","table","offset","component","component_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:6085:9
	makeExtern< int (*)(const ecs_world_t *,const ecs_table_t *,int,ecs_id_t,ecs_entity_t,ecs_flags64_t,ecs_entity_t *,ecs_id_t *,ecs_table_record_t **) , ecs_search_relation , SimNode_ExtFuncCall >(lib,"ecs_search_relation","ecs_search_relation")
		->args({"world","table","offset","component","rel","flags","tgt_out","component_out","tr_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:6112:9
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,ecs_id_t,ecs_entity_t,bool,ecs_component_record_t *,ecs_entity_t *,ecs_id_t *,ecs_table_record_t **) , ecs_search_relation_for_entity , SimNode_ExtFuncCall >(lib,"ecs_search_relation_for_entity","ecs_search_relation_for_entity")
		->args({"world","entity","id","rel","self","cr","tgt_out","id_out","tr_out"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:6134:6
	makeExtern< void (*)(ecs_world_t *,ecs_table_t *) , ecs_table_clear_entities , SimNode_ExtFuncCall >(lib,"ecs_table_clear_entities","ecs_table_clear_entities")
		->args({"world","table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:56:6
	makeExtern< void (*)(const char *,int,const char *) , ecs_deprecated_ , SimNode_ExtFuncCall >(lib,"ecs_deprecated_","ecs_deprecated_")
		->args({"file","line","msg"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:68:6
	makeExtern< void (*)(int) , ecs_log_push_ , SimNode_ExtFuncCall >(lib,"ecs_log_push_","ecs_log_push_")
		->args({"level"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:77:6
	makeExtern< void (*)(int) , ecs_log_pop_ , SimNode_ExtFuncCall >(lib,"ecs_log_pop_","ecs_log_pop_")
		->args({"level"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:87:6
	makeExtern< bool (*)(int) , ecs_should_log , SimNode_ExtFuncCall >(lib,"ecs_should_log","ecs_should_log")
		->args({"level"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:99:13
	makeExtern< const char * (*)(int) , ecs_strerror , SimNode_ExtFuncCall >(lib,"ecs_strerror","ecs_strerror")
		->args({"error_code"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:594:5
	makeExtern< int (*)(int) , ecs_log_set_level , SimNode_ExtFuncCall >(lib,"ecs_log_set_level","ecs_log_set_level")
		->args({"level"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:602:5
	makeExtern< int (*)() , ecs_log_get_level , SimNode_ExtFuncCall >(lib,"ecs_log_get_level","ecs_log_get_level")
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:611:6
	makeExtern< bool (*)(bool) , ecs_log_enable_colors , SimNode_ExtFuncCall >(lib,"ecs_log_enable_colors","ecs_log_enable_colors")
		->args({"enabled"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:622:6
	makeExtern< bool (*)(bool) , ecs_log_enable_timestamp , SimNode_ExtFuncCall >(lib,"ecs_log_enable_timestamp","ecs_log_enable_timestamp")
		->args({"enabled"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:639:6
	makeExtern< bool (*)(bool) , ecs_log_enable_timedelta , SimNode_ExtFuncCall >(lib,"ecs_log_enable_timedelta","ecs_log_enable_timedelta")
		->args({"enabled"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:648:5
	makeExtern< int (*)() , ecs_log_last_error , SimNode_ExtFuncCall >(lib,"ecs_log_last_error","ecs_log_last_error")
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:655:6
	makeExtern< void (*)(bool) , ecs_log_start_capture , SimNode_ExtFuncCall >(lib,"ecs_log_start_capture","ecs_log_start_capture")
		->args({"capture_try"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:662:7
	makeExtern< char * (*)() , ecs_log_stop_capture , SimNode_ExtFuncCall >(lib,"ecs_log_stop_capture","ecs_log_stop_capture")
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:681:6
	makeExtern< void (*)(ecs_vec_t *) , ecs_log_start_collect_errors , SimNode_ExtFuncCall >(lib,"ecs_log_start_collect_errors","ecs_log_start_collect_errors")
		->args({"errors"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/log.h:689:6
	makeExtern< void (*)() , ecs_log_stop_collect_errors , SimNode_ExtFuncCall >(lib,"ecs_log_stop_collect_errors","ecs_log_stop_collect_errors")
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/entity_ranges.h:48:27
	makeExtern< const ecs_entity_range_t * (*)(ecs_world_t *,unsigned int,unsigned int) , ecs_entity_range_new , SimNode_ExtFuncCall >(lib,"ecs_entity_range_new","ecs_entity_range_new")
		->args({"world","min","max"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/entity_ranges.h:68:6
	makeExtern< void (*)(ecs_world_t *,const ecs_entity_range_t *) , ecs_entity_range_set , SimNode_ExtFuncCall >(lib,"ecs_entity_range_set","ecs_entity_range_set")
		->args({"world","range"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/entity_ranges.h:87:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_entity_range_t *) , ecs_new_from_range , SimNode_ExtFuncCall >(lib,"ecs_new_from_range","ecs_new_from_range")
		->args({"world","range"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/entity_ranges.h:99:27
	makeExtern< const ecs_entity_range_t * (*)(const ecs_world_t *) , ecs_entity_range_get , SimNode_ExtFuncCall >(lib,"ecs_entity_range_get","ecs_entity_range_get")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:46:13
	makeExtern< float (*)(ecs_world_t *,float) , ecs_frame_begin , SimNode_ExtFuncCall >(lib,"ecs_frame_begin","ecs_frame_begin")
		->args({"world","delta_time"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:57:6
	makeExtern< void (*)(ecs_world_t *) , ecs_frame_end , SimNode_ExtFuncCall >(lib,"ecs_frame_end","ecs_frame_end")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:81:6
	makeExtern< void (*)(ecs_world_t *) , ecs_quit , SimNode_ExtFuncCall >(lib,"ecs_quit","ecs_quit")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:91:6
	makeExtern< bool (*)(const ecs_world_t *) , ecs_should_quit , SimNode_ExtFuncCall >(lib,"ecs_should_quit","ecs_should_quit")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:106:6
	makeExtern< void (*)(ecs_world_t *,bool) , ecs_measure_frame_time , SimNode_ExtFuncCall >(lib,"ecs_measure_frame_time","ecs_measure_frame_time")
		->args({"world","enable"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:121:6
	makeExtern< void (*)(ecs_world_t *,bool) , ecs_measure_system_time , SimNode_ExtFuncCall >(lib,"ecs_measure_system_time","ecs_measure_system_time")
		->args({"world","enable"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:140:6
	makeExtern< void (*)(ecs_world_t *,float) , ecs_set_target_fps , SimNode_ExtFuncCall >(lib,"ecs_set_target_fps","ecs_set_target_fps")
		->args({"world","fps"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:151:6
	makeExtern< void (*)(ecs_world_t *,float) , ecs_set_time_scale , SimNode_ExtFuncCall >(lib,"ecs_set_time_scale","ecs_set_time_scale")
		->args({"world","scale"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/frame.h:161:6
	makeExtern< void (*)(ecs_world_t *) , ecs_reset_clock , SimNode_ExtFuncCall >(lib,"ecs_reset_clock","ecs_reset_clock")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/app.h:75:5
	makeExtern< int (*)(ecs_world_t *,ecs_app_desc_t *) , ecs_app_run , SimNode_ExtFuncCall >(lib,"ecs_app_run","ecs_app_run")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/app.h:88:5
	makeExtern< int (*)(ecs_world_t *,const ecs_app_desc_t *) , ecs_app_run_frame , SimNode_ExtFuncCall >(lib,"ecs_app_run_frame","ecs_app_run_frame")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:141:20
	makeExtern< ecs_http_server_t * (*)(const ecs_http_server_desc_t *) , ecs_http_server_init , SimNode_ExtFuncCall >(lib,"ecs_http_server_init","ecs_http_server_init")
		->args({"desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:150:6
	makeExtern< void (*)(ecs_http_server_t *) , ecs_http_server_fini , SimNode_ExtFuncCall >(lib,"ecs_http_server_fini","ecs_http_server_fini")
		->args({"server"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:160:5
	makeExtern< int (*)(ecs_http_server_t *) , ecs_http_server_start , SimNode_ExtFuncCall >(lib,"ecs_http_server_start","ecs_http_server_start")
		->args({"server"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/http.h:171:6
	makeExtern< void (*)(ecs_http_server_t *,float) , ecs_http_server_dequeue , SimNode_ExtFuncCall >(lib,"ecs_http_server_dequeue","ecs_http_server_dequeue")
		->args({"server","delta_time"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

