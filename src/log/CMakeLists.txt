file(GLOB log_src "src/*.c")
add_library(log STATIC ${log_src})
set_target_properties(log PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "bin")