#ifndef SHRIMP_H
    #define SHRIMP_H

    #include "shrimp_common.h"
    #include "shrimp_log.h"
    #include "shrimp_io.h"
    #include "shrimp_lexer.h"

    // Shrimp main structure
    typedef struct shrimp_s {
        shrimp_io_t io;
        shrimp_lexer_t lexer;
    } shrimp_t;

#endif