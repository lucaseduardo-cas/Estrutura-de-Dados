/*
Ponteiros para Ponteiros
- Um ponteiro para ponteiro armazena o endereço de
outro ponteiro
- Esse conceito é útil para alocação dinâmica de matrizes e
manipulação avançada de memória.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Ponteiros para ponteiros - malloc() - Alocação simples
int main (void) {
    setlocale(LC_ALL, "portuguese");

    int x = 10;
    int *p = &x; // Ponteiro para inteiro
    int **pp = &p; // Ponteiro para ponteiro

    printf("Valor de x: %d\n", **pp); // Acessando o valor original

    printf("\n\n\n");
    return 0;
}
