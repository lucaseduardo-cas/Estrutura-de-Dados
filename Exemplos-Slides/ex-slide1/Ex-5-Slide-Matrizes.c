#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system("cls");

    int matA [5][3], matB [5][3], matC [5][3];
    int i, j, k=1;

    printf("Digite os elementos da matriz A:\n");
    for (i=0; i<5; i++) {
        for (j=0; j<3; j++) {
            printf("%2d° elemento: ", k);
            scanf("%d", &matA[i][j]);
            k++;
        }
    }

    printf("\n\n");
    k=1;

    printf("Digite os elementos da matriz B:\n");
    for (i=0; i<5; i++) {
        for (j=0; j<3; j++) {
            printf("%2d° elemento: ", k);
            scanf("%d", &matB[i][j]);
            k++;
        }
    }

    printf("\n\n");
    printf("Soma matriz A + matriz B:\n");
    for (i=0; i<5; i++) {
        for (j=0; j<3; j++) {
            matC[i][j] = matA[i][j] + matB[i][j];
            printf("%2d ", matC[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    return 0;
}
