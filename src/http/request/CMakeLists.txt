set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/http/request/request.h"
        "${gate_SOURCE_DIR}/include/http/request/method.h"
        "${gate_SOURCE_DIR}/include/http/request/misc.h"
        "${gate_SOURCE_DIR}/include/http/request/origin_form.h"
        "${gate_SOURCE_DIR}/include/http/request/segment.h"
        "${gate_SOURCE_DIR}/include/http/request/absolute_path.h"
        "${gate_SOURCE_DIR}/include/http/request/pchar.h"
        "${gate_SOURCE_DIR}/include/http/request/unreserved.h"
)

add_library(request
        request.c
        method.c
        misc.c
        request_target.c
        origin_form.c
        segment.c
        absolute_path.c
        pchar.c
        unreserved.c
        ${HEADER_LIST})

target_link_libraries(request PRIVATE
        vector
        trie
)

target_include_directories(request PUBLIC ${gate_SOURCE_DIR}/include)
