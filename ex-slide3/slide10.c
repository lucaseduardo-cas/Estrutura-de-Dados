#include <stdio.h>

int main (void) {
    int var = 1;
    int *ptr;
    ptr = &var;
    *ptr = 3;

    printf ("  Acesso direto: %d\n", var);
    printf ("Acesso indireto: %d\n", *ptr);
    printf ("  Acesso direto: %p\n", (void*)&var);
    printf ("Acesso indireto: %p\n", (void*)ptr);

    return 0;
}
