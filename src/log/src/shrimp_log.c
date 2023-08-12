#include "shrimp_log.h"

void log_check_errno(FILE *out, const char *type_str, char *format_log_msg)
{
    if (errno)
        fprintf(out, "[%s]: %s (%s)\n", type_str, format_log_msg, strerror(errno));
    else
        fprintf(out, "[%s]: %s\n", type_str, format_log_msg);
}

void shrimp_log(shrimp_log_type type, const char *log_msg, ...)
{
    va_list args = {0};
    shrimp_log_t shrimp_log_list[] = {
        {stderr, &args, NULL, shrimp_log_fatal},
        {stderr, &args, NULL, shrimp_log_error},
        {stdout, &args, NULL, shrimp_log_info},
        {stdout, &args, NULL, shrimp_log_debug}
    };

    va_start(args, log_msg);

    if (vasprintf(&shrimp_log_list[type].format_msg, log_msg, args) < 0) {
        fprintf(stderr, "[%s]: Memory allocation for logging message failed\n", D_RED(FATAL));
        va_end(args);
        exit(EXIT_FAILURE);
    }

    shrimp_log_list[type].func_ptr(shrimp_log_list[type]);

    va_end(args);
    free(shrimp_log_list[type].format_msg);
}