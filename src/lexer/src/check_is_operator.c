#include "shrimp_lexer.h"

int try_match_token(char *token, shrimp_token_kind_list_t *token_list, int list_size)
{
    for (int index = 0; index < list_size; index++) {
        if (!strcmp(token, token_list[index].value))
            return (index);
    }

    return (-1);
}

shrimp_token_node_t *check_is_operator(shrimp_lexer_t *lexer)
{
    int ret = 0;
    shrimp_token_kind_list_t token_list[20] = {
        {"::", SHRIMP_TOKEN_KIND_LINK},
        {"!=", SHRIMP_TOKEN_KIND_INV_EQU},
        {"==", SHRIMP_TOKEN_KIND_EQU_EQU},
        {"<=", SHRIMP_TOKEN_KIND_LESS_EQU},
        {">=", SHRIMP_TOKEN_KIND_GREAT_EQU},
        {"+=", SHRIMP_TOKEN_KIND_PLUS_EQU},
        {"-=", SHRIMP_TOKEN_KIND_MINUS_EQU},
        {"*=", SHRIMP_TOKEN_KIND_MULT_EQU},
        {"/=", SHRIMP_TOKEN_KIND_DIV_EQU},
        {"@", SHRIMP_TOKEN_KIND_AT},
        {".", SHRIMP_TOKEN_KIND_DOT},
        {":", SHRIMP_TOKEN_KIND_BIND},
        {"=", SHRIMP_TOKEN_KIND_EQUAL},
        {"+", SHRIMP_TOKEN_KIND_PLUS},
        {"-", SHRIMP_TOKEN_KIND_MINUS},
        {"*", SHRIMP_TOKEN_KIND_MULTIPLY},
        {"/", SHRIMP_TOKEN_KIND_DIVIDE},
        {"<", SHRIMP_TOKEN_KIND_LESS},
        {">", SHRIMP_TOKEN_KIND_GREAT},
        {"!", SHRIMP_TOKEN_KIND_INVERT},
    };

    for (int index = 0; index < 20; index++) {
        if (*lexer->buffer == *token_list[index].value) {
            dump_token_len(lexer, strlen(token_list[index].value));
            if ((ret = try_match_token(lexer->token, token_list, 20)) > -1) {
                lexer->buffer += strlen(lexer->token);
                return (create_new_token_node(SHRIMP_TOKEN_TYPE_OPERATOR, token_list[ret].kind, token_list[ret].value));
            }
        }
    }

    return (NULL);
}