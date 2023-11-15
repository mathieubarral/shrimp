#include "shrimp_lexer.h"

void push_to_token_list(shrimp_lexer_t *lexer, shrimp_token_node_t *new_node)
{
    shrimp_token_node_t *tmp = lexer->token_list;

    if (!lexer->token_list)
        lexer->token_list = new_node;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = new_node;
    }
}