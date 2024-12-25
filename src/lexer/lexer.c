#include "./lexer.h"

bool is_file_at_end(char ch) {
    return ch == EOF ? true : false;
}

char get_and_consume_current_char(FILE* p_file) {
    return fgetc(p_file);
}

void unconsume_prev_char(char ch, FILE* p_file) {
    ungetc(ch, p_file);
}

bool match_cond_consume_char(FILE* p_file, char expected_char) {
    char actual_char = get_and_consume_current_char(p_file);
    bool is_at_end = is_file_at_end(actual_char);

    if (is_at_end || expected_char != actual_char) {
        unconsume_prev_char(actual_char, p_file);
        return false;
    }
    
    return true;
}

void iterative_till_same_consume_char(FILE* p_file, char end_char) {
    char actual_char = get_and_consume_current_char(p_file);
    bool is_at_end = is_file_at_end(actual_char);

    while (!is_at_end || actual_char != end_char) {
        actual_char = get_and_consume_current_char(p_file);
        is_at_end = is_file_at_end(actual_char);
    }

    // TODO : be really sure that we are trying to preserve the EOF char, right ????
    if (is_at_end) unconsume_prev_char(actual_char, p_file);
}

int_auto_list* get_token_lists_from_file(FILE* p_file) {
    char current_char = get_and_consume_current_char(p_file);
    bool is_at_end = is_file_at_end(current_char);

    int_auto_list* p_auto_list =  initialize_int_auto_list();

    while (!is_at_end) {
        switch (current_char) {
            case '(': insert_int_auto_list(p_auto_list, LEFT_PAREN); break;
            case ')': insert_int_auto_list(p_auto_list, RIGHT_PAREN); break;
            case '{': insert_int_auto_list(p_auto_list, LEFT_BRACE); break;
            case '}': insert_int_auto_list(p_auto_list, RIGHT_BRACE); break;
            case ',': insert_int_auto_list(p_auto_list, COMMA); break;
            case '.': insert_int_auto_list(p_auto_list, DOT); break;
            case '-': insert_int_auto_list(p_auto_list, MINUS); break;
            case '+': insert_int_auto_list(p_auto_list, PLUS); break;
            case '*': insert_int_auto_list(p_auto_list, SEMICOLON); break;
            case '!': {
                bool is_char_equal = match_cond_consume_char(p_file, '=');
                token token_to_insert = is_char_equal ? BANG_EQUAL : BANG;
                insert_int_auto_list(p_auto_list, token_to_insert);
                break;
            }
            case '<': {
                bool is_char_equal = match_cond_consume_char(p_file, '=');
                token token_to_insert = is_char_equal ? LESS_EQUAL : LESS;
                insert_int_auto_list(p_auto_list, token_to_insert);
                break;
            }
            case '>': {
                bool is_char_equal = match_cond_consume_char(p_file, '=');
                token token_to_insert = is_char_equal ? GREATER_EQUAL : GREATER;
                insert_int_auto_list(p_auto_list, token_to_insert);
                break;
            }
            case '/': {
                bool is_char_slash = match_cond_consume_char(p_file, '/');

                if (!is_char_slash) {
                    insert_int_auto_list(p_auto_list, SLASH);
                    break;
                }

                iterative_till_same_consume_char(p_file, '\n');
                break;
            }
            case ' ':
            case '\r':
            case '\t':
            case '\n':
                break;
            default: {
                // TODO: Do some better error logging for the interpreter that user can then use
                // Also, How to provide the file and line no
                log_error("Unrecognizable Character for the interpreter. Find the char below");
                log_error(&current_char); 
                free_int_auto_list(p_auto_list);
                // TODO: Think more about how this would affect the repl mode which runs infinitely
                exit(EXIT_FAILURE);
            }
        }

        current_char = get_and_consume_current_char(p_file);
        is_at_end = is_file_at_end(current_char);
    }

    return p_auto_list;
}
