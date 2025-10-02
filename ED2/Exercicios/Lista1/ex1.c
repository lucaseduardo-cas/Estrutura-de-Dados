/*
Exercício 1 – N-ésimo Número Triangular
O número triangular de ordem “n” é dado pela soma:
T(n) = ((n)n + 1) / 2

Implemente recursivamente a soma:
T(n) = n + T(n - 1), T(1) = 1
*/

#include <stdio.h>
#include <stdlib.h>

int numeroTriangular(int n) {
    if (n == 1) {
        return 1;
    }
    return n + numeroTriangular(n - 1);
}

int main(void) {
    int n;
    int resultado;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Erro! O numero deve ser positivo.\n");
    } else {
        resultado = numeroTriangular(n);
        printf("O numero triangular de %d e: %d\n", n, resultado);
    }
    
    return 0;
}