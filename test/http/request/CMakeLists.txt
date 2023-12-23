add_executable(test_request
        unreserved.cpp
        pchar.cpp)

target_link_libraries(test_request PRIVATE
        GTest::gtest_main
        request
)
