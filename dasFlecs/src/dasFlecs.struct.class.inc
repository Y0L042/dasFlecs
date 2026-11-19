// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

// from flecs.h:413:9
struct ecs_type_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_type_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_type_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_type_t", ml, "ecs_type_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(array)>("_array","array");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
	}
};

// from flecs.h:535:16
struct ecs_header_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_header_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_header_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_header_t", ml, "ecs_header_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(refcount)>("refcount","refcount");
		addField<DAS_BIND_MANAGED_FIELD(mixins)>("mixins","mixins");
	}
};

// from flecs/datastructures/vec.h:16:16
struct ecs_vec_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_vec_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_vec_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_vec_t", ml, "ecs_vec_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(array)>("_array","array");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(size)>("size","size");
	}
};

// from flecs/datastructures/sparse.h:27:16
struct ecs_sparse_page_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_sparse_page_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_sparse_page_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_sparse_page_t", ml, "ecs_sparse_page_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(sparse)>("sparse","sparse");
		addField<DAS_BIND_MANAGED_FIELD(data)>("data","data");
	}
};

// from flecs/datastructures/sparse.h:34:16
struct ecs_sparse_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_sparse_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_sparse_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_sparse_t", ml, "ecs_sparse_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(dense)>("dense","dense");
		addField<DAS_BIND_MANAGED_FIELD(pages)>("pages","pages");
		addField<DAS_BIND_MANAGED_FIELD(size)>("size","size");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(max_id)>("max_id","max_id");
		addField<DAS_BIND_MANAGED_FIELD(allocator)>("allocator","allocator");
		addField<DAS_BIND_MANAGED_FIELD(page_allocator)>("page_allocator","page_allocator");
	}
};

// from flecs/datastructures/block_allocator.h:15:16
struct ecs_block_allocator_block_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_block_allocator_block_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_block_allocator_block_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_block_allocator_block_t", ml, "ecs_block_allocator_block_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(memory)>("memory","memory");
		addField<DAS_BIND_MANAGED_FIELD(next)>("next","next");
	}
};

// from flecs/datastructures/block_allocator.h:21:16
struct ecs_block_allocator_chunk_header_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_block_allocator_chunk_header_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_block_allocator_chunk_header_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_block_allocator_chunk_header_t", ml, "ecs_block_allocator_chunk_header_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(next)>("next","next");
	}
};

// from flecs/datastructures/block_allocator.h:26:16
struct ecs_block_allocator_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_block_allocator_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_block_allocator_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_block_allocator_t", ml, "ecs_block_allocator_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(data_size)>("data_size","data_size");
		addField<DAS_BIND_MANAGED_FIELD(chunk_size)>("chunk_size","chunk_size");
		addField<DAS_BIND_MANAGED_FIELD(chunks_per_block)>("chunks_per_block","chunks_per_block");
		addField<DAS_BIND_MANAGED_FIELD(block_size)>("block_size","block_size");
		addField<DAS_BIND_MANAGED_FIELD(head)>("head","head");
		addField<DAS_BIND_MANAGED_FIELD(block_head)>("block_head","block_head");
	}
};

// from flecs/datastructures/stack_allocator.h:10:16
struct ecs_stack_page_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_stack_page_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_stack_page_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_stack_page_t", ml, "ecs_stack_page_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(data)>("data","data");
		addField<DAS_BIND_MANAGED_FIELD(next)>("next","next");
		addField<DAS_BIND_MANAGED_FIELD(sp)>("sp","sp");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
	}
};

// from flecs/datastructures/stack_allocator.h:18:16
struct ecs_stack_cursor_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_stack_cursor_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_stack_cursor_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_stack_cursor_t", ml, "ecs_stack_cursor_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(prev)>("prev","prev");
		addField<DAS_BIND_MANAGED_FIELD(page)>("page","page");
		addField<DAS_BIND_MANAGED_FIELD(sp)>("sp","sp");
		addField<DAS_BIND_MANAGED_FIELD(is_free)>("is_free","is_free");
	}
};

// from flecs/datastructures/stack_allocator.h:29:16
struct ecs_stack_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_stack_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_stack_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_stack_t", ml, "ecs_stack_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(first)>("first","first");
		addField<DAS_BIND_MANAGED_FIELD(tail_page)>("tail_page","tail_page");
		addField<DAS_BIND_MANAGED_FIELD(tail_cursor)>("tail_cursor","tail_cursor");
	}
};

// from flecs/datastructures/map.h:25:16
struct ecs_bucket_entry_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_bucket_entry_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_bucket_entry_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_bucket_entry_t", ml, "ecs_bucket_entry_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(key)>("key","key");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<DAS_BIND_MANAGED_FIELD(next)>("next","next");
	}
};

// from flecs/datastructures/map.h:32:16
struct ecs_bucket_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_bucket_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_bucket_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_bucket_t", ml, "ecs_bucket_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(first)>("first","first");
	}
};

// from flecs/datastructures/map.h:37:8
struct ecs_map_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_map_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_map_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_map_t", ml, "ecs_map_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(buckets)>("buckets","buckets");
		addField<DAS_BIND_MANAGED_FIELD(bucket_count)>("bucket_count","bucket_count");
		addField<DAS_BIND_MANAGED_FIELD(allocator)>("allocator","allocator");
	}
};

// from flecs/datastructures/map.h:50:16
struct ecs_map_iter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_map_iter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_map_iter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_map_iter_t", ml, "ecs_map_iter_t") {
	}
	void init () {
		addField<ecs_map_t *,offsetof(ManagedType,map)>("map","map")
			.adjustAot("das_reinterpret<ecs_map_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(bucket)>("bucket","bucket");
		addField<DAS_BIND_MANAGED_FIELD(entry)>("entry","entry");
		addField<DAS_BIND_MANAGED_FIELD(res)>("res","res");
	}
};

// from flecs/datastructures/allocator.h:17:8
struct ecs_allocator_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_allocator_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_allocator_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_allocator_t", ml, "ecs_allocator_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(chunks)>("chunks","chunks");
		addField<DAS_BIND_MANAGED_FIELD(sizes)>("sizes","sizes");
	}
};

// from flecs/datastructures/strbuf.h:30:16
struct ecs_strbuf_list_elem_GeneratedAnnotation : ManagedStructureAnnotation<ecs_strbuf_list_elem> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_strbuf_list_elem_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_strbuf_list_elem", ml, "ecs_strbuf_list_elem") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<char *,offsetof(ManagedType,separator)>("separator","separator")
			.adjustAot("das_reinterpret<char *>::pass(",")");
	}
};

// from flecs/datastructures/strbuf.h:36:16
struct ecs_strbuf_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_strbuf_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_strbuf_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_strbuf_t", ml, "ecs_strbuf_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(content)>("content","content");
		addField<DAS_BIND_MANAGED_FIELD(length)>("length","length");
		addField<DAS_BIND_MANAGED_FIELD(size)>("size","size");
		addField<DAS_BIND_MANAGED_FIELD(list_stack)>("list_stack","list_stack");
		addField<DAS_BIND_MANAGED_FIELD(list_sp)>("list_sp","list_sp");
		addField<DAS_BIND_MANAGED_FIELD(small_string)>("small_string","small_string");
	}
};

// from flecs/os_api.h:39:16
struct ecs_time_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_time_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_time_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_time_t", ml, "ecs_time_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(sec)>("sec","sec");
		addField<DAS_BIND_MANAGED_FIELD(nanosec)>("nanosec","nanosec");
	}
};

// from flecs/os_api.h:312:16
struct ecs_os_api_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_os_api_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_os_api_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_os_api_t", ml, "ecs_os_api_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(log_level_)>("log_level_","log_level_");
		addField<DAS_BIND_MANAGED_FIELD(log_indent_)>("log_indent_","log_indent_");
		addField<DAS_BIND_MANAGED_FIELD(log_last_error_)>("log_last_error_","log_last_error_");
		addField<DAS_BIND_MANAGED_FIELD(log_last_timestamp_)>("log_last_timestamp_","log_last_timestamp_");
		addField<DAS_BIND_MANAGED_FIELD(flags_)>("flags_","flags_");
		addField<DAS_BIND_MANAGED_FIELD(log_out_)>("log_out_","log_out_");
	}
};

// from flecs.h:820:16
struct ecs_term_ref_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_term_ref_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_term_ref_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_term_ref_t", ml, "ecs_term_ref_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
	}
};

// from flecs.h:835:8
struct ecs_term_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_term_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_term_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_term_t", ml, "ecs_term_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(src)>("src","src");
		addField<DAS_BIND_MANAGED_FIELD(first)>("first","first");
		addField<DAS_BIND_MANAGED_FIELD(second)>("second","second");
		addField<DAS_BIND_MANAGED_FIELD(trav)>("trav","trav");
		addField<DAS_BIND_MANAGED_FIELD(inout)>("inout","inout");
		addField<DAS_BIND_MANAGED_FIELD(oper)>("oper","oper");
		addField<DAS_BIND_MANAGED_FIELD(field_index)>("field_index","field_index");
		addField<DAS_BIND_MANAGED_FIELD(flags_)>("flags_","flags_");
	}
};

// from flecs.h:859:8
struct ecs_query_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_t", ml, "ecs_query_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(hdr)>("hdr","hdr");
		addField<DAS_BIND_MANAGED_FIELD(terms)>("terms","terms");
		addField<DAS_BIND_MANAGED_FIELD(sizes)>("sizes","sizes");
		addField<DAS_BIND_MANAGED_FIELD(ids)>("ids","ids");
		addField<DAS_BIND_MANAGED_FIELD(bloom_filter)>("bloom_filter","bloom_filter");
		addField<DAS_BIND_MANAGED_FIELD(flags)>("flags","flags");
		addField<DAS_BIND_MANAGED_FIELD(var_count)>("var_count","var_count");
		addField<DAS_BIND_MANAGED_FIELD(term_count)>("term_count","term_count");
		addField<DAS_BIND_MANAGED_FIELD(field_count)>("field_count","field_count");
		addField<DAS_BIND_MANAGED_FIELD(fixed_fields)>("fixed_fields","fixed_fields");
		addField<DAS_BIND_MANAGED_FIELD(var_fields)>("var_fields","var_fields");
		addField<DAS_BIND_MANAGED_FIELD(static_id_fields)>("static_id_fields","static_id_fields");
		addField<DAS_BIND_MANAGED_FIELD(data_fields)>("data_fields","data_fields");
		addField<DAS_BIND_MANAGED_FIELD(write_fields)>("write_fields","write_fields");
		addField<DAS_BIND_MANAGED_FIELD(read_fields)>("read_fields","read_fields");
		addField<DAS_BIND_MANAGED_FIELD(row_fields)>("row_fields","row_fields");
		addField<DAS_BIND_MANAGED_FIELD(shared_readonly_fields)>("shared_readonly_fields","shared_readonly_fields");
		addField<DAS_BIND_MANAGED_FIELD(set_fields)>("set_fields","set_fields");
		addField<DAS_BIND_MANAGED_FIELD(cache_kind)>("cache_kind","cache_kind");
		addField<DAS_BIND_MANAGED_FIELD(vars)>("vars","vars");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(binding_ctx)>("binding_ctx","binding_ctx");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(stage)>("stage","stage");
		addField<DAS_BIND_MANAGED_FIELD(world)>("world","world");
		addField<DAS_BIND_MANAGED_FIELD(eval_count)>("eval_count","eval_count");
	}
};

// from flecs.h:904:8
struct ecs_observer_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_observer_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_observer_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_observer_t", ml, "ecs_observer_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(hdr)>("hdr","hdr");
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
		addField<DAS_BIND_MANAGED_FIELD(events)>("events","events");
		addField<DAS_BIND_MANAGED_FIELD(event_count)>("event_count","event_count");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(callback_ctx)>("callback_ctx","callback_ctx");
		addField<DAS_BIND_MANAGED_FIELD(run_ctx)>("run_ctx","run_ctx");
		addField<DAS_BIND_MANAGED_FIELD(observable)>("observable","observable");
		addField<DAS_BIND_MANAGED_FIELD(world)>("world","world");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
	}
};

// from flecs.h:979:8
struct ecs_type_hooks_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_type_hooks_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_type_hooks_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_type_hooks_t", ml, "ecs_type_hooks_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(flags)>("flags","flags");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(binding_ctx)>("binding_ctx","binding_ctx");
		addField<DAS_BIND_MANAGED_FIELD(lifecycle_ctx)>("lifecycle_ctx","lifecycle_ctx");
	}
};

// from flecs.h:1053:8
struct ecs_type_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_type_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_type_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_type_info_t", ml, "ecs_type_info_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(size)>("size","size");
		addField<DAS_BIND_MANAGED_FIELD(alignment)>("alignment","alignment");
		addField<DAS_BIND_MANAGED_FIELD(hooks)>("hooks","hooks");
		addField<DAS_BIND_MANAGED_FIELD(component)>("component","component");
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(refcount)>("refcount","refcount");
	}
};

// from flecs/private/api_types.h:37:16
struct ecs_event_record_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_event_record_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_event_record_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_event_record_t", ml, "ecs_event_record_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(any)>("any","any");
		addField<DAS_BIND_MANAGED_FIELD(wildcard)>("wildcard","wildcard");
		addField<DAS_BIND_MANAGED_FIELD(wildcard_pair)>("wildcard_pair","wildcard_pair");
		addField<DAS_BIND_MANAGED_FIELD(event_ids)>("event_ids","event_ids");
		addField<DAS_BIND_MANAGED_FIELD(event_ids_filter)>("event_ids_filter","event_ids_filter");
		addField<DAS_BIND_MANAGED_FIELD(event)>("event","event");
	}
};

