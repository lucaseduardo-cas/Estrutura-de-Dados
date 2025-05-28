/*
Exercício1: Fazer um programa que leia a nota de 10 alunos e
fazer a média da turma
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");

    float nota[10], media=0;
    int i;

    for (i=0; i<10; i++) {
        printf("Digite a nota do %2d° aluno: ", i + 1);
        scanf("%f", &nota[i]);

        media += nota[i];
    }

    printf("\n\nMédia da turma: %.2f", media / 10.0);

    printf("\n\n\n");
    return 0;
}
