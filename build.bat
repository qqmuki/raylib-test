@echo off
cd emsdk
call emsdk_env.bat
cd ..
emcc -o index.html raylib-test.c -Os -Wall -I.\raylib\raylib-5.0_webassembly\include -L.\raylib\raylib-5.0_webassembly\lib -lraylib -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB --shell-file minshell.html
if %ERRORLEVEL% equ 0 (
    echo Compilation successful!
) else (
    echo Compilation failed.
)
