#ifndef SHRIMP_LOG_H
    #define SHRIMP_LOG_H

    #include "shrimp_common.h"

    #define D_RED(str) ("\033[0;31m" #str "\033[0m") 
    #define L_RED(str) ("\033[0;91m" #str "\033[0m") 
    #define BLUE(str) ("\033[0;36m" #str "\033[0m")
    #define PURPLE(str) ("\033[0;35m" #str "\033[0m")

    typedef enum {
        SHRIMP_FATAL,
        SHRIMP_ERROR,
        SHRIMP_INFO,
        SHRIMP_DEBUG
    } shrimp_log_type;

    typedef struct shrimp_log_s {
        FILE *out;
        va_list *args;
        char *format_msg;
        void (*func_ptr)(struct shrimp_log_s log);
    } shrimp_log_t;

    void shrimp_log(shrimp_log_type type, const char *log_msg, ...);
    void log_check_errno(FILE *out, const char *type_str, char *format_log_msg);
    void shrimp_log_fatal(shrimp_log_t log);
    void shrimp_log_error(shrimp_log_t log);
    void shrimp_log_info(shrimp_log_t log);
    void shrimp_log_debug(shrimp_log_t log);

#endif