set(HEADER_LIST
        ${gate_SOURCE_DIR}/include/socket/socket.h
        ${gate_SOURCE_DIR}/include/socket/listener.h)

add_library(socket
        socket.c
        listener.c
        ${HEADER_LIST})

target_include_directories(socket PUBLIC ${gate_SOURCE_DIR}/include)

