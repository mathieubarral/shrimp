#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_symbol(shrimp_lexer_t *lexer)
{
    shrimp_token_type_list_t token_list[SHRIMP_SYMBOL_SIZE] = {
        {"(", SHRIMP_TOKEN_SYMBOL_OPEN_PAR},
        {")", SHRIMP_TOKEN_SYMBOL_CLOSE_PAR},
        {"{", SHRIMP_TOKEN_SYMBOL_OPEN_CURL},
        {"}", SHRIMP_TOKEN_SYMBOL_CLOSE_CURL},
        {"[", SHRIMP_TOKEN_SYMBOL_OPEN_BRACKET},
        {"]", SHRIMP_TOKEN_SYMBOL_CLOSE_BRACKET},
        {";", SHRIMP_TOKEN_SYMBOL_SEMICOLON},
        {",", SHRIMP_TOKEN_SYMBOL_COLON},
        {"&", SHRIMP_TOKEN_SYMBOL_REFERENCE}
    };

    for (int index = 0; index < SHRIMP_SYMBOL_SIZE; index++) {
        if (*lexer->buffer == *token_list[index].value) {
            dump_token_len(lexer, 1);
            buffer_forward(lexer, 1);
            return (create_new_token_node(lexer, token_list[index].type));
        }
    }

    return (NULL);
}