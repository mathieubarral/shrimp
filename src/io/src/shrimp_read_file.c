#include "shrimp_io.h"

void shrimp_read_file(shrimp_file_t *file)
{
    size_t file_size = file->stat.st_size;

    if (!(file->buffer = calloc(file_size, sizeof(char))))
        shrimp_log(SHRIMP_FATAL, "Failed to allocate file buffer");

    shrimp_log(SHRIMP_DEBUG, "Trying to read file '%s'...", file->name);
    if (fread(file->buffer, 1, file_size, file->ptr) != file_size)
        shrimp_log(SHRIMP_FATAL, "Failed to read file '%s'", file->name);
    shrimp_log(SHRIMP_DEBUG, "File '%s' successfully readed", file->name);
}