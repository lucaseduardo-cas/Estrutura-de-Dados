/*
Exercício 7. Sequência de Collatz
A sequência de Collatz é definida da seguinte forma:
* Se o número é par, divide-se por 2.
* Se é ímpar, multiplica-se por 3 e soma 1.
Repita até chegar a 1. Faça isso com recursividade.
*/

#include <stdio.h>

void collatz(int n) {
    printf("%d ", n);
    if (n == 1) {
        return;
    }
    if (n % 2 == 0) {
        collatz(n / 2);
    } else {
        collatz(3 * n + 1);
    }
}

int main(void) {
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);
    
    if (numero <= 0) {
        printf("O numero deve ser positivo.\n");
    } else {
        printf("A sequencia de Collatz para %d e:\n", numero);
        collatz(numero);
        printf("\n");
    }

    return 0;
}