// from flecs/private/api_types.h:46:8
struct ecs_observable_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_observable_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_observable_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_observable_t", ml, "ecs_observable_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(on_add)>("on_add","on_add");
		addField<DAS_BIND_MANAGED_FIELD(on_remove)>("on_remove","on_remove");
		addField<DAS_BIND_MANAGED_FIELD(on_set)>("on_set","on_set");
		addField<DAS_BIND_MANAGED_FIELD(on_wildcard)>("on_wildcard","on_wildcard");
		addField<DAS_BIND_MANAGED_FIELD(on_table_create)>("on_table_create","on_table_create");
		addField<DAS_BIND_MANAGED_FIELD(on_table_delete)>("on_table_delete","on_table_delete");
		addField<DAS_BIND_MANAGED_FIELD(events)>("events","events");
		addField<DAS_BIND_MANAGED_FIELD(global_observers)>("global_observers","global_observers");
		addField<DAS_BIND_MANAGED_FIELD(last_observer_id)>("last_observer_id","last_observer_id");
	}
};

// from flecs/private/api_types.h:59:16
struct ecs_table_range_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_range_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_range_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_range_t", ml, "ecs_table_range_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(table)>("_table","table");
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
	}
};

// from flecs/private/api_types.h:68:16
struct ecs_var_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_var_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_var_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_var_t", ml, "ecs_var_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(range)>("_range","range");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
	}
};

// from flecs/private/api_types.h:81:8
struct ecs_ref_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_ref_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_ref_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_ref_t", ml, "ecs_ref_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(table_id)>("table_id","table_id");
		addField<DAS_BIND_MANAGED_FIELD(table_version_fast)>("table_version_fast","table_version_fast");
		addField<DAS_BIND_MANAGED_FIELD(table_version)>("table_version","table_version");
		addField<DAS_BIND_MANAGED_FIELD(ptr)>("ptr","ptr");
	}
};

// from flecs/private/api_types.h:93:16
struct ecs_page_iter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_page_iter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_page_iter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_page_iter_t", ml, "ecs_page_iter_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
		addField<DAS_BIND_MANAGED_FIELD(limit)>("limit","limit");
		addField<DAS_BIND_MANAGED_FIELD(remaining)>("remaining","remaining");
	}
};

// from flecs/private/api_types.h:100:16
struct ecs_worker_iter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_worker_iter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_worker_iter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_worker_iter_t", ml, "ecs_worker_iter_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(index)>("index","index");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
	}
};

// from flecs/private/api_types.h:106:16
struct ecs_table_cache_elem_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_cache_elem_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_cache_elem_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_cache_elem_t", ml, "ecs_table_cache_elem_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(table)>("_table","table");
		addField<DAS_BIND_MANAGED_FIELD(tr)>("tr","tr");
		addField<DAS_BIND_MANAGED_FIELD(column)>("column","column");
		addField<DAS_BIND_MANAGED_FIELD(index)>("index","index");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
	}
};

// from flecs/private/api_types.h:115:16
struct ecs_table_cache_iter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_cache_iter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_cache_iter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_cache_iter_t", ml, "ecs_table_cache_iter_t") {
	}
	void init () {
		addField<ecs_table_cache_elem_t *,offsetof(ManagedType,elems)>("elems","elems")
			.adjustAot("das_reinterpret<ecs_table_cache_elem_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(remaining)>("remaining","remaining");
		addField<ecs_table_cache_elem_t *,offsetof(ManagedType,cur)>("cur","cur")
			.adjustAot("das_reinterpret<ecs_table_cache_elem_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(flags)>("flags","flags");
	}
};

// from flecs/private/api_types.h:123:16
struct ecs_each_iter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_each_iter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_each_iter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_each_iter_t", ml, "ecs_each_iter_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(it)>("it","it");
		addField<DAS_BIND_MANAGED_FIELD(ids)>("ids","ids");
		addField<DAS_BIND_MANAGED_FIELD(sources)>("sources","sources");
		addField<DAS_BIND_MANAGED_FIELD(sizes)>("sizes","sizes");
		addField<DAS_BIND_MANAGED_FIELD(columns)>("columns","columns");
		addField<ecs_table_record_t *,offsetof(ManagedType,trs)>("trs","trs")
			.adjustAot("das_reinterpret<ecs_table_record_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(cr)>("cr","cr");
	}
};

// from flecs/private/api_types.h:135:16
struct ecs_query_op_profile_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_op_profile_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_op_profile_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_op_profile_t", ml, "ecs_query_op_profile_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
	}
};

// from flecs/private/api_types.h:140:16
struct ecs_query_trivial_ctx_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_trivial_ctx_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_trivial_ctx_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_trivial_ctx_t", ml, "ecs_query_trivial_ctx_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(it)>("it","it");
		addField<ecs_table_record_t *,offsetof(ManagedType,tr)>("tr","tr")
			.adjustAot("das_reinterpret<ecs_table_record_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(start_from)>("start_from","start_from");
		addField<DAS_BIND_MANAGED_FIELD(first_to_eval)>("first_to_eval","first_to_eval");
	}
};

// from flecs/private/api_types.h:148:16
struct ecs_query_iter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_iter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_iter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_iter_t", ml, "ecs_query_iter_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(vars)>("vars","vars");
		addField<struct ecs_query_var_t *,offsetof(ManagedType,query_vars)>("query_vars","query_vars")
			.adjustAot("das_reinterpret<struct ecs_query_var_t *>::pass(",")");
		addField<struct ecs_query_op_t *,offsetof(ManagedType,ops)>("ops","ops")
			.adjustAot("das_reinterpret<struct ecs_query_op_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(op_ctx)>("op_ctx","op_ctx");
		addField<DAS_BIND_MANAGED_FIELD(written)>("written","written");
		addField<DAS_BIND_MANAGED_FIELD(profile)>("profile","profile");
		addField<DAS_BIND_MANAGED_FIELD(op)>("op","op");
		addField<DAS_BIND_MANAGED_FIELD(group)>("group","group");
		addField<DAS_BIND_MANAGED_FIELD(tables)>("tables","tables");
		addField<DAS_BIND_MANAGED_FIELD(all_tables)>("all_tables","all_tables");
		addField<DAS_BIND_MANAGED_FIELD(elem)>("elem","elem");
		addField<DAS_BIND_MANAGED_FIELD(cur)>("cur","cur");
		addField<DAS_BIND_MANAGED_FIELD(all_cur)>("all_cur","all_cur");
		addField<DAS_BIND_MANAGED_FIELD(iter_single_group)>("iter_single_group","iter_single_group");
		addField<DAS_BIND_MANAGED_FIELD(trivial)>("trivial","trivial");
	}
};

// from flecs/private/api_types.h:176:16
struct ecs_iter_private_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_iter_private_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_iter_private_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_iter_private_t", ml, "ecs_iter_private_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity_iter)>("entity_iter","entity_iter");
		addField<DAS_BIND_MANAGED_FIELD(stack_cursor)>("stack_cursor","stack_cursor");
	}
};

// from flecs/private/api_types.h:188:16
struct ecs_cmd_entry_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_cmd_entry_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_cmd_entry_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_cmd_entry_t", ml, "ecs_cmd_entry_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(first)>("first","first");
		addField<DAS_BIND_MANAGED_FIELD(last)>("last","last");
		addField<DAS_BIND_MANAGED_FIELD(removed)>("removed","removed");
	}
};

// from flecs/private/api_types.h:195:16
struct ecs_commands_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_commands_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_commands_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_commands_t", ml, "ecs_commands_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(prev)>("prev","prev");
		addField<DAS_BIND_MANAGED_FIELD(next)>("next","next");
		addField<DAS_BIND_MANAGED_FIELD(queue)>("queue","queue");
		addField<DAS_BIND_MANAGED_FIELD(stack)>("stack","stack");
		addField<DAS_BIND_MANAGED_FIELD(entries)>("entries","entries");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(entry)>("entry","entry");
		addField<DAS_BIND_MANAGED_FIELD(cursor)>("cursor","cursor");
		addField<DAS_BIND_MANAGED_FIELD(has_remove)>("has_remove","has_remove");
		addField<DAS_BIND_MANAGED_FIELD(second_entity)>("second_entity","second_entity");
		addField<DAS_BIND_MANAGED_FIELD(second_entry)>("second_entry","second_entry");
		addField<DAS_BIND_MANAGED_FIELD(last_entity)>("last_entity","last_entity");
		addField<DAS_BIND_MANAGED_FIELD(last_entry)>("last_entry","last_entry");
	}
};

// from flecs/private/api_support.h:246:16
struct ecs_suspend_readonly_state_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_suspend_readonly_state_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_suspend_readonly_state_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_suspend_readonly_state_t", ml, "ecs_suspend_readonly_state_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(is_readonly)>("is_readonly","is_readonly");
		addField<DAS_BIND_MANAGED_FIELD(scope)>("scope","scope");
	}
};

// from flecs/datastructures/hashmap.h:15:16
struct ecs_hm_bucket_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_hm_bucket_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_hm_bucket_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_hm_bucket_t", ml, "ecs_hm_bucket_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(next)>("next","next");
	}
};

// from flecs/datastructures/hashmap.h:24:9
struct ecs_hashmap_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_hashmap_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_hashmap_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_hashmap_t", ml, "ecs_hashmap_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(key_size)>("key_size","key_size");
		addField<DAS_BIND_MANAGED_FIELD(value_size)>("value_size","value_size");
		addField<DAS_BIND_MANAGED_FIELD(value_offset)>("value_offset","value_offset");
		addField<DAS_BIND_MANAGED_FIELD(bucket_size)>("bucket_size","bucket_size");
		addField<DAS_BIND_MANAGED_FIELD(impl)>("impl","impl");
	}
};

// from flecs/datastructures/hashmap.h:35:9
struct flecs_hashmap_iter_t_GeneratedAnnotation : ManagedStructureAnnotation<flecs_hashmap_iter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	flecs_hashmap_iter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("flecs_hashmap_iter_t", ml, "flecs_hashmap_iter_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(it)>("it","it");
		addField<DAS_BIND_MANAGED_FIELD(bucket)>("bucket","bucket");
		addField<ecs_hashmap_t *,offsetof(ManagedType,map)>("map","map")
			.adjustAot("das_reinterpret<ecs_hashmap_t *>::pass(",")");
	}
};

// from flecs/datastructures/hashmap.h:42:9
struct flecs_hashmap_result_t_GeneratedAnnotation : ManagedStructureAnnotation<flecs_hashmap_result_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	flecs_hashmap_result_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("flecs_hashmap_result_t", ml, "flecs_hashmap_result_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(key)>("key","key");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<DAS_BIND_MANAGED_FIELD(hash)>("hash","hash");
	}
};

// from flecs/private/api_internals.h:18:8
struct ecs_record_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_record_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_record_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_record_t", ml, "ecs_record_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(table)>("_table","table");
		addField<DAS_BIND_MANAGED_FIELD(row)>("row","row");
		addField<DAS_BIND_MANAGED_FIELD(dense)>("dense","dense");
	}
};

// from flecs/private/api_internals.h:25:16
struct ecs_table_cache_hdr_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_cache_hdr_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_cache_hdr_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_cache_hdr_t", ml, "ecs_table_cache_hdr_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(cr)>("cr","cr");
		addField<DAS_BIND_MANAGED_FIELD(table)>("_table","table");
	}
};

// from flecs/private/api_internals.h:33:8
struct ecs_table_record_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_record_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_record_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_record_t", ml, "ecs_table_record_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(hdr)>("hdr","hdr");
		addField<DAS_BIND_MANAGED_FIELD(index)>("index","index");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(column)>("column","column");
	}
};

// from flecs/private/api_internals.h:42:16
struct ecs_table_diff_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_diff_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_diff_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_diff_t", ml, "ecs_table_diff_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(added)>("added","added");
		addField<DAS_BIND_MANAGED_FIELD(removed)>("removed","removed");
		addField<DAS_BIND_MANAGED_FIELD(added_flags)>("added_flags","added_flags");
		addField<DAS_BIND_MANAGED_FIELD(removed_flags)>("removed_flags","removed_flags");
	}
};

// from flecs/private/api_internals.h:277:16
struct ecs_table_records_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_records_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_records_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_records_t", ml, "ecs_table_records_t") {
	}
	void init () {
		addField<ecs_table_record_t *,offsetof(ManagedType,array)>("_array","array")
			.adjustAot("das_reinterpret<ecs_table_record_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
	}
};

// from flecs.h:1069:16
struct ecs_value_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_value_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_value_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_value_t", ml, "ecs_value_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(ptr)>("ptr","ptr");
	}
};

// from flecs.h:1078:16
struct ecs_entity_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_entity_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_entity_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_entity_desc_t", ml, "ecs_entity_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(_canary)>("_canary","_canary");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(parent)>("parent","parent");
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,sep)>("sep","sep")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,root_sep)>("root_sep","root_sep")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,symbol)>("symbol","symbol")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(use_low_id)>("use_low_id","use_low_id");
	}
};

// from flecs.h:1115:16
struct ecs_bulk_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_bulk_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_bulk_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_bulk_desc_t", ml, "ecs_bulk_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(_canary)>("_canary","_canary");
		addField<DAS_BIND_MANAGED_FIELD(entities)>("entities","entities");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(ids)>("ids","ids");
		addField<DAS_BIND_MANAGED_FIELD(data)>("data","data");
		addField<DAS_BIND_MANAGED_FIELD(table)>("_table","table");
	}
};

// from flecs.h:1145:16
struct ecs_component_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_component_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_component_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_component_desc_t", ml, "ecs_component_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(_canary)>("_canary","_canary");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
	}
};

