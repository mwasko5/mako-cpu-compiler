#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"

int lookup_token(const char *str);
int lookup_opcode(const char *str);

typedef struct {
    const char *name;
    int token;
    int opcode;
} TokenEntry;

enum TokenType {
    TOK_OPERATION = 1,
    TOK_REGISTER = 2,
    
    TOK_ERROR = -1
};

static TokenEntry keyword_table[] = {
    // OPERATION KEYWORDS //
    // token field is the funct field
    {"ADD", 0b0000000, 0b0110011},
    {"SUB", 0b0110000, 0b0110011},
    {"MUL", 0b0000001, 0b0110011},

    // REGISTER KEYWORDS //
    {"$zero", TOK_REGISTER, 0},
    {"$ra", TOK_REGISTER, 1},
    {"sp", TOK_REGISTER, 2},
    {"gp", TOK_REGISTER, 3},
    {"tp", TOK_REGISTER, 4},
    {"t0", TOK_REGISTER, 5},
    {"t1", TOK_REGISTER, 6},
    {"t2", TOK_REGISTER, 7},
    {"s0", TOK_REGISTER, 8},
    {"s1", TOK_REGISTER, 9},
    {"a0", TOK_REGISTER, 10},
    {"a1", TOK_REGISTER, 11},
    {"a2", TOK_REGISTER, 12},
    {"a3", TOK_REGISTER, 13},
    {"a4", TOK_REGISTER, 14},
    {"a5", TOK_REGISTER, 15},
    {"a6", TOK_REGISTER, 16},
    {"a7", TOK_REGISTER, 17},
    {"s2", TOK_REGISTER, 18},
    {"s3", TOK_REGISTER, 19},
    {"s4", TOK_REGISTER, 20},
    {"s5", TOK_REGISTER, 21},
    {"s6", TOK_REGISTER, 22},
    {"s7", TOK_REGISTER, 23},
    {"s8", TOK_REGISTER, 24},
    {"s9", TOK_REGISTER, 25},
    {"s10", TOK_REGISTER, 26},
    {"s11", TOK_REGISTER, 27},
    {"t3", TOK_REGISTER, 28},
    {"t4", TOK_REGISTER, 29},
    {"t5", TOK_REGISTER, 30},
    {"t6", TOK_REGISTER, 31},

    // ERROR HANDLING KEYWORDS //
    {NULL, TOK_ERROR, -1}
};


int lookup_token(const char *str) {
    for (int i = 0; keyword_table[i].name != NULL; i++) {
        if (strcmp(str, keyword_table[i].name) == 0)
            return keyword_table[i].token;
    }
    return TOK_ERROR;  // default
}

int lookup_opcode(const char *str) {
    for (int i = 0; keyword_table[i].name != NULL; i++) {
        if (strcmp(str, keyword_table[i].name) == 0)
            return keyword_table[i].opcode;
    }
    return TOK_ERROR;  // default
}