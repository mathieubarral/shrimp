#include "shrimp_lexer.h"

void dump_token_tester(shrimp_lexer_t *lexer, int (*tester)(int))
{
    int length = 0;

    for (; lexer->buffer[length] && tester(lexer->buffer[length]); length++);

    if (!length) return;

    lexer->token = calloc(length + 1, sizeof(char));

    for (int index = 0; lexer->buffer[index] && tester(lexer->buffer[index]); index++)
        lexer->token[index] = lexer->buffer[index];
}