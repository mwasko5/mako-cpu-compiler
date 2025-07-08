#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"

#define MAX_OPERATION_NAME_LEN 4 // ex: ADDI
#define MAX_REGISTER_NAME_LEN 5 // ex: $zero

// 2 types: numerical operations and data operations

typedef struct {
    const char *name;

    const char *field1;
    const char *field2;
    const char *field3;
} NumericalOperation;

typedef struct {
    const char *name;

    const char *field1;
    const char *offset;
    const char *field2;
} DataOperation;

typedef struct {
    const char *name;

    const char *field1;
    const char *field2;
    const char *immediate;
} ImmediateOperation;

static NumericalOperation numerical_operation_table[] = {
    {"ADD"}, // "ADD $rd,$rs1,$rs2"
    {"SUB"} // "SUB $rd,$rs1,$rs2"
};

static DataOperation data_operation_table[] = {
    {"LW"}, // LW $rd,offset($rs1)
    {"SW"} // SW $rs2,offset($rs1)
};

char** separate_numerical_instruction_string(const char *str) {
    char** array = malloc(4 * sizeof(char*));

    int str_index = 0;

    char* operator_string;
    operator_string = (char*)malloc((MAX_OPERATION_NAME_LEN + 1) * sizeof(char)); // n+1 size for "\0" operator
    
    while (str[str_index] != ' ') { // OPERATOR
        operator_string[str_index] = str[str_index];

        str_index += 1;
    }
    operator_string[str_index] = '\0';

    str_index += 1; // move to the start of the next section

    char* rd_string; int rd_start_index = str_index;
    rd_string = (char*)malloc((MAX_REGISTER_NAME_LEN + 1) * sizeof(char));
    while (str[str_index] != ',') { // $rd
        rd_string[str_index - rd_start_index] = str[str_index];

        str_index += 1;
    }
    rd_string[str_index - rd_start_index] = '\0';

    char* rs1_string; int rs1_start_index = str_index;
    rs1_string = (char*)malloc((MAX_REGISTER_NAME_LEN + 1) * sizeof(char));
    while (str[str_index] != ',') { // $rs1
        rs1_string[str_index - rs1_start_index] = str[str_index];

        str_index += 1;
    }
    rs1_string[str_index - rs1_start_index] = '\0';

    char* rs2_string; int rs2_start_index = str_index;
    rs2_string = (char*)malloc((MAX_REGISTER_NAME_LEN + 1) * sizeof(char));
    while (str[str_index] != '\n') { // $rs2
        rs2_string[str_index - rs2_start_index] = str[str_index];

        str_index += 1;
    }
    rs2_string[str_index - rs2_start_index] = '\0';

    array[0] = operator_string; array[1] = rd_string; array[2] = rs1_string; array[3] = rs2_string;

    free(operator_string);
    free(rd_string);
    free(rs1_string);
    free(rs2_string);

    return array;

    free(array);
}