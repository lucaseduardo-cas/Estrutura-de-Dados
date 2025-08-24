#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system("cls");

    int mat[10][10];
    int maiorValor=0;
    int i, j, k=1, l, m;

    printf("Leia uma matriz 10x10:\n");
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            printf("%3d° número: ", k);
            scanf("%d", &mat[i][j]);
            k++;

            if (mat[i][j] > maiorValor) {
                maiorValor = mat[i][j];
                l = i;
                m = j;
            }
        }
    }

    printf("\n\nLocalização do maior valor L/C:\n");
    printf("(%d;%d)", l, m);

    printf("\n\n\n");
    return 0;
}
