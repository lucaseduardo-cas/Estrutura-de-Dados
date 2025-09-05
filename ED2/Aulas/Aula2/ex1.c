/*
Recursividade em programação
*/

#include <stdio.h>

// Função recursiva para calcular fatorial
int fatorial (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial(n = 1);
}

int main(void) {
    int num = 5;
    printf("Fatorial de %d = %d\n", num, fatorial(num));
    return 0;
}