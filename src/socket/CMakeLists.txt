set(HEADER_LIST "${gate_SOURCE_DIR}/include/socket/socket.h")

add_library(socket socket.c ${HEADER_LIST})

target_include_directories(socket PUBLIC ${gate_SOURCE_DIR}/include)

