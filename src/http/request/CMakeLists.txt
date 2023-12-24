set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/http/request/request.h"
        "${gate_SOURCE_DIR}/include/http/request/method.h"
        "${gate_SOURCE_DIR}/include/http/request/misc.h"
        "${gate_SOURCE_DIR}/include/http/request/origin_form.h"
        "${gate_SOURCE_DIR}/include/http/request/segment.h"
        "${gate_SOURCE_DIR}/include/http/request/absolute_path.h"
        "${gate_SOURCE_DIR}/include/http/request/pchar.h"
        "${gate_SOURCE_DIR}/include/http/request/unreserved.h"
        "${gate_SOURCE_DIR}/include/http/request/pct_encoded.h"
        "${gate_SOURCE_DIR}/include/http/request/sub_delims.h"
        "${gate_SOURCE_DIR}/include/http/request/query.h"
        "${gate_SOURCE_DIR}/include/http/request/absolute_form.h"
        "${gate_SOURCE_DIR}/include/http/request/absolute_uri.h"
        "${gate_SOURCE_DIR}/include/http/request/scheme.h"
        "${gate_SOURCE_DIR}/include/http/request/hier_part.h"
        "${gate_SOURCE_DIR}/include/http/request/authority.h"
        "${gate_SOURCE_DIR}/include/http/request/userinfo.h"
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
        pct_encoded.c
        sub_delims.c
        query.c
        absolute_form.c
        absolute_uri.c
        scheme.c
        hier_part.c
        authority.c
        userinfo.c
        ${HEADER_LIST})

target_link_libraries(request PRIVATE
        vector
        trie
)

target_include_directories(request PUBLIC ${gate_SOURCE_DIR}/include)
