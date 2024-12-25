#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "./../../std/loggers/log.h"
#include "./../../std/assertions/assert_conditions.h"
#include "./../../std/strings/formatter/str_formatter.h"
#include "./../../std/files/file.h"
#include "./../../src/lexer/lexer.h"

#define MAX_LEXER_TEST_INPUT_LEN 50
#define TOTAL_NO_OF_APLHABETS 26
#define CURRENT_LEXER_TOKEN_CAPACITY_SIZE 19

// TODO: Add the test cases for other added lexemes
void test_get_token_lists_from_file() {
    log_info("Starting the get_token_lists_from_file method");
    
    FILE* p_file = open_file("./tests/lexer/test_input.txt", "r");
    int_auto_list* p_tokens_list = get_token_lists_from_file(p_file);

    printf("%ld\n", p_tokens_list -> len);
    printf("%d\n", (p_tokens_list -> p_list)[0]);
    printf("%d\n", LEFT_PAREN);
    printf("%d\n", RIGHT_PAREN);

    assert((p_tokens_list -> len) == 1, "Tokens list len is not 1");
    assert((p_tokens_list -> p_list)[0] == LEFT_PAREN, "Tokens list value is not correct");

    close_file(p_file);

    log_info("Completed the get_token_lists_from_file method. Passed !!!!!");
}

token get_lexer_token_from_int(int num) {
    token tok;
    switch(num) {
        case 0:         tok = LEFT_PAREN;     break;
        case 1:         tok = RIGHT_PAREN;    break;
        case 2:         tok = LEFT_BRACE;     break;
        case 3:         tok = RIGHT_BRACE;    break;
        case 4:         tok = COMMA;          break;
        case 5:         tok = DOT;            break;
        case 6:         tok = MINUS;          break;
        case 7:         tok = PLUS;           break;
        case 8:         tok = SEMICOLON;      break;
        case 9:         tok = STAR;           break;
        case 10:        tok = BANG;           break;
        case 11:        tok = EQUAL;          break;
        case 12:        tok = BANG_EQUAL;     break;
        case 13:        tok = EQUAL_EQUAL;    break;
        case 14:        tok = LESS;           break;
        case 15:        tok = LESS_EQUAL;     break;
        case 16:        tok = GREATER;        break;
        case 17:        tok = GREATER_EQUAL;  break;
        case 18:        tok = SLASH;          break;
        default: {
            log_error("Test: Unrecognizable int to get the token.");
            exit(EXIT_FAILURE);
        }
    }

    return tok;
}

char* get_string_literal_from_lexer_token(token tok) {
    char* p_str_literal;
    switch(tok) {
        case LEFT_PAREN:    p_str_literal = "(";    break;
        case RIGHT_PAREN:   p_str_literal = ")";    break;
        case LEFT_BRACE:    p_str_literal = "{";    break;
        case RIGHT_BRACE:   p_str_literal = "}";    break;
        case COMMA:         p_str_literal = ",";    break;
        case DOT:           p_str_literal = ".";    break;
        case MINUS:         p_str_literal = "-";    break;
        case PLUS:          p_str_literal = "+";    break;
        case SEMICOLON:     p_str_literal = ";";    break;
        case STAR:          p_str_literal = "*";    break;
        case BANG:          p_str_literal = "!";    break;
        case EQUAL:         p_str_literal = "=";    break;
        case BANG_EQUAL:    p_str_literal = "!=";   break;
        case EQUAL_EQUAL:   p_str_literal = "==";   break;
        case LESS:          p_str_literal = "<";    break;
        case LESS_EQUAL:    p_str_literal = "<=";   break;
        case GREATER:       p_str_literal = ">";    break;
        case GREATER_EQUAL: p_str_literal = ">=";   break;
        case SLASH:         p_str_literal = "/";    break;
        default: {
            log_error("Test: Unrecognizable token to parse. Find the token enum below");
            exit(EXIT_FAILURE);
        }
    }

    return p_str_literal;
}

FILE* create_seeded_file_type_sim_env() {
    // TODO: do that for a string eg, repl
    
    close_file(open_file("./tests/lexer/test_input.txt", "w"));
    FILE* p_file = open_file("./tests/lexer/test_input.txt", "a");

    srand(time(NULL));
    int input_str_len = rand() % MAX_LEXER_TEST_INPUT_LEN;

    log_info_formatted_one_int_args("Test: Tyring to create a seed for test environment with length: %d", input_str_len);

    for (int i = 0; i < input_str_len; i++) {
        int random_num = (rand() % (CURRENT_LEXER_TOKEN_CAPACITY_SIZE - 1));
        token tok = get_lexer_token_from_int(random_num);
        char* p_token_str_literal = get_string_literal_from_lexer_token(tok);
        append_file(p_file, p_token_str_literal);
    }

    log_info("Test: Created a seed for test environment. See the file: /tests/lexer/test_input.txt");

    return p_file;
}

// Inspired by Deterministic Simulation Testing
void test_lexer() {

    FILE* p_file = create_seeded_file_type_sim_env();

    close_file(p_file);
}
