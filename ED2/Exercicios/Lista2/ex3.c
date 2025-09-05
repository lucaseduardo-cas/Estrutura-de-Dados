/*
Exercício 3 – Contar os dígitos de um número
Escreva uma função recursiva que receba um número inteiro e retorne
quantos dígitos ele possui.
*/

#include <stdio.h>
#include <stdlib.h>

int contaDigitos(int n) {
    if (n < 0) {
        n = -n;
    }
    if (n < 10) {
        return 1;
    }
    return 1 + contaDigitos(n / 10);
}

int main(void) {
    int numero;
    int resultado;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    
    if (numero == 0) {
        printf("O numero de digitos e: 1\n");
    } else {
        resultado = contaDigitos(numero);
        printf("O numero de digitos e: %d\n", resultado);
    }

    return 0;
}