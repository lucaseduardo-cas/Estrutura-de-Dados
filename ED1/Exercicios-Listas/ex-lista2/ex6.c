#include <stdio.h>

int main (void) {
    int a, b, *p1, *p2;
    a = 4;
    b = 3;
    p1 = &a;
    p2 = p1;

    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;

    printf("a = %d\nb = %d\np1 = %d\np2 = %d\n", a, b, *p1, *p2);
}