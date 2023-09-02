#include "shrimp_log.h"

void log_check_errno(FILE *out, const char *type_str, char *format_log_msg)
{
    if (errno)
        fprintf(out, "[%s]: %s (%s)\n", type_str, format_log_msg, strerror(errno));
    else
        fprintf(out, "[%s]: %s\n", type_str, format_log_msg);
}

void format_log_msg(shrimp_log_t *log, const char *log_msg, va_list *args)
{
    if (vasprintf(&log->format_msg, log_msg, *args) < 0) {
        fprintf(stderr, "[%s]: Memory allocation for logging message failed\n", D_RED(FATAL));
        va_end(*args);
        exit(EXIT_FAILURE);
    }

    va_end(*args);
}

void shrimp_log(shrimp_log_type type, const char *log_msg, ...)
{
    va_list args = {0};
    shrimp_log_t shrimp_log_list[] = {
        {stderr, NULL, shrimp_log_fatal},
        {stderr, NULL, shrimp_log_error},
        {stdout, NULL, shrimp_log_info},
        {stdout, NULL, shrimp_log_debug}
    };

    va_start(args, log_msg);
    format_log_msg(&shrimp_log_list[type], log_msg, &args);

    shrimp_log_list[type].func_ptr(shrimp_log_list[type]);
    free(shrimp_log_list[type].format_msg);
}