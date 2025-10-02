/*
Resumo Comparativo
    • Seleção: O(n2), não estável, sem memória extra, simples
    • Troca: O(n2), estável, sem memória extra, didático
    • Distribuição: O(n), estável, exige memória extra, inteiros
      limitados
    • Inserção: O(n2), estável, sem memória extra, listas pequenas
    • Intercalação: O(n log n), estável, exige memória extra, grandes
      volumes

Sugestão de Estudo
    • 1. Revisar ideia central de cada algoritmo
    • 2. Implementar pelo menos uma vez em C
    • 3. Comparar tempos de execução com vetores
      grandes
    • 4. Refletir sobre quando escolher cada
      algoritmo
*/

#include <stdio.h>
#include <stdlib.h> // Necessário para malloc, calloc, exit (usados no Counting Sort)

#define MAX 100

void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void countingSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r); // Auxiliar do Merge Sort

// --- IMPLEMENTAÇÃO DA FUNÇÃO AUXILIAR ---
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void countingSort(int arr[], int n) {
    int i, max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    // Aloca count e output dinamicamente
    int *count = (int*)calloc(max + 1, sizeof(int));
    int *output = (int*)malloc(n * sizeof(int));
    if (count == NULL || output == NULL) { /* Lida com falha */ exit(1); }

    for (i = 0; i < n; i++) count[arr[i]]++;
    for (i = 1; i <= max; i++) count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < n; i++) arr[i] = output[i];
    
    free(count);
    free(output);
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
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
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[MAX], n, choice;
    
    printf("--- Menu de Teste de Algoritmos de Ordenacao ---\n");
    printf("Digite o tamanho do vetor (max %d): ", MAX);
    
    // Validação básica de entrada
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Tamanho invalido ou excedeu o limite.\n");
        return 1;
    }
    
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Erro na leitura dos elementos.\n");
            return 1;
        }
    }
    
    printf("\nVetor original: ");
    printArray(arr, n);

    printf("\nEscolha o algoritmo de ordenacao:\n");
    printf("1 - Selection Sort (O(n^2))\n");
    printf("2 - Bubble Sort (O(n^2))\n");
    printf("3 - Insertion Sort (O(n^2))\n");
    printf("4 - Counting Sort (O(n+k))\n");
    printf("5 - Merge Sort (O(n log n))\n");
    
    if (scanf("%d", &choice) != 1) {
        printf("Erro na leitura da opcao.\n");
        return 1;
    }
    
    switch (choice) {
        case 1: selectionSort(arr, n); break;
        case 2: bubbleSort(arr, n); break;
        case 3: insertionSort(arr, n); break;
        case 4: countingSort(arr, n); break;
        case 5: mergeSort(arr, 0, n - 1); break;
        default: 
            printf("Opcao invalida!\n"); 
            return 0;
    }

    printf("\n>>> Vetor Ordenado: ");
    printArray(arr, n);
    
    return 0;
}