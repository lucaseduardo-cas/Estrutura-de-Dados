#include <stdio.h>

int main () {
    int num = 10;
    //int* ptr_num; // 'ptr_num' é uma variável que armazena um endereço de memória.
    int *ptr_num;

    ptr_num = &num; // '&num' pega o ENDEREÇO de memória da variável 'num'. Agora 'ptr_num' armazena o endereço de 'num'.

    printf("%p\n", ptr_num);

    *ptr_num = 20; // Aqui, '*' desreferencia ptr_num, e o valor no endereço

    printf("%d\n", num);

    return 0;
}
