add_executable(test_vector
        vector.cpp)

target_link_libraries(test_vector PRIVATE
        GTest::gtest_main
        vector)
