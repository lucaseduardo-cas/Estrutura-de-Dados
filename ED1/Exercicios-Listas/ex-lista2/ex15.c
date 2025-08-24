#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
    int qtd;
} Produto;

// Função para calcular o total
float calcularTotal(Produto *produto) {
    return produto->preco * produto->qtd;
}

int main(void) {
    Produto produto;
    float total;

    // Entrada de dados
    printf("Nome: ");
    scanf("%s", produto.nome); // Já é um array, não precisa de '&'

    printf("Preço: ");
    scanf("%f", &produto.preco);

    printf("Quantidade: ");
    scanf("%d", &produto.qtd);

    // Calcula o total chamando a função
    total = calcularTotal(&produto);

    // Exibe o total
    printf("Total: %.2f\n", total);

    return 0;
}
