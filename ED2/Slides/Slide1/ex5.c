/*
Exemplo 5 – Soma dos elementos de
um vetor

Enunciado:
Implemente uma função recursiva que calcule a soma dos
elementos de um vetor de inteiros.
*/

#include <stdio.h>

// Função recursiva para somar os elementos do vetor
int somaVetor(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 0; // Caso base: vetor vazio tem soma zero
    }
    return vetor[tamanho - 1] + somaVetor(vetor, tamanho - 1);
    // Soma o último elemento com o restante
}

int main(void) {
    int v[] = {1, 2, 3, 4, 5};
    int tamanho = 5;
    
    printf("Soma dos elementos = %d\n", somaVetor(v, tamanho));
    
    return 0;
}

