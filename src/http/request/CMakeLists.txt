set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/http/request/request.h"
        "${gate_SOURCE_DIR}/include/http/request/method.h"
)

add_library(request
        request.c
        method.c
        ${HEADER_LIST})

target_link_libraries(request PRIVATE
        vector
)

target_include_directories(request PUBLIC ${gate_SOURCE_DIR}/include)
