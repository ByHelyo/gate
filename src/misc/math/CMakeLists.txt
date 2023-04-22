set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/misc/math/math.h")

add_library(math
        math.c
        ${HEADER_LIST}
)

target_include_directories(math PUBLIC ${gate_SOURCE_DIR}/include)