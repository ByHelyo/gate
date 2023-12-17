set(HEADER_LIST
        "${gate_SOURCE_DIR}/include/misc/trie/trie.h")

add_library(trie
        trie.c
        ${HEADER_LIST}
)

target_link_libraries(trie PRIVATE
        vector
)

target_include_directories(trie PUBLIC ${gate_SOURCE_DIR}/include)