// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

// from flecs/private/api_defines.h:174:17
auto alias_ecs_flags8_t = typeFactory<unsigned char>::make(lib);
alias_ecs_flags8_t->alias = "ecs_flags8_t";
addAlias(alias_ecs_flags8_t);

// from flecs/private/api_defines.h:175:18
auto alias_ecs_flags16_t = typeFactory<unsigned short>::make(lib);
alias_ecs_flags16_t->alias = "ecs_flags16_t";
addAlias(alias_ecs_flags16_t);

// from flecs/private/api_defines.h:176:18
auto alias_ecs_flags32_t = typeFactory<unsigned int>::make(lib);
alias_ecs_flags32_t->alias = "ecs_flags32_t";
addAlias(alias_ecs_flags32_t);

// from flecs/private/api_defines.h:177:18
auto alias_ecs_flags64_t = typeFactory<uint64_t>::make(lib);
alias_ecs_flags64_t->alias = "ecs_flags64_t";
addAlias(alias_ecs_flags64_t);

// from flecs/private/api_defines.h:194:17
auto alias_ecs_size_t = typeFactory<int>::make(lib);
alias_ecs_size_t->alias = "ecs_size_t";
addAlias(alias_ecs_size_t);

// from flecs.h:389:18
auto alias_ecs_id_t = typeFactory<uint64_t>::make(lib);
alias_ecs_id_t->alias = "ecs_id_t";
addAlias(alias_ecs_id_t);

// from flecs.h:396:18
auto alias_ecs_entity_t = typeFactory<ecs_id_t>::make(lib);
alias_ecs_entity_t->alias = "ecs_entity_t";
addAlias(alias_ecs_entity_t);

// from flecs.h:529:14
auto alias_ecs_poly_t = typeFactory<void>::make(lib);
alias_ecs_poly_t->alias = "ecs_poly_t";
addAlias(alias_ecs_poly_t);

// from flecs/datastructures/map.h:16:18
auto alias_ecs_map_data_t = typeFactory<uint64_t>::make(lib);
alias_ecs_map_data_t->alias = "ecs_map_data_t";
addAlias(alias_ecs_map_data_t);

// from flecs/datastructures/map.h:19:24
auto alias_ecs_map_key_t = typeFactory<ecs_map_data_t>::make(lib);
alias_ecs_map_key_t->alias = "ecs_map_key_t";
addAlias(alias_ecs_map_key_t);

// from flecs/datastructures/map.h:22:24
auto alias_ecs_map_val_t = typeFactory<ecs_map_data_t>::make(lib);
alias_ecs_map_val_t->alias = "ecs_map_val_t";
addAlias(alias_ecs_map_val_t);

// from flecs/os_api.h:59:19
auto alias_ecs_os_thread_t = typeFactory<uintptr_t>::make(lib);
alias_ecs_os_thread_t->alias = "ecs_os_thread_t";
addAlias(alias_ecs_os_thread_t);

// from flecs/os_api.h:60:19
auto alias_ecs_os_cond_t = typeFactory<uintptr_t>::make(lib);
alias_ecs_os_cond_t->alias = "ecs_os_cond_t";
addAlias(alias_ecs_os_cond_t);

// from flecs/os_api.h:61:19
auto alias_ecs_os_mutex_t = typeFactory<uintptr_t>::make(lib);
alias_ecs_os_mutex_t->alias = "ecs_os_mutex_t";
addAlias(alias_ecs_os_mutex_t);

// from flecs/os_api.h:62:19
auto alias_ecs_os_dl_t = typeFactory<uintptr_t>::make(lib);
alias_ecs_os_dl_t->alias = "ecs_os_dl_t";
addAlias(alias_ecs_os_dl_t);

// from flecs/os_api.h:63:19
auto alias_ecs_os_sock_t = typeFactory<uintptr_t>::make(lib);
alias_ecs_os_sock_t->alias = "ecs_os_sock_t";
addAlias(alias_ecs_os_sock_t);

// from flecs/os_api.h:66:18
auto alias_ecs_os_thread_id_t = typeFactory<uint64_t>::make(lib);
alias_ecs_os_thread_id_t->alias = "ecs_os_thread_id_t";
addAlias(alias_ecs_os_thread_id_t);

