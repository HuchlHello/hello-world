cmake_minimum_required(VERSION 3.10)
project(TestQtUi LANGUAGES CXX)

message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "Generator: ${CMAKE_GENERATOR}")
message(STATUS "Source dir: ${CMAKE_SOURCE_DIR}")
message(STATUS "Binary dir: ${CMAKE_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "C++ standard required: ${CMAKE_CXX_STANDARD_REQUIRED}")
message(STATUS "Project name: ${PROJECT_NAME}")

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
set(QT_VERSION_MAJOR 6)

# Enable Qt automoc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME} main.cpp)
message(STATUS "Executable target added: ${PROJECT_NAME}")

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)
