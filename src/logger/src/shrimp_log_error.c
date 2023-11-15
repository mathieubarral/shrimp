#include "shrimp_logger.h"

void shrimp_log_error(shrimp_log_t log)
{
    log_check_errno(log.out, L_RED(ERROR), log.format_msg);
}