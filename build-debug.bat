@echo off
REM Debug build script for TestQtUi project using MSYS2 MinGW

REM Set MSYS2 paths (adjust if your MSYS2 is installed elsewhere)
set MSYS2_ROOT=D:\msys64
set PATH=%MSYS2_ROOT%\mingw64\bin;%MSYS2_ROOT%\usr\bin;%PATH%

REM Clean previous debug build
if exist build-debug rmdir /s /q build-debug

REM Configure with CMake for debug build explicitly set compilers and make program
cmake -G "MinGW Makefiles" -S . -B build-debug ^
  -DCMAKE_MAKE_PROGRAM="%MSYS2_ROOT%\mingw64\bin\mingw32-make.exe" ^
  -DCMAKE_C_COMPILER="%MSYS2_ROOT%\mingw64\bin\gcc.exe" ^
  -DCMAKE_CXX_COMPILER="%MSYS2_ROOT%\mingw64\bin\g++.exe" ^
  -DCMAKE_BUILD_TYPE=Debug
if %errorlevel% neq 0 goto :error

REM Build
cmake --build build-debug --config Debug
if %errorlevel% neq 0 goto :error

echo Debug build successful!
goto :end

:error
echo Debug build failed!
pause

:end