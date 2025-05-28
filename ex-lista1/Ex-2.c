/*
2. Declare um vetor de 10 posições e o preencha com os 10 primeiros números
impares e o escreva.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system("cls");

    int x[10];
    int i;

    for (i = 0; i < 10; i++) {
        x[i] = (i * 2) +1;
        printf("%d ", x[i]);
    }

    printf("\n\n\n");
    return 0;
}