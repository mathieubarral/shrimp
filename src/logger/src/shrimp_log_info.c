#include "shrimp_logger.h"

void shrimp_log_info(shrimp_log_t log)
{
    fprintf(log.out, "[%s] %s\n", BLUE(INFO), log.format_msg);
}