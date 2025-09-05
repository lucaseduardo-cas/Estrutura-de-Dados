/*
Sequencia de Fibonacci
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci (int n) {
    if (n == 0) return 0; // Caso base 1
    if (n == 1) return 1; // Caso base 2
    return fibonacci (n - 1) + fibonacci(n - 1); // Passo recursivo
}

int main(void) {
    int termos = 10;
    printf("Sequência de Fibonacci até %d termos:\n", termos);
    for (int i = 0; i < termos; i++) {
        printf("%4d\n", fibonacci(i));
    }
    return 0;
}