#include <stdio.h>

int main(void) {
    int matriz[5][5];
    int i, j;

    // Preenchendo a matriz
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == j) {
                matriz[i][j] = 1; 
            } else {
                matriz[i][j] = 0; 
            }
        }
    }

    // Exibindo a matriz
    printf("Matriz 5x5 resultante:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
