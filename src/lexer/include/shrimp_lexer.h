#ifndef SHRIMP_LEXER_H
    #define SHRIMP_LEXER_H

    #include "shrimp_common.h"
    #include "shrimp_io.h"

    // Shrimp keywords enum
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
        SHRIMP_TOKEN_KIND_UNDEF,
        SHRIMP_KEYWORD_ENUM_SIZE
    } shrimp_keyword_type;

    // Shrimp operators enum
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
        SHRIMP_TOKEN_KIND_INVERT,
        SHRIMP_OPERATOR_ENUM_SIZE
    } shrimp_operator_type;

    // Shrimp symbols enum
    typedef enum {
        SHRIMP_TOKEN_KIND_OPEN_PAR,
        SHRIMP_TOKEN_KIND_CLOSE_PAR,
        SHRIMP_TOKEN_KIND_OPEN_CURL,
        SHRIMP_TOKEN_KIND_CLOSE_CURL,
        SHRIMP_TOKEN_KIND_OPEN_BRACKET,
        SHRIMP_TOKEN_KIND_CLOSE_BRACKET,
        SHRIMP_TOKEN_KIND_SEMICOLON,
        SHRIMP_TOKEN_KIND_COLON,
        SHRIMP_TOKEN_KIND_REFERENCE,
        SHRIMP_SYMBOL_ENUM_SIZE
    } shrimp_symbol_type;

    // Shrimp token kinds union
    typedef union {
        int empty;
        shrimp_symbol_type symb;
        shrimp_keyword_type key;
        shrimp_operator_type op;
    } shrimp_token_kind;

    // Shrimp token types enum
    typedef enum {
        SHRIMP_TOKEN_TYPE_SYMBOL,
        SHRIMP_TOKEN_TYPE_KEYWORD,
        SHRIMP_TOKEN_TYPE_OPERATOR,
        SHRIMP_TOKEN_TYPE_ID,
        SHRIMP_TOKEN_TYPE_LIT_INT,
        SHRIMP_TOKEN_TYPE_LIT_CHAR,
        SHRIMP_TOKEN_TYPE_LIT_STRING,
        SHRIMP_TOKEN_TYPE_ENUM_SIZE
    } shrimp_token_type;

    // Shrimp token kind list structure
    typedef struct shrimp_token_id_s {
        const char *value;
        shrimp_token_kind kind;
    } shrimp_token_kind_list_t;

    // Shrimp token structure
    typedef struct shrimp_token_s {
        size_t size;
        char *value;
        shrimp_token_kind kind;
    } shrimp_token_t;

    // Shrimp token node structure
    typedef struct shrimp_token_node_s {
        shrimp_token_t token;
        shrimp_token_type type;
        struct shrimp_token_node_s *next;
    } shrimp_token_node_t;

    // Shrimp lexer structure
    typedef struct shrimp_lexer_s {
        char *token;
        char *buffer;
        size_t list_size;
        size_t buffer_size;
        shrimp_token_node_t *token_list;
    } shrimp_lexer_t;

    /**
     * @brief Initialize lexer with given file
     *
     * @param lexer Pointer to lexer
     * @param file File to tokenize
     */
    void shrimp_init_lexer(shrimp_lexer_t *lexer, shrimp_file_t file);

    /**
     * @brief Tokenize given lexer
     *
     * @param lexer Pointer to initialized lexer
     */
    void shrimp_tokenize(shrimp_lexer_t *lexer);

    /**
     * @brief Dump token based on length
     *
     * @param lexer Pointer to lexer
     * @param len Length to dump
     */
    void dump_token_len(shrimp_lexer_t *lexer, size_t len);

    /**
     * @brief Dump token based on a tester function
     *
     * @param lexer Pointer to lexer
     * @param tester Tester function pointer
     */
    void dump_token_tester(shrimp_lexer_t *lexer, int (*tester)(int));

    /**
     * @brief Dump token based until given delimiter
     *
     * @param lexer Pointer to lexer
     * @param delim Delimiter to stop
     */
    void dump_token_delim(shrimp_lexer_t *lexer, char delim);

    /**
     * @brief Create a new token node object
     *
     * @param type Token type
     * @param kind Token kind
     * @param value Token value
     *
     * @return Pointer to new token node
     */
    shrimp_token_node_t *create_new_token_node(shrimp_token_type type, shrimp_token_kind kind, const char *value);

    /**
     * @brief Push given node to token node list
     *
     * @param lexer Pointer to lexer
     * @param new_node New node to push
     */
    void push_to_token_list(shrimp_lexer_t *lexer, shrimp_token_node_t *new_node);

    /**
     * @brief Check if current token is a symbol
     *
     * @param lexer Pointer to lexer
     */
    shrimp_token_node_t *check_is_symbol(shrimp_lexer_t *lexer);

    /**
     * @brief Check if current token is an operator
     *
     * @param lexer Pointer to lexer
     */
    shrimp_token_node_t *check_is_operator(shrimp_lexer_t *lexer);

    /**
     * @brief Check if current token is a literal
     *
     * @param lexer Pointer to lexer
     */
    shrimp_token_node_t *check_is_literal(shrimp_lexer_t *lexer);

    /**
     * @brief Check if current token is a keyword
     *
     * @param lexer Pointer to lexer
     */
    shrimp_token_node_t *check_is_keyword(shrimp_lexer_t *lexer);

    /**
     * @brief Check if current token is an identifier
     *
     * @param lexer Pointer to lexer
     */
    shrimp_token_node_t *check_is_id(shrimp_lexer_t *lexer);

    /**
     * @brief Get the token type printable string
     *
     * @param type Token type
     *
     * @return Token type printable string
     */
    const char *get_token_type_str(shrimp_token_type type);

    /**
     * @brief Get the token kind printable string
     *
     * @param type Token type
     * @param kind Token kind
     *
     * @return Token kind printable string
     */
    const char *get_token_kind_str(shrimp_token_type type, shrimp_token_kind kind);

#endif