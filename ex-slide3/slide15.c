/*
Passagem de Parâmetro por Valor
- Na passagem por valor, uma cópia do argumento é passada para a função
- Assim, qualquer modificação dentro da função não altera a variável original.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Passagem de parâmetro por valor
void alterarValor(int a) {
    a = 20; // Altera apenas a cópia local
}

int main (void) {
    setlocale(LC_ALL, "portuguese");

    int x = 10;
    alterarValor(x);
    printf("Valor de x após a função: %d\n", x); // Ainda será 10

    printf("\n\n\n");
    return 0;
}
