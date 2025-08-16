// Como descobrir o tamanho de uma variável em bytes (Função sizeof)

#include <stdio.h>

int main(int argc, char** argv) {
    int a, tamanho;
    float b[5];

    tamanho = sizeof(tamanho);
    printf("Tamanho: %2d\n", tamanho);

    tamanho = sizeof(int);
    printf("Char   : %2d\n", tamanho);

    tamanho = sizeof(double);
    printf("Double : %2d\n", tamanho);

    tamanho = sizeof(float);
    printf("Float  : %2d\n", tamanho);

    tamanho = sizeof(char);
    printf("Char   : %2d\n", tamanho);

    tamanho = sizeof(b);
    printf("Char   : %2d\n", tamanho);


    // Exemplo direto no printf
    printf("Printf : %2ld\n", sizeof(int));

    return 0;
}