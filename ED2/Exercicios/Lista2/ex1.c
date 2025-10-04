/*
1. Ordenação por Seleção (Selection Sort)
Uma empresa de logística deseja organizar os pesos de cargas em ordem decrescente 
para otimizar o planejamento de transporte. Implemente um programa em C que utilize 
o algoritmo Selection Sort para ordenar um vetor de decimais representando os pesos 
das cargas. Ao final, exiba o vetor ordenado.
*/

#include <stdio.h>

void selectionSortDecrescente(float arr[], int n) {
    int i, j, max_idx;
    float temp;

    // Loop externo: percorre o array até o penúltimo elemento
    for (i = 0; i < n - 1; i++) {
        // Assume que o maior elemento está na posição atual (i)
        max_idx = i;

        // Loop interno: procura o MAIOR elemento no restante do array (a partir de i+1)
        for (j = i + 1; j < n; j++) {
            // A ÚNICA MUDANÇA para decrescente é esta condição
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }

        // Troca o maior elemento encontrado com o elemento na posição i
        temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}

void imprimirVetor(float arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // Vetor de exemplo com pesos (decimais)
    float pesos[] = {150.75, 22.10, 300.50, 88.00, 10.99};
    int tamanho = sizeof(pesos) / sizeof(pesos[0]);

    printf("Pesos originais: ");
    imprimirVetor(pesos, tamanho);

    selectionSortDecrescente(pesos, tamanho);

    printf("Pesos ordenados (Decrescente): ");
    imprimirVetor(pesos, tamanho);

    return 0;
}