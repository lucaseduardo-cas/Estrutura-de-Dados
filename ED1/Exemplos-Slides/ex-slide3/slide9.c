#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    int a, b, *p;
    a = 2;
    p = &b; // Essa linha não existe no slide original. O programa compila sem ela por falha do compilador, mas não significa que está correto.
    *p = 3;
    b = a + (*p);
    printf ("%d\n", b);

    return 0;
}
