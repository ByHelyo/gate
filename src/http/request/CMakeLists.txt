set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/http/request/request.h")

add_library(request
        request.c
        ${HEADER_LIST})

target_link_libraries(request PRIVATE
        vector
)

target_include_directories(request PUBLIC ${gate_SOURCE_DIR}/include)
