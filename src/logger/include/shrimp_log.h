#ifndef SHRIMP_LOG_H
    #define SHRIMP_LOG_H

    #include "shrimp_common.h"

    #define D_RED(str) ("\033[0;31m" #str "\033[0m")
    #define L_RED(str) ("\033[0;91m" #str "\033[0m")
    #define BLUE(str) ("\033[0;36m" #str "\033[0m")
    #define PURPLE(str) ("\033[0;35m" #str "\033[0m")

    // Shrimp logger type enum
    typedef enum {
        SHRIMP_FATAL,
        SHRIMP_ERROR,
        SHRIMP_INFO,
        SHRIMP_DEBUG
    } shrimp_log_type;

    // Shrimp logger structure
    typedef struct shrimp_log_s {
        FILE *out;
        char *format_msg;
        void (*func_ptr)(struct shrimp_log_s log);
    } shrimp_log_t;

    /**
     * @brief Print log message of given type
     *
     * @param type Log message type
     * @param log_msg Log message
     * @param ... Arguments of log message
     */
    void shrimp_log(shrimp_log_type type, const char *log_msg, ...);

    /**
     * @brief Check if errno is set and print formatted log message
     *
     * @param out Output stream pointer
     * @param type_str Printable string of log type
     * @param format_log_msg Printable formatted log message
     */
    void log_check_errno(FILE *out, const char *type_str, char *format_log_msg);

    /**
     * @brief Print formatted error message and exit
     *
     * @param log Logger structure
     */
    void shrimp_log_fatal(shrimp_log_t log);

    /**
     * @brief Print formatted error message
     *
     * @param log Logger struture
     */
    void shrimp_log_error(shrimp_log_t log);

    /**
     * @brief Print formatted info message
     *
     * @param log Logger struture
     */
    void shrimp_log_info(shrimp_log_t log);

    /**
     * @brief Print formatted debug message
     *
     * @param log Logger struture
     */
    void shrimp_log_debug(shrimp_log_t log);

#endif