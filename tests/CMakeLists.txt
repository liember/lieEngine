project(test)

add_executable(test main.cpp)

add_subdirectory(googletest)

target_link_libraries(
        gtest_main
)
