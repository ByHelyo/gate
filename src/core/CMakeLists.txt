set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/core/core.h")

add_library(core
        core.c
        ${HEADER_LIST})

target_link_libraries(core PRIVATE
        event)

target_include_directories(core PUBLIC ${gate_SOURCE_DIR}/include)
