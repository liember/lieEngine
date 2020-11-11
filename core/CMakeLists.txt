
project(core)				
set(SOURCE_LIB core.cpp core.hpp)
add_library(core STATIC ${SOURCE_LIB})

target_include_directories(core PUBLIC ${COMMON})
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )