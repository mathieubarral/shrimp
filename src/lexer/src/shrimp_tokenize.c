#include "shrimp_lexer.h"

void print_token_list(shrimp_lexer_t *lexer)
{
    const char *token_type_str = NULL;
    const char *token_kind_str = NULL;

    for (shrimp_token_node_t *tmp = lexer->token_list; tmp; tmp = tmp->next) {
        token_type_str = get_token_type_str(tmp->type);
        token_kind_str = get_token_kind_str(tmp->type, tmp->token.kind);
        fprintf(stdout, "token: <'%s', %s, %s>\n", tmp->token.value, token_type_str, token_kind_str);
    }
}

bool is_unwanted_char(char curr_char)
{
    char unwanted[4] = {' ', '\t', '\n', '\r'};

    for (int index = 0; index < 4; index++) {
        if (curr_char == unwanted[index])
            return (true);
    }
    return (false);
}

void skip_unwanted(shrimp_lexer_t *lexer)
{
    for (; is_unwanted_char(*lexer->buffer); lexer->buffer++);
    if (*lexer->buffer == '#')
        for (int index = 0; *lexer->buffer && *lexer->buffer != '\n'; lexer->buffer++);
}

void shrimp_tokenize(shrimp_lexer_t *lexer)
{
    shrimp_token_node_t *ret = NULL;
    shrimp_token_node_t *(*func_list[])(shrimp_lexer_t *lexer) = {
        check_is_symbol,
        check_is_literal,
        check_is_operator,
        check_is_keyword,
        check_is_id,
        NULL
    };

    while (*lexer->buffer) {
        skip_unwanted(lexer);
        for (int index = 0; func_list[index]; index++) {
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