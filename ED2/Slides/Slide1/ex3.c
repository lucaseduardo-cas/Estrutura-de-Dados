/*
Recursividade em Programação
Exemplo 3 – Cálculo do Máximo Divisor Comum (MDC) com Recursividade
    • O MDC entre dois números inteiros positivos a e b é o maior
      número que divide ambos sem deixar resto.
    • Matematicamente, podemos defini-lo pelo Algoritmo de
      Euclides, que funciona assim:

mdc (a, b) = { a                se b =  0
             { mdc (b, a mob b) se b =/ 0

Ou seja:
    • Se b = 0, então mdc (a, b) = a.
    •  Caso contrário, chamamos a função novamente, trocamos os papéis dos
       números, até que b se torne zero.

Explicação matemática do exemplo:
    Suponha que queremos calcular MDC(48, 18):
        1. mdc (48, 18) -> como b =/ 0, fazemos mdc (18, 48 mod 18).
        2. 48 mod 18 = 12, então mdc (18, 12).
        3. mdc (18, 12) -> novamente b =/ 0, logo mdc (12, 18 mod 12).
        4. 18 mod 12 = 6, então mdc(12, 6).
        5. mdc (12, 6) -> como b =/ 0, calculamos mdc (6, 12 mod 6).
        6. 12 mod 6 = 0, então mdc (6, 0) = 6.

    Portanto, MDC(48, 18) = 6

    int func_mdc(int a, int b) {
        // Parada: quando b for zero, o resultado é “a”
        if (b == 0) {
            return a;
        }
        // Passo recursivo: chama a função trocando os valores
        return func_mdc(b, a % b);
    }
*/

#include <stdio.h>

// Função recursiva para calcular MDC usando o Algoritmo de Euclides
int funcaoMDC (int a, int b) {
    // Caso base: quando b for zero, o resultado é a
    if (b == 0) {
        return a;
    }
    // Passo recursivo: chama a função trocando os valores
    return funcaoMDC (b, a % b);
}

int main (void) {
    int x, y;

    printf("Digite dois números inteiros positivos:\n");
    printf("1° número: ");
    scanf("%d", &x);
    printf("2° número: ");
    scanf("%d", &y);

    printf("O MDC de %d e %d é: %d\n", x, y, funcaoMDC(x, y));
    return 0;
}

