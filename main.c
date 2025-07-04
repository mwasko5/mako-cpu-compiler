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

    char str[80];

    printf("ADD token = %d\n", lookup_token("ADD"));

    // while (fgets(str, 80, ptr) != NULL) {
    if (fgets(str, 80, ptr) != NULL) {
        puts(str);
    }

    fclose(ptr);

    return 0;
}
