#include "shrimp_parser.h"

// TODO: Implement array type parsing

shrimp_var_t *parse_var_decl(shrimp_token_node_t **token_list)
{
    shrimp_var_t *new_var = calloc(1, sizeof(shrimp_var_t));

    new_var->var_name = expect_token(token_list, SHRIMP_TOKEN_TYPE_ID);
    if (strcmp(new_var->var_name.value, "none")) {
        expect_token(token_list, SHRIMP_TOKEN_OPERATOR_BIND);
        new_var->var_type = expect_token(token_list, SHRIMP_TOKEN_TYPE_ID);
    }
    new_var->value = (shrimp_token_t) {0};

    return (new_var);
}