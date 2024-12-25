#ifndef LEXER_LEXER
#define LEXER_LEXER

#include "stdbool.h"
#include "./../../std/data_structures/auto_lists/int_auto_list.h"

typedef enum Token {
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    STAR,
    BANG,
    EQUAL,
    BANG_EQUAL,
    EQUAL_EQUAL,
    LESS,
    LESS_EQUAL,
    GREATER,
    GREATER_EQUAL,
    SLASH
} token;

int_auto_list* get_token_lists_from_file(FILE* p_file);

#endif
