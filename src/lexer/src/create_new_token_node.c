#include "shrimp_lexer.h"

shrimp_token_node_t *create_new_token_node(shrimp_lexer_t *lexer, shrimp_token_type type)
{
    shrimp_token_node_t *new_node = calloc(1, sizeof(shrimp_token_node_t));

    new_node->token.type = type;
    new_node->token.value = strdup(lexer->token);
    new_node->token.size = strlen(lexer->token);
    new_node->token.pos.line = lexer->pos.line;
    new_node->token.pos.col = lexer->pos.col;

    new_node->next = NULL;

    return (new_node);
}