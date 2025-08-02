/*
8) Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função que retorne 
a soma do dobro dos dois números lidos. A função deverá armazenar o dobro de A na propria variável A 
e o dobro de B na própria variável B.
*/

#include <stdio.h>

int somaDobro(int *a, int *b) {
    *a = *a * 2; // Dobra A
    *b = *b * 2; // Dobra B
    return *a + *b; // Retorna a soma dos valores dobrados
}

int main (void) {
    int a, b, soma;

    printf("Valor de A: ");
    scanf("%d", &a);
    printf("Valor de B: ");
    scanf("%d", &b);

    //soma = somaDobro(&a, &b);

    printf("\nSoma do dobro: %d\n", soma);
    printf("A dobrado: %d\n", a);
    printf("B dobrado: %d\n", b);

    printf("\n\n\n");
    return 0;
}