// from flecs/addons/script.h:272:38
auto alias_EcsScriptFunction = typeFactory<ecs_script_function_t>::make(lib);
alias_EcsScriptFunction->alias = "EcsScriptFunction";
addAlias(alias_EcsScriptFunction);

// from flecs/addons/script.h:279:38
auto alias_EcsScriptMethod = typeFactory<ecs_script_function_t>::make(lib);
alias_EcsScriptMethod->alias = "EcsScriptMethod";
addAlias(alias_EcsScriptMethod);

// from flecs/addons/meta.h:95:14
auto alias_ecs_bool_t = typeFactory<bool>::make(lib);
alias_ecs_bool_t->alias = "ecs_bool_t";
addAlias(alias_ecs_bool_t);

// from flecs/addons/meta.h:96:14
auto alias_ecs_char_t = typeFactory<char>::make(lib);
alias_ecs_char_t->alias = "ecs_char_t";
addAlias(alias_ecs_char_t);

// from flecs/addons/meta.h:97:23
auto alias_ecs_byte_t = typeFactory<unsigned char>::make(lib);
alias_ecs_byte_t->alias = "ecs_byte_t";
addAlias(alias_ecs_byte_t);

// from flecs/addons/meta.h:98:17
auto alias_ecs_u8_t = typeFactory<unsigned char>::make(lib);
alias_ecs_u8_t->alias = "ecs_u8_t";
addAlias(alias_ecs_u8_t);

// from flecs/addons/meta.h:99:18
auto alias_ecs_u16_t = typeFactory<unsigned short>::make(lib);
alias_ecs_u16_t->alias = "ecs_u16_t";
addAlias(alias_ecs_u16_t);

// from flecs/addons/meta.h:100:18
auto alias_ecs_u32_t = typeFactory<unsigned int>::make(lib);
alias_ecs_u32_t->alias = "ecs_u32_t";
addAlias(alias_ecs_u32_t);

// from flecs/addons/meta.h:101:18
auto alias_ecs_u64_t = typeFactory<uint64_t>::make(lib);
alias_ecs_u64_t->alias = "ecs_u64_t";
addAlias(alias_ecs_u64_t);

// from flecs/addons/meta.h:102:19
auto alias_ecs_uptr_t = typeFactory<uintptr_t>::make(lib);
alias_ecs_uptr_t->alias = "ecs_uptr_t";
addAlias(alias_ecs_uptr_t);

// from flecs/addons/meta.h:103:16
auto alias_ecs_i8_t = typeFactory<signed char>::make(lib);
alias_ecs_i8_t->alias = "ecs_i8_t";
addAlias(alias_ecs_i8_t);

// from flecs/addons/meta.h:104:17
auto alias_ecs_i16_t = typeFactory<short>::make(lib);
alias_ecs_i16_t->alias = "ecs_i16_t";
addAlias(alias_ecs_i16_t);

// from flecs/addons/meta.h:105:17
auto alias_ecs_i32_t = typeFactory<int>::make(lib);
alias_ecs_i32_t->alias = "ecs_i32_t";
addAlias(alias_ecs_i32_t);

// from flecs/addons/meta.h:106:17
auto alias_ecs_i64_t = typeFactory<int64_t>::make(lib);
alias_ecs_i64_t->alias = "ecs_i64_t";
addAlias(alias_ecs_i64_t);

// from flecs/addons/meta.h:107:18
auto alias_ecs_iptr_t = typeFactory<intptr_t>::make(lib);
alias_ecs_iptr_t->alias = "ecs_iptr_t";
addAlias(alias_ecs_iptr_t);

// from flecs/addons/meta.h:108:15
auto alias_ecs_f32_t = typeFactory<float>::make(lib);
alias_ecs_f32_t->alias = "ecs_f32_t";
addAlias(alias_ecs_f32_t);

// from flecs/addons/meta.h:109:16
auto alias_ecs_f64_t = typeFactory<double>::make(lib);
alias_ecs_f64_t->alias = "ecs_f64_t";
addAlias(alias_ecs_f64_t);

// from flecs/addons/meta.h:110:15
auto alias_ecs_string_t = typeFactory<char *>::make(lib);
alias_ecs_string_t->alias = "ecs_string_t";
addAlias(alias_ecs_string_t);

