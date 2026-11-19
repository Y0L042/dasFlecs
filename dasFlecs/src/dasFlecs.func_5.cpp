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
void Module_dasFlecs::initFunctions_5() {
// from flecs.h:5009:6
	makeExtern< void (*)(ecs_world_t *,ecs_event_desc_t *) , ecs_emit , SimNode_ExtFuncCall >(lib,"ecs_emit","ecs_emit")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5018:6
	makeExtern< void (*)(ecs_world_t *,ecs_event_desc_t *) , ecs_enqueue , SimNode_ExtFuncCall >(lib,"ecs_enqueue","ecs_enqueue")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5037:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,const ecs_observer_desc_t *) , ecs_observer_init , SimNode_ExtFuncCall >(lib,"ecs_observer_init","ecs_observer_init")
		->args({"world","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5057:14
	makeExtern< ecs_entity_t (*)(ecs_world_t *,ecs_entity_t,const ecs_observer_desc_t *) , ecs_observer_update , SimNode_ExtFuncCall >(lib,"ecs_observer_update","ecs_observer_update")
		->args({"world","observer","desc"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5071:23
	makeExtern< const ecs_observer_t * (*)(const ecs_world_t *,ecs_entity_t) , ecs_observer_get , SimNode_ExtFuncCall >(lib,"ecs_observer_get","ecs_observer_get")
		->args({"world","observer"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5098:6
	makeExtern< bool (*)(ecs_iter_t *) , ecs_iter_next , SimNode_ExtFuncCall >(lib,"ecs_iter_next","ecs_iter_next")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5111:6
	makeExtern< void (*)(ecs_iter_t *) , ecs_iter_fini , SimNode_ExtFuncCall >(lib,"ecs_iter_fini","ecs_iter_fini")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5126:9
	makeExtern< int (*)(ecs_iter_t *) , ecs_iter_count , SimNode_ExtFuncCall >(lib,"ecs_iter_count","ecs_iter_count")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5142:6
	makeExtern< bool (*)(ecs_iter_t *) , ecs_iter_is_true , SimNode_ExtFuncCall >(lib,"ecs_iter_is_true","ecs_iter_is_true")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5153:14
	makeExtern< ecs_entity_t (*)(ecs_iter_t *) , ecs_iter_first , SimNode_ExtFuncCall >(lib,"ecs_iter_first","ecs_iter_first")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5192:6
	makeExtern< void (*)(ecs_iter_t *,int,ecs_entity_t) , ecs_iter_set_var , SimNode_ExtFuncCall >(lib,"ecs_iter_set_var","ecs_iter_set_var")
		->args({"it","var_id","entity"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5208:6
	makeExtern< void (*)(ecs_iter_t *,int,const ecs_table_t *) , ecs_iter_set_var_as_table , SimNode_ExtFuncCall >(lib,"ecs_iter_set_var_as_table","ecs_iter_set_var_as_table")
		->args({"it","var_id","table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5224:6
	makeExtern< void (*)(ecs_iter_t *,int,const ecs_table_range_t *) , ecs_iter_set_var_as_range , SimNode_ExtFuncCall >(lib,"ecs_iter_set_var_as_range","ecs_iter_set_var_as_range")
		->args({"it","var_id","range"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5244:14
	makeExtern< ecs_entity_t (*)(ecs_iter_t *,int) , ecs_iter_get_var , SimNode_ExtFuncCall >(lib,"ecs_iter_get_var","ecs_iter_get_var")
		->args({"it","var_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5255:13
	makeExtern< const char * (*)(const ecs_iter_t *,int) , ecs_iter_get_var_name , SimNode_ExtFuncCall >(lib,"ecs_iter_get_var_name","ecs_iter_get_var_name")
		->args({"it","var_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5265:9
	makeExtern< int (*)(const ecs_iter_t *) , ecs_iter_get_var_count , SimNode_ExtFuncCall >(lib,"ecs_iter_get_var_count","ecs_iter_get_var_count")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5274:12
	makeExtern< ecs_var_t * (*)(const ecs_iter_t *) , ecs_iter_get_vars , SimNode_ExtFuncCall >(lib,"ecs_iter_get_vars","ecs_iter_get_vars")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5291:14
	makeExtern< ecs_table_t * (*)(ecs_iter_t *,int) , ecs_iter_get_var_as_table , SimNode_ExtFuncCall >(lib,"ecs_iter_get_var_as_table","ecs_iter_get_var_as_table")
		->args({"it","var_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5309:19
	makeExtern< ecs_table_range_t (*)(ecs_iter_t *,int) , ecs_iter_get_var_as_range , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_iter_get_var_as_range","ecs_iter_get_var_as_range")
		->args({"it","var_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5325:6
	makeExtern< bool (*)(ecs_iter_t *,int) , ecs_iter_var_is_constrained , SimNode_ExtFuncCall >(lib,"ecs_iter_var_is_constrained","ecs_iter_var_is_constrained")
		->args({"it","var_id"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5345:10
	makeExtern< uint64_t (*)(const ecs_iter_t *) , ecs_iter_get_group , SimNode_ExtFuncCall >(lib,"ecs_iter_get_group","ecs_iter_get_group")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5360:6
	makeExtern< bool (*)(ecs_iter_t *) , ecs_iter_changed , SimNode_ExtFuncCall >(lib,"ecs_iter_changed","ecs_iter_changed")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5380:12
	makeExtern< ecs_iter_t (*)(const ecs_iter_t *,int,int) , ecs_page_iter , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_page_iter","ecs_page_iter")
		->args({"it","offset","limit"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5392:6
	makeExtern< bool (*)(ecs_iter_t *) , ecs_page_next , SimNode_ExtFuncCall >(lib,"ecs_page_next","ecs_page_next")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5416:12
	makeExtern< ecs_iter_t (*)(const ecs_iter_t *,int,int) , ecs_worker_iter , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_worker_iter","ecs_worker_iter")
		->args({"it","index","count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5428:6
	makeExtern< bool (*)(ecs_iter_t *) , ecs_worker_next , SimNode_ExtFuncCall >(lib,"ecs_worker_next","ecs_worker_next")
		->args({"it"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5473:7
	makeExtern< void * (*)(const ecs_iter_t *,size_t,signed char) , ecs_field_w_size , SimNode_ExtFuncCall >(lib,"ecs_field_w_size","ecs_field_w_size")
		->args({"it","size","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5491:7
	makeExtern< void * (*)(const ecs_iter_t *,size_t,signed char) , ecs_base_field_w_size , SimNode_ExtFuncCall >(lib,"ecs_base_field_w_size","ecs_base_field_w_size")
		->args({"it","size","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5519:7
	makeExtern< void * (*)(const ecs_iter_t *,size_t,signed char,int) , ecs_field_at_w_size , SimNode_ExtFuncCall >(lib,"ecs_field_at_w_size","ecs_field_at_w_size")
		->args({"it","size","index","row"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5534:6
	makeExtern< bool (*)(const ecs_iter_t *,signed char) , ecs_field_is_readonly , SimNode_ExtFuncCall >(lib,"ecs_field_is_readonly","ecs_field_is_readonly")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5549:6
	makeExtern< bool (*)(const ecs_iter_t *,signed char) , ecs_field_is_writeonly , SimNode_ExtFuncCall >(lib,"ecs_field_is_writeonly","ecs_field_is_writeonly")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5560:6
	makeExtern< bool (*)(const ecs_iter_t *,signed char) , ecs_field_is_set , SimNode_ExtFuncCall >(lib,"ecs_field_is_set","ecs_field_is_set")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5571:10
	makeExtern< ecs_id_t (*)(const ecs_iter_t *,signed char) , ecs_field_id , SimNode_ExtFuncCall >(lib,"ecs_field_id","ecs_field_id")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5584:9
	makeExtern< int (*)(const ecs_iter_t *,signed char) , ecs_field_column , SimNode_ExtFuncCall >(lib,"ecs_field_column","ecs_field_column")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5596:14
	makeExtern< ecs_entity_t (*)(const ecs_iter_t *,signed char) , ecs_field_src , SimNode_ExtFuncCall >(lib,"ecs_field_src","ecs_field_src")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5608:8
	makeExtern< size_t (*)(const ecs_iter_t *,signed char) , ecs_field_size , SimNode_ExtFuncCall >(lib,"ecs_field_size","ecs_field_size")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5621:8
	makeExtern< size_t (*)(const ecs_iter_t *,signed char) , ecs_field_stride , SimNode_ExtFuncCall >(lib,"ecs_field_stride","ecs_field_stride")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5639:6
	makeExtern< bool (*)(const ecs_iter_t *,signed char) , ecs_field_is_self , SimNode_ExtFuncCall >(lib,"ecs_field_is_self","ecs_field_is_self")
		->args({"it","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5659:19
	makeExtern< const ecs_type_t * (*)(const ecs_table_t *) , ecs_table_get_type , SimNode_ExtFuncCall >(lib,"ecs_table_get_type","ecs_table_get_type")
		->args({"table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5673:9
	makeExtern< int (*)(const ecs_world_t *,const ecs_table_t *,ecs_id_t) , ecs_table_get_type_index , SimNode_ExtFuncCall >(lib,"ecs_table_get_type_index","ecs_table_get_type_index")
		->args({"world","table","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5688:9
	makeExtern< int (*)(const ecs_world_t *,const ecs_table_t *,ecs_id_t) , ecs_table_get_column_index , SimNode_ExtFuncCall >(lib,"ecs_table_get_column_index","ecs_table_get_column_index")
		->args({"world","table","component"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5701:9
	makeExtern< int (*)(const ecs_table_t *) , ecs_table_column_count , SimNode_ExtFuncCall >(lib,"ecs_table_column_count","ecs_table_column_count")
		->args({"table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5718:9
	makeExtern< int (*)(const ecs_table_t *,int) , ecs_table_type_to_column_index , SimNode_ExtFuncCall >(lib,"ecs_table_type_to_column_index","ecs_table_type_to_column_index")
		->args({"table","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5731:9
	makeExtern< int (*)(const ecs_table_t *,int) , ecs_table_column_to_type_index , SimNode_ExtFuncCall >(lib,"ecs_table_column_to_type_index","ecs_table_column_to_type_index")
		->args({"table","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5744:7
	makeExtern< void * (*)(const ecs_table_t *,int,int) , ecs_table_get_column , SimNode_ExtFuncCall >(lib,"ecs_table_get_column","ecs_table_get_column")
		->args({"table","index","offset"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5759:7
	makeExtern< void * (*)(const ecs_world_t *,const ecs_table_t *,ecs_id_t,int) , ecs_table_get_id , SimNode_ExtFuncCall >(lib,"ecs_table_get_id","ecs_table_get_id")
		->args({"world","table","component","offset"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5773:8
	makeExtern< size_t (*)(const ecs_table_t *,int) , ecs_table_get_column_size , SimNode_ExtFuncCall >(lib,"ecs_table_get_column_size","ecs_table_get_column_size")
		->args({"table","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5784:9
	makeExtern< int (*)(const ecs_table_t *) , ecs_table_count , SimNode_ExtFuncCall >(lib,"ecs_table_count","ecs_table_count")
		->args({"table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5795:9
	makeExtern< int (*)(const ecs_table_t *) , ecs_table_size , SimNode_ExtFuncCall >(lib,"ecs_table_size","ecs_table_size")
		->args({"table"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:5805:21
	makeExtern< const ecs_entity_t * (*)(const ecs_table_t *) , ecs_table_entities , SimNode_ExtFuncCall >(lib,"ecs_table_entities","ecs_table_entities")
		->args({"table"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

