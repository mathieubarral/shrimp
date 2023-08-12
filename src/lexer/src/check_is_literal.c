#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_lit_str(shrimp_lexer_t *lexer)
{
    shrimp_token_node_t *ret = NULL;

    if (*lexer->buffer != '\"') return (NULL);
    lexer->buffer++;
    dump_token_until(lexer, '\"');

    if (!lexer->token) return (NULL);
    lexer->buffer += strlen(lexer->token);
    lexer->buffer++;
    return (create_new_token_node(SHRIMP_TOKEN_TYPE_LIT_STRING, (shrimp_token_kind) 0, lexer->token));
}

shrimp_token_node_t *check_is_lit_num(shrimp_lexer_t *lexer)
{
    dump_token_tester(lexer, isdigit);

    if (!lexer->token) return (NULL);
    lexer->buffer += strlen(lexer->token);
    return (create_new_token_node(SHRIMP_TOKEN_TYPE_LIT_INT, (shrimp_token_kind) 0, lexer->token));
}

shrimp_token_node_t *check_is_literal(shrimp_lexer_t *lexer)
{
    shrimp_token_node_t *ret = NULL;
    shrimp_token_node_t *(*func_ptr[2])(shrimp_lexer_t *lexer) = {
        check_is_lit_str,
        check_is_lit_num
    };

    for (int index = 0; index < 2; index++)
        if ((ret = func_ptr[index](lexer))) return (ret);

    return (NULL);
}