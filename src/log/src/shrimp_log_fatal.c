#include "shrimp_log.h"

void shrimp_log_fatal(shrimp_log_t log)
{
    log_check_errno(log.out, D_RED(FATAL), log.format_msg);
    va_end(*log.args);
    exit(EXIT_FAILURE);
}