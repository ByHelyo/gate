set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/logger/log.h")

add_library(logger
        log.c
        ${HEADER_LIST})

target_include_directories(logger PUBLIC ${gate_SOURCE_DIR}/include)