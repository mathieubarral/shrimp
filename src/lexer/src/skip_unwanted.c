#include "shrimp_lexer.h"

bool is_unwanted_char(char curr_char)
{
    char unwanted[4] = {' ', '\t', '\n', '\r'};

    for (int index = 0; index < 4; index++)
        if (curr_char == unwanted[index]) return (true);
    return (false);
}

void skip_unwanted(shrimp_lexer_t *lexer)
{
    while (is_unwanted_char(*lexer->buffer) || *lexer->buffer == '#') {
        for (; is_unwanted_char(*lexer->buffer); buffer_forward(lexer, 1))
            lexer->pos.col += (*lexer->buffer != '\n') ? 1 : 0;

        if (*lexer->buffer == '#')
            for (int index = 0; *lexer->buffer && *lexer->buffer != '\n'; buffer_forward(lexer, 1), lexer->pos.col++);
    }
}