#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_symbol(shrimp_lexer_t *lexer)
{
    shrimp_token_kind_list_t token_list[SHRIMP_SYMBOL_ENUM_SIZE] = {
        {"(", SHRIMP_TOKEN_KIND_OPEN_PAR},
        {")", SHRIMP_TOKEN_KIND_CLOSE_PAR},
        {"{", SHRIMP_TOKEN_KIND_OPEN_CURL},
        {"}", SHRIMP_TOKEN_KIND_CLOSE_CURL},
        {"[", SHRIMP_TOKEN_KIND_OPEN_BRACKET},
        {"]", SHRIMP_TOKEN_KIND_CLOSE_BRACKET},
        {";", SHRIMP_TOKEN_KIND_SEMICOLON},
        {",", SHRIMP_TOKEN_KIND_COLON},
        {"&", SHRIMP_TOKEN_KIND_REFERENCE}
    };

    for (int index = 0; index < SHRIMP_SYMBOL_ENUM_SIZE; index++) {
        if (*lexer->buffer == *token_list[index].value) {
            lexer->buffer++;
            return (create_new_token_node(SHRIMP_TOKEN_TYPE_SYMBOL, token_list[index].kind, token_list[index].value));
        }
    }

    return (NULL);
}