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
void Module_dasFlecs::initFunctions_11() {
// from flecs/addons/meta.h:673:19
	makeExtern< ecs_meta_cursor_t (*)(const ecs_world_t *,ecs_entity_t,void *) , ecs_meta_cursor , SimNode_ExtFuncCallAndCopyOrMove >(lib,"ecs_meta_cursor","ecs_meta_cursor")
		->args({"world","type","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:684:7
	makeExtern< void * (*)(ecs_meta_cursor_t *) , ecs_meta_get_ptr , SimNode_ExtFuncCall >(lib,"ecs_meta_get_ptr","ecs_meta_get_ptr")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:693:5
	makeExtern< int (*)(ecs_meta_cursor_t *) , ecs_meta_next , SimNode_ExtFuncCall >(lib,"ecs_meta_next","ecs_meta_next")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:702:5
	makeExtern< int (*)(ecs_meta_cursor_t *,int) , ecs_meta_elem , SimNode_ExtFuncCall >(lib,"ecs_meta_elem","ecs_meta_elem")
		->args({"cursor","elem"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:713:5
	makeExtern< int (*)(ecs_meta_cursor_t *,const char *) , ecs_meta_member , SimNode_ExtFuncCall >(lib,"ecs_meta_member","ecs_meta_member")
		->args({"cursor","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:724:5
	makeExtern< int (*)(ecs_meta_cursor_t *,const ecs_value_t *) , ecs_meta_key , SimNode_ExtFuncCall >(lib,"ecs_meta_key","ecs_meta_key")
		->args({"cursor","key"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:736:5
	makeExtern< int (*)(ecs_meta_cursor_t *,const char *) , ecs_meta_try_member , SimNode_ExtFuncCall >(lib,"ecs_meta_try_member","ecs_meta_try_member")
		->args({"cursor","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:749:5
	makeExtern< int (*)(ecs_meta_cursor_t *,const char *) , ecs_meta_dotmember , SimNode_ExtFuncCall >(lib,"ecs_meta_dotmember","ecs_meta_dotmember")
		->args({"cursor","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:761:5
	makeExtern< int (*)(ecs_meta_cursor_t *,const char *) , ecs_meta_try_dotmember , SimNode_ExtFuncCall >(lib,"ecs_meta_try_dotmember","ecs_meta_try_dotmember")
		->args({"cursor","name"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:771:5
	makeExtern< int (*)(ecs_meta_cursor_t *) , ecs_meta_push , SimNode_ExtFuncCall >(lib,"ecs_meta_push","ecs_meta_push")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:780:5
	makeExtern< int (*)(ecs_meta_cursor_t *) , ecs_meta_pop , SimNode_ExtFuncCall >(lib,"ecs_meta_pop","ecs_meta_pop")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:789:6
	makeExtern< bool (*)(const ecs_meta_cursor_t *) , ecs_meta_is_collection , SimNode_ExtFuncCall >(lib,"ecs_meta_is_collection","ecs_meta_is_collection")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:801:6
	makeExtern< bool (*)(const ecs_meta_cursor_t *) , ecs_meta_is_map , SimNode_ExtFuncCall >(lib,"ecs_meta_is_map","ecs_meta_is_map")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:810:14
	makeExtern< ecs_entity_t (*)(const ecs_meta_cursor_t *) , ecs_meta_get_type , SimNode_ExtFuncCall >(lib,"ecs_meta_get_type","ecs_meta_get_type")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:819:14
	makeExtern< ecs_entity_t (*)(const ecs_meta_cursor_t *) , ecs_meta_get_unit , SimNode_ExtFuncCall >(lib,"ecs_meta_get_unit","ecs_meta_get_unit")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:828:13
	makeExtern< const char * (*)(const ecs_meta_cursor_t *) , ecs_meta_get_member , SimNode_ExtFuncCall >(lib,"ecs_meta_get_member","ecs_meta_get_member")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:837:14
	makeExtern< ecs_entity_t (*)(const ecs_meta_cursor_t *) , ecs_meta_get_member_id , SimNode_ExtFuncCall >(lib,"ecs_meta_get_member_id","ecs_meta_get_member_id")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:851:5
	makeExtern< int (*)(ecs_meta_cursor_t *,bool) , ecs_meta_set_bool , SimNode_ExtFuncCall >(lib,"ecs_meta_set_bool","ecs_meta_set_bool")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:862:5
	makeExtern< int (*)(ecs_meta_cursor_t *,char) , ecs_meta_set_char , SimNode_ExtFuncCall >(lib,"ecs_meta_set_char","ecs_meta_set_char")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:873:5
	makeExtern< int (*)(ecs_meta_cursor_t *,int64_t) , ecs_meta_set_int , SimNode_ExtFuncCall >(lib,"ecs_meta_set_int","ecs_meta_set_int")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:884:5
	makeExtern< int (*)(ecs_meta_cursor_t *,uint64_t) , ecs_meta_set_uint , SimNode_ExtFuncCall >(lib,"ecs_meta_set_uint","ecs_meta_set_uint")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:895:5
	makeExtern< int (*)(ecs_meta_cursor_t *,double) , ecs_meta_set_float , SimNode_ExtFuncCall >(lib,"ecs_meta_set_float","ecs_meta_set_float")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:906:5
	makeExtern< int (*)(ecs_meta_cursor_t *,const char *) , ecs_meta_set_string , SimNode_ExtFuncCall >(lib,"ecs_meta_set_string","ecs_meta_set_string")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:917:5
	makeExtern< int (*)(ecs_meta_cursor_t *,const char *) , ecs_meta_set_string_literal , SimNode_ExtFuncCall >(lib,"ecs_meta_set_string_literal","ecs_meta_set_string_literal")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:928:5
	makeExtern< int (*)(ecs_meta_cursor_t *,ecs_entity_t) , ecs_meta_set_entity , SimNode_ExtFuncCall >(lib,"ecs_meta_set_entity","ecs_meta_set_entity")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:939:5
	makeExtern< int (*)(ecs_meta_cursor_t *,ecs_id_t) , ecs_meta_set_id , SimNode_ExtFuncCall >(lib,"ecs_meta_set_id","ecs_meta_set_id")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:949:5
	makeExtern< int (*)(ecs_meta_cursor_t *) , ecs_meta_set_null , SimNode_ExtFuncCall >(lib,"ecs_meta_set_null","ecs_meta_set_null")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:961:5
	makeExtern< int (*)(ecs_meta_cursor_t *,const ecs_value_t *) , ecs_meta_set_value , SimNode_ExtFuncCall >(lib,"ecs_meta_set_value","ecs_meta_set_value")
		->args({"cursor","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:973:6
	makeExtern< bool (*)(const ecs_meta_cursor_t *) , ecs_meta_get_bool , SimNode_ExtFuncCall >(lib,"ecs_meta_get_bool","ecs_meta_get_bool")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:982:6
	makeExtern< char (*)(const ecs_meta_cursor_t *) , ecs_meta_get_char , SimNode_ExtFuncCall >(lib,"ecs_meta_get_char","ecs_meta_get_char")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:991:9
	makeExtern< int64_t (*)(const ecs_meta_cursor_t *) , ecs_meta_get_int , SimNode_ExtFuncCall >(lib,"ecs_meta_get_int","ecs_meta_get_int")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1000:10
	makeExtern< uint64_t (*)(const ecs_meta_cursor_t *) , ecs_meta_get_uint , SimNode_ExtFuncCall >(lib,"ecs_meta_get_uint","ecs_meta_get_uint")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1009:8
	makeExtern< double (*)(const ecs_meta_cursor_t *) , ecs_meta_get_float , SimNode_ExtFuncCall >(lib,"ecs_meta_get_float","ecs_meta_get_float")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1020:13
	makeExtern< const char * (*)(const ecs_meta_cursor_t *) , ecs_meta_get_string , SimNode_ExtFuncCall >(lib,"ecs_meta_get_string","ecs_meta_get_string")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1030:14
	makeExtern< ecs_entity_t (*)(const ecs_meta_cursor_t *) , ecs_meta_get_entity , SimNode_ExtFuncCall >(lib,"ecs_meta_get_entity","ecs_meta_get_entity")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1040:10
	makeExtern< ecs_id_t (*)(const ecs_meta_cursor_t *) , ecs_meta_get_id , SimNode_ExtFuncCall >(lib,"ecs_meta_get_id","ecs_meta_get_id")
		->args({"cursor"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1050:8
	makeExtern< double (*)(ecs_primitive_kind_t,const void *) , ecs_meta_ptr_to_float , SimNode_ExtFuncCall >(lib,"ecs_meta_ptr_to_float","ecs_meta_ptr_to_float")
		->args({"type_kind","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1064:12
	makeExtern< int (*)(const ecs_meta_op_t *,const void *) , ecs_meta_op_get_elem_count , SimNode_ExtFuncCall >(lib,"ecs_meta_op_get_elem_count","ecs_meta_op_get_elem_count")
		->args({"op","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1084:14
	makeExtern< ecs_entity_t (*)(const ecs_world_t *,ecs_entity_t,int64_t) , ecs_constant_to_entity_id , SimNode_ExtFuncCall >(lib,"ecs_constant_to_entity_id","ecs_constant_to_entity_id")
		->args({"world","type","value"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1111:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,void *) , ecs_ptr_init , SimNode_ExtFuncCall >(lib,"ecs_ptr_init","ecs_ptr_init")
		->args({"world","type","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1124:5
	makeExtern< int (*)(const ecs_world_t *,const ecs_type_info_t *,void *) , ecs_ptr_init_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_ptr_init_w_type_info","ecs_ptr_init_w_type_info")
		->args({"world","ti","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1136:7
	makeExtern< void * (*)(ecs_world_t *,ecs_entity_t) , ecs_ptr_new , SimNode_ExtFuncCall >(lib,"ecs_ptr_new","ecs_ptr_new")
		->args({"world","type"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1146:7
	makeExtern< void * (*)(ecs_world_t *,const ecs_type_info_t *) , ecs_ptr_new_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_ptr_new_w_type_info","ecs_ptr_new_w_type_info")
		->args({"world","ti"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1157:5
	makeExtern< int (*)(const ecs_world_t *,const ecs_type_info_t *,void *) , ecs_ptr_fini_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_ptr_fini_w_type_info","ecs_ptr_fini_w_type_info")
		->args({"world","ti","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1170:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,void *) , ecs_ptr_fini , SimNode_ExtFuncCall >(lib,"ecs_ptr_fini","ecs_ptr_fini")
		->args({"world","type","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1183:5
	makeExtern< int (*)(ecs_world_t *,const ecs_type_info_t *,void *) , ecs_ptr_free_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_ptr_free_w_type_info","ecs_ptr_free_w_type_info")
		->args({"world","ti","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1196:5
	makeExtern< int (*)(ecs_world_t *,ecs_entity_t,void *) , ecs_ptr_free , SimNode_ExtFuncCall >(lib,"ecs_ptr_free","ecs_ptr_free")
		->args({"world","type","ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1210:5
	makeExtern< int (*)(const ecs_world_t *,const ecs_type_info_t *,void *,const void *) , ecs_ptr_copy_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_ptr_copy_w_type_info","ecs_ptr_copy_w_type_info")
		->args({"world","ti","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1225:5
	makeExtern< int (*)(const ecs_world_t *,ecs_entity_t,void *,const void *) , ecs_ptr_copy , SimNode_ExtFuncCall >(lib,"ecs_ptr_copy","ecs_ptr_copy")
		->args({"world","type","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
// from flecs/addons/meta.h:1240:5
	makeExtern< int (*)(const ecs_world_t *,const ecs_type_info_t *,void *,void *) , ecs_ptr_move_w_type_info , SimNode_ExtFuncCall >(lib,"ecs_ptr_move_w_type_info","ecs_ptr_move_w_type_info")
		->args({"world","ti","dst","src"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

