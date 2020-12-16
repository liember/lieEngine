
project(core)				
set(SOURCE_LIB time_event.hpp base_object.hpp math/vector2d.h math/fractions.h)
add_library(core STATIC ${SOURCE_LIB})

target_link_libraries(core containers)

target_include_directories(core PUBLIC ${COMMON})
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )