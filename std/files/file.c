#include "./file.h"

FILE* _open_file(char* file_path, char* per) {
    FILE* p_file = fopen(file_path, per);

    if (!p_file) {
        log_fatal("Unable to open the below file with corresponding permissions");
        log_fatal(file_path);
        exit(EXIT_FAILURE);
    }

    return p_file;
}

void __append_file(FILE* p_file, char* p_string) {
    fprintf(p_file, "%s", p_string);
}

void __close_file(FILE* p_file) {
    fclose(p_file);
}
