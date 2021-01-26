cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(PROJECT_NAME lieEngine)
set(CORE ${CMAKE_CURRENT_SOURCE_DIR}/core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${PROJECT_NAME})

include_directories(core/PointedQuadTree)
include_directories(core)

#add_subdirectory(core_view)
add_subdirectory(tests)