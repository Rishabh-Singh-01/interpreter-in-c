#include "./main.h"

int main(int argc, char* argv[]) {

    assert(argc <= 2, "More than one parameter passed to the application. Provide either a file path or start a repl.");

    if (argc == 1) {
        FILE* p_file = open_file(argv[1], "r");
        int_auto_list* p_tokens_list = get_token_lists_from_file(p_file);
        printf("%d", *(p_tokens_list -> p_list));
        close_file(p_file);

        return 0;
    }

    // Start the repl

    return 0;
}
