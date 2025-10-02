/*
Exemplo 1 – Cálculo do Fatorial
n! = n x (n - 1)! com 0! = 1
*/ 

#include <stdio.h>

// Função recursiva para calcular fatorial
int funcaoFatorial (int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: fatorial de 0 ou 1 é 1
    }
    return n * funcaoFatorial (n - 1); // Passo recursivo
}

int main (void) {
    int num = 5;
    printf("Fatorial de %d = %d\n", num, funcaoFatorial(num));
    return 0;
}