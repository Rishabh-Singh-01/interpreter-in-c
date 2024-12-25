#include "./../std/loggers/log.h"
#include "./lexer/test.h"



int main() {
    log_info("Starting the testing suite");

    test_lexer();


    log_info("Completed the testing suite. Passed !!!!");
    return 0;
}
