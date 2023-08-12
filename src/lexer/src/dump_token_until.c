#include "shrimp_lexer.h"

void dump_token_until(shrimp_lexer_t *lexer, char delim)
{
    int length = 0;

    for (; lexer->buffer[length] && lexer->buffer[length] != delim; length++);

    if (!lexer->buffer[length])
        shrimp_log(SHRIMP_FATAL, "Error missing expected delimiter '%c'\n", delim);

    if (!length) return;

    lexer->token = calloc(length + 1, sizeof(char));

    for (int index = 0; lexer->buffer[index] && lexer->buffer[index] != delim; index++)
        lexer->token[index] = lexer->buffer[index];
}