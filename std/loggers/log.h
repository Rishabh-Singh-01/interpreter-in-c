#ifndef LOGGERS_LOG
#define LOGGERS_LOG

#include <stdio.h>
#include <time.h>

void __log_info(const char* file, int line, char* p_message);
void __log_debug(const char* file, int line, char* p_message);
void __log_error(const char* file, int line, char* p_message);
void __log_fatal(const char* file, int line, char* p_message);

void __log_info_formatted_one_int_args(const char* file, int line, char* p_format_str, int num1);
void __log_info_formatted_two_int_args(const char* file, int line, char* p_format_str, int num1, int num2);


#define log_info(p_message) __log_info(__FILE__, __LINE__, p_message);
#define log_error(p_message) __log_error(__FILE__, __LINE__, p_message);
#define log_debug(p_message) __log_debug(__FILE__, __LINE__, p_message);
#define log_fatal(p_message) __log_fatal(__FILE__, __LINE__, p_message);

#define log_info_with_file_line(file, line, p_message) __log_info(file, line, p_message);
#define log_error_with_file_line(file, line, p_message) __log_error(file, line, p_message);
#define log_debug_with_file_line(file, line, p_message) __log_debug(file, line, p_message);
#define log_fatal_with_file_line(file, line, p_message) __log_fatal(file, line, p_message);

#define log_info_formatted_one_int_args(p_message, num1) __log_info_formatted_one_int_args(__FILE__, __LINE__, p_message, num1);
#define log_info_formatted_two_int_args(p_message, num1, num2) __log_info_formatted_two_int_args(__FILE__, __LINE__, p_message, num1, num2);

#endif
