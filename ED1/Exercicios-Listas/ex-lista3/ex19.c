/*
19) Implemente o TAD da lista encadeada e dinâmica.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No* insere(No *lista, int x) {
    No *novo = malloc(sizeof(No));
    novo->valor = x;
    novo->prox = lista;
    return novo;
}

void imprime(No *lista) {
    while (lista) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

int main() {
    No *minha_lista = NULL;

    minha_lista = insere(minha_lista, 10);
    minha_lista = insere(minha_lista, 20);
    minha_lista = insere(minha_lista, 30);
    minha_lista = insere(minha_lista, 40);

    imprime(minha_lista);

    // Liberar a memória alocada
    No *atual = minha_lista;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}
