cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_NAME lieEngine)
set(COMMON ${CMAKE_CURRENT_SOURCE_DIR}/common)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${PROJECT_NAME})

add_subdirectory(core)
add_subdirectory(core_view)
add_subdirectory(tests)