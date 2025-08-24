/*
Funções para Alocação Dinâmica
- calloc( ) – Aloca memória para um número de elementos
- Clear allocation – funciona como malloc( ) mas inicializa a memória com zeros
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função de alocação dinâmica - calloc () - Alocação e inicialização
int main (void) {
    setlocale(LC_ALL, "portuguese");

    int *arr;
    int n = 5; // Tamanho do array

    arr = (int*) calloc(n, sizeof(int)); // Aloca e inicializa com zeros

    if (arr == NULL) { // Boa prática caso o calloc não consiga alocar memória
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]); // Todos os valores serão 0
    }

    free(arr); // Libera a memória

    printf("\n\n\n");
    return 0;
}
