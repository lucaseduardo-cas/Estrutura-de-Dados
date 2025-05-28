#include <stdio.h>

int main (void) {
    int num = 42;
    int *ptr1 = &num;
    int *ptr2 = ptr1;
    *ptr2 = 99;

    printf("num = %d\n", num);
    return 0;
}