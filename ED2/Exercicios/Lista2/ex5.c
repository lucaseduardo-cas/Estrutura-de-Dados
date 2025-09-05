/*
Exercício 5. Busca binária recursiva
Implemente a busca binária de forma recursiva para encontrar um número
dentro de um vetor ordenado.
*/

#include <stdio.h>

int buscaBinaria(int vetor[], int item, int baixo, int alto) {
    if (baixo > alto) {
        return -1;
    }
    
    int meio = baixo + (alto - baixo) / 2;
    
    if (vetor[meio] == item) {
        return meio;
    }
    
    if (vetor[meio] < item) {
        return buscaBinaria(vetor, item, meio + 1, alto);
    }
    
    return buscaBinaria(vetor, item, baixo, meio - 1);
}

int main(void) {
    int vetor[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int item;
    int resultado;
    
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &item);
    
    resultado = buscaBinaria(vetor, item, 0, n - 1);
    
    if (resultado != -1) {
        printf("Elemento encontrado no indice: %d\n", resultado);
    } else {
        printf("Elemento nao encontrado no vetor.\n");
    }
    
    return 0;
}