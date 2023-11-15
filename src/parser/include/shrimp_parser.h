#ifndef SHRIMP_PARSER_H
    #define SHRIMP_PARSER_H

    #include "shrimp_common.h"
    #include "shrimp_logger.h"
    #include "shrimp_lexer.h"

    // TODO: Add documentation

    typedef struct shrimp_var_s {
        shrimp_token_t var_name;
        shrimp_token_t var_type;
        shrimp_token_t value;
    } shrimp_var_t;

    typedef struct shrimp_param_node_s {
        shrimp_var_t *param;
        struct shrimp_param_node_s *next;
    } shrimp_param_node_t;

    typedef struct shrimp_funcref_s {
        shrimp_token_t name;
        shrimp_param_node_t *params;
        shrimp_token_t ret;
    } shrimp_funcref_t;

    // typedef struct shrimp_stmt_s {
    // } shrimp_stmt_t;

    // typedef struct shrimp_func_body_s {
    //     size_t size;
    //     shrimp_stmt_t stmt;
    // } shrimp_func_body_t;

    typedef struct shrimp_funcdef_s {
        shrimp_token_t name;
        shrimp_param_node_t *params;
        shrimp_token_t ret;
        // shrimp_func_body_t body;
    } shrimp_funcdef_t;

    typedef union {
        shrimp_funcdef_t funcdef;
        shrimp_funcref_t funcref;
        shrimp_var_t var;
    } shrimp_top_value;

    typedef struct shrimp_top_node_s {
        shrimp_token_type type;
        shrimp_top_value value;
    } shrimp_top_node_t;

    typedef struct shrimp_top_func_list_s {
        shrimp_token_type type;
        shrimp_top_node_t *(*func)(shrimp_token_node_t **token_list);
    } shrimp_top_func_list_t;

    typedef struct shrimp_module_s {
        shrimp_top_node_t *list;
    } shrimp_module_t;

    // typedef struct shrimp_parser_func_list_s {
    // } shrimp_parser_func_list_s;

    void shrimp_parse(shrimp_token_node_t *token_list);
    shrimp_token_t expect_token(shrimp_token_node_t **node, shrimp_token_type type);
    shrimp_top_node_t *create_new_top_node(shrimp_token_type type, shrimp_top_value value);
    shrimp_top_node_t *parse_funcdef(shrimp_token_node_t **token_list);
    shrimp_top_node_t *parse_funcref(shrimp_token_node_t **token_list);
    shrimp_param_node_t *parse_func_params(shrimp_token_node_t **token_list);
    shrimp_top_node_t *parse_var_init(shrimp_token_node_t **token_list);
    shrimp_var_t *parse_var_decl(shrimp_token_node_t **token_list);

#endif