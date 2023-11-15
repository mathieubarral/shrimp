#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_id(shrimp_lexer_t *lexer)
{
    dump_token_tester(lexer, isalnum);

    if (!lexer->token) return (NULL);

    buffer_forward(lexer, strlen(lexer->token));
    return (create_new_token_node(lexer, SHRIMP_TOKEN_TYPE_ID));
}