// from flecs.h:1184:8
struct ecs_iter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_iter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_iter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_iter_t", ml, "ecs_iter_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(stage)>("stage","stage");
		addField<DAS_BIND_MANAGED_FIELD(world)>("world","world");
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<ecs_entity_t *,offsetof(ManagedType,entities)>("entities","entities")
			.adjustAot("das_reinterpret<ecs_entity_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(ptrs)>("ptrs","ptrs");
		addField<DAS_BIND_MANAGED_FIELD(trs)>("trs","trs");
		addField<int16_t *,offsetof(ManagedType,columns)>("columns","columns")
			.adjustAot("das_reinterpret<int16_t *>::pass(",")");
		addField<ecs_size_t *,offsetof(ManagedType,sizes)>("sizes","sizes")
			.adjustAot("das_reinterpret<ecs_size_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(table)>("_table","table");
		addField<DAS_BIND_MANAGED_FIELD(other_table)>("other_table","other_table");
		addField<DAS_BIND_MANAGED_FIELD(ids)>("ids","ids");
		addField<DAS_BIND_MANAGED_FIELD(sources)>("sources","sources");
		addField<DAS_BIND_MANAGED_FIELD(constrained_vars)>("constrained_vars","constrained_vars");
		addField<DAS_BIND_MANAGED_FIELD(set_fields)>("set_fields","set_fields");
		addField<DAS_BIND_MANAGED_FIELD(ref_fields)>("ref_fields","ref_fields");
		addField<DAS_BIND_MANAGED_FIELD(row_fields)>("row_fields","row_fields");
		addField<DAS_BIND_MANAGED_FIELD(up_fields)>("up_fields","up_fields");
		addField<DAS_BIND_MANAGED_FIELD(system)>("system","system");
		addField<DAS_BIND_MANAGED_FIELD(event)>("event","event");
		addField<DAS_BIND_MANAGED_FIELD(event_id)>("event_id","event_id");
		addField<DAS_BIND_MANAGED_FIELD(event_cur)>("event_cur","event_cur");
		addField<DAS_BIND_MANAGED_FIELD(field_count)>("field_count","field_count");
		addField<DAS_BIND_MANAGED_FIELD(term_index)>("term_index","term_index");
		addField<ecs_query_t *,offsetof(ManagedType,query)>("query","query")
			.adjustAot("das_reinterpret<ecs_query_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(param)>("param","param");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(binding_ctx)>("binding_ctx","binding_ctx");
		addField<DAS_BIND_MANAGED_FIELD(callback_ctx)>("callback_ctx","callback_ctx");
		addField<DAS_BIND_MANAGED_FIELD(run_ctx)>("run_ctx","run_ctx");
		addField<DAS_BIND_MANAGED_FIELD(delta_time)>("delta_time","delta_time");
		addField<DAS_BIND_MANAGED_FIELD(delta_system_time)>("delta_system_time","delta_system_time");
		addField<DAS_BIND_MANAGED_FIELD(frame_offset)>("frame_offset","frame_offset");
		addField<DAS_BIND_MANAGED_FIELD(flags)>("flags","flags");
		addField<DAS_BIND_MANAGED_FIELD(interrupted_by)>("interrupted_by","interrupted_by");
		addField<DAS_BIND_MANAGED_FIELD(priv_)>("priv_","priv_");
		addField<DAS_BIND_MANAGED_FIELD(chain_it)>("chain_it","chain_it");
	}
};

// from flecs.h:1316:16
struct ecs_query_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_desc_t", ml, "ecs_query_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(_canary)>("_canary","_canary");
		addField<DAS_BIND_MANAGED_FIELD(terms)>("terms","terms");
		addField<char *,offsetof(ManagedType,expr)>("expr","expr")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(cache_kind)>("cache_kind","cache_kind");
		addField<DAS_BIND_MANAGED_FIELD(flags)>("flags","flags");
		addField<DAS_BIND_MANAGED_FIELD(order_by)>("order_by","order_by");
		addField<DAS_BIND_MANAGED_FIELD(group_by)>("group_by","group_by");
		addField<DAS_BIND_MANAGED_FIELD(group_by_ctx)>("group_by_ctx","group_by_ctx");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(binding_ctx)>("binding_ctx","binding_ctx");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
	}
};

// from flecs.h:1390:16
struct ecs_observer_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_observer_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_observer_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_observer_desc_t", ml, "ecs_observer_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(_canary)>("_canary","_canary");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
		addField<DAS_BIND_MANAGED_FIELD(events)>("events","events");
		addField<DAS_BIND_MANAGED_FIELD(yield_existing)>("yield_existing","yield_existing");
		addField<DAS_BIND_MANAGED_FIELD(global_observer)>("global_observer","global_observer");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(callback_ctx)>("callback_ctx","callback_ctx");
		addField<DAS_BIND_MANAGED_FIELD(run_ctx)>("run_ctx","run_ctx");
		addField<DAS_BIND_MANAGED_FIELD(last_event_id)>("last_event_id","last_event_id");
		addField<DAS_BIND_MANAGED_FIELD(term_index_)>("term_index_","term_index_");
		addField<DAS_BIND_MANAGED_FIELD(flags_)>("flags_","flags_");
	}
};

// from flecs.h:1451:16
struct ecs_event_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_event_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_event_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_event_desc_t", ml, "ecs_event_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(event)>("event","event");
		addField<ecs_type_t *,offsetof(ManagedType,ids)>("ids","ids")
			.adjustAot("das_reinterpret<ecs_type_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(table)>("_table","table");
		addField<DAS_BIND_MANAGED_FIELD(other_table)>("other_table","other_table");
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(param)>("param","param");
		addField<void *,offsetof(ManagedType,const_param)>("const_param","const_param")
			.adjustAot("das_reinterpret<void *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(set_ptr)>("set_ptr","set_ptr");
		addField<DAS_BIND_MANAGED_FIELD(observable)>("observable","observable");
		addField<DAS_BIND_MANAGED_FIELD(flags)>("flags","flags");
	}
};

// from flecs.h:1511:16
struct ecs_build_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_build_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_build_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_build_info_t", ml, "ecs_build_info_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,compiler)>("compiler","compiler")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(addons)>("addons","addons");
		addField<DAS_BIND_MANAGED_FIELD(flags)>("flags","flags");
		addField<char *,offsetof(ManagedType,version)>("version","version")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(version_major)>("version_major","version_major");
		addField<DAS_BIND_MANAGED_FIELD(version_minor)>("version_minor","version_minor");
		addField<DAS_BIND_MANAGED_FIELD(version_patch)>("version_patch","version_patch");
		addField<DAS_BIND_MANAGED_FIELD(debug)>("debug","debug");
		addField<DAS_BIND_MANAGED_FIELD(sanitize)>("sanitize","sanitize");
		addField<DAS_BIND_MANAGED_FIELD(perf_trace)>("perf_trace","perf_trace");
	}
};

// from flecs.h:1525:16
struct ecs_world_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_world_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_world_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_world_info_t", ml, "ecs_world_info_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(last_component_id)>("last_component_id","last_component_id");
		addField<DAS_BIND_MANAGED_FIELD(delta_time_raw)>("delta_time_raw","delta_time_raw");
		addField<DAS_BIND_MANAGED_FIELD(delta_time)>("delta_time","delta_time");
		addField<DAS_BIND_MANAGED_FIELD(time_scale)>("time_scale","time_scale");
		addField<DAS_BIND_MANAGED_FIELD(target_fps)>("target_fps","target_fps");
		addField<DAS_BIND_MANAGED_FIELD(frame_time_total)>("frame_time_total","frame_time_total");
		addField<DAS_BIND_MANAGED_FIELD(system_time_total)>("system_time_total","system_time_total");
		addField<DAS_BIND_MANAGED_FIELD(emit_time_total)>("emit_time_total","emit_time_total");
		addField<DAS_BIND_MANAGED_FIELD(merge_time_total)>("merge_time_total","merge_time_total");
		addField<DAS_BIND_MANAGED_FIELD(rematch_time_total)>("rematch_time_total","rematch_time_total");
		addField<DAS_BIND_MANAGED_FIELD(world_time_total)>("world_time_total","world_time_total");
		addField<DAS_BIND_MANAGED_FIELD(world_time_total_raw)>("world_time_total_raw","world_time_total_raw");
		addField<DAS_BIND_MANAGED_FIELD(frame_count_total)>("frame_count_total","frame_count_total");
		addField<DAS_BIND_MANAGED_FIELD(merge_count_total)>("merge_count_total","merge_count_total");
		addField<DAS_BIND_MANAGED_FIELD(eval_comp_monitors_total)>("eval_comp_monitors_total","eval_comp_monitors_total");
		addField<DAS_BIND_MANAGED_FIELD(rematch_count_total)>("rematch_count_total","rematch_count_total");
		addField<DAS_BIND_MANAGED_FIELD(id_create_total)>("id_create_total","id_create_total");
		addField<DAS_BIND_MANAGED_FIELD(id_delete_total)>("id_delete_total","id_delete_total");
		addField<DAS_BIND_MANAGED_FIELD(table_create_total)>("table_create_total","table_create_total");
		addField<DAS_BIND_MANAGED_FIELD(table_delete_total)>("table_delete_total","table_delete_total");
		addField<DAS_BIND_MANAGED_FIELD(pipeline_build_count_total)>("pipeline_build_count_total","pipeline_build_count_total");
		addField<DAS_BIND_MANAGED_FIELD(systems_ran_total)>("systems_ran_total","systems_ran_total");
		addField<DAS_BIND_MANAGED_FIELD(observers_ran_total)>("observers_ran_total","observers_ran_total");
		addField<DAS_BIND_MANAGED_FIELD(queries_ran_total)>("queries_ran_total","queries_ran_total");
		addField<DAS_BIND_MANAGED_FIELD(tag_id_count)>("tag_id_count","tag_id_count");
		addField<DAS_BIND_MANAGED_FIELD(component_id_count)>("component_id_count","component_id_count");
		addField<DAS_BIND_MANAGED_FIELD(pair_id_count)>("pair_id_count","pair_id_count");
		addField<DAS_BIND_MANAGED_FIELD(table_count)>("table_count","table_count");
		addField<DAS_BIND_MANAGED_FIELD(creation_time)>("creation_time","creation_time");
		addField<char *,offsetof(ManagedType,name_prefix)>("name_prefix","name_prefix")
			.adjustAot("das_reinterpret<char *>::pass(",")");
	}
};

// from flecs.h:1585:16
struct ecs_query_group_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_group_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_group_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_group_info_t", ml, "ecs_query_group_info_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(match_count)>("match_count","match_count");
		addField<DAS_BIND_MANAGED_FIELD(table_count)>("table_count","table_count");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
	}
};

// from flecs.h:1602:16
struct EcsIdentifier_GeneratedAnnotation : ManagedStructureAnnotation<EcsIdentifier> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsIdentifier_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsIdentifier", ml, "EcsIdentifier") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<DAS_BIND_MANAGED_FIELD(length)>("length","length");
		addField<DAS_BIND_MANAGED_FIELD(hash)>("hash","hash");
		addField<DAS_BIND_MANAGED_FIELD(index_hash)>("index_hash","index_hash");
		addField<DAS_BIND_MANAGED_FIELD(index)>("index","index");
	}
};

// from flecs.h:1611:16
struct EcsComponent_GeneratedAnnotation : ManagedStructureAnnotation<EcsComponent> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsComponent_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsComponent", ml, "EcsComponent") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(size)>("size","size");
		addField<DAS_BIND_MANAGED_FIELD(alignment)>("alignment","alignment");
	}
};

// from flecs.h:1617:16
struct EcsPoly_GeneratedAnnotation : ManagedStructureAnnotation<EcsPoly> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsPoly_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsPoly", ml, "EcsPoly") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(poly)>("poly","poly");
	}
};

// from flecs.h:1622:16
struct EcsParent_GeneratedAnnotation : ManagedStructureAnnotation<EcsParent> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsParent_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsParent", ml, "EcsParent") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
	}
};

// from flecs.h:1627:9
struct ecs_tree_spawner_child_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_tree_spawner_child_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_tree_spawner_child_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_tree_spawner_child_t", ml, "ecs_tree_spawner_child_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,child_name)>("child_name","child_name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(table)>("_table","table");
		addField<DAS_BIND_MANAGED_FIELD(child)>("child","child");
		addField<DAS_BIND_MANAGED_FIELD(parent_index)>("parent_index","parent_index");
	}
};

// from flecs.h:1635:9
struct ecs_tree_spawner_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_tree_spawner_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_tree_spawner_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_tree_spawner_t", ml, "ecs_tree_spawner_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(children)>("children","children");
	}
};

// from flecs.h:1646:16
struct EcsTreeSpawner_GeneratedAnnotation : ManagedStructureAnnotation<EcsTreeSpawner> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsTreeSpawner_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsTreeSpawner", ml, "EcsTreeSpawner") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(data)>("data","data");
	}
};

// from flecs.h:2052:16
struct ecs_entities_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_entities_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_entities_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_entities_t", ml, "ecs_entities_t") {
	}
	void init () {
		addField<ecs_entity_t *,offsetof(ManagedType,ids)>("ids","ids")
			.adjustAot("das_reinterpret<ecs_entity_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(alive_count)>("alive_count","alive_count");
	}
};

// from flecs.h:2418:16
struct ecs_delete_empty_tables_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_delete_empty_tables_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_delete_empty_tables_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_delete_empty_tables_desc_t", ml, "ecs_delete_empty_tables_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(clear_generation)>("clear_generation","clear_generation");
		addField<DAS_BIND_MANAGED_FIELD(delete_generation)>("delete_generation","delete_generation");
		addField<DAS_BIND_MANAGED_FIELD(time_budget_seconds)>("time_budget_seconds","time_budget_seconds");
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
	}
};

// from flecs.h:4721:16
struct ecs_query_cache_revalidate_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_cache_revalidate_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_cache_revalidate_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_cache_revalidate_t", ml, "ecs_query_cache_revalidate_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
		addField<DAS_BIND_MANAGED_FIELD(table_id)>("table_id","table_id");
	}
};

// from flecs.h:4937:16
struct ecs_query_count_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_count_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_count_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_count_t", ml, "ecs_query_count_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(results)>("results","results");
		addField<DAS_BIND_MANAGED_FIELD(entities)>("entities","entities");
		addField<DAS_BIND_MANAGED_FIELD(tables)>("tables","tables");
	}
};

