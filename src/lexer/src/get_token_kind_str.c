#include "shrimp_lexer.h"

const char *get_token_kind_symbol_str(shrimp_token_kind kind)
{
    const char *token_str_list[9] = {
        "SHRIMP_TOKEN_KIND_OPEN_PAR",
        "SHRIMP_TOKEN_KIND_CLOSE_PAR",
        "SHRIMP_TOKEN_KIND_OPEN_CURL",
        "SHRIMP_TOKEN_KIND_CLOSE_CURL",
        "SHRIMP_TOKEN_KIND_OPEN_BRACKET",
        "SHRIMP_TOKEN_KIND_CLOSE_BRACKET",
        "SHRIMP_TOKEN_KIND_SEMICOLON",
        "SHRIMP_TOKEN_KIND_COLON",
        "SHRIMP_TOKEN_KIND_REFERENCE"
    };

    return (token_str_list[kind.symb]);
}

const char *get_token_kind_operator_str(shrimp_token_kind kind)
{
    const char *token_str_list[20] = {
        "SHRIMP_TOKEN_KIND_LINK",
        "SHRIMP_TOKEN_KIND_INV_EQU",
        "SHRIMP_TOKEN_KIND_EQU_EQU",
        "SHRIMP_TOKEN_KIND_LESS_EQU",
        "SHRIMP_TOKEN_KIND_GREAT_EQU",
        "SHRIMP_TOKEN_KIND_PLUS_EQU",
        "SHRIMP_TOKEN_KIND_MINUS_EQU",
        "SHRIMP_TOKEN_KIND_MULT_EQU",
        "SHRIMP_TOKEN_KIND_DIV_EQU",
        "SHRIMP_TOKEN_KIND_AT",
        "SHRIMP_TOKEN_KIND_DOT",
        "SHRIMP_TOKEN_KIND_BIND",
        "SHRIMP_TOKEN_KIND_EQUAL",
        "SHRIMP_TOKEN_KIND_PLUS",
        "SHRIMP_TOKEN_KIND_MINUS",
        "SHRIMP_TOKEN_KIND_MULTIPLY",
        "SHRIMP_TOKEN_KIND_DIVIDE",
        "SHRIMP_TOKEN_KIND_LESS",
        "SHRIMP_TOKEN_KIND_GREAT",
        "SHRIMP_TOKEN_KIND_INVERT"
    };

    return (token_str_list[kind.op]);
}

const char *get_token_kind_keyword_str(shrimp_token_kind kind)
{
    const char *token_str_list[13] = {
        "SHRIMP_TOKEN_KIND_IMPORT",
        "SHRIMP_TOKEN_KIND_AS",
        "SHRIMP_TOKEN_KIND_FUNCDEF",
        "SHRIMP_TOKEN_KIND_FUNCREF",
        "SHRIMP_TOKEN_KIND_TYPEDEF",
        "SHRIMP_TOKEN_KIND_IF",
        "SHRIMP_TOKEN_KIND_ELIF",
        "SHRIMP_TOKEN_KIND_ELSE",
        "SHRIMP_TOKEN_KIND_FOR",
        "SHRIMP_TOKEN_KIND_WHILE",
        "SHRIMP_TOKEN_KIND_RETURN",
        "SHRIMP_TOKEN_KIND_NEW",
        "SHRIMP_TOKEN_KIND_UNDEF"
    };

    return (token_str_list[kind.key]);
}

const char *get_token_kind_str(shrimp_token_type type, shrimp_token_kind kind)
{
    const char *(*func_list[3])(shrimp_token_kind kind) = {
        get_token_kind_symbol_str,
        get_token_kind_keyword_str,
        get_token_kind_operator_str
    };

    if (type > 2) return ("NONE");

    return (func_list[type](kind));
}