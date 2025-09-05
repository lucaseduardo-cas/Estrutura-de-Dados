/*
Ponteiros e Strings
- É possível manipular uma string usando ponteiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Ponteiros e String
int main (void) {
    setlocale(LC_ALL, "portuguese");

    // char str [] = "Hello";
    char str [] = "Lucas Eduardo Cassiano Silva";
    char *ptr = str;

    while (*ptr != '\0') { // '\0' = "cactere nulo". Em C indica o final de uma string.
        printf("%c", *ptr);
        ptr++; // ptr percorre a string sem precisar de um índice.
    }

    printf("\n\n\n");
    return 0;
}
