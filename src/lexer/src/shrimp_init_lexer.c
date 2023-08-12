#include "shrimp_lexer.h"

void shrimp_init_lexer(shrimp_lexer_t *lexer, shrimp_file_t file)
{
    shrimp_log(SHRIMP_DEBUG, "Initialize lexer...");

    lexer->token = NULL;
    lexer->buffer = strdup(file.buffer);
    lexer->buffer_size = strlen(file.buffer);

    shrimp_log(SHRIMP_DEBUG, "Lexer initialized with buffer size: %d", lexer->buffer_size);
}