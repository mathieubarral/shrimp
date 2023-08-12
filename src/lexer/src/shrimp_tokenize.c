#include "shrimp_lexer.h"

// TODO: Implement comments handling

void print_token_list(shrimp_lexer_t *lexer)
{
    const char *token_type_str = NULL;
    const char *token_kind_str = NULL;

    for (shrimp_token_node_t *tmp = lexer->token_list; tmp; tmp = tmp->next) {
        token_type_str = get_token_type_str(tmp->type);
        token_kind_str = get_token_kind_str(tmp->type, tmp->token.kind);
        fprintf(stdout, "token: '%s'\t\t%s\t\t%s\n", tmp->token.value, token_type_str, token_kind_str);
    }
}

void shrimp_tokenize(shrimp_lexer_t *lexer)
{
    shrimp_token_node_t *ret = NULL;
    shrimp_token_node_t *(*func_list[5])(shrimp_lexer_t *lexer) = {
        check_is_symbol,
        check_is_operator,
        check_is_literal,
        check_is_keyword,
        check_is_id
    };

    while (*lexer->buffer) {
        for (; isspace(*lexer->buffer); lexer->buffer++);
        for (int index = 0; index < 5; index++) {
            if ((ret = func_list[index](lexer))) {
                push_to_token_list(lexer, ret);
                break;
            }
        }
        if (!ret) lexer->buffer++;
        free(lexer->token);
        lexer->token = NULL;
        ret = NULL;
    }

    #ifdef DEBUG_MODE
    print_token_list(lexer);
    #endif
}