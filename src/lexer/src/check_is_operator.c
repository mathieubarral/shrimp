#include "shrimp_lexer.h"

int try_match_token(char *token, shrimp_token_type_list_t *token_list, int list_size)
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
    shrimp_token_type_list_t token_list[SHRIMP_OPERATOR_SIZE] = {
        {"::", SHRIMP_TOKEN_OPERATOR_LINK},
        {"!=", SHRIMP_TOKEN_OPERATOR_INV_EQU},
        {"==", SHRIMP_TOKEN_OPERATOR_EQU_EQU},
        {"<=", SHRIMP_TOKEN_OPERATOR_LESS_EQU},
        {">=", SHRIMP_TOKEN_OPERATOR_GREAT_EQU},
        {"+=", SHRIMP_TOKEN_OPERATOR_PLUS_EQU},
        {"-=", SHRIMP_TOKEN_OPERATOR_MINUS_EQU},
        {"*=", SHRIMP_TOKEN_OPERATOR_MULT_EQU},
        {"/=", SHRIMP_TOKEN_OPERATOR_DIV_EQU},
        {"@", SHRIMP_TOKEN_OPERATOR_AT},
        {".", SHRIMP_TOKEN_OPERATOR_DOT},
        {":", SHRIMP_TOKEN_OPERATOR_BIND},
        {"=", SHRIMP_TOKEN_OPERATOR_EQUAL},
        {"+", SHRIMP_TOKEN_OPERATOR_PLUS},
        {"-", SHRIMP_TOKEN_OPERATOR_MINUS},
        {"*", SHRIMP_TOKEN_OPERATOR_MULTIPLY},
        {"/", SHRIMP_TOKEN_OPERATOR_DIVIDE},
        {"<", SHRIMP_TOKEN_OPERATOR_LESS},
        {">", SHRIMP_TOKEN_OPERATOR_GREAT},
        {"!", SHRIMP_TOKEN_OPERATOR_INVERT},
    };

    for (int index = 0; index < SHRIMP_OPERATOR_SIZE; index++) {
        if (*lexer->buffer == *token_list[index].value) {
            dump_token_len(lexer, strlen(token_list[index].value));
            if ((ret = try_match_token(lexer->token, token_list, SHRIMP_OPERATOR_SIZE)) > -1) {
                buffer_forward(lexer, strlen(lexer->token));
                return (create_new_token_node(lexer, token_list[ret].type));
            }
        }
    }

    return (NULL);
}