// from flecs/addons/entity_ranges.h:26:16
struct ecs_entity_range_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_entity_range_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_entity_range_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_entity_range_t", ml, "ecs_entity_range_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(min)>("min","min");
		addField<DAS_BIND_MANAGED_FIELD(max)>("max","max");
		addField<DAS_BIND_MANAGED_FIELD(cur)>("cur","cur");
		addField<DAS_BIND_MANAGED_FIELD(recycled)>("recycled","recycled");
	}
};

// from flecs/addons/app.h:37:16
struct ecs_app_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_app_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_app_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_app_desc_t", ml, "ecs_app_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(target_fps)>("target_fps","target_fps");
		addField<DAS_BIND_MANAGED_FIELD(delta_time)>("delta_time","delta_time");
		addField<DAS_BIND_MANAGED_FIELD(threads)>("threads","threads");
		addField<DAS_BIND_MANAGED_FIELD(frames)>("frames","frames");
		addField<DAS_BIND_MANAGED_FIELD(enable_rest)>("enable_rest","enable_rest");
		addField<DAS_BIND_MANAGED_FIELD(enable_stats)>("enable_stats","enable_stats");
		addField<DAS_BIND_MANAGED_FIELD(port)>("port","port");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
	}
};

// from flecs/addons/http.h:51:9
struct ecs_http_connection_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_http_connection_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_http_connection_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_http_connection_t", ml, "ecs_http_connection_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(server)>("server","server");
		addField<DAS_BIND_MANAGED_FIELD(host)>("host","host");
		addField<DAS_BIND_MANAGED_FIELD(port)>("port","port");
	}
};

// from flecs/addons/http.h:60:9
struct ecs_http_key_value_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_http_key_value_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_http_key_value_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_http_key_value_t", ml, "ecs_http_key_value_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,key)>("key","key")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,value)>("value","value")
			.adjustAot("das_reinterpret<char *>::pass(",")");
	}
};

// from flecs/addons/http.h:76:9
struct ecs_http_request_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_http_request_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_http_request_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_http_request_t", ml, "ecs_http_request_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(method)>("method","method");
		addField<DAS_BIND_MANAGED_FIELD(path)>("path","path");
		addField<DAS_BIND_MANAGED_FIELD(body)>("body","body");
		addField<DAS_BIND_MANAGED_FIELD(headers)>("headers","headers");
		addField<DAS_BIND_MANAGED_FIELD(params)>("params","params");
		addField<DAS_BIND_MANAGED_FIELD(header_count)>("header_count","header_count");
		addField<DAS_BIND_MANAGED_FIELD(param_count)>("param_count","param_count");
		addField<DAS_BIND_MANAGED_FIELD(conn)>("conn","conn");
	}
};

// from flecs/addons/http.h:91:9
struct ecs_http_reply_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_http_reply_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_http_reply_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_http_reply_t", ml, "ecs_http_reply_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(code)>("code","code");
		addField<DAS_BIND_MANAGED_FIELD(body)>("body","body");
		addField<char *,offsetof(ManagedType,status)>("status","status")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,content_type)>("content_type","content_type")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(headers)>("headers","headers");
	}
};

// from flecs/addons/http.h:124:9
struct ecs_http_server_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_http_server_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_http_server_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_http_server_desc_t", ml, "ecs_http_server_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(port)>("port","port");
		addField<char *,offsetof(ManagedType,ipaddr)>("ipaddr","ipaddr")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(send_queue_wait_ms)>("send_queue_wait_ms","send_queue_wait_ms");
		addField<DAS_BIND_MANAGED_FIELD(cache_timeout)>("cache_timeout","cache_timeout");
		addField<DAS_BIND_MANAGED_FIELD(cache_purge_timeout)>("cache_purge_timeout","cache_purge_timeout");
	}
};

// from flecs/addons/rest.h:50:9
struct ecs_rest_ctx_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_rest_ctx_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_rest_ctx_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_rest_ctx_t", ml, "ecs_rest_ctx_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(world)>("world","world");
		addField<DAS_BIND_MANAGED_FIELD(srv)>("srv","srv");
		addField<DAS_BIND_MANAGED_FIELD(rc)>("rc","rc");
		addField<DAS_BIND_MANAGED_FIELD(cmd_captures)>("cmd_captures","cmd_captures");
		addField<DAS_BIND_MANAGED_FIELD(last_time)>("last_time","last_time");
		addField<DAS_BIND_MANAGED_FIELD(readonly)>("readonly","readonly");
	}
};

// from flecs/addons/rest.h:60:9
struct EcsRest_GeneratedAnnotation : ManagedStructureAnnotation<EcsRest> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsRest_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsRest", ml, "EcsRest") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(port)>("port","port");
		addField<DAS_BIND_MANAGED_FIELD(ipaddr)>("ipaddr","ipaddr");
		addField<DAS_BIND_MANAGED_FIELD(impl)>("impl","impl");
		addField<DAS_BIND_MANAGED_FIELD(readonly)>("readonly","readonly");
	}
};

// from flecs/addons/timer.h:35:16
struct EcsTimer_GeneratedAnnotation : ManagedStructureAnnotation<EcsTimer> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsTimer_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsTimer", ml, "EcsTimer") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(timeout)>("timeout","timeout");
		addField<DAS_BIND_MANAGED_FIELD(time)>("time","time");
		addField<DAS_BIND_MANAGED_FIELD(overshoot)>("overshoot","overshoot");
		addField<DAS_BIND_MANAGED_FIELD(fired_count)>("fired_count","fired_count");
		addField<DAS_BIND_MANAGED_FIELD(active)>("active","active");
		addField<DAS_BIND_MANAGED_FIELD(single_shot)>("single_shot","single_shot");
	}
};

// from flecs/addons/timer.h:45:16
struct EcsRateFilter_GeneratedAnnotation : ManagedStructureAnnotation<EcsRateFilter> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsRateFilter_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsRateFilter", ml, "EcsRateFilter") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(src)>("src","src");
		addField<DAS_BIND_MANAGED_FIELD(rate)>("rate","rate");
		addField<DAS_BIND_MANAGED_FIELD(tick_count)>("tick_count","tick_count");
		addField<DAS_BIND_MANAGED_FIELD(time_elapsed)>("time_elapsed","time_elapsed");
	}
};

// from flecs/addons/pipeline.h:89:16
struct ecs_pipeline_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_pipeline_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_pipeline_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_pipeline_desc_t", ml, "ecs_pipeline_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
	}
};

// from flecs/addons/system.h:32:16
struct EcsTickSource_GeneratedAnnotation : ManagedStructureAnnotation<EcsTickSource> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsTickSource_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsTickSource", ml, "EcsTickSource") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(tick)>("tick","tick");
		addField<DAS_BIND_MANAGED_FIELD(time_elapsed)>("time_elapsed","time_elapsed");
	}
};

// from flecs/addons/system.h:38:16
struct ecs_system_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_system_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_system_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_system_desc_t", ml, "ecs_system_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(_canary)>("_canary","_canary");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
		addField<DAS_BIND_MANAGED_FIELD(phase)>("phase","phase");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(callback_ctx)>("callback_ctx","callback_ctx");
		addField<DAS_BIND_MANAGED_FIELD(run_ctx)>("run_ctx","run_ctx");
		addField<DAS_BIND_MANAGED_FIELD(interval)>("interval","interval");
		addField<DAS_BIND_MANAGED_FIELD(rate)>("rate","rate");
		addField<DAS_BIND_MANAGED_FIELD(tick_source)>("tick_source","tick_source");
		addField<DAS_BIND_MANAGED_FIELD(multi_threaded)>("multi_threaded","multi_threaded");
		addField<DAS_BIND_MANAGED_FIELD(immediate)>("immediate","immediate");
	}
};

// from flecs/addons/system.h:139:16
struct ecs_system_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_system_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_system_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_system_t", ml, "ecs_system_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(hdr)>("hdr","hdr");
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
		addField<DAS_BIND_MANAGED_FIELD(group_id)>("group_id","group_id");
		addField<DAS_BIND_MANAGED_FIELD(group_id_set)>("group_id_set","group_id_set");
		addField<DAS_BIND_MANAGED_FIELD(tick_source)>("tick_source","tick_source");
		addField<DAS_BIND_MANAGED_FIELD(multi_threaded)>("multi_threaded","multi_threaded");
		addField<DAS_BIND_MANAGED_FIELD(immediate)>("immediate","immediate");
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(callback_ctx)>("callback_ctx","callback_ctx");
		addField<DAS_BIND_MANAGED_FIELD(run_ctx)>("run_ctx","run_ctx");
		addField<DAS_BIND_MANAGED_FIELD(time_spent)>("time_spent","time_spent");
		addField<DAS_BIND_MANAGED_FIELD(time_passed)>("time_passed","time_passed");
		addField<DAS_BIND_MANAGED_FIELD(last_frame)>("last_frame","last_frame");
	}
};

// from flecs/addons/stats.h:44:16
struct ecs_gauge_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_gauge_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_gauge_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_gauge_t", ml, "ecs_gauge_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(avg)>("avg","avg");
		addField<DAS_BIND_MANAGED_FIELD(min)>("min","min");
		addField<DAS_BIND_MANAGED_FIELD(max)>("max","max");
	}
};

// from flecs/addons/stats.h:51:16
struct ecs_counter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_counter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_counter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_counter_t", ml, "ecs_counter_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(rate)>("rate","rate");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
	}
};

// from flecs/addons/stats.h:57:15
struct ecs_metric_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_metric_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_metric_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_metric_t", ml, "ecs_metric_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(gauge)>("gauge","gauge");
		addField<DAS_BIND_MANAGED_FIELD(counter)>("counter","counter");
	}
};

// from flecs/addons/stats.h:63:16
struct ecs_world_stats_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_world_stats_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_world_stats_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_world_stats_t", ml, "ecs_world_stats_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(first_)>("first_","first_");
		addField<DAS_BIND_MANAGED_FIELD(last_)>("last_","last_");
		addField<DAS_BIND_MANAGED_FIELD(t)>("t","t");
	}
};

// from flecs/addons/stats.h:172:16
struct ecs_query_stats_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_stats_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_stats_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_stats_t", ml, "ecs_query_stats_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(first_)>("first_","first_");
		addField<DAS_BIND_MANAGED_FIELD(result_count)>("result_count","result_count");
		addField<DAS_BIND_MANAGED_FIELD(matched_table_count)>("matched_table_count","matched_table_count");
		addField<DAS_BIND_MANAGED_FIELD(matched_entity_count)>("matched_entity_count","matched_entity_count");
		addField<DAS_BIND_MANAGED_FIELD(last_)>("last_","last_");
		addField<DAS_BIND_MANAGED_FIELD(t)>("t","t");
	}
};

// from flecs/addons/stats.h:184:16
struct ecs_system_stats_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_system_stats_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_system_stats_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_system_stats_t", ml, "ecs_system_stats_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(first_)>("first_","first_");
		addField<DAS_BIND_MANAGED_FIELD(time_spent)>("time_spent","time_spent");
		addField<DAS_BIND_MANAGED_FIELD(last_)>("last_","last_");
		addField<DAS_BIND_MANAGED_FIELD(task)>("task","task");
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
	}
};

// from flecs/addons/stats.h:195:16
struct ecs_sync_stats_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_sync_stats_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_sync_stats_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_sync_stats_t", ml, "ecs_sync_stats_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(first_)>("first_","first_");
		addField<DAS_BIND_MANAGED_FIELD(time_spent)>("time_spent","time_spent");
		addField<DAS_BIND_MANAGED_FIELD(commands_enqueued)>("commands_enqueued","commands_enqueued");
		addField<DAS_BIND_MANAGED_FIELD(last_)>("last_","last_");
		addField<DAS_BIND_MANAGED_FIELD(system_count)>("system_count","system_count");
		addField<DAS_BIND_MANAGED_FIELD(multi_threaded)>("multi_threaded","multi_threaded");
		addField<DAS_BIND_MANAGED_FIELD(immediate)>("immediate","immediate");
	}
};

// from flecs/addons/stats.h:207:16
struct ecs_pipeline_stats_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_pipeline_stats_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_pipeline_stats_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_pipeline_stats_t", ml, "ecs_pipeline_stats_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(canary_)>("canary_","canary_");
		addField<DAS_BIND_MANAGED_FIELD(systems)>("systems","systems");
		addField<DAS_BIND_MANAGED_FIELD(sync_points)>("sync_points","sync_points");
		addField<DAS_BIND_MANAGED_FIELD(t)>("t","t");
		addField<DAS_BIND_MANAGED_FIELD(system_count)>("system_count","system_count");
		addField<DAS_BIND_MANAGED_FIELD(active_system_count)>("active_system_count","active_system_count");
		addField<DAS_BIND_MANAGED_FIELD(rebuild_count)>("rebuild_count","rebuild_count");
	}
};

// from flecs/addons/stats.h:442:9
struct EcsStatsHeader_GeneratedAnnotation : ManagedStructureAnnotation<EcsStatsHeader> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsStatsHeader_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsStatsHeader", ml, "EcsStatsHeader") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(elapsed)>("elapsed","elapsed");
		addField<DAS_BIND_MANAGED_FIELD(reduce_count)>("reduce_count","reduce_count");
	}
};

// from flecs/addons/stats.h:448:9
struct EcsWorldStats_GeneratedAnnotation : ManagedStructureAnnotation<EcsWorldStats> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsWorldStats_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsWorldStats", ml, "EcsWorldStats") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(hdr)>("hdr","hdr");
		addField<DAS_BIND_MANAGED_FIELD(stats)>("stats","stats");
	}
};

// from flecs/addons/stats.h:454:9
struct EcsSystemStats_GeneratedAnnotation : ManagedStructureAnnotation<EcsSystemStats> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsSystemStats_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsSystemStats", ml, "EcsSystemStats") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(hdr)>("hdr","hdr");
		addField<DAS_BIND_MANAGED_FIELD(stats)>("stats","stats");
	}
};

