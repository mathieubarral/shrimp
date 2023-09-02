#include "shrimp_lexer.h"

const char *get_token_type_str(shrimp_token_type type)
{
    const char *token_str_list[SHRIMP_TOKEN_TYPE_ENUM_SIZE] = {
        "SHRIMP_TOKEN_TYPE_SYMBOL",
        "SHRIMP_TOKEN_TYPE_KEYWORD",
        "SHRIMP_TOKEN_TYPE_OPERATOR",
        "SHRIMP_TOKEN_TYPE_ID",
        "SHRIMP_TOKEN_TYPE_LIT_INT",
        "SHRIMP_TOKEN_TYPE_LIT_CHAR",
        "SHRIMP_TOKEN_TYPE_LIT_STRING"
    };

    return (token_str_list[type]);
}