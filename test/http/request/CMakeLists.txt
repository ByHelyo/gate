add_executable(test_request
        unreserved.cpp
        pct_encoded.cpp
        sub_delims.cpp
        pchar.cpp
        segment.cpp
        absolute_path.cpp
        origin_form.cpp
        query_parse.cpp
        scheme.cpp
        userinfo.cpp
        h16.cpp
        dec_octet.cpp
        ipv4address.cpp
        ls32.cpp
        ipv6address.cpp
        ipvfuture.cpp
)

target_link_libraries(test_request PRIVATE
        GTest::gtest_main
        request
)
