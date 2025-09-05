/*
7) Escreva um programa que contenha duas variaveis inteiras. Leia essas variáveis do teclado. Em
seguida, compare seus endereços e exiba o conteudo do maior endereço.
*/

#include <stdio.h>

int main (void) {
    int a, b;

    printf("Variável A e B: ");
    scanf("%d %d", &a, &b);

    if (&a > &b) {
        printf("\nConteúdo de maior endereço: %d", a);
    } else {
        printf("\nConteúdo de maior endereço: %d", b);
    }
    
    return 0;
}