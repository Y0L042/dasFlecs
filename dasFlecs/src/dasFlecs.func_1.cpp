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
void Module_dasFlecs::initFunctions_1() {
// from flecs/datastructures/vec.h:34:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int) , ecs_vec_init , SimNode_ExtFuncCall >(lib,"ecs_vec_init","ecs_vec_init")
		->args({"allocator","vec","size","elem_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:49:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int,const char *) , ecs_vec_init_w_dbg_info , SimNode_ExtFuncCall >(lib,"ecs_vec_init_w_dbg_info","ecs_vec_init_w_dbg_info")
		->args({"allocator","vec","size","elem_count","type_name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:72:6
	makeExtern< void (*)(ecs_vec_t *,int) , ecs_vec_init_if , SimNode_ExtFuncCall >(lib,"ecs_vec_init_if","ecs_vec_init_if")
		->args({"vec","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:91:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int) , ecs_vec_fini , SimNode_ExtFuncCall >(lib,"ecs_vec_fini","ecs_vec_fini")
		->args({"allocator","vec","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:113:12
	makeExtern< ecs_vec_t * (*)(ecs_allocator_t *,ecs_vec_t *,int) , ecs_vec_reset , SimNode_ExtFuncCall >(lib,"ecs_vec_reset","ecs_vec_reset")
		->args({"allocator","vec","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:132:6
	makeExtern< void (*)(ecs_vec_t *) , ecs_vec_clear , SimNode_ExtFuncCall >(lib,"ecs_vec_clear","ecs_vec_clear")
		->args({"vec"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:143:7
	makeExtern< void * (*)(ecs_allocator_t *,ecs_vec_t *,int) , ecs_vec_append , SimNode_ExtFuncCall >(lib,"ecs_vec_append","ecs_vec_append")
		->args({"allocator","vec","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:165:6
	makeExtern< void (*)(ecs_vec_t *,int,int) , ecs_vec_remove , SimNode_ExtFuncCall >(lib,"ecs_vec_remove","ecs_vec_remove")
		->args({"vec","size","elem"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:186:6
	makeExtern< void (*)(ecs_vec_t *,int,int) , ecs_vec_remove_ordered , SimNode_ExtFuncCall >(lib,"ecs_vec_remove_ordered","ecs_vec_remove_ordered")
		->args({"v","size","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:205:6
	makeExtern< void (*)(ecs_vec_t *) , ecs_vec_remove_last , SimNode_ExtFuncCall >(lib,"ecs_vec_remove_last","ecs_vec_remove_last")
		->args({"vec"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:216:11
	makeExtern< ecs_vec_t (*)(ecs_allocator_t *,const ecs_vec_t *,int) , ecs_vec_copy , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_vec_copy","ecs_vec_copy")
		->args({"allocator","vec","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:237:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int) , ecs_vec_reclaim , SimNode_ExtFuncCall >(lib,"ecs_vec_reclaim","ecs_vec_reclaim")
		->args({"allocator","vec","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:259:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int) , ecs_vec_set_size , SimNode_ExtFuncCall >(lib,"ecs_vec_set_size","ecs_vec_set_size")
		->args({"allocator","vec","size","elem_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:283:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int) , ecs_vec_set_min_size , SimNode_ExtFuncCall >(lib,"ecs_vec_set_min_size","ecs_vec_set_min_size")
		->args({"allocator","vec","size","elem_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:307:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int) , ecs_vec_set_min_count , SimNode_ExtFuncCall >(lib,"ecs_vec_set_min_count","ecs_vec_set_min_count")
		->args({"allocator","vec","size","elem_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:331:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int) , ecs_vec_set_min_count_zeromem , SimNode_ExtFuncCall >(lib,"ecs_vec_set_min_count_zeromem","ecs_vec_set_min_count_zeromem")
		->args({"allocator","vec","size","elem_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:355:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int) , ecs_vec_set_count , SimNode_ExtFuncCall >(lib,"ecs_vec_set_count","ecs_vec_set_count")
		->args({"allocator","vec","size","elem_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:380:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int,const ecs_type_info_t *) , ecs_vec_set_count_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_vec_set_count_w_type_info","ecs_vec_set_count_w_type_info")
		->args({"allocator","vec","size","elem_count","ti"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:396:6
	makeExtern< void (*)(ecs_allocator_t *,ecs_vec_t *,int,int,const ecs_type_info_t *) , ecs_vec_set_min_count_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_vec_set_min_count_w_type_info","ecs_vec_set_min_count_w_type_info")
		->args({"allocator","vec","size","elem_count","ti"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:412:7
	makeExtern< void * (*)(ecs_allocator_t *,ecs_vec_t *,int,int) , ecs_vec_grow , SimNode_ExtFuncCall >(lib,"ecs_vec_grow","ecs_vec_grow")
		->args({"allocator","vec","size","elem_count"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:434:9
	makeExtern< int (*)(const ecs_vec_t *) , ecs_vec_count , SimNode_ExtFuncCall >(lib,"ecs_vec_count","ecs_vec_count")
		->args({"vec"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:443:9
	makeExtern< int (*)(const ecs_vec_t *) , ecs_vec_size , SimNode_ExtFuncCall >(lib,"ecs_vec_size","ecs_vec_size")
		->args({"vec"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:454:7
	makeExtern< void * (*)(const ecs_vec_t *,int,int) , ecs_vec_get , SimNode_ExtFuncCall >(lib,"ecs_vec_get","ecs_vec_get")
		->args({"vec","size","index"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:475:7
	makeExtern< void * (*)(const ecs_vec_t *) , ecs_vec_first , SimNode_ExtFuncCall >(lib,"ecs_vec_first","ecs_vec_first")
		->args({"vec"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/vec.h:494:7
	makeExtern< void * (*)(const ecs_vec_t *,int) , ecs_vec_last , SimNode_ExtFuncCall >(lib,"ecs_vec_last","ecs_vec_last")
		->args({"vec","size"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:74:6
	makeExtern< void (*)(ecs_map_t *,ecs_allocator_t *) , ecs_map_init , SimNode_ExtFuncCall >(lib,"ecs_map_init","ecs_map_init")
		->args({"map","allocator"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:84:6
	makeExtern< void (*)(ecs_map_t *,ecs_allocator_t *) , ecs_map_init_if , SimNode_ExtFuncCall >(lib,"ecs_map_init_if","ecs_map_init_if")
		->args({"map","allocator"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:93:6
	makeExtern< void (*)(ecs_map_t *) , ecs_map_reclaim , SimNode_ExtFuncCall >(lib,"ecs_map_reclaim","ecs_map_reclaim")
		->args({"map"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:101:6
	makeExtern< void (*)(ecs_map_t *) , ecs_map_fini , SimNode_ExtFuncCall >(lib,"ecs_map_fini","ecs_map_fini")
		->args({"map"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:111:16
	makeExtern< ecs_map_val_t * (*)(const ecs_map_t *,ecs_map_key_t) , ecs_map_get , SimNode_ExtFuncCall >(lib,"ecs_map_get","ecs_map_get")
		->args({"map","key"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:122:7
	makeExtern< void * (*)(const ecs_map_t *,ecs_map_key_t) , ecs_map_get_deref_ , SimNode_ExtFuncCall >(lib,"ecs_map_get_deref_","ecs_map_get_deref_")
		->args({"map","key"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:133:16
	makeExtern< ecs_map_val_t * (*)(ecs_map_t *,ecs_map_key_t) , ecs_map_ensure , SimNode_ExtFuncCall >(lib,"ecs_map_ensure","ecs_map_ensure")
		->args({"map","key"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:145:7
	makeExtern< void * (*)(ecs_map_t *,int,ecs_map_key_t) , ecs_map_ensure_alloc , SimNode_ExtFuncCall >(lib,"ecs_map_ensure_alloc","ecs_map_ensure_alloc")
		->args({"map","elem_size","key"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:157:6
	makeExtern< void (*)(ecs_map_t *,ecs_map_key_t,ecs_map_val_t) , ecs_map_insert , SimNode_ExtFuncCall >(lib,"ecs_map_insert","ecs_map_insert")
		->args({"map","key","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:170:7
	makeExtern< void * (*)(ecs_map_t *,int,ecs_map_key_t) , ecs_map_insert_alloc , SimNode_ExtFuncCall >(lib,"ecs_map_insert_alloc","ecs_map_insert_alloc")
		->args({"map","elem_size","key"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:182:15
	makeExtern< ecs_map_val_t (*)(ecs_map_t *,ecs_map_key_t) , ecs_map_remove , SimNode_ExtFuncCall >(lib,"ecs_map_remove","ecs_map_remove")
		->args({"map","key"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:192:6
	makeExtern< void (*)(ecs_map_t *,ecs_map_key_t) , ecs_map_remove_free , SimNode_ExtFuncCall >(lib,"ecs_map_remove_free","ecs_map_remove_free")
		->args({"map","key"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:201:6
	makeExtern< void (*)(ecs_map_t *) , ecs_map_clear , SimNode_ExtFuncCall >(lib,"ecs_map_clear","ecs_map_clear")
		->args({"map"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:216:16
	makeExtern< ecs_map_iter_t (*)(const ecs_map_t *) , ecs_map_iter , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_map_iter","ecs_map_iter")
		->args({"map"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:225:6
	makeExtern< bool (*)(ecs_map_iter_t *) , ecs_map_iter_valid , SimNode_ExtFuncCall >(lib,"ecs_map_iter_valid","ecs_map_iter_valid")
		->args({"iter"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:234:6
	makeExtern< bool (*)(ecs_map_iter_t *) , ecs_map_next , SimNode_ExtFuncCall >(lib,"ecs_map_next","ecs_map_next")
		->args({"iter"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/datastructures/map.h:243:6
	makeExtern< void (*)(ecs_map_t *,const ecs_map_t *) , ecs_map_copy , SimNode_ExtFuncCall >(lib,"ecs_map_copy","ecs_map_copy")
		->args({"dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:1991:14
	makeExtern< ecs_world_t * (*)() , ecs_init , SimNode_ExtFuncCall >(lib,"ecs_init","ecs_init")
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2000:14
	makeExtern< ecs_world_t * (*)() , ecs_mini , SimNode_ExtFuncCall >(lib,"ecs_mini","ecs_mini")
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2012:14
	makeExtern< ecs_world_t * (*)(int,char *[]) , ecs_init_w_args , SimNode_ExtFuncCall >(lib,"ecs_init_w_args","ecs_init_w_args")
		->args({"argc","argv"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2023:5
	makeExtern< int (*)(ecs_world_t *) , ecs_fini , SimNode_ExtFuncCall >(lib,"ecs_fini","ecs_fini")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2034:6
	makeExtern< bool (*)(const ecs_world_t *) , ecs_is_fini , SimNode_ExtFuncCall >(lib,"ecs_is_fini","ecs_is_fini")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2085:16
	makeExtern< ecs_entities_t (*)(const ecs_world_t *) , ecs_get_entities , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_get_entities","ecs_get_entities")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2096:15
	makeExtern< unsigned int (*)(const ecs_world_t *) , ecs_world_get_flags , SimNode_ExtFuncCall >(lib,"ecs_world_get_flags","ecs_world_get_flags")
		->args({"world"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs.h:2162:6
	makeExtern< bool (*)(ecs_world_t *,bool) , ecs_readonly_begin , SimNode_ExtFuncCall >(lib,"ecs_readonly_begin","ecs_readonly_begin")
		->args({"world","multi_threaded"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

