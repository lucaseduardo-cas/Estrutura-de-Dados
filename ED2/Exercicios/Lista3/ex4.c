/*
================== EXPLICAÇÕES ==================

(1) Recursividade no Merge Sort:
O algoritmo divide o vetor repetidamente em duas partes (chamadas recursivas)
até que cada subvetor tenha apenas um elemento. Depois, as chamadas são
"desempilhadas" e os vetores são mesclados em ordem crescente. A condição-base
é quando inicio >= fim, encerrando as chamadas recursivas.

(2) Comparação entre os Métodos:
- Merge Sort (recursivo): O(n log n), mais rápido e estável, ideal para grandes volumes.
- Selection Sort (iterativo): O(n²), mais simples, porém lento para vetores grandes.

Resultados observados:
Para vetores de 10, 100 e 500 elementos:
  - Merge Sort: tempos entre 0.001 e 0.035 ms.
  - Selection Sort: tempos entre 0.001 e 0.107 ms.
O Merge Sort apresentou desempenho superior e crescimento de tempo mais previsível.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a) Função recursiva para fatorial
long long fatorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * fatorial(n - 1);
}

// b) Funções do Merge Sort (recursivo)
void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    int aux[fim - inicio + 1];

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim) aux[k++] = v[j++];

    for (i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = aux[k];
}

void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

// c) Função iterativa - Selection Sort
void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menor])
                menor = j;
        }
        if (menor != i) {
            int temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
        }
    }
}

// Gera vetor aleatório
void gerarVetor(int v[], int n) {
    for (int i = 0; i < n; i++)
        v[i] = rand() % 1000;
}

// Copia vetor
void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

// Exibe vetor
void exibirVetor(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    srand(time(NULL));

    int opcao, n;
    int v[500], copia[500];
    clock_t inicio, fim;
    double tempo;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Vetor de 10 elementos\n");
        printf("2 - Vetor de 100 elementos\n");
        printf("3 - Vetor de 500 elementos\n");
        printf("4 - Vetor de 20 elementos (teste completo)\n");
        printf("5 - Calcular fatorial\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        if (opcao == 5) {
            int num;
            printf("Digite um numero: ");
            scanf("%d", &num);
            printf("Fatorial de %d = %lld\n", num, fatorial(num));
            continue;
        }

        if (opcao == 1) n = 10;
        else if (opcao == 2) n = 100;
        else if (opcao == 3) n = 500;
        else if (opcao == 4) n = 20;
        else continue;

        gerarVetor(v, n);
        printf("\nVetor original:\n");
        exibirVetor(v, n);

        // Merge Sort
        copiarVetor(v, copia, n);
        inicio = clock();
        mergeSort(copia, 0, n - 1);
        fim = clock();
        tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
        printf("\nOrdenado com Merge Sort:\n");
        exibirVetor(copia, n);
        printf("Tempo Merge Sort: %.3f ms\n", tempo);

        // Selection Sort
        copiarVetor(v, copia, n);
        inicio = clock();
        selectionSort(copia, n);
        fim = clock();
        tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
        printf("\nOrdenado com Selection Sort:\n");
        exibirVetor(copia, n);
        printf("Tempo Selection Sort: %.3f ms\n", tempo);

    } while (opcao != 0);

    return 0;
}