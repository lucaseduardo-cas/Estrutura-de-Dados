#include <stdio.h>

int main () {
    int x, y, *p;

    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    printf("x=%d y=%d *p=%d\n\n\n", x, y, *p);
}