// from flecs/addons/stats.h:460:9
struct EcsPipelineStats_GeneratedAnnotation : ManagedStructureAnnotation<EcsPipelineStats> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsPipelineStats_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsPipelineStats", ml, "EcsPipelineStats") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(hdr)>("hdr","hdr");
		addField<DAS_BIND_MANAGED_FIELD(stats)>("stats","stats");
	}
};

// from flecs/addons/stats.h:466:9
struct EcsWorldSummary_GeneratedAnnotation : ManagedStructureAnnotation<EcsWorldSummary> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsWorldSummary_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsWorldSummary", ml, "EcsWorldSummary") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(target_fps)>("target_fps","target_fps");
		addField<DAS_BIND_MANAGED_FIELD(time_scale)>("time_scale","time_scale");
		addField<DAS_BIND_MANAGED_FIELD(fps)>("fps","fps");
		addField<DAS_BIND_MANAGED_FIELD(frame_time_total)>("frame_time_total","frame_time_total");
		addField<DAS_BIND_MANAGED_FIELD(system_time_total)>("system_time_total","system_time_total");
		addField<DAS_BIND_MANAGED_FIELD(merge_time_total)>("merge_time_total","merge_time_total");
		addField<DAS_BIND_MANAGED_FIELD(entity_count)>("entity_count","entity_count");
		addField<DAS_BIND_MANAGED_FIELD(table_count)>("table_count","table_count");
		addField<DAS_BIND_MANAGED_FIELD(frame_count)>("frame_count","frame_count");
		addField<DAS_BIND_MANAGED_FIELD(command_count)>("command_count","command_count");
		addField<DAS_BIND_MANAGED_FIELD(merge_count)>("merge_count","merge_count");
		addField<DAS_BIND_MANAGED_FIELD(systems_ran_total)>("systems_ran_total","systems_ran_total");
		addField<DAS_BIND_MANAGED_FIELD(observers_ran_total)>("observers_ran_total","observers_ran_total");
		addField<DAS_BIND_MANAGED_FIELD(queries_ran_total)>("queries_ran_total","queries_ran_total");
		addField<DAS_BIND_MANAGED_FIELD(tag_count)>("tag_count","tag_count");
		addField<DAS_BIND_MANAGED_FIELD(component_count)>("component_count","component_count");
		addField<DAS_BIND_MANAGED_FIELD(pair_count)>("pair_count","pair_count");
		addField<DAS_BIND_MANAGED_FIELD(frame_time_frame)>("frame_time_frame","frame_time_frame");
		addField<DAS_BIND_MANAGED_FIELD(system_time_frame)>("system_time_frame","system_time_frame");
		addField<DAS_BIND_MANAGED_FIELD(merge_time_frame)>("merge_time_frame","merge_time_frame");
		addField<DAS_BIND_MANAGED_FIELD(merge_count_frame)>("merge_count_frame","merge_count_frame");
		addField<DAS_BIND_MANAGED_FIELD(systems_ran_frame)>("systems_ran_frame","systems_ran_frame");
		addField<DAS_BIND_MANAGED_FIELD(observers_ran_frame)>("observers_ran_frame","observers_ran_frame");
		addField<DAS_BIND_MANAGED_FIELD(queries_ran_frame)>("queries_ran_frame","queries_ran_frame");
		addField<DAS_BIND_MANAGED_FIELD(command_count_frame)>("command_count_frame","command_count_frame");
		addField<DAS_BIND_MANAGED_FIELD(simulation_time)>("simulation_time","simulation_time");
		addField<DAS_BIND_MANAGED_FIELD(uptime)>("uptime","uptime");
		addField<DAS_BIND_MANAGED_FIELD(build_info)>("build_info","build_info");
	}
};

// from flecs/addons/stats.h:510:9
struct ecs_entities_memory_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_entities_memory_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_entities_memory_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_entities_memory_t", ml, "ecs_entities_memory_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(alive_count)>("alive_count","alive_count");
		addField<DAS_BIND_MANAGED_FIELD(not_alive_count)>("not_alive_count","not_alive_count");
		addField<DAS_BIND_MANAGED_FIELD(bytes_entity_index)>("bytes_entity_index","bytes_entity_index");
		addField<DAS_BIND_MANAGED_FIELD(bytes_names)>("bytes_names","bytes_names");
		addField<DAS_BIND_MANAGED_FIELD(bytes_doc_strings)>("bytes_doc_strings","bytes_doc_strings");
	}
};

// from flecs/addons/stats.h:519:9
struct ecs_component_memory_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_component_memory_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_component_memory_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_component_memory_t", ml, "ecs_component_memory_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(instances)>("instances","instances");
		addField<DAS_BIND_MANAGED_FIELD(bytes_table_components)>("bytes_table_components","bytes_table_components");
		addField<DAS_BIND_MANAGED_FIELD(bytes_table_components_unused)>("bytes_table_components_unused","bytes_table_components_unused");
		addField<DAS_BIND_MANAGED_FIELD(bytes_toggle_bitsets)>("bytes_toggle_bitsets","bytes_toggle_bitsets");
		addField<DAS_BIND_MANAGED_FIELD(bytes_sparse_components)>("bytes_sparse_components","bytes_sparse_components");
	}
};

// from flecs/addons/stats.h:528:9
struct ecs_component_index_memory_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_component_index_memory_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_component_index_memory_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_component_index_memory_t", ml, "ecs_component_index_memory_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(bytes_component_record)>("bytes_component_record","bytes_component_record");
		addField<DAS_BIND_MANAGED_FIELD(bytes_table_cache)>("bytes_table_cache","bytes_table_cache");
		addField<DAS_BIND_MANAGED_FIELD(bytes_name_index)>("bytes_name_index","bytes_name_index");
		addField<DAS_BIND_MANAGED_FIELD(bytes_ordered_children)>("bytes_ordered_children","bytes_ordered_children");
		addField<DAS_BIND_MANAGED_FIELD(bytes_reachable_cache)>("bytes_reachable_cache","bytes_reachable_cache");
	}
};

// from flecs/addons/stats.h:538:9
struct ecs_query_memory_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_query_memory_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_query_memory_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_query_memory_t", ml, "ecs_query_memory_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(cached_count)>("cached_count","cached_count");
		addField<DAS_BIND_MANAGED_FIELD(bytes_query)>("bytes_query","bytes_query");
		addField<DAS_BIND_MANAGED_FIELD(bytes_cache)>("bytes_cache","bytes_cache");
		addField<DAS_BIND_MANAGED_FIELD(bytes_group_by)>("bytes_group_by","bytes_group_by");
		addField<DAS_BIND_MANAGED_FIELD(bytes_order_by)>("bytes_order_by","bytes_order_by");
		addField<DAS_BIND_MANAGED_FIELD(bytes_plan)>("bytes_plan","bytes_plan");
		addField<DAS_BIND_MANAGED_FIELD(bytes_terms)>("bytes_terms","bytes_terms");
		addField<DAS_BIND_MANAGED_FIELD(bytes_misc)>("bytes_misc","bytes_misc");
	}
};

// from flecs/addons/stats.h:555:9
struct ecs_table_memory_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_memory_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_memory_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_memory_t", ml, "ecs_table_memory_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(empty_count)>("empty_count","empty_count");
		addField<DAS_BIND_MANAGED_FIELD(column_count)>("column_count","column_count");
		addField<DAS_BIND_MANAGED_FIELD(bytes_table)>("bytes_table","bytes_table");
		addField<DAS_BIND_MANAGED_FIELD(bytes_type)>("bytes_type","bytes_type");
		addField<DAS_BIND_MANAGED_FIELD(bytes_entities)>("bytes_entities","bytes_entities");
		addField<DAS_BIND_MANAGED_FIELD(bytes_overrides)>("bytes_overrides","bytes_overrides");
		addField<DAS_BIND_MANAGED_FIELD(bytes_column_map)>("bytes_column_map","bytes_column_map");
		addField<DAS_BIND_MANAGED_FIELD(bytes_component_map)>("bytes_component_map","bytes_component_map");
		addField<DAS_BIND_MANAGED_FIELD(bytes_dirty_state)>("bytes_dirty_state","bytes_dirty_state");
		addField<DAS_BIND_MANAGED_FIELD(bytes_edges)>("bytes_edges","bytes_edges");
	}
};

// from flecs/addons/stats.h:570:9
struct ecs_table_histogram_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_table_histogram_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_table_histogram_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_table_histogram_t", ml, "ecs_table_histogram_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity_counts)>("entity_counts","entity_counts");
	}
};

// from flecs/addons/stats.h:575:9
struct ecs_misc_memory_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_misc_memory_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_misc_memory_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_misc_memory_t", ml, "ecs_misc_memory_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(bytes_world)>("bytes_world","bytes_world");
		addField<DAS_BIND_MANAGED_FIELD(bytes_observers)>("bytes_observers","bytes_observers");
		addField<DAS_BIND_MANAGED_FIELD(bytes_systems)>("bytes_systems","bytes_systems");
		addField<DAS_BIND_MANAGED_FIELD(bytes_pipelines)>("bytes_pipelines","bytes_pipelines");
		addField<DAS_BIND_MANAGED_FIELD(bytes_table_lookup)>("bytes_table_lookup","bytes_table_lookup");
		addField<DAS_BIND_MANAGED_FIELD(bytes_component_record_lookup)>("bytes_component_record_lookup","bytes_component_record_lookup");
		addField<DAS_BIND_MANAGED_FIELD(bytes_locked_components)>("bytes_locked_components","bytes_locked_components");
		addField<DAS_BIND_MANAGED_FIELD(bytes_type_info)>("bytes_type_info","bytes_type_info");
		addField<DAS_BIND_MANAGED_FIELD(bytes_commands)>("bytes_commands","bytes_commands");
		addField<DAS_BIND_MANAGED_FIELD(bytes_component_ids)>("bytes_component_ids","bytes_component_ids");
		addField<DAS_BIND_MANAGED_FIELD(bytes_reflection)>("bytes_reflection","bytes_reflection");
		addField<DAS_BIND_MANAGED_FIELD(bytes_tree_spawner)>("bytes_tree_spawner","bytes_tree_spawner");
		addField<DAS_BIND_MANAGED_FIELD(bytes_prefab_child_indices)>("bytes_prefab_child_indices","bytes_prefab_child_indices");
		addField<DAS_BIND_MANAGED_FIELD(bytes_stats)>("bytes_stats","bytes_stats");
		addField<DAS_BIND_MANAGED_FIELD(bytes_rest)>("bytes_rest","bytes_rest");
	}
};

// from flecs/addons/stats.h:595:9
struct ecs_allocator_memory_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_allocator_memory_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_allocator_memory_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_allocator_memory_t", ml, "ecs_allocator_memory_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(bytes_component_record)>("bytes_component_record","bytes_component_record");
		addField<DAS_BIND_MANAGED_FIELD(bytes_pair_record)>("bytes_pair_record","bytes_pair_record");
		addField<DAS_BIND_MANAGED_FIELD(bytes_sparse_chunk)>("bytes_sparse_chunk","bytes_sparse_chunk");
		addField<DAS_BIND_MANAGED_FIELD(bytes_allocator)>("bytes_allocator","bytes_allocator");
		addField<DAS_BIND_MANAGED_FIELD(bytes_stack_allocator)>("bytes_stack_allocator","bytes_stack_allocator");
		addField<DAS_BIND_MANAGED_FIELD(bytes_cmd_entry_chunk)>("bytes_cmd_entry_chunk","bytes_cmd_entry_chunk");
		addField<DAS_BIND_MANAGED_FIELD(bytes_query_impl)>("bytes_query_impl","bytes_query_impl");
		addField<DAS_BIND_MANAGED_FIELD(bytes_query_cache)>("bytes_query_cache","bytes_query_cache");
		addField<DAS_BIND_MANAGED_FIELD(bytes_misc)>("bytes_misc","bytes_misc");
	}
};

// from flecs/addons/stats.h:608:9
struct EcsWorldMemory_GeneratedAnnotation : ManagedStructureAnnotation<EcsWorldMemory> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsWorldMemory_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsWorldMemory", ml, "EcsWorldMemory") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entities)>("entities","entities");
		addField<DAS_BIND_MANAGED_FIELD(components)>("components","components");
		addField<DAS_BIND_MANAGED_FIELD(component_index)>("component_index","component_index");
		addField<DAS_BIND_MANAGED_FIELD(queries)>("queries","queries");
		addField<DAS_BIND_MANAGED_FIELD(tables)>("tables","tables");
		addField<DAS_BIND_MANAGED_FIELD(table_histogram)>("table_histogram","table_histogram");
		addField<DAS_BIND_MANAGED_FIELD(misc)>("misc","misc");
		addField<DAS_BIND_MANAGED_FIELD(allocators)>("allocators","allocators");
		addField<DAS_BIND_MANAGED_FIELD(collection_time)>("collection_time","collection_time");
	}
};

// from flecs/addons/metrics.h:66:16
struct EcsMetricValue_GeneratedAnnotation : ManagedStructureAnnotation<EcsMetricValue> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsMetricValue_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsMetricValue", ml, "EcsMetricValue") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
	}
};

// from flecs/addons/metrics.h:71:16
struct EcsMetricSource_GeneratedAnnotation : ManagedStructureAnnotation<EcsMetricSource> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsMetricSource_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsMetricSource", ml, "EcsMetricSource") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
	}
};

// from flecs/addons/metrics.h:76:16
struct ecs_metric_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_metric_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_metric_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_metric_desc_t", ml, "ecs_metric_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(_canary)>("_canary","_canary");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(member)>("member","member");
		addField<char *,offsetof(ManagedType,dotmember)>("dotmember","dotmember")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(targets)>("targets","targets");
		addField<DAS_BIND_MANAGED_FIELD(kind)>("kind","kind");
		addField<char *,offsetof(ManagedType,brief)>("brief","brief")
			.adjustAot("das_reinterpret<char *>::pass(",")");
	}
};

