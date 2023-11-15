#include "shrimp_logger.h"

void shrimp_log_debug(shrimp_log_t log)
{
    #ifdef DEBUG_MODE
    fprintf(log.out, "[%s] %s\n", PURPLE(DEBUG), log.format_msg);
    #endif
}