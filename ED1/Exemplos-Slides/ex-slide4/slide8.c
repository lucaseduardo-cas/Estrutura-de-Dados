/*
Tipos Abstratos de Dados (TAD)

• Uma struct é uma coleção de variáveis de diferentes tipos,
agrupadas sob um mesmo nome
- Usada para organizar dados relacionados, especialmente quando
esses dados possuem tipos diferente
- É como criar um tipo personalizado reunindo diversos campos que
representam algo mais complexo

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    // características do aluno
    char nome[30];
    int matricula;
    char curso[30];
} aluno;

int main(void) {
    aluno UEG;

    printf("Digite o nome do aluno: ");
    scanf("%s", UEG.nome);
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &UEG.matricula);
    printf("Digite o curso do aluno: ");
    scanf("%s", UEG.curso);

    printf("\nO aluno %s", UEG.nome);
    printf(" tem a matricula: %d", UEG.matricula);
    printf(" e cursa: %s", UEG.curso);
}
