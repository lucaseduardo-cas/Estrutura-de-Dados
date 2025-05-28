#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota;
} Aluno;

void exibirAlunos(Aluno alunos[], int tamanho) {
    printf("\nLista de Alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s", alunos[i].nome);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nota: %.2f\n", alunos[i].nota);
        printf("--------------------\n");
    }
}

int main() {
    Aluno alunos[3];  // Criando um array para 3 alunos

    // Coletando os dados dos alunos
    for (int i = 0; i < 3; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, 50, stdin); // Lê o nome (com espaços)

        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);

        getchar(); // Limpa o buffer do teclado
        printf("\n\n");
    }

    // Chamando a função para exibir os alunos
    exibirAlunos(alunos, 3);

    return 0;
}
