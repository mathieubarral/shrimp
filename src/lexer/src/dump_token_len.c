#include "shrimp_lexer.h"

void dump_token_len(shrimp_lexer_t *lexer, size_t len)
{
    if (!len) return;

    lexer->token = calloc(len + 1, sizeof(char));

    for (int index = 0; lexer->buffer[index] && index < len; index++)
        lexer->token[index] = lexer->buffer[index];
}