#include "log.h"

#include "../calendars/date_time.h"

#define EXTRA_LEN_FOR_ERROR_CONSOLIDATION 10

void __log_info(const char* file, int line, char* p_message) {
    date_time dt;
    get_current_local_date_time(&dt);
    printf("%d-%02d-%02d %0d:%02d:%02d - INFO [%s:%d] - %s\n", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second, file, line, p_message);
}

void __log_debug(const char* file, int line, char* p_message) {
    date_time dt;
    get_current_local_date_time(&dt);
    printf("%d-%02d-%02d %0d:%02d:%02d - DEBUG [%s:%d] - %s\n", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second, file, line, p_message);
}

void __log_error(const char* file, int line, char* p_message) {
    date_time dt;
    get_current_local_date_time(&dt);
    printf("%d-%02d-%02d %0d:%02d:%02d - ERROR [%s:%d] - %s\n", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second, file, line, p_message);
}

void __log_fatal(const char* file, int line, char* p_message) {
    date_time dt;
    get_current_local_date_time(&dt);
    printf("%d-%02d-%02d %0d:%02d:%02d - FATAL [%s:%d] - %s\n", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second, file, line, p_message);
}

void __log_info_formatted_one_int_args(const char* file, int line, char* p_format_str, int num1) {
    int temp = 0;
    while(p_format_str[temp] != '\0') temp++;

    size_t size = (temp + EXTRA_LEN_FOR_ERROR_CONSOLIDATION) * sizeof(int);
    char buffer[size];

    snprintf(buffer, sizeof(buffer), p_format_str, num1);
    __log_info(file, line, buffer);
}

void __log_info_formatted_two_int_args(const char* file, int line, char* p_format_str, int num1, int num2) {
    int temp = 0;
    while(p_format_str[temp] != '\0') temp++;

    size_t size = (temp + EXTRA_LEN_FOR_ERROR_CONSOLIDATION) * sizeof(int);
    char buffer[size];

    snprintf(buffer, sizeof(buffer), p_format_str, num1, num2);
    __log_info(file, line, buffer);
}
