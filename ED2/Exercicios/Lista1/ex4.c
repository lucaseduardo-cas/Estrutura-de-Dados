/*
Exercício 4. Verificar se uma palavra é palíndromo
Escreva uma função recursiva que verifique se uma palavra é palíndromo
(lida da mesma forma de trás para frente).
*/

#include <stdio.h>
#include <string.h>

int ePalindromo(char *palavra, int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    }
    if (palavra[inicio] != palavra[fim]) {
        return 0;
    }
    return ePalindromo(palavra, inicio + 1, fim - 1);
}

int main(void) {
    char palavra[50];
    
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    if (ePalindromo(palavra, 0, strlen(palavra) - 1)) {
        printf("A palavra e um palindromo.\n");
    } else {
        printf("A palavra nao e um palindromo.\n");
    }

    return 0;
}