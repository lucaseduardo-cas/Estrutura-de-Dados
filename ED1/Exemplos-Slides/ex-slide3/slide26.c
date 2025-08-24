/*
Funções para Alocação Dinâmica
- A função realloc() é usada para redimensionar um bloco de memória que já foi alocado com malloc() ou calloc().
- Ela permite aumentar ou diminuir o tamanho da memória.
- Pode realocar em outro endereço, então é obrigatório reatribuir o ponteiro:
arr = realloc(arr, novo_tamanho);

- free( ) – Liberando memória
- Toda memória alocada dinamicamente deve ser liberada com free()
para evitar vazamentos de memória.
- Importante:
- Não tente acessar ptr depois de free(ptr). Isso pode causar
comportamento indefinido.
- Após free(), é boa prática definir ptr = NULL; para evitar
referências inválidas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Funções de alocação dinâmica - realloc () - Redmensionando memória
int main (void) {
    setlocale(LC_ALL, "portuguese");

    int *arr;
    int n = 3; // Tamanho do array

    arr = (int*) malloc(n * sizeof(int)); // n = 3 (aloca espaço para 3 inteiros: ex.: arr[0], arr[1], arr[2])
    if (arr == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Preenchendo o array inicial
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Redimensiona para 5 elementos
    arr = (int*) realloc(arr, 5 * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao realocar memória!\n");
        return 1;
    }

    // Novos elementos precisam ser atribuídos
    arr[3] = 4;
    arr[4] = 5;

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    free(arr); // Libera a memória
    arr = NULL;

    printf("\n\n\n");
    return 0;
}
