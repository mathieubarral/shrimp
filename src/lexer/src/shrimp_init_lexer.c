#include "shrimp_lexer.h"

void shrimp_init_lexer(shrimp_lexer_t *lexer, shrimp_file_t file)
{
    size_t buffer_size = strlen(file.buffer);

    shrimp_log(SHRIMP_DEBUG, "Initialize lexer...");

    lexer->pos.line = 1;
    lexer->pos.col = 1;
    lexer->token = NULL;
    lexer->buffer = strdup(file.buffer);

    shrimp_log(SHRIMP_DEBUG, "Lexer initialized with buffer size: %d", buffer_size);
}