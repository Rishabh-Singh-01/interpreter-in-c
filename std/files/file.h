#ifndef STD_FILES_FILE
#define STD_FILES_FILE

#include <stdio.h>
#include <stdlib.h>
#include "./../loggers/log.h"

FILE* _open_file(char* p_file_path, char* p_per);
void __append_file(FILE* p_file, char* p_string);
void __close_file(FILE* p_file);

#define open_file(p_file_path, p_per) _open_file(p_file_path, p_per)
#define append_file(p_file, p_string) __append_file(p_file, p_string)
#define close_file(p_file) __close_file(p_file)

#endif
