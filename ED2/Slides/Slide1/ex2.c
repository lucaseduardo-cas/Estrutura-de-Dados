/*
Exemplo 2 – Sequencia de Fibonacci
Em termos matemáticos, a sequência é definida recursivamente pela fórmula matemática abaixo,
sendo o primeiro termo F1 = 1:
    Fn = Fn - 1 + Fn - 2,
e valores iniciais:
    F1 = 1, F2 = 1

Cada número é a soma de seus dois antecessores
    1 1 2 3 5 8 13 21

Observações:
    • Fibonacci é um clássico exemplo recursivo.
    • Custo computacional elevado, pois há
      muitas chamadas redundantes.
*/

#include <stdio.h>

// Função recursiva para calcular n-ésimo termo de Fibonacci
int funcaoFibonacci (int n) {
    if (n == 0) return 0; // Caso base 1
    if (n == 1) return 1; // Caso base 2
    return funcaoFibonacci (n - 1) + funcaoFibonacci (n - 2); // Passo recursivo
}

int main(void) {
    int termos = 10;

    printf("Sequência de Fibonacci até %d termos:\n", termos);
    for (int i = 0; i < termos; i++) {
        printf("%d ", funcaoFibonacci(i));
    }

    printf("\n");
    return 0;
}