#include "shrimp.h"

// TODO: Handle argument flags

int main(int argc, char **argv)
{
    shrimp_t shrimp = {0};

    if (argc != 2 || !strcmp(argv[1], "-h")) {
        fprintf(stderr, "Usage: shrimp <file>\n");
        return (EXIT_FAILURE);
    }

    shrimp_open_file(&shrimp.io.in, argv[1]);
    shrimp_read_file(&shrimp.io.in);
    shrimp_init_lexer(&shrimp.lexer, shrimp.io.in);
    shrimp_tokenize(&shrimp.lexer);
    shrimp_close_file(shrimp.io.in);
    return (EXIT_SUCCESS);
}