/*
Exemplo 4 – Inversão de uma string

Elabore uma função recursiva que imprima uma string invertida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverterString(char str[], int n) {
    // '\0' é o caractere nulo. Em C, todas as strings são arrays de caracteres terminados com este caractere especial.
    // Ele marca o fim da string.
    // //if(str[n] == '\0') {
    // //    return;
    // //}

    // Se o n atingir o tamanho da string, significa que chegamos ao final da string.
    if(n == strlen(str)) {
        return; // caso base
    }

    inverterString(str, n + 1); // chamada recursiva

    printf("%c", str[n]); // imprimir caractere após a chamada recursiva
}

int main() {
    char palavra[] = "Universidade";

    printf("Palavra Original: %s\n", palavra);
    printf("Palavra Invertida: ");
    inverterString(palavra, 0);

    printf("\n");
    return 0;
}