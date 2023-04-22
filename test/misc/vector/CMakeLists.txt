add_executable(test
        vector.cpp)

target_link_libraries(test PRIVATE
        GTest::gtest_main
        vector)
