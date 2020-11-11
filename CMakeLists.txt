cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_NAME lieEngine)
set(SOURCES src/test.cpp)
set(COMMON ${CMAKE_CURRENT_SOURCE_DIR}/common)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_subdirectory(core)
target_link_libraries(${PROJECT_NAME} core)

add_subdirectory(core_view)
target_link_libraries(${PROJECT_NAME} core_view)

