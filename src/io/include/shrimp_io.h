#ifndef SHRIMP_IO_H
    #define SHRIMP_IO_H

    #include "shrimp_log.h"
    #include "shrimp_common.h"

    typedef struct shrimp_file_s {
        int fd;
        FILE *ptr;
        char *name;
        char *buffer;
        struct stat stat;
    } shrimp_file_t;

    typedef struct shrimp_io_s {
        shrimp_file_t in;
        shrimp_file_t out;
    } shrimp_io_t;

    void shrimp_open_file(shrimp_file_t *file, const char *filepath);
    void shrimp_read_file(shrimp_file_t *file);
    void shrimp_close_file(shrimp_file_t file);

#endif