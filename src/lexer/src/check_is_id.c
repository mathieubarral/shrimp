#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_id(shrimp_lexer_t *lexer)
{
    dump_token_tester(lexer, isalnum);

    if (!lexer->token) return (NULL);

    lexer->buffer += strlen(lexer->token);
    return (create_new_token_node(SHRIMP_TOKEN_TYPE_ID, (shrimp_token_kind) 0, lexer->token));
}