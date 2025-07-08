#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "parser.h"

// gcc main.c parser.c parser.h -o main

int main(void) {
    FILE* ptr;

    ptr = fopen("instruction.txt", "r");

    if (ptr == NULL) {
        printf("ERROR OPENING FILE\n");

        exit(1);
    }

    char read_line_str[80];

    // while (fgets(str, 80, ptr) != NULL) {
    if (fgets(read_line_str, 80, ptr) != NULL) {
        // puts(read_line_str);
        char** array = separate_numerical_instruction_string(read_line_str);

        printf("operator: %s\n", array[0]);
        printf("rd: %s\n", array[1]);
        printf("rs1: %s\n", array[2]);
        printf("rs2: %s\n", array[3]);

        free(array);
    }

    fclose(ptr);

    return 0;
}
