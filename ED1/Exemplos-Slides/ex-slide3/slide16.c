/*
Passagem de Parâmetro por Referência
- Na passagem por referência, passamos o endereço da variável para a função
- Assim, a função pode modificar diretamente o valor original.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Passagem de parâmetro por referência
void alteraPorReferencia(int *ptr) {
   *ptr = 20; // Modifica o valor da variável original
}

int main (void) {
    setlocale(LC_ALL, "portuguese");

    int x = 10;
    alteraPorReferencia(&x);
    printf("Valor de x após a função: %d\n", x); // Agora será 20

    printf("\n\n\n");
    return 0;
}
