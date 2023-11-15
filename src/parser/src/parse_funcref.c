#include "shrimp_parser.h"

shrimp_top_node_t *parse_funcref(shrimp_token_node_t **token_list)
{
    shrimp_funcref_t new_funcref = {0};

    expect_token(token_list, SHRIMP_TOKEN_KEYWORD_FUNCREF);

    new_funcref.name = expect_token(token_list, SHRIMP_TOKEN_TYPE_ID);
    new_funcref.params = parse_func_params(token_list);

    expect_token(token_list, SHRIMP_TOKEN_OPERATOR_BIND);

    new_funcref.ret = expect_token(token_list, SHRIMP_TOKEN_TYPE_ID);

    expect_token(token_list, SHRIMP_TOKEN_SYMBOL_SEMICOLON);

    return (create_new_top_node(SHRIMP_TOKEN_KEYWORD_FUNCREF, (shrimp_top_value) new_funcref));
}