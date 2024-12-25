#ifndef STD_ASSERTIONS_ASSERT_CONDITIONS
#define STD_ASSERTIONS_ASSERT_CONDITIONS

#include <stdbool.h>
#include <stdlib.h>
#include "./../loggers/log.h"

void _assert(bool condition, char* p_error_message, const char* file, int line);
#define assert(condition, p_error_message) _assert(condition, p_error_message, __FILE__, __LINE__);

#endif
