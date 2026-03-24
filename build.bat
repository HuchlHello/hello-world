@echo off
REM Build script for TestQtUi project using MSYS2 MinGW

REM Set MSYS2 paths (adjust if your MSYS2 is installed elsewhere)
set MSYS2_ROOT=D:\msys64
set PATH=%MSYS2_ROOT%\mingw64\bin;%MSYS2_ROOT%\usr\bin;%PATH%

REM Clean previous build
if exist build rmdir /s /q build

REM Configure with CMake, explicitly set compilers and make program
cmake -G "MinGW Makefiles" -S . -B build ^
  -DCMAKE_MAKE_PROGRAM="%MSYS2_ROOT%\mingw64\bin\mingw32-make.exe" ^
  -DCMAKE_C_COMPILER="%MSYS2_ROOT%\mingw64\bin\gcc.exe" ^
  -DCMAKE_CXX_COMPILER="%MSYS2_ROOT%\mingw64\bin\g++.exe"
if %errorlevel% neq 0 goto :error

REM Build
cmake --build build
if %errorlevel% neq 0 goto :error

echo Build successful!
goto :end

:error
echo Build failed!
pause

:end