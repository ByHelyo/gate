cmake_minimum_required(VERSION 3.24)
project(gate
        VERSION 1.0
        DESCRIPTION "HTTP reverse proxy"
        LANGUAGES C CXX)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(
        -DLOG_USE_COLOR
)

add_compile_options(
        -Werror
        -Wall
        -Wextra
        -g3
        -pedantic
        -Wpedantic
        -fsanitize=address
        -Wdocumentation
        -Wshadow
        -Wdouble-promotion
        #-Wformat=2
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

find_package(Doxygen)
if (Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found, not building docs")
endif()

find_package(GTest)
if(GTest_FOUND)
    add_subdirectory(test)
else()
    message(STATUS "GTest not found, not building test")
endif()

add_subdirectory(app)
add_subdirectory(src)