#include "shrimp_io.h"

#ifdef DEBUG_MODE
void shrimp_print_file_infos(struct stat stat)
{
    shrimp_log(SHRIMP_DEBUG, "File info successfully retrieved");
    fprintf(stdout, "\towner id: %d\n", stat.st_uid);
    fprintf(stdout, "\tgroup id: %d\n", stat.st_gid);
    fprintf(stdout, "\tfile size: %ld\n", stat.st_size);
    fprintf(stdout, "\tblocks allocated: %ld\n", stat.st_blocks);
}
#endif

void shrimp_open_file(shrimp_file_t *file, const char *filepath)
{
    shrimp_log(SHRIMP_DEBUG, "Trying to open file '%s'...", filepath);
    if ((file->fd = open(filepath, O_RDONLY)) < 0)
        shrimp_log(SHRIMP_FATAL, "Failed to open file '%s'", filepath);
    shrimp_log(SHRIMP_DEBUG, "File '%s' successfully opened", filepath);

    shrimp_log(SHRIMP_DEBUG, "Trying to get file infos...", filepath);
    if (fstat(file->fd, &file->stat) < 0)
        shrimp_log(SHRIMP_FATAL, "Failed to get file infos");
    #ifdef DEBUG_MODE
        shrimp_print_file_infos(file->stat);
    #endif

    if (file->stat.st_size <= 0)
        shrimp_log(SHRIMP_FATAL, "File '%s' is empty", filepath);

    shrimp_log(SHRIMP_DEBUG, "Trying to get file pointer...", filepath);
    if (!(file->ptr = fdopen(file->fd, "r")))
        shrimp_log(SHRIMP_FATAL, "Failed to get file pointer");
    shrimp_log(SHRIMP_DEBUG, "File pointer successfully retrieved", filepath);
    file->name = strdup(filepath);
}