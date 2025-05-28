/*
Alocação dinâmica
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int *x;

    x = malloc(sizeof(int));

    if(!x) {
        printf("Erro na alocação!\n");
        return 1;
    } else {
        printf("Mmeória alocada com sucesso!\n");
        printf("x:%d\n", *x);
        *x = 50;
        printf("x:%d\n", *x);
    }

    return 0;
}
