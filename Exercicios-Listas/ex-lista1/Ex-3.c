/*
3. Leia um vetor de 16 posições e troque os 8 primeiros valores pelos 8 últimos e
vice-e-versa. Escreva ao final o vetor obtido.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system("cls");

    int x[16], y[16];
    int i;

    printf("Leia um vetor de 16 posições:\n");
    for (i = 0; i < 16; i++) { 
        printf("%2d° posição: ", i + 1);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < 16; i++) { 
        if (i >= 8) {
            y[i - 8] = x[i];
        } else {
            y[i + 8] = x[i];
        }
    }

    printf("\nVetor Vice-Versa:\n");
    for (i = 0; i < 16; i++) {
        printf("%2d; ", y[i]);
    }

    printf("\n\n\n");
    return 0;
}