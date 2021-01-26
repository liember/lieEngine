project(test)

add_executable(test main.cpp PQTree_test.cpp Quadrant_test.cpp Vector2d_test.cpp)

add_subdirectory(googletest)

target_link_libraries(test
        gtest_main
)
