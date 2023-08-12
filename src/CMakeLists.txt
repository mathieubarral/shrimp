add_subdirectory("log")
add_subdirectory("io")
add_subdirectory("lexer")

file(GLOB shrimp_src "*.c")
add_executable(shrimp ${shrimp_src})
target_link_libraries(shrimp lexer io log)
set_target_properties(shrimp PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")