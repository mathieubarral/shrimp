file(GLOB lexer_src "src/*.c")
add_library(lexer STATIC ${lexer_src})
set_target_properties(lexer PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "bin")