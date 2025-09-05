/*
9) Qual é a saída do programa abaixo e por que?
*/

#include <stdio.h>

void increment () {
    static int count = 0;
    count++;
    printf("Count: %d\n", count);
}

int main (void) {
    increment ();
    increment ();
    return 0;
}