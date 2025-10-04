// Exemplo de recursividade de 0 a 100

#include <stdio.h>
#include <stdlib.h>

int valoresAte100(int num) {
    if (num == 100 + 1) {
        return 1;
    }
    printf("%3d\n", num);

    return valoresAte100(num + 1);
}

int main(void) {
    int n = 0;

    valoresAte100(n);
    return 0;
}