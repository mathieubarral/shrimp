#include "shrimp_parser.h"

void push_to_param_list(shrimp_param_node_t *param_list, shrimp_var_t *new_var)
{
    shrimp_param_node_t *tmp = param_list;
    shrimp_param_node_t *new_node = calloc(1, sizeof(shrimp_param_node_t));

    new_node->param = new_var;
    new_node->next = NULL;

    for (; tmp->next; tmp = tmp->next);
    tmp->next = new_node;
}

shrimp_param_node_t *parse_func_params(shrimp_token_node_t **token_list)
{
    shrimp_var_t *new_var = NULL;
    shrimp_param_node_t *new_param = NULL;

    expect_token(token_list, SHRIMP_TOKEN_SYMBOL_OPEN_PAR);

    new_param = calloc(1, sizeof(shrimp_param_node_t));
    new_param->param = parse_var_decl(token_list);
    new_param->next = NULL;

    while ((*token_list) && (*token_list)->token.type == SHRIMP_TOKEN_SYMBOL_COLON) {
        expect_token(token_list, SHRIMP_TOKEN_SYMBOL_COLON);
        new_var = parse_var_decl(token_list);
        push_to_param_list(new_param, new_var);
    }
    expect_token(token_list, SHRIMP_TOKEN_SYMBOL_CLOSE_PAR);

    return (new_param);
}