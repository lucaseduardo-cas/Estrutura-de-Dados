/*
2. Ordenação por Troca (Bubble Sort)
Um professor deseja organizar as notas dos alunos em ordem decrescente para verificar 
rapidamente quem obteve os melhores resultados. Implemente em C o algoritmo Bubble Sort 
para ordenar um vetor de notas (reais). Mostre passo a passo como os elementos trocam de 
posição até a lista ficar ordenada.
*/

#include <stdio.h>

void imprimirVetor(float arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

void bubbleSortDecrescente(float arr[], int n) {
    int i, j;
    float temp;

    // Loop externo: controla o número de passagens (N-1)
    for (i = 0; i < n - 1; i++) {
        // Loop interno: compara e troca elementos adjacentes
        // o - i garante que não comparamos a parte já ordenada no final
        for (j = 0; j < n - 1 - i; j++) {
            // Se o elemento ATUAL for MENOR que o PRÓXIMO elemento, TROCA
            // A comparação '>' garante a ordem decrescente (o maior "borbulha" para a esquerda)
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                // Mostrar a troca (Passo a passo)
                printf("Troca: %.1f <-> %.1f. Array: ", arr[j + 1], arr[j]);
                imprimirVetor(arr, n);
            }
        }
    }
}

int main(void) {
    // Vetor de exemplo com notas (reais)
    float notas[] = {7.5, 9.0, 5.5, 8.0, 6.5};
    int tamanho = sizeof(notas) / sizeof(notas[0]);

    printf("Notas originais: ");
    imprimirVetor(notas, tamanho);
    printf("--- Iniciando Bubble Sort Decrescente ---\n");

    bubbleSortDecrescente(notas, tamanho);

    printf("--- Bubble Sort Finalizado ---\n");
    printf("Notas ordenadas (Decrescente): ");
    imprimirVetor(notas, tamanho);

    return 0;
}