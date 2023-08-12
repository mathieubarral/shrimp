file(GLOB io_src "src/*.c")
add_library(io STATIC ${io_src})
target_link_libraries(io log)
set_target_properties(io PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "bin")