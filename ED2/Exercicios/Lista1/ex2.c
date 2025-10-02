/*
A potência a^N pode ser definida recursivamente como:
a^n = a x a^n-1, a^0 = 1
Implemente uma função recursiva que calcule a potência de um número
inteiro.
*/

#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    }
    return base * potencia(base, expoente - 1);
}

int main(void) {
    int a;
    int n;
    int resultado;
    
    printf("Digite a base (a): ");
    scanf("%d", &a);
    printf("Digite o expoente (n): ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Erro: O expoente deve ser um numero inteiro nao-negativo.\n");
    } else {
        resultado = potencia(a, n);
        printf("O resultado de %d elevado a %d e: %d\n", a, n, resultado);
    }
    
    return 0;
}