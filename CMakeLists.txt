cmake_minimum_required(VERSION 3.23)
project(gate
        VERSION 1.0
        DESCRIPTION "HTTP reverse proxy"
        LANGUAGES C)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 99)

add_compile_options(
        -Werror
        -Wall
        -Wextra
        -g3
        -pedantic
        -Wpedantic
        -fsanitize=address
        -Weverything
        -Wdocumentation
        -Wshadow
        -Wdouble-promotion
        -Wformat=2
        -Wundef
        -fno-common
        -Wconversion
        -Wpointer-arith
        -Wcast-align
        -Wstrict-prototypes
        -Wstrict-overflow=5
        -Wwrite-strings
        -Waggregate-return
        -Wcast-qual
        -Wswitch-default
        -Wswitch-enum
        -Wunreachable-code
)
add_link_options(-fsanitize=address)

add_subdirectory(src)
