#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int matriz[10][10], i, j;
    int maior, linha = 0, coluna = 0;

    printf("Digite os valores da matriz 10x10:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            if (i == 0 && j == 0) {
                maior = matriz[i][j];
            }
            
            // Verifica se o número atual é maior
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                linha = i;
                coluna = j;
            }
        }
    }

    // Exibe a posição do maior valor
    printf("\nO maior valor é %d e está localizado na posição [%d][%d]\n", maior, linha, coluna);

    return 0;
}
