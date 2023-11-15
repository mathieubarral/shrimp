#include "shrimp_lexer.h"

void print_token_list(shrimp_lexer_t *lexer)
{
    const char *token_type_str = NULL;
    const char *token_kind_str = NULL;

    for (shrimp_token_node_t *tmp = lexer->token_list; tmp; tmp = tmp->next) {
        token_type_str = get_token_type_str(tmp->token.type);
        fprintf(stdout, "token: <'%s', %zu, %zu, %zu, %s>\n", tmp->token.value, tmp->token.pos.line, tmp->token.pos.col, tmp->token.size, token_type_str);
    }
}

void buffer_forward(shrimp_lexer_t *lexer, size_t len)
{
    for (int index = 0; index < len; index++, lexer->buffer++) {
        if (*(lexer->buffer) == '\n') {
            lexer->pos.col = 1;
            lexer->pos.line++;
        }
    }
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
                lexer->pos.col += ret->token.size;
                break;
            }
        }

        if (!ret) shrimp_log(SHRIMP_FATAL, "%zu:%zu -> unknown symbol '%c'", lexer->pos.line, lexer->pos.col, *lexer->buffer);

        free(lexer->token);
        lexer->token = NULL;
        ret = NULL;
    }

    #ifdef DEBUG_MODE
    print_token_list(lexer);
    #endif
}