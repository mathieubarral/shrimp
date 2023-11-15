#ifndef SHRIMP_LEXER_H
    #define SHRIMP_LEXER_H

    #include "shrimp_common.h"
    #include "shrimp_io.h"

    #define SHRIMP_SYMBOL_SIZE 9
    #define SHRIMP_KEYWORD_SIZE 13
    #define SHRIMP_OPERATOR_SIZE 20

    // Shrimp token type enum
    typedef enum {
        SHRIMP_TOKEN_KEYWORD_IMPORT,
        SHRIMP_TOKEN_KEYWORD_AS,
        SHRIMP_TOKEN_KEYWORD_FUNCDEF,
        SHRIMP_TOKEN_KEYWORD_FUNCREF,
        SHRIMP_TOKEN_KEYWORD_TYPEDEF,
        SHRIMP_TOKEN_KEYWORD_IF,
        SHRIMP_TOKEN_KEYWORD_ELIF,
        SHRIMP_TOKEN_KEYWORD_ELSE,
        SHRIMP_TOKEN_KEYWORD_FOR,
        SHRIMP_TOKEN_KEYWORD_WHILE,
        SHRIMP_TOKEN_KEYWORD_RETURN,
        SHRIMP_TOKEN_KEYWORD_NEW,
        SHRIMP_TOKEN_KEYWORD_UNDEF,

        SHRIMP_TOKEN_OPERATOR_LINK,
        SHRIMP_TOKEN_OPERATOR_INV_EQU,
        SHRIMP_TOKEN_OPERATOR_EQU_EQU,
        SHRIMP_TOKEN_OPERATOR_LESS_EQU,
        SHRIMP_TOKEN_OPERATOR_GREAT_EQU,
        SHRIMP_TOKEN_OPERATOR_PLUS_EQU,
        SHRIMP_TOKEN_OPERATOR_MINUS_EQU,
        SHRIMP_TOKEN_OPERATOR_MULT_EQU,
        SHRIMP_TOKEN_OPERATOR_DIV_EQU,
        SHRIMP_TOKEN_OPERATOR_AT,
        SHRIMP_TOKEN_OPERATOR_DOT,
        SHRIMP_TOKEN_OPERATOR_BIND,
        SHRIMP_TOKEN_OPERATOR_EQUAL,
        SHRIMP_TOKEN_OPERATOR_PLUS,
        SHRIMP_TOKEN_OPERATOR_MINUS,
        SHRIMP_TOKEN_OPERATOR_MULTIPLY,
        SHRIMP_TOKEN_OPERATOR_DIVIDE,
        SHRIMP_TOKEN_OPERATOR_LESS,
        SHRIMP_TOKEN_OPERATOR_GREAT,
        SHRIMP_TOKEN_OPERATOR_INVERT,

        SHRIMP_TOKEN_SYMBOL_OPEN_PAR,
        SHRIMP_TOKEN_SYMBOL_CLOSE_PAR,
        SHRIMP_TOKEN_SYMBOL_OPEN_CURL,
        SHRIMP_TOKEN_SYMBOL_CLOSE_CURL,
        SHRIMP_TOKEN_SYMBOL_OPEN_BRACKET,
        SHRIMP_TOKEN_SYMBOL_CLOSE_BRACKET,
        SHRIMP_TOKEN_SYMBOL_SEMICOLON,
        SHRIMP_TOKEN_SYMBOL_COLON,
        SHRIMP_TOKEN_SYMBOL_REFERENCE,

        SHRIMP_TOKEN_TYPE_ID,
        SHRIMP_TOKEN_TYPE_LIT_INT,
        SHRIMP_TOKEN_TYPE_LIT_CHAR,
        SHRIMP_TOKEN_TYPE_LIT_STRING,

        SHRIMP_TOKEN_TYPE_ENUM_SIZE
    } shrimp_token_type;

    // Shrimp token kind list structure
    typedef struct shrimp_token_id_s {
        const char *value;
        shrimp_token_type type;
    } shrimp_token_type_list_t;

    typedef struct shrimp_lexer_pos_s {
        size_t line;
        size_t col;
    } shrimp_lexer_pos_t;

    // Shrimp token structure
    typedef struct shrimp_token_s {
        size_t size;
        char *value;
        shrimp_lexer_pos_t pos;
        shrimp_token_type type;
    } shrimp_token_t;

    // Shrimp token node structure
    typedef struct shrimp_token_node_s {
        shrimp_token_t token;
        struct shrimp_token_node_s *next;
    } shrimp_token_node_t;

    // Shrimp lexer structure
    typedef struct shrimp_lexer_s {
        char *token;
        char *buffer;
        shrimp_lexer_pos_t pos;
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
     * @param lexer Pointer to lexer
     */
    void shrimp_tokenize(shrimp_lexer_t *lexer);

    /**
     * @brief Fast forward buffer from len
     *
     * @param lexer Pointer to lexer
     * @param len Length to forward the buffer
     */
    void buffer_forward(shrimp_lexer_t *lexer, size_t len);

    /**
     * @brief Skip unwanted characters
     *
     * @param lexer Pointer to lexer
     */
    void skip_unwanted(shrimp_lexer_t *lexer);

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
     * @param lexer Pointer to lexer
     * @param type Token type
     *
     * @return Pointer to new token node
     */
    shrimp_token_node_t *create_new_token_node(shrimp_lexer_t *lexer, shrimp_token_type type);

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

#endif