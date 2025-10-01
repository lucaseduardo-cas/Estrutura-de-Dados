/*
Ordenação por Inserção (Insertion Sort)
    • Ideia: constrói lista ordenada inserindo
      elementos na posição correta
    • Complexidade: O(n2) no pior caso, O(n) no
      melhor
    • Vantagens: eficiente para listas pequenas,
      estável
    • Desvantagens: ineficiente em listas grandes
    • Quando usar: listas pequenas ou quase
      ordenadas
*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; // valor atual a ser inserido
        j = i - 1;
    // move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // insere a chave na posição correta

        printf("Vetor apos inserir o elemento %d: ", key);
        imprimirVetor(arr, n);
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

int main() {
    int vetorTeste[] = {12, 11, 13, 5, 6};
    int tamanho = sizeof(vetorTeste) / sizeof(vetorTeste[0]);

    printf("--- Teste do Insertion Sort ---\n");
    
    // 3. Imprime o vetor antes da ordenação
    printf("Vetor original (Tamanho = %d):\n", tamanho);
    imprimirVetor(vetorTeste, tamanho);
    
    printf("\nIniciando Insertion Sort e mostrando passos:\n");
    
    // 4. Executa o algoritmo de ordenação
    insertionSort(vetorTeste, tamanho);

    // 5. Imprime o vetor final ordenado
    printf("\n--- Resultado Final ---\n");
    printf("Vetor completamente ordenado:\n");
    imprimirVetor(vetorTeste, tamanho);
    
    return 0;
}