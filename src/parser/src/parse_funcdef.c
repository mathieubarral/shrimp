#include "shrimp_parser.h"

// TODO: Implement function body parsing

// shrimp_func_body_t parse_func_body(shrimp_token_node_t **token_list)
// {

// }

shrimp_top_node_t *parse_funcdef(shrimp_token_node_t **token_list)
{
    shrimp_funcdef_t new_funcdef = {0};

    expect_token(token_list, SHRIMP_TOKEN_KEYWORD_FUNCDEF);

    new_funcdef.name = expect_token(token_list, SHRIMP_TOKEN_TYPE_ID);
    new_funcdef.params = parse_func_params(token_list);

    expect_token(token_list, SHRIMP_TOKEN_OPERATOR_BIND);

    new_funcdef.ret = expect_token(token_list, SHRIMP_TOKEN_TYPE_ID);
    // new_funcdef->body = parse_func_body(token_list);

    return (create_new_top_node(SHRIMP_TOKEN_KEYWORD_FUNCDEF, (shrimp_top_value) new_funcdef));
}