// from flecs/addons/alerts.h:51:16
struct EcsAlertInstance_GeneratedAnnotation : ManagedStructureAnnotation<EcsAlertInstance> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsAlertInstance_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsAlertInstance", ml, "EcsAlertInstance") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(message)>("message","message");
	}
};

// from flecs/addons/alerts.h:56:16
struct EcsAlertsActive_GeneratedAnnotation : ManagedStructureAnnotation<EcsAlertsActive> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsAlertsActive_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsAlertsActive", ml, "EcsAlertsActive") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(info_count)>("info_count","info_count");
		addField<DAS_BIND_MANAGED_FIELD(warning_count)>("warning_count","warning_count");
		addField<DAS_BIND_MANAGED_FIELD(error_count)>("error_count","error_count");
		addField<DAS_BIND_MANAGED_FIELD(alerts)>("alerts","alerts");
	}
};

// from flecs/addons/alerts.h:69:16
struct ecs_alert_severity_filter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_alert_severity_filter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_alert_severity_filter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_alert_severity_filter_t", ml, "ecs_alert_severity_filter_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(severity)>("severity","severity");
		addField<DAS_BIND_MANAGED_FIELD(with)>("_with","with");
		addField<char *,offsetof(ManagedType,var)>("_var","var")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(_var_index)>("_var_index","_var_index");
	}
};

// from flecs/addons/alerts.h:78:16
struct ecs_alert_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_alert_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_alert_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_alert_desc_t", ml, "ecs_alert_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(_canary)>("_canary","_canary");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
		addField<char *,offsetof(ManagedType,message)>("message","message")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,doc_name)>("doc_name","doc_name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,brief)>("brief","brief")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(severity)>("severity","severity");
		addField<DAS_BIND_MANAGED_FIELD(severity_filters)>("severity_filters","severity_filters");
		addField<DAS_BIND_MANAGED_FIELD(retain_period)>("retain_period","retain_period");
		addField<DAS_BIND_MANAGED_FIELD(member)>("member","member");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<char *,offsetof(ManagedType,var)>("_var","var")
			.adjustAot("das_reinterpret<char *>::pass(",")");
	}
};

// from flecs/addons/json.h:41:16
struct ecs_from_json_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_from_json_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_from_json_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_from_json_desc_t", ml, "ecs_from_json_desc_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,expr)>("expr","expr")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(lookup_ctx)>("lookup_ctx","lookup_ctx");
		addField<DAS_BIND_MANAGED_FIELD(strict)>("strict","strict");
	}
};

// from flecs/addons/json.h:220:16
struct ecs_entity_to_json_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_entity_to_json_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_entity_to_json_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_entity_to_json_desc_t", ml, "ecs_entity_to_json_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(serialize_entity_id)>("serialize_entity_id","serialize_entity_id");
		addField<DAS_BIND_MANAGED_FIELD(serialize_doc)>("serialize_doc","serialize_doc");
		addField<DAS_BIND_MANAGED_FIELD(serialize_full_paths)>("serialize_full_paths","serialize_full_paths");
		addField<DAS_BIND_MANAGED_FIELD(serialize_inherited)>("serialize_inherited","serialize_inherited");
		addField<DAS_BIND_MANAGED_FIELD(serialize_values)>("serialize_values","serialize_values");
		addField<DAS_BIND_MANAGED_FIELD(serialize_builtin)>("serialize_builtin","serialize_builtin");
		addField<DAS_BIND_MANAGED_FIELD(serialize_type_info)>("serialize_type_info","serialize_type_info");
		addField<DAS_BIND_MANAGED_FIELD(serialize_alerts)>("serialize_alerts","serialize_alerts");
		addField<DAS_BIND_MANAGED_FIELD(serialize_refs)>("serialize_refs","serialize_refs");
		addField<DAS_BIND_MANAGED_FIELD(serialize_matches)>("serialize_matches","serialize_matches");
	}
};

// from flecs/addons/json.h:301:16
struct ecs_iter_to_json_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_iter_to_json_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_iter_to_json_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_iter_to_json_desc_t", ml, "ecs_iter_to_json_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(serialize_entity_ids)>("serialize_entity_ids","serialize_entity_ids");
		addField<DAS_BIND_MANAGED_FIELD(serialize_values)>("serialize_values","serialize_values");
		addField<DAS_BIND_MANAGED_FIELD(serialize_builtin)>("serialize_builtin","serialize_builtin");
		addField<DAS_BIND_MANAGED_FIELD(serialize_doc)>("serialize_doc","serialize_doc");
		addField<DAS_BIND_MANAGED_FIELD(serialize_full_paths)>("serialize_full_paths","serialize_full_paths");
		addField<DAS_BIND_MANAGED_FIELD(serialize_fields)>("serialize_fields","serialize_fields");
		addField<DAS_BIND_MANAGED_FIELD(serialize_inherited)>("serialize_inherited","serialize_inherited");
		addField<DAS_BIND_MANAGED_FIELD(serialize_table)>("serialize_table","serialize_table");
		addField<DAS_BIND_MANAGED_FIELD(serialize_type_info)>("serialize_type_info","serialize_type_info");
		addField<DAS_BIND_MANAGED_FIELD(serialize_field_info)>("serialize_field_info","serialize_field_info");
		addField<DAS_BIND_MANAGED_FIELD(serialize_query_info)>("serialize_query_info","serialize_query_info");
		addField<DAS_BIND_MANAGED_FIELD(serialize_query_plan)>("serialize_query_plan","serialize_query_plan");
		addField<DAS_BIND_MANAGED_FIELD(serialize_query_profile)>("serialize_query_profile","serialize_query_profile");
		addField<DAS_BIND_MANAGED_FIELD(dont_serialize_results)>("dont_serialize_results","dont_serialize_results");
		addField<DAS_BIND_MANAGED_FIELD(serialize_alerts)>("serialize_alerts","serialize_alerts");
		addField<DAS_BIND_MANAGED_FIELD(serialize_refs)>("serialize_refs","serialize_refs");
		addField<DAS_BIND_MANAGED_FIELD(serialize_matches)>("serialize_matches","serialize_matches");
		addField<DAS_BIND_MANAGED_FIELD(serialize_parents_before_children)>("serialize_parents_before_children","serialize_parents_before_children");
		addField<DAS_BIND_MANAGED_FIELD(query)>("query","query");
	}
};

// from flecs/addons/json.h:404:16
struct ecs_world_to_json_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_world_to_json_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_world_to_json_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_world_to_json_desc_t", ml, "ecs_world_to_json_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(serialize_builtin)>("serialize_builtin","serialize_builtin");
		addField<DAS_BIND_MANAGED_FIELD(serialize_modules)>("serialize_modules","serialize_modules");
	}
};

// from flecs/addons/script_input.h:51:16
struct EcsScriptMouseEvent_GeneratedAnnotation : ManagedStructureAnnotation<EcsScriptMouseEvent> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScriptMouseEvent_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScriptMouseEvent", ml, "EcsScriptMouseEvent") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(target)>("target","target");
		addField<DAS_BIND_MANAGED_FIELD(screen_x)>("screen_x","screen_x");
		addField<DAS_BIND_MANAGED_FIELD(screen_y)>("screen_y","screen_y");
		addField<DAS_BIND_MANAGED_FIELD(local_x)>("local_x","local_x");
		addField<DAS_BIND_MANAGED_FIELD(local_y)>("local_y","local_y");
		addField<DAS_BIND_MANAGED_FIELD(delta_x)>("delta_x","delta_x");
		addField<DAS_BIND_MANAGED_FIELD(delta_y)>("delta_y","delta_y");
		addField<DAS_BIND_MANAGED_FIELD(button)>("button","button");
		addField<DAS_BIND_MANAGED_FIELD(buttons)>("buttons","buttons");
		addField<DAS_BIND_MANAGED_FIELD(ctrl)>("ctrl","ctrl");
		addField<DAS_BIND_MANAGED_FIELD(shift)>("shift","shift");
		addField<DAS_BIND_MANAGED_FIELD(alt)>("alt","alt");
		addField<DAS_BIND_MANAGED_FIELD(meta)>("meta","meta");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
	}
};

// from flecs/addons/script_input.h:78:16
struct EcsScriptKeyboardEvent_GeneratedAnnotation : ManagedStructureAnnotation<EcsScriptKeyboardEvent> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScriptKeyboardEvent_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScriptKeyboardEvent", ml, "EcsScriptKeyboardEvent") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(key)>("key","key");
		addField<DAS_BIND_MANAGED_FIELD(down)>("down","down");
		addField<DAS_BIND_MANAGED_FIELD(repeat)>("repeat","repeat");
		addField<DAS_BIND_MANAGED_FIELD(ctrl)>("ctrl","ctrl");
		addField<DAS_BIND_MANAGED_FIELD(shift)>("shift","shift");
		addField<DAS_BIND_MANAGED_FIELD(alt)>("alt","alt");
		addField<DAS_BIND_MANAGED_FIELD(meta)>("meta","meta");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
	}
};

// from flecs/addons/script_input.h:96:16
struct EcsScriptFocusEvent_GeneratedAnnotation : ManagedStructureAnnotation<EcsScriptFocusEvent> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScriptFocusEvent_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScriptFocusEvent", ml, "EcsScriptFocusEvent") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(target)>("target","target");
		addField<DAS_BIND_MANAGED_FIELD(related)>("related","related");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
	}
};

// from flecs/addons/script_input.h:113:16
struct EcsScriptActivateEvent_GeneratedAnnotation : ManagedStructureAnnotation<EcsScriptActivateEvent> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScriptActivateEvent_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScriptActivateEvent", ml, "EcsScriptActivateEvent") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(target)>("target","target");
		addField<DAS_BIND_MANAGED_FIELD(keyboard)>("keyboard","keyboard");
		addField<DAS_BIND_MANAGED_FIELD(local_x)>("local_x","local_x");
		addField<DAS_BIND_MANAGED_FIELD(local_y)>("local_y","local_y");
		addField<DAS_BIND_MANAGED_FIELD(ctrl)>("ctrl","ctrl");
		addField<DAS_BIND_MANAGED_FIELD(shift)>("shift","shift");
		addField<DAS_BIND_MANAGED_FIELD(alt)>("alt","alt");
		addField<DAS_BIND_MANAGED_FIELD(meta)>("meta","meta");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
	}
};

// from flecs/addons/script_input.h:202:16
struct ecs_script_event_hooks_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_event_hooks_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_event_hooks_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_event_hooks_t", ml, "ecs_script_event_hooks_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
	}
};

// from flecs/addons/script_input.h:210:16
struct ecs_script_event_result_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_event_result_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_event_result_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_event_result_t", ml, "ecs_script_event_result_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(resolved)>("resolved","resolved");
		addField<DAS_BIND_MANAGED_FIELD(stopped)>("stopped","stopped");
	}
};

// from flecs/addons/script_shell.h:93:16
struct ecs_shell_result_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_result_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_result_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_result_t", ml, "ecs_shell_result_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(results)>("results","results");
		addField<DAS_BIND_MANAGED_FIELD(errors)>("errors","errors");
	}
};

// from flecs/addons/script_shell.h:107:16
struct ecs_shell_resource_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_resource_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_resource_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_resource_t", ml, "ecs_shell_resource_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(name)>("name","name");
		addField<DAS_BIND_MANAGED_FIELD(content_type)>("content_type","content_type");
	}
};

// from flecs/addons/script_shell.h:127:16
struct EcsCommandSession_GeneratedAnnotation : ManagedStructureAnnotation<EcsCommandSession> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsCommandSession_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsCommandSession", ml, "EcsCommandSession") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(scope)>("scope","scope");
		addField<DAS_BIND_MANAGED_FIELD(history)>("history","history");
		addField<DAS_BIND_MANAGED_FIELD(history_size)>("history_size","history_size");
		addField<DAS_BIND_MANAGED_FIELD(results)>("results","results");
		addField<DAS_BIND_MANAGED_FIELD(resources)>("resources","resources");
		addField<DAS_BIND_MANAGED_FIELD(resource_path)>("resource_path","resource_path");
	}
};

// from flecs/addons/script_shell.h:137:16
struct EcsScriptShell_GeneratedAnnotation : ManagedStructureAnnotation<EcsScriptShell> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScriptShell_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScriptShell", ml, "EcsScriptShell") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(command_paths)>("command_paths","command_paths");
	}
};

// from flecs/addons/script_shell.h:142:16
struct ecs_shell_session_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_session_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_session_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_session_desc_t", ml, "ecs_shell_session_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(scope)>("scope","scope");
		addField<DAS_BIND_MANAGED_FIELD(history_size)>("history_size","history_size");
	}
};

// from flecs/addons/script_shell.h:149:16
struct ecs_shell_param_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_param_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_param_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_param_info_t", ml, "ecs_shell_param_info_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(name)>("name","name");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(optional)>("optional","optional");
		addField<DAS_BIND_MANAGED_FIELD(brief)>("brief","brief");
	}
};

// from flecs/addons/script_shell.h:157:16
struct ecs_shell_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_info_t", ml, "ecs_shell_info_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(name)>("name","name");
		addField<DAS_BIND_MANAGED_FIELD(brief)>("brief","brief");
		addField<DAS_BIND_MANAGED_FIELD(params)>("params","params");
		addField<DAS_BIND_MANAGED_FIELD(return_type)>("return_type","return_type");
	}
};

// from flecs/addons/script_shell.h:165:16
struct ecs_shell_tree_node_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_tree_node_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_tree_node_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_tree_node_t", ml, "ecs_shell_tree_node_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(depth)>("depth","depth");
	}
};

// from flecs/addons/script_shell.h:171:16
struct ecs_shell_component_value_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_component_value_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_component_value_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_component_value_t", ml, "ecs_shell_component_value_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
	}
};

