/*
Ordenação por Intercalação (Merge Sort)
    • Ideia: divide vetor, ordena e intercala
      subvetores
    • Complexidade: O(n log n)
    • Vantagens: ótimo desempenho, estável
    • Desvantagens: requer memória extra
    • Quando usar: grandes volumes de dados
*/

#include <stdio.h>
#include <stdlib.h> // Para a função printf

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // cria arrays temporários (L[] e R[])
    int L[n1], R[n2];

    // copia dados para os arrays L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // intercala os arrays temporários de volta em arr[l..r]
    i = 0; // Índice inicial do primeiro sub-array (L)
    j = 0; // Índice inicial do segundo sub-array (R)
    k = l; // Índice inicial do array mesclado (arr)

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copia os elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copia os elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontra o ponto do meio para dividir o vetor em duas metades
        int m = l + (r - l) / 2;

        // Chamada recursiva para ordenar a primeira metade
        mergeSort(arr, l, m);
        
        // Chamada recursiva para ordenar a segunda metade
        mergeSort(arr, m + 1, r);

        // Intercala as duas metades ordenadas
        merge(arr, l, m, r);
        
        // [Didático] Mostra o estado do vetor após a intercalação (merge)
        printf("Vetor apos o Merge de sub-listas [%d...%d]: ", l, r);
        imprimirVetor(arr, r - l + 1);
    }
}

// Nota: Para ser didático, esta função assume que o array completo 'arr' está sendo passado,
// mas para o printf dentro do mergeSort, passaremos o tamanho relativo (n).
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
    // 1. Array de teste
    int vetorTeste[] = {38, 27, 43, 3, 9, 82, 10};
    // 2. Calcula o tamanho do array
    int tamanho = sizeof(vetorTeste) / sizeof(vetorTeste[0]);

    printf("--- Teste do Merge Sort (Recursivo) ---\n");
    
    // 3. Imprime o vetor antes da ordenação
    printf("Vetor original (Tamanho = %d):\n", tamanho);
    imprimirVetor(vetorTeste, tamanho);
    
    printf("\nIniciando Merge Sort e mostrando as intercalacoes (Merges):\n");
    
    // 4. Executa o algoritmo de ordenação
    // Chamada inicial: ordenar de l=0 até r=tamanho-1
    mergeSort(vetorTeste, 0, tamanho - 1);

    // 5. Imprime o vetor final ordenado
    printf("\n--- Resultado Final ---\n");
    printf("Vetor completamente ordenado:\n");
    imprimirVetor(vetorTeste, tamanho);
    
    return 0;
}