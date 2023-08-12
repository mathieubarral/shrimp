#ifndef SHRIMP_LEXER_H
    #define SHRIMP_LEXER_H

    #include "shrimp_common.h"
    #include "shrimp_io.h"

    typedef enum {
        SHRIMP_TOKEN_KIND_IMPORT,
        SHRIMP_TOKEN_KIND_AS,
        SHRIMP_TOKEN_KIND_FUNCDEF,
        SHRIMP_TOKEN_KIND_FUNCREF,
        SHRIMP_TOKEN_KIND_TYPEDEF,
        SHRIMP_TOKEN_KIND_IF,
        SHRIMP_TOKEN_KIND_ELIF,
        SHRIMP_TOKEN_KIND_ELSE,
        SHRIMP_TOKEN_KIND_FOR,
        SHRIMP_TOKEN_KIND_WHILE,
        SHRIMP_TOKEN_KIND_RETURN,
        SHRIMP_TOKEN_KIND_NEW,
        SHRIMP_TOKEN_KIND_UNDEF
    } shrimp_keyword_type;

    typedef enum {
        SHRIMP_TOKEN_KIND_LINK,
        SHRIMP_TOKEN_KIND_INV_EQU,
        SHRIMP_TOKEN_KIND_EQU_EQU,
        SHRIMP_TOKEN_KIND_LESS_EQU,
        SHRIMP_TOKEN_KIND_GREAT_EQU,
        SHRIMP_TOKEN_KIND_PLUS_EQU,
        SHRIMP_TOKEN_KIND_MINUS_EQU,
        SHRIMP_TOKEN_KIND_MULT_EQU,
        SHRIMP_TOKEN_KIND_DIV_EQU,
        SHRIMP_TOKEN_KIND_AT,
        SHRIMP_TOKEN_KIND_DOT,
        SHRIMP_TOKEN_KIND_BIND,
        SHRIMP_TOKEN_KIND_EQUAL,
        SHRIMP_TOKEN_KIND_PLUS,
        SHRIMP_TOKEN_KIND_MINUS,
        SHRIMP_TOKEN_KIND_MULTIPLY,
        SHRIMP_TOKEN_KIND_DIVIDE,
        SHRIMP_TOKEN_KIND_LESS,
        SHRIMP_TOKEN_KIND_GREAT,
        SHRIMP_TOKEN_KIND_INVERT
    } shrimp_operator_type;

    typedef enum {
        SHRIMP_TOKEN_KIND_OPEN_PAR,
        SHRIMP_TOKEN_KIND_CLOSE_PAR,
        SHRIMP_TOKEN_KIND_OPEN_CURL,
        SHRIMP_TOKEN_KIND_CLOSE_CURL,
        SHRIMP_TOKEN_KIND_OPEN_BRACKET,
        SHRIMP_TOKEN_KIND_CLOSE_BRACKET,
        SHRIMP_TOKEN_KIND_SEMICOLON,
        SHRIMP_TOKEN_KIND_COLON,
        SHRIMP_TOKEN_KIND_REFERENCE
    } shrimp_symbol_type;

    typedef union {
        int empty;
        shrimp_symbol_type symb;
        shrimp_keyword_type key;
        shrimp_operator_type op;
    } shrimp_token_kind;

    typedef enum {
        SHRIMP_TOKEN_TYPE_SYMBOL,
        SHRIMP_TOKEN_TYPE_KEYWORD,
        SHRIMP_TOKEN_TYPE_OPERATOR,
        SHRIMP_TOKEN_TYPE_ID,
        SHRIMP_TOKEN_TYPE_LIT_INT,
        SHRIMP_TOKEN_TYPE_LIT_STRING
    } shrimp_token_type;

    typedef struct shrimp_token_id_s {
        const char *value;
        shrimp_token_kind kind;
    } shrimp_token_kind_list_t;

    typedef struct shrimp_token_s {
        size_t size;
        char *value;
        shrimp_token_kind kind;
    } shrimp_token_t;

    typedef struct shrimp_token_node_s {
        shrimp_token_t token;
        shrimp_token_type type;
        struct shrimp_token_node_s *next;
    } shrimp_token_node_t;

    typedef struct shrimp_lexer_s {
        char *token;
        char *buffer;
        size_t list_size;
        size_t buffer_size;
        shrimp_token_node_t *token_list;
    } shrimp_lexer_t;

    void shrimp_init_lexer(shrimp_lexer_t *lexer, shrimp_file_t file);
    void shrimp_tokenize(shrimp_lexer_t *lexer);
    void dump_token_len(shrimp_lexer_t *lexer, size_t len);
    void dump_token_tester(shrimp_lexer_t *lexer, int (*tester)(int));
    void dump_token_until(shrimp_lexer_t *lexer, char delim);
    shrimp_token_node_t *create_new_token_node(shrimp_token_type type, shrimp_token_kind kind, const char *value);
    void push_to_token_list(shrimp_lexer_t *lexer, shrimp_token_node_t *new_node);
    shrimp_token_node_t *check_is_symbol(shrimp_lexer_t *lexer);
    shrimp_token_node_t *check_is_operator(shrimp_lexer_t *lexer);
    shrimp_token_node_t *check_is_literal(shrimp_lexer_t *lexer);
    shrimp_token_node_t *check_is_keyword(shrimp_lexer_t *lexer);
    shrimp_token_node_t *check_is_id(shrimp_lexer_t *lexer);
    const char *get_token_type_str(shrimp_token_type type);
    const char *get_token_kind_str(shrimp_token_type type, shrimp_token_kind kind);

#endif