// from flecs/addons/script_shell.h:177:16
struct ecs_shell_entity_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_entity_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_entity_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_entity_info_t", ml, "ecs_shell_entity_info_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(components)>("components","components");
		addField<DAS_BIND_MANAGED_FIELD(ids)>("ids","ids");
	}
};

// from flecs/addons/script_shell.h:185:16
struct ecs_shell_doc_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_doc_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_doc_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_doc_info_t", ml, "ecs_shell_doc_info_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(name)>("name","name");
		addField<DAS_BIND_MANAGED_FIELD(brief)>("brief","brief");
		addField<DAS_BIND_MANAGED_FIELD(detail)>("detail","detail");
		addField<DAS_BIND_MANAGED_FIELD(link)>("link","link");
		addField<DAS_BIND_MANAGED_FIELD(color)>("color","color");
	}
};

// from flecs/addons/script_shell.h:195:16
struct ecs_shell_query_row_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_query_row_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_query_row_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_query_row_t", ml, "ecs_shell_query_row_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(fields)>("fields","fields");
	}
};

// from flecs/addons/script_shell.h:201:16
struct ecs_shell_grep_match_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_grep_match_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_grep_match_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_grep_match_t", ml, "ecs_shell_grep_match_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(id)>("id","id");
		addField<DAS_BIND_MANAGED_FIELD(text)>("text","text");
	}
};

// from flecs/addons/script_shell.h:208:16
struct ecs_shell_script_info_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_script_info_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_script_info_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_script_info_t", ml, "ecs_shell_script_info_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(script)>("script","script");
		addField<DAS_BIND_MANAGED_FIELD(filename)>("filename","filename");
		addField<DAS_BIND_MANAGED_FIELD(lines)>("lines","lines");
		addField<DAS_BIND_MANAGED_FIELD(unsaved)>("unsaved","unsaved");
		addField<DAS_BIND_MANAGED_FIELD(error)>("error","error");
	}
};

// from flecs/addons/script_shell.h:217:16
struct ecs_shell_script_line_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_script_line_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_script_line_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_script_line_t", ml, "ecs_shell_script_line_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(line)>("line","line");
		addField<DAS_BIND_MANAGED_FIELD(text)>("text","text");
	}
};

// from flecs/addons/script_shell.h:223:16
struct ecs_shell_script_match_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_script_match_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_script_match_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_script_match_t", ml, "ecs_shell_script_match_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(script)>("script","script");
		addField<DAS_BIND_MANAGED_FIELD(line)>("line","line");
		addField<DAS_BIND_MANAGED_FIELD(text)>("text","text");
	}
};

// from flecs/addons/script_shell.h:230:16
struct ecs_shell_script_location_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_script_location_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_script_location_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_script_location_t", ml, "ecs_shell_script_location_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(script)>("script","script");
		addField<DAS_BIND_MANAGED_FIELD(line)>("line","line");
		addField<DAS_BIND_MANAGED_FIELD(column)>("column","column");
		addField<DAS_BIND_MANAGED_FIELD(template_)>("template_","template_");
		addField<DAS_BIND_MANAGED_FIELD(statement)>("statement","statement");
	}
};

// from flecs/addons/script_shell.h:239:16
struct ecs_shell_script_error_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_script_error_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_script_error_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_script_error_t", ml, "ecs_shell_script_error_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(script)>("script","script");
		addField<DAS_BIND_MANAGED_FIELD(error)>("error","error");
	}
};

// from flecs/addons/script_shell.h:246:16
struct ecs_shell_pointer_state_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_shell_pointer_state_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_shell_pointer_state_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_shell_pointer_state_t", ml, "ecs_shell_pointer_state_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(event)>("event","event");
		addField<DAS_BIND_MANAGED_FIELD(pressed)>("pressed","pressed");
	}
};

// from flecs/addons/script.h:85:16
struct ecs_script_template_ref_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_template_ref_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_template_ref_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_template_ref_t", ml, "ecs_script_template_ref_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
	}
};

// from flecs/addons/script.h:94:16
struct ecs_script_var_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_var_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_var_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_var_t", ml, "ecs_script_var_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<ecs_type_info_t *,offsetof(ManagedType,type_info)>("type_info","type_info")
			.adjustAot("das_reinterpret<ecs_type_info_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(sp)>("sp","sp");
		addField<DAS_BIND_MANAGED_FIELD(is_const)>("is_const","is_const");
		addField<DAS_BIND_MANAGED_FIELD(owned)>("owned","owned");
	}
};

// from flecs/addons/script.h:104:16
struct ecs_script_vars_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_vars_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_vars_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_vars_t", ml, "ecs_script_vars_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(parent)>("parent","parent");
		addField<DAS_BIND_MANAGED_FIELD(sp)>("sp","sp");
		addField<DAS_BIND_MANAGED_FIELD(var_index)>("var_index","var_index");
		addField<DAS_BIND_MANAGED_FIELD(vars)>("vars","vars");
		addField<ecs_world_t *,offsetof(ManagedType,world)>("world","world")
			.adjustAot("das_reinterpret<ecs_world_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(stack)>("stack","stack");
		addField<DAS_BIND_MANAGED_FIELD(cursor)>("cursor","cursor");
		addField<DAS_BIND_MANAGED_FIELD(allocator)>("allocator","allocator");
	}
};

// from flecs/addons/script.h:118:16
struct ecs_script_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_t", ml, "ecs_script_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(world)>("world","world");
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,code)>("code","code")
			.adjustAot("das_reinterpret<char *>::pass(",")");
	}
};

// from flecs/addons/script.h:130:16
struct EcsScript_GeneratedAnnotation : ManagedStructureAnnotation<EcsScript> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScript_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScript", ml, "EcsScript") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(filename)>("filename","filename");
		addField<DAS_BIND_MANAGED_FIELD(code)>("code","code");
		addField<DAS_BIND_MANAGED_FIELD(error)>("error","error");
		addField<DAS_BIND_MANAGED_FIELD(script)>("script","script");
		addField<DAS_BIND_MANAGED_FIELD(template_)>("template_","template_");
		addField<DAS_BIND_MANAGED_FIELD(observers)>("observers","observers");
		addField<DAS_BIND_MANAGED_FIELD(dyn_observers)>("dyn_observers","dyn_observers");
		addField<DAS_BIND_MANAGED_FIELD(skip_unknown)>("skip_unknown","skip_unknown");
		addField<DAS_BIND_MANAGED_FIELD(ir)>("ir","ir");
		addField<DAS_BIND_MANAGED_FIELD(saved_code)>("saved_code","saved_code");
		addField<DAS_BIND_MANAGED_FIELD(undo)>("undo","undo");
	}
};

// from flecs/addons/script.h:157:16
struct ecs_function_ctx_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_function_ctx_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_function_ctx_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_function_ctx_t", ml, "ecs_function_ctx_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(world)>("world","world");
		addField<DAS_BIND_MANAGED_FIELD(function)>("_function","function");
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
	}
};

// from flecs/addons/script.h:180:16
struct ecs_script_parameter_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_parameter_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_parameter_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_parameter_t", ml, "ecs_script_parameter_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(optional)>("optional","optional");
		addField<char *,offsetof(ManagedType,brief)>("brief","brief")
			.adjustAot("das_reinterpret<char *>::pass(",")");
	}
};

// from flecs/addons/script.h:193:16
struct ecs_script_eval_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_eval_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_eval_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_eval_desc_t", ml, "ecs_script_eval_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(runtime)>("runtime","runtime");
		addField<DAS_BIND_MANAGED_FIELD(skip_unknown)>("skip_unknown","skip_unknown");
		addField<DAS_BIND_MANAGED_FIELD(ir)>("ir","ir");
	}
};

// from flecs/addons/script.h:226:16
struct ecs_script_eval_result_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_eval_result_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_eval_result_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_eval_result_t", ml, "ecs_script_eval_result_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(error)>("error","error");
		addField<DAS_BIND_MANAGED_FIELD(line)>("line","line");
		addField<DAS_BIND_MANAGED_FIELD(column)>("column","column");
	}
};

// from flecs/addons/script_async.h:85:16
struct EcsScriptTask_GeneratedAnnotation : ManagedStructureAnnotation<EcsScriptTask> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScriptTask_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScriptTask", ml, "EcsScriptTask") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(tasks)>("tasks","tasks");
	}
};

// from flecs/addons/script_async.h:113:16
struct ecs_script_task_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_task_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_task_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_task_desc_t", ml, "ecs_script_task_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(loop)>("loop","loop");
		addField<DAS_BIND_MANAGED_FIELD(iterations)>("iterations","iterations");
	}
};

// from flecs/addons/script_async.h:426:16
struct ecs_async_function_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_async_function_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_async_function_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_async_function_desc_t", ml, "ecs_async_function_desc_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(parent)>("parent","parent");
		addField<DAS_BIND_MANAGED_FIELD(params)>("params","params");
		addField<DAS_BIND_MANAGED_FIELD(return_type)>("return_type","return_type");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
	}
};

// from flecs/addons/script.h:240:16
struct EcsScriptConstVar_GeneratedAnnotation : ManagedStructureAnnotation<EcsScriptConstVar> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScriptConstVar_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScriptConstVar", ml, "EcsScriptConstVar") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<ecs_type_info_t *,offsetof(ManagedType,type_info)>("type_info","type_info")
			.adjustAot("das_reinterpret<ecs_type_info_t *>::pass(",")");
	}
};

// from flecs/addons/script.h:250:16
struct EcsScriptMutVar_GeneratedAnnotation : ManagedStructureAnnotation<EcsScriptMutVar> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsScriptMutVar_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsScriptMutVar", ml, "EcsScriptMutVar") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<ecs_type_info_t *,offsetof(ManagedType,type_info)>("type_info","type_info")
			.adjustAot("das_reinterpret<ecs_type_info_t *>::pass(",")");
	}
};

// from flecs/addons/script.h:255:8
struct ecs_script_function_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_function_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_function_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_function_t", ml, "ecs_script_function_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(return_type)>("return_type","return_type");
		addField<DAS_BIND_MANAGED_FIELD(params)>("params","params");
		addField<DAS_BIND_MANAGED_FIELD(vector_callbacks)>("vector_callbacks","vector_callbacks");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
		addField<DAS_BIND_MANAGED_FIELD(binding_ctx)>("binding_ctx","binding_ctx");
	}
};

// from flecs/addons/script.h:491:16
struct ecs_script_source_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_source_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_source_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_source_t", ml, "ecs_script_source_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
		addField<DAS_BIND_MANAGED_FIELD(length)>("length","length");
		addField<DAS_BIND_MANAGED_FIELD(line)>("line","line");
		addField<DAS_BIND_MANAGED_FIELD(column)>("column","column");
		addField<DAS_BIND_MANAGED_FIELD(has_scope)>("has_scope","has_scope");
		addField<DAS_BIND_MANAGED_FIELD(template_)>("template_","template_");
	}
};

// from flecs/addons/script.h:812:16
struct ecs_script_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_script_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_script_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_script_desc_t", ml, "ecs_script_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<char *,offsetof(ManagedType,filename)>("filename","filename")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,code)>("code","code")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(skip_unknown)>("skip_unknown","skip_unknown");
		addField<DAS_BIND_MANAGED_FIELD(ir)>("ir","ir");
	}
};

// from flecs/addons/script.h:1145:16
struct ecs_expr_eval_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_expr_eval_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_expr_eval_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_expr_eval_desc_t", ml, "ecs_expr_eval_desc_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<char *,offsetof(ManagedType,expr)>("expr","expr")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<ecs_script_vars_t *,offsetof(ManagedType,vars)>("vars","vars")
			.adjustAot("das_reinterpret<ecs_script_vars_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(lookup_ctx)>("lookup_ctx","lookup_ctx");
		addField<DAS_BIND_MANAGED_FIELD(disable_folding)>("disable_folding","disable_folding");
		addField<DAS_BIND_MANAGED_FIELD(disable_dynamic_variable_binding)>("disable_dynamic_variable_binding","disable_dynamic_variable_binding");
		addField<DAS_BIND_MANAGED_FIELD(allow_unresolved_identifiers)>("allow_unresolved_identifiers","allow_unresolved_identifiers");
		addField<DAS_BIND_MANAGED_FIELD(partial)>("partial","partial");
		addField<DAS_BIND_MANAGED_FIELD(runtime)>("runtime","runtime");
		addField<DAS_BIND_MANAGED_FIELD(script_visitor)>("script_visitor","script_visitor");
	}
};

// from flecs/addons/script.h:1258:16
struct ecs_const_var_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_const_var_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_const_var_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_const_var_desc_t", ml, "ecs_const_var_desc_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(parent)>("parent","parent");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
	}
};

// from flecs/addons/script.h:1351:16
struct ecs_mut_var_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_mut_var_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_mut_var_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_mut_var_desc_t", ml, "ecs_mut_var_desc_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(parent)>("parent","parent");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
	}
};

// from flecs/addons/script.h:1507:16
struct ecs_vector_fn_callbacks_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_vector_fn_callbacks_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_vector_fn_callbacks_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_vector_fn_callbacks_t", ml, "ecs_vector_fn_callbacks_t") {
	}
	void init () {
	}
};

// from flecs/addons/script.h:1513:16
struct ecs_function_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_function_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_function_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_function_desc_t", ml, "ecs_function_desc_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(parent)>("parent","parent");
		addField<DAS_BIND_MANAGED_FIELD(params)>("params","params");
		addField<DAS_BIND_MANAGED_FIELD(return_type)>("return_type","return_type");
		addField<DAS_BIND_MANAGED_FIELD(vector_callbacks)>("vector_callbacks","vector_callbacks");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
	}
};

// from flecs/addons/doc.h:67:16
struct EcsDocDescription_GeneratedAnnotation : ManagedStructureAnnotation<EcsDocDescription> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsDocDescription_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsDocDescription", ml, "EcsDocDescription") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
	}
};

