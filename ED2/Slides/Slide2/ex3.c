/*
Ordenação por Distribuição
    • (Counting Sort / Radix Sort / Bucket Sort)
    • Ideia: classifica dados em baldes ou contagens
    • Complexidade: O(n) em casos ideais
    • Vantagens: muito eficiente em inteiros
      limitados
    • Desvantagens: exige memória extra, ruim para
      dados genéricos
    • Quando usar: inteiros em faixas conhecidas

Algoritmo básico
    Couting Sort
    - 1. encontra o maior elemento
    - 2. inicializa o vetor count com zeros
    - 3. conta a frequência de cada elemento
    - 4. calcula posições acumuladas
    - 5. constrói o array de saída (em ordem estável)
    - 6. copia o vetor ordenado de volta
*/

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int i, max = arr[0];
    // encontra o maior elemento
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
        max = arr[i];
    }
    int *count = (int*)calloc(max + 1, sizeof(int));
    int *output = (int*)malloc(n * sizeof(int));
    // conta a frequência de cada elemento
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // calcula posições acumuladas
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    // constrói o array de saída
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    // copia para o array original
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    free(count);
    free(output);
}

void imprimirVetor(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // Array de teste (Contém duplicatas e a faixa máxima é 8)
    int vetorTeste[] = {4, 2, 2, 8, 3, 3, 1, 4};
    // Calcula o tamanho do array
    int tamanho = sizeof(vetorTeste) / sizeof(vetorTeste[0]);

    printf("--- Teste do Counting Sort ---\n");
    
    // Imprime o vetor antes da ordenação
    printf("Vetor original (Tamanho = %d):\n", tamanho);
    imprimirVetor(vetorTeste, tamanho);
    
    printf("\nIniciando Counting Sort...\n");
    
    // Executa o algoritmo de ordenação
    countingSort(vetorTeste, tamanho);

    // Imprime o vetor final ordenado
    printf("\n--- Resultado Final ---\n");
    printf("Vetor completamente ordenado:\n");
    imprimirVetor(vetorTeste, tamanho);
    
    return 0;
}