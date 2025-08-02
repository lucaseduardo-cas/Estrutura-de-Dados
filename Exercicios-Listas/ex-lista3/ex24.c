/*
24) Usando os conceitos de TAD, implemente uma fila sobre uma lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *ini, *fim;
} Fila;

void enfileira(Fila *f, int x) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    novo->valor = x;
    novo->prox = NULL;
    if (f->fim) {
        f->fim->prox = novo;
    } else {
        f->ini = novo;
    }
    f->fim = novo;
}

int desenfileira(Fila *f) {
    if (f->ini == NULL) {
        printf("Fila vazia! Nao e possivel desenfileirar.\n");
        return -1; // Valor sentinela para indicar erro ou fila vazia
    }
    No *temp = f->ini;
    int v = temp->valor;
    f->ini = temp->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return v;
}

void imprimeFila(Fila *f) {
    if (f->ini == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos na fila (do inicio para o fim):\n");
    No *atual = f->ini;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Fila minha_fila;
    minha_fila.ini = NULL;
    minha_fila.fim = NULL; // Inicializa a fila como vazia

    printf("Enfileirando elementos...\n");
    enfileira(&minha_fila, 100);
    imprimeFila(&minha_fila);
    enfileira(&minha_fila, 200);
    imprimeFila(&minha_fila);
    enfileira(&minha_fila, 300);
    imprimeFila(&minha_fila);

    printf("\nDesenfileirando elementos...\n");
    int valor;
    valor = desenfileira(&minha_fila);
    if (valor != -1) {
        printf("Desenfileirou: %d\n", valor);
    }
    imprimeFila(&minha_fila);

    valor = desenfileira(&minha_fila);
    if (valor != -1) {
        printf("Desenfileirou: %d\n", valor);
    }
    imprimeFila(&minha_fila);

    valor = desenfileira(&minha_fila);
    if (valor != -1) {
        printf("Desenfileirou: %d\n", valor);
    }
    imprimeFila(&minha_fila);

    valor = desenfileira(&minha_fila); // Tenta desenfileirar de uma fila vazia
    if (valor != -1) {
        printf("Desenfileirou: %d\n", valor);
    }
    imprimeFila(&minha_fila);

    // Liberar a memória alocada (caso ainda haja algum elemento por um desenfileira falho)
    No *atual = minha_fila.ini;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}
