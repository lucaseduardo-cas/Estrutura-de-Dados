/*
1. Leia um vetor de 12 posições e em seguida ler também dois valores X e Y
quaisquer correspondentes a duas posições no vetor. Ao final seu programa
deverá escrever a soma dos valores encontrados nas respectivas posições X e Y.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system("cls");

    int vetor[12], somaPosicoes;
    int x, y;
    int i;

    printf("Leia um vetor de 12 posições:\n");
    for (i = 0; i < 12; i++) {
        printf("%2d° posição: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    while (1) {
        printf("\n\nDigite o valor de X: ");
        scanf("%d", &x);
        if (x < 1 || x > 12) {
            printf("Posição inválida. Tente novamente.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("Digite o valor de Y: ");
        scanf("%d", &y);
        if (y < 1 || y > 12) {
            printf("Posição inválida. Tente novamente.\n");
        } else {
            break;
        }
    }
    
    x--; y--;

    somaPosicoes = (vetor[x]) + (vetor[y]);

    printf("\n\nSoma nas posições %d e %d do vetor ", x, y);
    for (i = 0; i < 12; i++) {
        printf("%2d; ", vetor[i]);
    }
    printf("\nResultado: %d", somaPosicoes);


    printf("\n\n\n");
    return 0;
}