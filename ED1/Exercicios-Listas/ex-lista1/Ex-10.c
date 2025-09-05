#include <stdio.h>

int main(void) {
    int matriz[20][20], x, i, j, encontrado = 0;

    // Leitura da matriz 20x20
    printf("Digite os elementos da matriz 20x20:\n");
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Leitura do valor X
    printf("\nDigite o valor a ser buscado: ");
    scanf("%d", &x);

    // Busca na matriz
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (matriz[i][j] == x) {
                printf("\nValor encontrado na posição: Linha %d, Coluna %d\n", i, j);
                encontrado = 1;
            }
        }
    }

    // Se não encontrou o valor
    if (!encontrado) {
        printf("\nValor não encontrado na matriz.\n");
    }

    return 0;
}
