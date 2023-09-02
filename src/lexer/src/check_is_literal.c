#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_lit_char(shrimp_lexer_t *lexer)
{
    shrimp_token_node_t *ret = NULL;

    if (*lexer->buffer != '\'') return (NULL);
    lexer->buffer++;
    dump_token_delim(lexer, '\'');

    if (!lexer->token) return (NULL);
    if (strlen(lexer->token) > 1)
        shrimp_log(SHRIMP_FATAL, "'%s' multi-character literal character", lexer->token);
    lexer->buffer += strlen(lexer->token);
    lexer->buffer++;
    return (create_new_token_node(SHRIMP_TOKEN_TYPE_LIT_CHAR, (shrimp_token_kind) 0, lexer->token));
}

shrimp_token_node_t *check_is_lit_str(shrimp_lexer_t *lexer)
{
    shrimp_token_node_t *ret = NULL;

    if (*lexer->buffer != '\"') return (NULL);
    lexer->buffer++;
    dump_token_delim(lexer, '\"');

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
    shrimp_token_node_t *(*func_ptr[])(shrimp_lexer_t *lexer) = {
        check_is_lit_char,
        check_is_lit_str,
        check_is_lit_num,
        NULL
    };

    for (int index = 0; func_ptr[index]; index++)
        if ((ret = func_ptr[index](lexer))) return (ret);

    return (NULL);
}