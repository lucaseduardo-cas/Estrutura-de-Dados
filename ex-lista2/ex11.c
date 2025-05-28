#include <stdio.h>

typedef struct {
    char nome[50];  
    int idade;      
    float altura;   
} Pessoa;

int main() {
    Pessoa p;  // Declarando uma variável do tipo Pessoa

    // Solicitando os dados ao usuário
    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);  // Lê uma string com espaços

    printf("Digite a idade: ");
    scanf("%d", &p.idade);

    printf("Digite a altura: ");
    scanf("%f", &p.altura);

    // Exibindo os dados inseridos
    printf("\nDados inseridos:\n");
    printf("Nome: %s", p.nome);  // Não precisa de & porque é um array
    printf("Idade: %d anos\n", p.idade);
    printf("Altura: %.2f metros\n", p.altura);

    return 0;
}
