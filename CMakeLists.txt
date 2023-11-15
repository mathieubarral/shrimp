cmake_minimum_required(VERSION 3.0.0)
project(Shrimp VERSION 0.0.1)

include_directories("include")
include_directories("src/logger/include")
include_directories("src/io/include")
include_directories("src/lexer/include")
include_directories("src/parser/include")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG_MODE)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

add_subdirectory("src")