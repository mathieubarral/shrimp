#include "shrimp_parser.h"

shrimp_token_t expect_token(shrimp_token_node_t **node, shrimp_token_type type)
{
    shrimp_token_t tmp = {0};

    const char *expected_type = get_token_type_str(type);
    const char *type_str = get_token_type_str((*node)->token.type);

    if ((*node)->token.type != type)
        shrimp_log(SHRIMP_FATAL, "%zu:%zu -> expected token type '%s' got '%s'", (*node)->token.pos.line, (*node)->token.pos.col, expected_type, type_str);

    tmp = (*node)->token;

    (*node) = (*node)->next;
    return (tmp);
}