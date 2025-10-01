/*
Ordenação por Troca (Bubble Sort)
    • Ideia: percorre o vetor, trocando vizinhos fora
      de ordem
    • Complexidade: O(n²)
    • Vantagens: simples, estável
    • Desvantagens: muito ineficiente em grandes
      listas
    • Quando usar: didático ou listas pequenas
*/

#include <stdio.h>
#include <stdlib.h>

// BUBBLE SORT (Ordenação por Troca)
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // troca se o elemento for maior que o próximo
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// --- Função Auxiliar para Imprimir o Vetor ---
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
    // 1. Array de teste
    int vetorTeste[] = {5, 1, 4, 2, 8};
    // 2. Calcula o tamanho do array
    int tamanho = sizeof(vetorTeste) / sizeof(vetorTeste[0]);

    printf("--- Teste do Bubble Sort ---\n");
    
    // 3. Imprime o vetor antes da ordenação
    printf("Vetor original (Tamanho = %d):\n", tamanho);
    imprimirVetor(vetorTeste, tamanho);
    
    printf("\nIniciando Bubble Sort e mostrando passos:\n");
    
    // 4. Executa o algoritmo de ordenação
    bubbleSort(vetorTeste, tamanho);

    // 5. Imprime o vetor final ordenado
    printf("\n--- Resultado Final ---\n");
    printf("Vetor completamente ordenado:\n");
    imprimirVetor(vetorTeste, tamanho);
    
    return 0;
}