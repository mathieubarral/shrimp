#include "shrimp_parser.h"

shrimp_top_node_t *create_new_top_node(shrimp_token_type type, shrimp_top_value value)
{
    shrimp_top_node_t *new_node = calloc(1, sizeof(shrimp_top_node_t));

    new_node->type = type;
    new_node->value = value;

    return (new_node);
}