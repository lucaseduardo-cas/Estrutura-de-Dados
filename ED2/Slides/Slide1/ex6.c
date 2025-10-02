/*
Desafio 1 – Torres de Hanói

• Enunciado:
    • O problema das Torres de Hanói consiste em mover todos os
      discos de um pino de origem para um pino de destino,
      utilizando um pino auxiliar.
    As regras são:
    • Apenas um disco pode ser movido por vez.
    • Um disco maior nunca pode ficar sobre um disco menor.
    • Implemente em C um programa recursivo que resolva o
      problema das Torres de Hanói para n discos, exibindo os
      movimentos passo a passo.

• Resolução:
    • A recursão é aplicada da seguinte forma:
    • Para mover n discos do pino A para o pino C (usando B como
      auxiliar):
    • Mova os n-1 discos de A para B (usando C como auxiliar).
    • Mova o maior disco de A para C.
    • Mova os n-1 discos de B para C (usando A como auxiliar).
*/

#include <stdio.h>

// Função recursiva para resolver as Torres de Hanói
void hanoi(int n, char origem, char destino, char auxiliar) {
    // Caso base: se há apenas 1 disco
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }

    // Passo 1: mover n-1 discos da origem para o auxiliar
    hanoi(n - 1, origem, auxiliar, destino);

    // Passo 2: mover o disco maior para o destino
    printf("Mover disco %d de %c para %c\n", n, origem, destino);

    // Passo 3: mover os n-1 discos do auxiliar para o destino
    hanoi(n - 1, auxiliar, destino, origem);
}

int main(void) {
    int n;

    printf("Digite o numero de discos: ");
    scanf("%d", &n);

    printf("\nSequencia de movimentos:\n");
    hanoi(n, 'A', 'C', 'B'); // A = origem, C = destino, B = auxiliar

    return 0;
}