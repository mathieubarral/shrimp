#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_lit_char(shrimp_lexer_t *lexer)
{
    shrimp_token_node_t *ret = NULL;

    if (*lexer->buffer != '\'') return (NULL);

    buffer_forward(lexer, 1);
    lexer->pos.col++;

    dump_token_delim(lexer, '\'');

    if (!lexer->token) return (NULL);
    if (strlen(lexer->token) > 1)
        shrimp_log(SHRIMP_FATAL, "%zu:%zu -> '%s' multi-character literal character", lexer->pos.line, lexer->pos.col, lexer->token);
    buffer_forward(lexer, strlen(lexer->token) + 1);
    ret = create_new_token_node(lexer, SHRIMP_TOKEN_TYPE_LIT_CHAR);
    lexer->pos.col++;
    return (ret);
}

shrimp_token_node_t *check_is_lit_str(shrimp_lexer_t *lexer)
{
    shrimp_token_node_t *ret = NULL;

    if (*lexer->buffer != '\"') return (NULL);

    buffer_forward(lexer, 1);
    lexer->pos.col++;

    dump_token_delim(lexer, '\"');

    if (!lexer->token) return (NULL);
    buffer_forward(lexer, strlen(lexer->token) + 1);
    ret = create_new_token_node(lexer, SHRIMP_TOKEN_TYPE_LIT_STRING);
    lexer->pos.col++;
    return (ret);
}

shrimp_token_node_t *check_is_lit_num(shrimp_lexer_t *lexer)
{
    dump_token_tester(lexer, isdigit);

    if (!lexer->token) return (NULL);

    buffer_forward(lexer, strlen(lexer->token));
    return (create_new_token_node(lexer, SHRIMP_TOKEN_TYPE_LIT_INT));
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