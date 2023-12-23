add_executable(test_request
        unreserved.cpp
        pct_encoded.cpp
        sub_delims.cpp
        pchar.cpp)

target_link_libraries(test_request PRIVATE
        GTest::gtest_main
        request
)
