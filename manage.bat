@echo off
rem cmd.exe version of manage.sh. Same commands, same environment variables.
setlocal EnableExtensions EnableDelayedExpansion

set "SCRIPT_DIR=%~dp0"
if "%SCRIPT_DIR:~-1%"=="\" set "SCRIPT_DIR=%SCRIPT_DIR:~0,-1%"

rem daslang install the module is built against. Scripts must run with this same daslang.
if not defined DASLANG_DIR set "DASLANG_DIR=C:\Programs\daslang"
if not defined LIBCLANG_DIR set "LIBCLANG_DIR=C:\Programs\libClang"
if not defined CMAKE_GENERATOR_NAME set "CMAKE_GENERATOR_NAME=Visual Studio 18 2026"
rem Optional local flecs checkout; empty = the build fetches the pinned tag.

set "DASLANG=%DASLANG_DIR%\bin\Release\daslang.exe"
set "DASFLECS_DIR=%SCRIPT_DIR%\dasFlecs"
set "BUILD_DIR=%SCRIPT_DIR%\_build"

rem No cmake on PATH: fall back to the one bundled with Visual Studio.
where cmake >nul 2>&1 || call :find_vs_cmake

set "CMD=%~1"
rem Everything after the command, passed through to run / fmt.
set "REST="
:collect_args
shift
if "%~1"=="" goto :dispatch
set REST=!REST! %1
goto :collect_args

:dispatch
if "%CMD%"==""         goto :usage
if /i "%CMD%"=="help"  goto :usage
if /i "%CMD%"=="gen"   goto :cmd_gen
if /i "%CMD%"=="build" goto :cmd_build
if /i "%CMD%"=="run"   goto :cmd_run
if /i "%CMD%"=="test"  goto :cmd_test
if /i "%CMD%"=="fmt"   goto :cmd_fmt
if /i "%CMD%"=="examples" goto :cmd_examples
echo Unknown command: %CMD%
call :print_usage
exit /b 1

:usage
call :print_usage
exit /b 0

:print_usage
echo Usage: %~nx0 ^<command^> [args]
echo.
echo Commands:
echo   gen                Regenerate dasFlecs\src\* from the flecs headers with dasClangBind
echo                      Uses %%DASLANG_DIR%%, %%LIBCLANG_DIR%%; %%FLECS_DIR%% is optional (default: the fetched flecs)
echo   build              Fetch flecs and build _build\Release\dasModuleFlecsGen.shared_module
echo   run [script.das]   Run a script with dasFlecs loaded (default: dasFlecs\examples\hello_flecs.das)
echo   test               Run the tests\ suites
echo   examples [filter]  Run dasFlecs\examples\^<category^>\*.das and compare with their // Output: blocks
echo   fmt [--verify]     Format the .das sources in place; with --verify, only report differences
echo   help               Show this help message
echo.
echo After a flecs update: gen, build, test.
exit /b 0

:find_vs_cmake
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" exit /b 0
for /f "usebackq delims=" %%i in (`"%VSWHERE%" -latest -prerelease -property installationPath`) do set "VS_PATH=%%i"
set "VS_CMAKE=%VS_PATH%\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin"
if exist "%VS_CMAKE%\cmake.exe" set "PATH=%VS_CMAKE%;%PATH%"
exit /b 0

:configure
echo ==^> Configuring dasFlecs (DASLANG_DIR=%DASLANG_DIR%)
set "FLECS_ARG="
if defined FLECS_DIR set "FLECS_ARG=-DFLECS_DIR=%FLECS_DIR%"
cmake -G "%CMAKE_GENERATOR_NAME%" -S "%SCRIPT_DIR%" -B "%BUILD_DIR%" -DDASLANG_DIR="%DASLANG_DIR%" -DCMAKE_BUILD_TYPE=Release %FLECS_ARG%
exit /b %errorlevel%

:cmd_gen
set "GEN_FLECS_DIR=%FLECS_DIR%"
if not defined GEN_FLECS_DIR (
    rem Configuring fetches flecs into _build\_deps\flecs-src
    call :configure || exit /b 1
    set "GEN_FLECS_DIR=%BUILD_DIR%\_deps\flecs-src"
)
rem The binder overwrites dasFlecs\src, so refuse to run against a bad path.
if not exist "%GEN_FLECS_DIR%\include\flecs.h" (
    echo ERROR: %GEN_FLECS_DIR%\include\flecs.h not found. Fix or unset FLECS_DIR.
    exit /b 1
)
rem Drop old function chunks: a smaller API would otherwise leave stale func_N.cpp files behind.
del /q "%DASFLECS_DIR%\src\dasFlecs.func_*.cpp" >nul 2>&1
echo ==^> Generating dasFlecs bindings (daslang: %DASLANG_DIR%, flecs: %GEN_FLECS_DIR%)
set "FLECS_INCLUDE=%GEN_FLECS_DIR%\include"
rem Capture to a file so the binder's exit code survives the [I] log filter.
set "GEN_LOG=%TEMP%\dasFlecs_gen_%RANDOM%.log"
"%DASLANG%" "%DASFLECS_DIR%\bind\bind_flecs.das" > "%GEN_LOG%" 2>&1
set "GEN_RC=%errorlevel%"
findstr /l /v /b /c:"[I]" "%GEN_LOG%"
del "%GEN_LOG%" >nul 2>&1
exit /b %GEN_RC%

:cmd_build
call :configure || exit /b 1
echo ==^> Building
cmake --build "%BUILD_DIR%" --config Release || exit /b 1
echo ==^> Done: %BUILD_DIR%\Release\dasModuleFlecsGen.shared_module
exit /b 0

:cmd_run
set "RUN_SCRIPT=%REST%"
if not defined RUN_SCRIPT set RUN_SCRIPT="%DASFLECS_DIR%\examples\hello_flecs.das"
"%DASLANG%" -load_module "%SCRIPT_DIR%" %RUN_SCRIPT%
exit /b %errorlevel%

:cmd_test
"%DASLANG%" -load_module "%SCRIPT_DIR%" "%DASLANG_DIR%\dastest\dastest.das" -- --test "%SCRIPT_DIR%\tests"
exit /b %errorlevel%

:cmd_examples
"%DASLANG%" "%SCRIPT_DIR%\tools\check_examples.das" -- --root "%SCRIPT_DIR%" --daslang "%DASLANG%" %REST%
exit /b %errorlevel%

:cmd_fmt
"%DASLANG%" "%DASLANG_DIR%\utils\das-fmt\dasfmt.das" -- --path "%DASFLECS_DIR%\flecs" --path "%DASFLECS_DIR%\bind" --path "%DASFLECS_DIR%\examples" --path "%SCRIPT_DIR%\tests" --path "%SCRIPT_DIR%\tools" %REST%
exit /b %errorlevel%
