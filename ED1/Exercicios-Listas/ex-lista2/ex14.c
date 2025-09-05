/*
14. Crie um programa que utilize structs aninhadas para armazenar informações de um endereço dentro de uma estrutura de Pessoa.

1. Crie uma struct chamada Endereco, contendo:
o rua (string de até 50 caracteres)
o numero (inteiro)
o cidade (string de até 30 caracteres)

2. Crie uma struct chamada Pessoa, contendo:
o nome (string de até 50 caracteres)
o idade (inteiro)
o endereco (struct Endereco)

3. Peça ao usuário para preencher os dados de uma pessoa e seu endereço.
*/

#include <stdio.h>

typedef struct {
    char rua[50];
    int numero;
    char cidade[30];
} Endereco;

typedef struct {
    char nome[50];
    int idade;
    Endereco endereco;  // Struct aninhada
} Pessoa;

int main() {
    Pessoa pessoa;

    // Coletando os dados da pessoa
    printf("Digite o nome: ");
    fgets(pessoa.nome, 50, stdin);

    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);
    getchar(); // Limpa o buffer

    // Coletando os dados do endereço
    printf("Digite a rua: ");
    fgets(pessoa.endereco.rua, 50, stdin);

    printf("Digite o número da casa: ");
    scanf("%d", &pessoa.endereco.numero);
    getchar(); // Limpa o buffer

    printf("Digite a cidade: ");
    fgets(pessoa.endereco.cidade, 30, stdin);

    // Exibindo os dados inseridos
    printf("\nDados da Pessoa:\n");
    printf("Nome: %s", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Endereco: %s, Nº %d, %s", 
           pessoa.endereco.rua, 
           pessoa.endereco.numero, 
           pessoa.endereco.cidade);

    return 0;
}
