#include <stdio.h>

void swapValues(double *x, double *y);

int main (void) {
    double a = 5.5;
    double b = 3.0;
    swapValues(&a, &b);

    printf("a = %.1f, b = %.1f\n", a, b);
    return 0;
}

void swapValues(double *x, double *y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}