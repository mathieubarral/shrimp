#include "shrimp_lexer.h"

shrimp_token_node_t *check_is_keyword(shrimp_lexer_t *lexer)
{
    shrimp_token_kind_list_t token_list[13] = {
        {"import", SHRIMP_TOKEN_KIND_IMPORT},
        {"as", SHRIMP_TOKEN_KIND_AS},
        {"funcdef", SHRIMP_TOKEN_KIND_FUNCDEF},
        {"funcref", SHRIMP_TOKEN_KIND_FUNCREF},
        {"typedef", SHRIMP_TOKEN_KIND_TYPEDEF},
        {"if", SHRIMP_TOKEN_KIND_IF},
        {"elif", SHRIMP_TOKEN_KIND_ELIF},
        {"else", SHRIMP_TOKEN_KIND_ELSE},
        {"for", SHRIMP_TOKEN_KIND_FOR},
        {"while", SHRIMP_TOKEN_KIND_WHILE},
        {"return", SHRIMP_TOKEN_KIND_RETURN},
        {"new", SHRIMP_TOKEN_KIND_NEW},
        {"undef", SHRIMP_TOKEN_KIND_UNDEF}
    };

    dump_token_tester(lexer, isalpha);

    if (!lexer->token) return (NULL);

    for (int index = 0; index < 13; index++) {
        if (!strcmp(lexer->token, token_list[index].value)) {
            lexer->buffer += strlen(lexer->token);
            return (create_new_token_node(SHRIMP_TOKEN_TYPE_KEYWORD, token_list[index].kind, lexer->token));
        }
    }

    return (NULL);
}