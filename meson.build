project('shrimp', 'c', version: '1.0.0')

if get_option('buildtype') == 'debug'
  add_project_arguments('-DDEBUG_MODE', language: 'c')
endif

shrimp_includes = [
    include_directories('include'),
    include_directories('src/io/include'),
    include_directories('src/lexer/include'),
    include_directories('src/logger/include'),
    include_directories('src/parser/include')
]

subdir('src/logger')
subdir('src/io')
subdir('src/lexer')
subdir('src/parser')

shrimp_lib = [parser, lexer, io, logger]

executable('shrimp', 'src/shrimp.c', include_directories: shrimp_includes, link_with: shrimp_lib)