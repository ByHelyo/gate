set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/misc/vector/vector.h"
        "${gate_SOURCE_DIR}/include/misc/vector/iter.h")

add_library(vector
        vector.c
        iter.c
        ${HEADER_LIST})

target_link_libraries(vector PRIVATE
        math
        logger
        )

target_include_directories(vector PUBLIC ${gate_SOURCE_DIR}/include)