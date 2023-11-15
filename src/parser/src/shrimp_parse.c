#include "shrimp_parser.h"

void shrimp_parse(shrimp_token_node_t *token_list)
{
    shrimp_top_node_t *ret = NULL;
    shrimp_top_func_list_t func_list[3] = {
        {SHRIMP_TOKEN_KEYWORD_FUNCDEF, parse_funcdef},
        {SHRIMP_TOKEN_KEYWORD_FUNCREF, parse_funcref},
        {SHRIMP_TOKEN_TYPE_ID, parse_var_init}
    };

    while (token_list) {
        for (int index = 0; index < 3; index++) {
            if (func_list[index].type == token_list->token.type) {
                ret = func_list[index].func(&token_list);
                break;
            }
        }
        if (!ret) shrimp_log(SHRIMP_FATAL, "%zu:%zu -> expected funcref, funcdef or variable", token_list->token.pos.line, token_list->token.pos.col);
        ret = NULL;
    }
}