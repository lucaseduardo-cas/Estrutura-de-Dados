/*
Exercício1: Declare uma matriz 5 x 5. Preencha com 1 a diagonal
principal e com 0 os demais elementos. Escreva ao final a matriz
obtida
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system("cls");

    int mat [5][5];
    int i, j;

    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            mat[i][j] = (i == j) ? 1 : 0; // Define a diagonal como 1 e o resto como 0
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    return 0;
}
