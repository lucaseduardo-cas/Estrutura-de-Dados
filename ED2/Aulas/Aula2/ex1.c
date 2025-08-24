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

    while(1) {
        system("clear");
        printf("Digite um número inteiro: ");
        scanf("%d", &n);
        
        if (n < 0) {
            printf("Erro! O fatorial não é definidoo para números negativos.");
            printf(" Deseja sair? (S/n)\n");
            printf("Opção: ");
            scanf(" %c", &opcao);
            if (opcao == 's') {
                break;
            } else {    
                continue;
            }
        }
        resultado = funcaoFatorial(n);
        printf("O fatorial de %d é: %d\n\n", n, resultado);
        printf("Deseja continuar? (S/n)\n");
        printf("Opção: ");
        scanf(" %c", &opcao);
        limpar_buffer();
    }
    return 0;
}