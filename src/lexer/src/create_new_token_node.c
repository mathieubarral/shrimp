#include "shrimp_lexer.h"

shrimp_token_node_t *create_new_token_node(shrimp_token_type type, shrimp_token_kind kind, const char *value)
{
    shrimp_token_node_t *new_node = calloc(1, sizeof(shrimp_token_node_t));

    new_node->type = type;
    new_node->next = NULL;

    new_node->token.kind = kind;
    new_node->token.value = strdup(value);
    new_node->token.size = strlen(value);

    return (new_node);
}