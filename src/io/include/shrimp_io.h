#ifndef SHRIMP_IO_H
    #define SHRIMP_IO_H

    #include "shrimp_log.h"
    #include "shrimp_common.h"

    // Shrimp file structure
    typedef struct shrimp_file_s {
        int fd;
        FILE *ptr;
        char *name;
        char *buffer;
        struct stat stat;
    } shrimp_file_t;

    // Shrimp io structure
    typedef struct shrimp_io_s {
        shrimp_file_t in;
        shrimp_file_t out;
    } shrimp_io_t;

    /**
     * @brief Open file at given filepath into given structure
     *
     * @param file Shrimp file structure
     * @param filepath Path of file to open
     */
    void shrimp_open_file(shrimp_file_t *file, const char *filepath);

    /**
     * @brief Read file in given structure
     *
     * @param file File to read
     */
    void shrimp_read_file(shrimp_file_t *file);

    /**
     * @brief Close file in given structure
     *
     * @param file File to close
     */
    void shrimp_close_file(shrimp_file_t file);

#endif