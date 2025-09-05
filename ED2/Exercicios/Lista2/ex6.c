/*
Exercício 6. Contar vogais em uma string
Elabore uma função recursiva que conte quantas vogais existem em uma
string.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarVogais(char *str, int index) {
    if (str[index] == '\0') {
        return 0;
    }
    char caracter = tolower(str[index]);
    if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
        return 1 + contarVogais(str, index + 1);
    }
    return contarVogais(str, index + 1);
}

int main(void) {
    char str[100];
    int resultado;
    
    printf("Digite uma string: ");
    scanf("%s", str);
    
    resultado = contarVogais(str, 0);
    
    printf("A string contem %d vogais.\n", resultado);
    
    return 0;
}