// from flecs/addons/meta.h:170:16
struct EcsType_GeneratedAnnotation : ManagedStructureAnnotation<EcsType> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsType_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsType", ml, "EcsType") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(kind)>("kind","kind");
		addField<DAS_BIND_MANAGED_FIELD(existing)>("existing","existing");
		addField<DAS_BIND_MANAGED_FIELD(partial)>("partial","partial");
	}
};

// from flecs/addons/meta.h:200:16
struct EcsPrimitive_GeneratedAnnotation : ManagedStructureAnnotation<EcsPrimitive> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsPrimitive_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsPrimitive", ml, "EcsPrimitive") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(kind)>("kind","kind");
	}
};

// from flecs/addons/meta.h:205:16
struct EcsMember_GeneratedAnnotation : ManagedStructureAnnotation<EcsMember> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsMember_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsMember", ml, "EcsMember") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(unit)>("unit","unit");
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
		addField<DAS_BIND_MANAGED_FIELD(use_offset)>("use_offset","use_offset");
	}
};

// from flecs/addons/meta.h:214:16
struct ecs_member_value_range_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_member_value_range_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_member_value_range_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_member_value_range_t", ml, "ecs_member_value_range_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(min)>("min","min");
		addField<DAS_BIND_MANAGED_FIELD(max)>("max","max");
	}
};

// from flecs/addons/meta.h:220:16
struct EcsMemberRanges_GeneratedAnnotation : ManagedStructureAnnotation<EcsMemberRanges> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsMemberRanges_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsMemberRanges", ml, "EcsMemberRanges") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<DAS_BIND_MANAGED_FIELD(warning)>("warning","warning");
		addField<DAS_BIND_MANAGED_FIELD(error)>("error","error");
	}
};

// from flecs/addons/meta.h:227:16
struct ecs_member_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_member_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_member_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_member_t", ml, "ecs_member_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
		addField<DAS_BIND_MANAGED_FIELD(unit)>("unit","unit");
		addField<DAS_BIND_MANAGED_FIELD(use_offset)>("use_offset","use_offset");
		addField<DAS_BIND_MANAGED_FIELD(range)>("_range","range");
		addField<DAS_BIND_MANAGED_FIELD(error_range)>("error_range","error_range");
		addField<DAS_BIND_MANAGED_FIELD(warning_range)>("warning_range","warning_range");
		addField<DAS_BIND_MANAGED_FIELD(size)>("size","size");
		addField<DAS_BIND_MANAGED_FIELD(member)>("member","member");
	}
};

// from flecs/addons/meta.h:271:16
struct EcsStruct_GeneratedAnnotation : ManagedStructureAnnotation<EcsStruct> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsStruct_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsStruct", ml, "EcsStruct") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(members)>("members","members");
	}
};

// from flecs/addons/meta.h:277:16
struct ecs_enum_constant_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_enum_constant_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_enum_constant_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_enum_constant_t", ml, "ecs_enum_constant_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<DAS_BIND_MANAGED_FIELD(value_unsigned)>("value_unsigned","value_unsigned");
		addField<DAS_BIND_MANAGED_FIELD(constant)>("constant","constant");
	}
};

// from flecs/addons/meta.h:292:16
struct EcsEnum_GeneratedAnnotation : ManagedStructureAnnotation<EcsEnum> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsEnum_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsEnum", ml, "EcsEnum") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(underlying_type)>("underlying_type","underlying_type");
	}
};

// from flecs/addons/meta.h:297:16
struct ecs_bitmask_constant_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_bitmask_constant_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_bitmask_constant_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_bitmask_constant_t", ml, "ecs_bitmask_constant_t") {
	}
	void init () {
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(value)>("value","value");
		addField<DAS_BIND_MANAGED_FIELD(_unused)>("_unused","_unused");
		addField<DAS_BIND_MANAGED_FIELD(constant)>("constant","constant");
	}
};

// from flecs/addons/meta.h:312:16
struct EcsBitmask_GeneratedAnnotation : ManagedStructureAnnotation<EcsBitmask> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsBitmask_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsBitmask", ml, "EcsBitmask") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(dummy_)>("dummy_","dummy_");
	}
};

// from flecs/addons/meta.h:317:16
struct EcsConstants_GeneratedAnnotation : ManagedStructureAnnotation<EcsConstants> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsConstants_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsConstants", ml, "EcsConstants") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(constants)>("constants","constants");
		addField<DAS_BIND_MANAGED_FIELD(ordered_constants)>("ordered_constants","ordered_constants");
	}
};

// from flecs/addons/meta.h:326:16
struct EcsArray_GeneratedAnnotation : ManagedStructureAnnotation<EcsArray> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsArray_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsArray", ml, "EcsArray") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
	}
};

// from flecs/addons/meta.h:332:16
struct EcsVector_GeneratedAnnotation : ManagedStructureAnnotation<EcsVector> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsVector_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsVector", ml, "EcsVector") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
	}
};

// from flecs/addons/meta.h:337:16
struct EcsMap_GeneratedAnnotation : ManagedStructureAnnotation<EcsMap> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsMap_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsMap", ml, "EcsMap") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(key_type)>("key_type","key_type");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
	}
};

// from flecs/addons/meta.h:348:16
struct ecs_serializer_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_serializer_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_serializer_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_serializer_t", ml, "ecs_serializer_t") {
	}
	void init () {
		addField<ecs_world_t *,offsetof(ManagedType,world)>("world","world")
			.adjustAot("das_reinterpret<ecs_world_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(ctx)>("ctx","ctx");
	}
};

// from flecs/addons/meta.h:421:16
struct EcsOpaque_GeneratedAnnotation : ManagedStructureAnnotation<EcsOpaque> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsOpaque_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsOpaque", ml, "EcsOpaque") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(as_type)>("as_type","as_type");
	}
};

// from flecs/addons/meta.h:513:16
struct ecs_unit_translation_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_unit_translation_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_unit_translation_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_unit_translation_t", ml, "ecs_unit_translation_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(factor)>("factor","factor");
		addField<DAS_BIND_MANAGED_FIELD(power)>("power","power");
	}
};

// from flecs/addons/meta.h:519:16
struct EcsUnit_GeneratedAnnotation : ManagedStructureAnnotation<EcsUnit> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsUnit_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsUnit", ml, "EcsUnit") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(symbol)>("symbol","symbol");
		addField<DAS_BIND_MANAGED_FIELD(prefix)>("prefix","prefix");
		addField<DAS_BIND_MANAGED_FIELD(base)>("base","base");
		addField<DAS_BIND_MANAGED_FIELD(over)>("over","over");
		addField<DAS_BIND_MANAGED_FIELD(translation)>("translation","translation");
	}
};

// from flecs/addons/meta.h:528:16
struct EcsUnitPrefix_GeneratedAnnotation : ManagedStructureAnnotation<EcsUnitPrefix> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsUnitPrefix_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsUnitPrefix", ml, "EcsUnitPrefix") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(symbol)>("symbol","symbol");
		addField<DAS_BIND_MANAGED_FIELD(translation)>("translation","translation");
	}
};

// from flecs/addons/meta.h:584:16
struct ecs_meta_op_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_meta_op_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_meta_op_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_meta_op_t", ml, "ecs_meta_op_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(kind)>("kind","kind");
		addField<DAS_BIND_MANAGED_FIELD(underlying_kind)>("underlying_kind","underlying_kind");
		addField<DAS_BIND_MANAGED_FIELD(offset)>("offset","offset");
		addField<char *,offsetof(ManagedType,name)>("name","name")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(elem_size)>("elem_size","elem_size");
		addField<DAS_BIND_MANAGED_FIELD(op_count)>("op_count","op_count");
		addField<DAS_BIND_MANAGED_FIELD(member_index)>("member_index","member_index");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<ecs_type_info_t *,offsetof(ManagedType,type_info)>("type_info","type_info")
			.adjustAot("das_reinterpret<ecs_type_info_t *>::pass(",")");
	}
};

// from flecs/addons/meta.h:603:16
struct EcsTypeSerializer_GeneratedAnnotation : ManagedStructureAnnotation<EcsTypeSerializer> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	EcsTypeSerializer_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EcsTypeSerializer", ml, "EcsTypeSerializer") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(kind)>("kind","kind");
		addField<DAS_BIND_MANAGED_FIELD(ops)>("ops","ops");
	}
};

// from flecs/addons/meta.h:617:16
struct ecs_meta_scope_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_meta_scope_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_meta_scope_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_meta_scope_t", ml, "ecs_meta_scope_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(ops)>("ops","ops");
		addField<DAS_BIND_MANAGED_FIELD(ops_count)>("ops_count","ops_count");
		addField<DAS_BIND_MANAGED_FIELD(ops_cur)>("ops_cur","ops_cur");
		addField<DAS_BIND_MANAGED_FIELD(prev_depth)>("prev_depth","prev_depth");
		addField<DAS_BIND_MANAGED_FIELD(ptr)>("ptr","ptr");
		addField<EcsOpaque *,offsetof(ManagedType,opaque)>("opaque","opaque")
			.adjustAot("das_reinterpret<EcsOpaque *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(members)>("members","members");
		addField<DAS_BIND_MANAGED_FIELD(is_collection)>("is_collection","is_collection");
		addField<DAS_BIND_MANAGED_FIELD(is_map)>("is_map","is_map");
		addField<DAS_BIND_MANAGED_FIELD(is_value)>("is_value","is_value");
		addField<DAS_BIND_MANAGED_FIELD(is_empty_scope)>("is_empty_scope","is_empty_scope");
		addField<DAS_BIND_MANAGED_FIELD(is_moved_scope)>("is_moved_scope","is_moved_scope");
		addField<DAS_BIND_MANAGED_FIELD(elem)>("elem","elem");
		addField<DAS_BIND_MANAGED_FIELD(elem_count)>("elem_count","elem_count");
	}
};

// from flecs/addons/meta.h:635:16
struct ecs_meta_cursor_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_meta_cursor_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_meta_cursor_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_meta_cursor_t", ml, "ecs_meta_cursor_t") {
	}
	void init () {
		addField<ecs_world_t *,offsetof(ManagedType,world)>("world","world")
			.adjustAot("das_reinterpret<ecs_world_t *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(scope)>("scope","scope");
		addField<DAS_BIND_MANAGED_FIELD(depth)>("depth","depth");
		addField<DAS_BIND_MANAGED_FIELD(valid)>("valid","valid");
		addField<DAS_BIND_MANAGED_FIELD(is_primitive_scope)>("is_primitive_scope","is_primitive_scope");
		addField<DAS_BIND_MANAGED_FIELD(lookup_ctx)>("lookup_ctx","lookup_ctx");
	}
};

// from flecs/addons/meta.h:1468:16
struct ecs_primitive_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_primitive_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_primitive_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_primitive_desc_t", ml, "ecs_primitive_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(kind)>("kind","kind");
	}
};

// from flecs/addons/meta.h:1486:16
struct ecs_enum_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_enum_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_enum_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_enum_desc_t", ml, "ecs_enum_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(constants)>("constants","constants");
		addField<DAS_BIND_MANAGED_FIELD(underlying_type)>("underlying_type","underlying_type");
	}
};

// from flecs/addons/meta.h:1505:16
struct ecs_bitmask_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_bitmask_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_bitmask_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_bitmask_desc_t", ml, "ecs_bitmask_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(constants)>("constants","constants");
	}
};

// from flecs/addons/meta.h:1523:16
struct ecs_array_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_array_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_array_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_array_desc_t", ml, "ecs_array_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
		addField<DAS_BIND_MANAGED_FIELD(count)>("count","count");
	}
};

// from flecs/addons/meta.h:1542:16
struct ecs_vector_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_vector_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_vector_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_vector_desc_t", ml, "ecs_vector_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
	}
};

// from flecs/addons/meta.h:1560:16
struct ecs_map_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_map_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_map_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_map_desc_t", ml, "ecs_map_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(key_type)>("key_type","key_type");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
	}
};

// from flecs/addons/meta.h:1579:16
struct ecs_struct_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_struct_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_struct_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_struct_desc_t", ml, "ecs_struct_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(members)>("members","members");
		addField<DAS_BIND_MANAGED_FIELD(create_member_entities)>("create_member_entities","create_member_entities");
	}
};

// from flecs/addons/meta.h:1637:16
struct ecs_opaque_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_opaque_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_opaque_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_opaque_desc_t", ml, "ecs_opaque_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<DAS_BIND_MANAGED_FIELD(type)>("_type","type");
	}
};

// from flecs/addons/meta.h:1671:16
struct ecs_unit_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_unit_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_unit_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_unit_desc_t", ml, "ecs_unit_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<char *,offsetof(ManagedType,symbol)>("symbol","symbol")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(quantity)>("quantity","quantity");
		addField<DAS_BIND_MANAGED_FIELD(base)>("base","base");
		addField<DAS_BIND_MANAGED_FIELD(over)>("over","over");
		addField<DAS_BIND_MANAGED_FIELD(translation)>("translation","translation");
		addField<DAS_BIND_MANAGED_FIELD(prefix)>("prefix","prefix");
	}
};

// from flecs/addons/meta.h:1712:16
struct ecs_unit_prefix_desc_t_GeneratedAnnotation : ManagedStructureAnnotation<ecs_unit_prefix_desc_t> {
	virtual bool isLocal() const override { return true; }
	virtual bool canBePlacedInContainer() const override { return true; }
	virtual bool hasNonTrivialCtor() const override { return false; }
	virtual bool canCopy() const override { return true; }
	ecs_unit_prefix_desc_t_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("ecs_unit_prefix_desc_t", ml, "ecs_unit_prefix_desc_t") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(entity)>("entity","entity");
		addField<char *,offsetof(ManagedType,symbol)>("symbol","symbol")
			.adjustAot("das_reinterpret<char *>::pass(",")");
		addField<DAS_BIND_MANAGED_FIELD(translation)>("translation","translation");
	}
};

