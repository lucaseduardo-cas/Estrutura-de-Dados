/*
1. Leia um vetor de 12 posi��es e em seguida ler tamb�m dois valores X e Y
quaisquer correspondentes a duas posi��es no vetor. Ao final seu programa
dever� escrever a soma dos valores encontrados nas respectivas posi��es X e Y.
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

    printf("Leia um vetor de 12 posi��es:\n");
    for (i = 0; i < 12; i++) {
        printf("%2d� posi��o: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    while (1) {
        printf("\n\nDigite o valor de X: ");
        scanf("%d", &x);
        if (x < 1 || x > 12) {
            printf("Posi��o inv�lida. Tente novamente.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("Digite o valor de Y: ");
        scanf("%d", &y);
        if (y < 1 || y > 12) {
            printf("Posi��o inv�lida. Tente novamente.\n");
        } else {
            break;
        }
    }
    
    x--; y--;

    somaPosicoes = (vetor[x]) + (vetor[y]);

    printf("\n\nSoma nas posi��es %d e %d do vetor ", x, y);
    for (i = 0; i < 12; i++) {
        printf("%2d; ", vetor[i]);
    }
    printf("\nResultado: %d", somaPosicoes);


    printf("\n\n\n");
    return 0;
}