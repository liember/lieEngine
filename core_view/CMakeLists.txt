
project(core_view)				
set(SOURCE_LIB core_view.cpp core_view.hpp)
include_directories(${COMMON})
add_library(core_view STATIC ${SOURCE_LIB})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(core_view glfw)

add_subdirectory(external/glad)
target_link_libraries(core_view glad)

target_include_directories(core_view PUBLIC ${COMMON})
target_include_directories(core_view PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )