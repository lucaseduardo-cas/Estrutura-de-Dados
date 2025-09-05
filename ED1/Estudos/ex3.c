/*
- Estrutura de dados - Pilha
No	       - Struct que representa cada elemento da pilha (valor + ponteiro pro próximo)
push	   - Cria um novo nó, coloca ele no topo
pop	       - Remove o nó do topo e retorna o valor
imprimir   - Percorre a pilha imprimindo cada valor
main	   - Testa tudo empilhando e desempilhando valores
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    Data data;
} Pessoa;

typedef struct no { // "no" apelido para estrutura
    Pessoa p;
    struct no *proximo; // Ponteiro para o próximo no
} No; // "No" nome da estrutura

Pessoa ler_pessoa () {
    Pessoa p; // Variável do tipo Pessoa
    printf("\nDigite o nome e data de nascimento (dd/mm/aaaa:)");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa (Pessoa p) {
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

// Função para a operação push (empilhar)
No* empilhar (No *topo) {  // Ponteiro para o topo
    No *novo = malloc(sizeof(No)); // novo é uma variável do tipo ponteiro para o no

    if (novo) {
        novo->p = ler_pessoa(); // Essa função cria lá dentro dela uma pessoa, preenche as informações e retorna Pessoa (será o novo topo da pilha)
        novo->proximo = topo; // Topo atual ficará abaixo do novo nó
        return novo;
    } else {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
}

int main(void) {
    No *topo = NULL;
    int opcao;

    do {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            printf("\nOpção inválida!!!\n");
            continue;
        }
    } while (opcao != 0);

    return 0;
}
