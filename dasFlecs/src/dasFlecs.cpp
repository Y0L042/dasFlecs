// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/simulate/bind_enum.h"
#include "dasFlecs.h"
#include "need_dasFlecs.h"
#include "dasFlecs.struct.impl.inc"
namespace das {
#include "dasFlecs.enum.class.inc"
#include "dasFlecs.struct.class.inc"
#include "dasFlecs.func.aot.inc"
Module_dasFlecs::Module_dasFlecs() : Module("flecs") {
}
bool Module_dasFlecs::initDependencies() {
	if ( initialized ) return true;
	initialized = true;
	lib.addModule(this);
	lib.addBuiltInModule();
	#include "dasFlecs.const.inc"
	#include "dasFlecs.enum.add.inc"
	#include "dasFlecs.dummy.add.inc"
	#include "dasFlecs.struct.add.inc"
	#include "dasFlecs.struct.postadd.inc"
	#include "dasFlecs.alias.add.inc"
	#include "dasFlecs.func.reg.inc"
	initMain();
	return true;
}
REGISTER_DYN_MODULE(Module_dasFlecs,Module_dasFlecs);
}
REGISTER_MODULE_IN_NAMESPACE(Module_dasFlecs,das);

