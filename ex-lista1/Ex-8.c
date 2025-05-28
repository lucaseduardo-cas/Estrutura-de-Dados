#include <stdio.h>

int main(void) {
    int A[4][4], B[4][4], C[4][4];
    int i, j;

    // Leitura da matriz A
    printf("Digite os elementos da matriz A (4x4):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Leitura da matriz B
    printf("\nDigite os elementos da matriz B (4x4):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Criando a matriz C com os maiores valores entre A e B
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            C[i][j] = (A[i][j] > B[i][j]) ? A[i][j] : B[i][j];
        }
    }

    // Exibindo a matriz C
    printf("\nMatriz C (maiores valores entre A e B):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
