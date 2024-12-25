#ifndef STD_STRINGS_FORMATTER_STR_FORMATTER
#define STD_STRINGS_FORMATTER_STR_FORMATTER

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void __format_string(char* p_format_str, int num, ...);

#define format_string(p_format_str, num, ...) __format_string(p_format_str, num, __VA_ARGS__);

#endif
