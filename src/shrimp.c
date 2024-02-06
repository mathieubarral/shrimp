#include "shrimp.h"

// TODO: Implement parser
// TODO: Fix memory leaks
// TODO: Handle argument flags
// TODO: Implement error visualisation
// TODO: Implement multiple file handling
// TODO: Create BNF file of the syntax

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
    shrimp_parse(shrimp.lexer.token_list);
    shrimp_close_file(shrimp.io.in);

    return (EXIT_SUCCESS);
}