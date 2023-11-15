file(GLOB parser_src "src/*.c")
add_library(parser STATIC ${parser_src})
set_target_properties(parser PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "bin")