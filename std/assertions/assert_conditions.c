#include "./assert_conditions.h"


void _assert(bool condition, char* p_error_message, const char* file, int line) {
    if (!condition) {
        log_fatal_with_file_line(file, line, "Assertion Failed. Find the Error message below.");
        log_fatal_with_file_line(file, line, p_error_message);
        exit(EXIT_FAILURE);
    }
}
