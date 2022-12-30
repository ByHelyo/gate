set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/event/event.h")

add_library(event
        event.c
        ${HEADER_LIST})

target_link_libraries(event PRIVATE
        socket)

target_include_directories(event PUBLIC ${gate_SOURCE_DIR}/include)

