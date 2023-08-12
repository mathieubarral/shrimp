#include "shrimp_io.h"

void shrimp_close_file(shrimp_file_t file)
{
    shrimp_log(SHRIMP_DEBUG, "Trying to close file '%s'...", file.name);
    if (fclose(file.ptr) == EOF)
        shrimp_log(SHRIMP_FATAL, "Failed to close file '%s'", file.name);
    shrimp_log(SHRIMP_DEBUG, "File successfully closed");
}