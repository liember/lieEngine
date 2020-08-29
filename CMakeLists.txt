cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_NAME lieEngine)

set(SOURCES src/core.cpp src/test.cpp src/view_core.cpp)
include_directories(include)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)