options gen2
options indenting = 4

module flecs_boost shared public

//! The dasFlecs convenience layer, one require for all of it:
//!
//!     require flecs/flecs_boost
//!
//! re-exports
//!   flecs          the generated C API
//!   flecs_helpers  free functions mirroring the flecs C macros (ecs_set, ecs_get, ecs_pair, ...)
//!   flecs_cpp      daslang ports of the flecs C++ classes (FlecsWorld, FlecsEntity, builders)
//!   flecs_macros   typed-block query / system / observer macros and [ecs_component]

require flecs public
require flecs/flecs_helpers public
require flecs/flecs_cpp public
require flecs/flecs_macros public
