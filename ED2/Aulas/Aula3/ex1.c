/*
1) Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcaoFatorial(int valorN) {
    if (valorN == 0 || valorN == 1) {
        return 1;
    }
    return valorN * funcaoFatorial(valorN - 1);
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int n;
    int resultado;
    char opcao;

    printf("Digite um número inteiro: ");
    scanf("%d", &n);
        
    if (n < 0) {
        printf("Erro! O fatorial não é definidoo para números negativos. ");
    }
    resultado = funcaoFatorial(n);
    printf("O fatorial de %d é: %d\n\n", n, resultado);
    
    return 0;
}