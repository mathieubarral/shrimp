#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_keyword(shrimp_lexer_t *lexer)
{
    shrimp_token_type_list_t token_list[SHRIMP_KEYWORD_SIZE] = {
        {"import", SHRIMP_TOKEN_KEYWORD_IMPORT},
        {"as", SHRIMP_TOKEN_KEYWORD_AS},
        {"funcdef", SHRIMP_TOKEN_KEYWORD_FUNCDEF},
        {"funcref", SHRIMP_TOKEN_KEYWORD_FUNCREF},
        {"typedef", SHRIMP_TOKEN_KEYWORD_TYPEDEF},
        {"if", SHRIMP_TOKEN_KEYWORD_IF},
        {"elif", SHRIMP_TOKEN_KEYWORD_ELIF},
        {"else", SHRIMP_TOKEN_KEYWORD_ELSE},
        {"for", SHRIMP_TOKEN_KEYWORD_FOR},
        {"while", SHRIMP_TOKEN_KEYWORD_WHILE},
        {"return", SHRIMP_TOKEN_KEYWORD_RETURN},
        {"new", SHRIMP_TOKEN_KEYWORD_NEW},
        {"undef", SHRIMP_TOKEN_KEYWORD_UNDEF}
    };

    dump_token_tester(lexer, isalpha);

    if (!lexer->token) return (NULL);

    for (int index = 0; index < SHRIMP_KEYWORD_SIZE; index++) {
        if (!strcmp(lexer->token, token_list[index].value)) {
            buffer_forward(lexer, strlen(lexer->token));
            return (create_new_token_node(lexer, token_list[index].type));
        }
    }

    return (NULL);
}