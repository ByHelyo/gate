set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/event/event.h"
        "${gate_SOURCE_DIR}/include/event/event_data.h")

add_library(event
        event.c
        event_data.c
        ${HEADER_LIST})

target_link_libraries(event PRIVATE
        socket
        logger
        vector)

target_include_directories(event PUBLIC ${gate_SOURCE_DIR}/include)