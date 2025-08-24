/*
1. Lista Sequencial

É uma estrutura de dados que usa um vetor (array) para armazenar os elementos em posições contíguas na memória. O tamanho máximo é fixo e definido na criação.

Características:
- Acesso rápido por índice (lista[0], lista[1], ...).
- Inserções e remoções são lentas se feitas no início ou no meio.
- Uso fixo de memória.

Exemplo, teste de mesa:
[10][20][30][-][-]   → tamanho atual = 3

1. Queremos inserir o número 15 na posição 1 (entre 10 e 20):
[10][20][20][30][-]   → copia 30 para 3, 20 para 2

2. Insere:
[10][15][20][30][-]
*/

// Código em C:
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

void inserir(Lista *l, int valor, int pos) {
    if (l->tamanho == MAX || pos < 0 || pos > l->tamanho) {
        printf("Erro: posição inválida ou lista cheia.\n");
        return;
    }

    for (int i = l->tamanho; i > pos; i--) {
        l->dados[i] = l->dados[i - 1];
    }

    l->dados[pos] = valor;
    l->tamanho++;
}

void exibir(Lista *l) {
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

int main() {
    Lista l = {.tamanho = 3, .dados = {10, 20, 30}};

    printf("Antes da inserção:\n");
    exibir(&l);

    inserir(&l, 15, 1);

    printf("Depois da inserção:\n");
    exibir(&l);

    return 0;
}

