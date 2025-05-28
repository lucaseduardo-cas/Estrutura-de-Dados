/*
Exercícios: Fazer um algoritmo que leia 100 valores números
inteiros e armazene-os em um vetor. aplique, verifique ntre estes
valores - se existem valores iguais a 30. Se existirem, escrever as
posições em que estes valores estiverem armazenadosde
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");

    int n[100];
    int valoresIguais30[100];
    int i, j=0, k;

    for (i=0; i<100; i++) {
        printf("%d° valor: ", i + 1);
        scanf("%d", &n[i]);

        if (n[i] == 30) {
            valoresIguais30[j] = i;
            j++;
        }
    }

    printf("\n\nPositivo dos valores iguais a 30:\n");
    for (i=0; i<j; i++) {
        printf("%d; ", valoresIguais30[i]);
    }

    printf("\n\n\n");
    return 0;
}
