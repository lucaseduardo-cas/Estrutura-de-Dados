/*
Exemplo: Passagem de Parâmetro por Referência
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função troca
void troca (int *px, int *py) { // px = &a e py = &b
    int temp; // 3 Declração da variável local: temp
    temp = *px; // 4 temp recebe conteúdo de px
    *px = *py; // 5 conteúdo de px recebe conteúdo de py
    *py =  temp; // 6 conteúdo de py recebe temp
}

int main (void) {
    setlocale(LC_ALL, "portuguese");

    int a = 5, b = 7; // 1 Declaração das variáveis a = 5 e b = 7;
    troca (&a, &b); // 2 Passamos os endereços das variáveis a e b para função troca: px e py
    printf("%d %d\n", a, b);

    printf("\n\n\n");
    return 0;
}
