/*
3. Ordenação por Inserção (Insertion Sort)
Um sistema de biblioteca precisa organizar os anos de publicação dos livros 
em ordem crescente. Implemente um programa em C que utilize o Insertion Sort 
para ordenar um vetor de inteiros representando os anos de publicação. Exiba 
o vetor antes e depois da ordenação. Compare o tempo de execução com o algoritmo 
do MergeSort, e diga qual é o melhor algoritmo nesse cenário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para medir o tempo, embora o pedido seja teórico

void insertionSort(int arr[], int n) {
    int i, chave, j;

    // Loop externo: Começa do segundo elemento (i=1)
    for (i = 1; i < n; i++) {
        chave = arr[i]; // Elemento a ser inserido na parte ordenada
        j = i - 1; 

        // Loop interno: Move os elementos da parte ordenada
        // que são maiores que a chave, para a direita
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave; // Insere a chave na sua posição correta
    }
}

void imprimirVetor(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // Vetor de exemplo com anos de publicação
    int anos[] = {2005, 1998, 2010, 1985, 2022, 1990};
    int tamanho = sizeof(anos) / sizeof(anos[0]);

    printf("Anos Originais: ");
    imprimirVetor(anos, tamanho);

    insertionSort(anos, tamanho);

    printf("Anos Ordenados (Crescente): ");
    imprimirVetor(anos, tamanho);

    return 0;
}