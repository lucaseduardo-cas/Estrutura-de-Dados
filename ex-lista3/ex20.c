/*
20) Utilizando o TAD lista anterior, modele e implemente um sistema de cadastro de alunos de uma universidade.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char nome[30];
    struct item *prox;
} Item;

Item* inserirItem(Item *lista, char nome[]) {
    Item *novo = malloc(sizeof(Item));
    strcpy(novo->nome, nome);
    novo->prox = lista;
    return novo;
}

Item* removerItem(Item *lista, char nome[]) {
    Item *ant = NULL, *atual = lista;
    while (atual && strcmp(atual->nome, nome) != 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (!atual) return lista;
    if (!ant) lista = atual->prox;
    else ant->prox = atual->prox;
    free(atual);
    return lista;
}

void imprimeItens(Item *lista) {
    while (lista) {
        printf("%s\n", lista->nome);
        lista = lista->prox;
    }
}

int main() {
    Item *cadastro_alunos = NULL;

    cadastro_alunos = inserirItem(cadastro_alunos, "Joao");
    cadastro_alunos = inserirItem(cadastro_alunos, "Maria");
    cadastro_alunos = inserirItem(cadastro_alunos, "Pedro");
    cadastro_alunos = inserirItem(cadastro_alunos, "Ana");

    printf("Alunos cadastrados:\n");
    imprimeItens(cadastro_alunos);

    cadastro_alunos = removerItem(cadastro_alunos, "Pedro");
    printf("\nAlunos apos a remocao de Pedro:\n");
    imprimeItens(cadastro_alunos);

    cadastro_alunos = removerItem(cadastro_alunos, "Joao");
    printf("\nAlunos apos a remocao de Joao:\n");
    imprimeItens(cadastro_alunos);

    // Liberar a memória alocada
    Item *atual = cadastro_alunos;
    while (atual != NULL) {
        Item *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}
