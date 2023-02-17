find_package(GTest)

add_executable(test
        misc/vector/vector.cpp)
target_link_libraries(test PRIVATE
        GTest::gtest_main
        vector)