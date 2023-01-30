set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/misc/vector/vector.h")

add_library(vector
        vector.c
        ${HEADER_LIST})

target_include_directories(vector PUBLIC ${gate_SOURCE_DIR}/include)

