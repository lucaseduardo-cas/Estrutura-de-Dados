/*
13. Crie uma struct chamada Carro, que contenha:
• marca (string de até 30 caracteres)
• ano (inteiro)
• preco (float)

O programa deve:

1. Criar uma variável do tipo Carro.
2. Criar um ponteiro para essa struct.
3. Pedir ao usuário para preencher os dados.
4. Exibir as informações acessando os valores pelo ponteiro.

*/

#include <stdio.h>

typedef struct {
    char marca[30];
    int ano;
    float preco;
} Carro;

int main(void) {
    Carro carro;          // Variável do tipo Carro
    Carro *ptrCarro;      // Ponteiro para struct Carro
    ptrCarro = &carro;    // O ponteiro aponta para a variável carro

    // Entrada de dados
    printf("Marca do carro: ");
    scanf("%s", ptrCarro->marca);  // Usando seta -> para acessar membros via ponteiro

    printf("Ano de fabricação: ");
    scanf("%d", &ptrCarro->ano);

    printf("Preço: ");
    scanf("%f", &ptrCarro->preco);

    // Exibição dos dados
    printf("\nMarca do carro: %s\n", ptrCarro->marca);
    printf("Ano de fabricação: %d\n", ptrCarro->ano);
    printf("Preço: %.2f\n", ptrCarro->preco);

    return 0;
}