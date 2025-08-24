/*
23) Usando os conceitos de TAD, implemente uma pilha sobre uma lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void push(Pilha *p, int x) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    novo->valor = x;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia! Nao e possivel desempilhar.\n");
        return -1; // Valor sentinela para indicar erro ou pilha vazia
    }
    No *temp = p->topo;
    int v = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return v;
}

void imprimePilha(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Elementos na pilha (do topo para a base):\n");
    No *atual = p->topo;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

int main() {
    Pilha minha_pilha;
    minha_pilha.topo = NULL; // Inicializa a pilha como vazia

    printf("Empilhando elementos...\n");
    push(&minha_pilha, 10);
    imprimePilha(&minha_pilha);
    push(&minha_pilha, 20);
    imprimePilha(&minha_pilha);
    push(&minha_pilha, 30);
    imprimePilha(&minha_pilha);

    printf("\nDesempilhando elementos...\n");
    int valor;
    valor = pop(&minha_pilha);
    if (valor != -1) {
        printf("Desempilhou: %d\n", valor);
    }
    imprimePilha(&minha_pilha);

    valor = pop(&minha_pilha);
    if (valor != -1) {
        printf("Desempilhou: %d\n", valor);
    }
    imprimePilha(&minha_pilha);

    valor = pop(&minha_pilha);
    if (valor != -1) {
        printf("Desempilhou: %d\n", valor);
    }
    imprimePilha(&minha_pilha);

    valor = pop(&minha_pilha); // Tenta desempilhar de uma pilha vazia
    if (valor != -1) {
        printf("Desempilhou: %d\n", valor);
    }
    imprimePilha(&minha_pilha);

    // Liberar a memória alocada (caso ainda haja algum elemento por um pop falho)
    No *atual = minha_pilha.topo;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}
