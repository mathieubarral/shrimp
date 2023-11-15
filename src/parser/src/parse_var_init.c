#include "shrimp_parser.h"

// TODO: Implement value parsing
// TODO: Implement array type parsing

shrimp_top_node_t *parse_var_init(shrimp_token_node_t **token_list)
{
    shrimp_var_t new_var = {0};

    new_var.var_name = expect_token(token_list, SHRIMP_TOKEN_TYPE_ID);

    expect_token(token_list, SHRIMP_TOKEN_OPERATOR_BIND);

    new_var.var_type = expect_token(token_list, SHRIMP_TOKEN_TYPE_ID);

    expect_token(token_list, SHRIMP_TOKEN_OPERATOR_EQUAL);

    new_var.value = (shrimp_token_t) {0};
    expect_token(token_list, SHRIMP_TOKEN_TYPE_LIT_INT);

    expect_token(token_list, SHRIMP_TOKEN_SYMBOL_SEMICOLON);

    return (create_new_top_node(SHRIMP_TOKEN_TYPE_ID, (shrimp_top_value) new_var));
}