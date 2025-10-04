/*
Ordenação por Seleção (Selection Sort)
    • Ideia: selecionar o menor elemento e
      colocá-lo na posição correta
    • Complexidade: O(n2)
    • Vantagens: simples, poucas trocas
    • Desvantagens: ineficiente para grandes dados,
      não é estável
    • Quando usar: quando simplicidade importa
      mais que desempenho
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
            min = i; // assume que o menor está na posição i
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j; // atualiza o índice do menor valor
            }
        }   
        // troca o menor valor encontrado com o valor na posição i
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
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

// --- Função Principal (main) para Teste ---
int main() {
    int vetorTeste[] = {64, 25, 12, 22, 11, 5, 90, 3};
    int tamanho = sizeof(vetorTeste) / sizeof(vetorTeste[0]);

    printf("--- Teste do Selection Sort ---\n");
    
    // 2. Imprime o vetor original
    printf("Vetor original (Tamanho = %d):\n", tamanho);
    imprimirVetor(vetorTeste, tamanho);
    
    // 3. Executa o algoritmo de ordenação
    printf("\nIniciando Selection Sort...\n");
    selectionSort(vetorTeste, tamanho);
    printf("Ordenacao concluida.\n");

    // 4. Imprime o vetor ordenado
    printf("\nVetor ordenado:\n");
    imprimirVetor(vetorTeste, tamanho);

    printf("\nTeste finalizado.\n");
    
    return 0;
}