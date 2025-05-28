/*
1. Quais serão os valores de x, y e p ao final do trecho do código abaixo?
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    printf("Valor de x: %d\n",  x);
    printf("Valor de y: %d\n",  y);
    printf("Valor de p: %d\n", *p);
}

