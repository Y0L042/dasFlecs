cmake_minimum_required(VERSION 3.22)
project(dasFlecs C CXX)

# Package entry point: `daspkg install` configures this directory with -DDASLANG_DIR=...
# dasFlecs fetches and builds flecs itself, so nothing else has to be installed.
#
#   cmake -S . -B _build -DDASLANG_DIR=C:/path/to/daslang
#   cmake --build _build --config Release
if(NOT DEFINED DASLANG_DIR)
    set(DASLANG_DIR "C:/Programs/daslang")
endif()
add_subdirectory(dasFlecs)
