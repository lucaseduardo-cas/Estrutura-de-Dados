/*
8) Faça o esquema de uma implementação sequencial e estática de uma pilha.
*/

#include <stdio.h>
#include <stdlib.h> // Incluído conforme sua preferência, embora não use malloc nesta versão

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = 0;
}

void push(Pilha *p, int valor) {
    if (p->topo == MAX) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->dados[p->topo] = valor;
    p->topo++;
}

int pop(Pilha *p) {
    if (p->topo == 0) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    p->topo--;
    return p->dados[p->topo];
}

int main() {
    Pilha minhaPilha;

    inicializarPilha(&minhaPilha);

    printf("--- Testando Pilha ---\n");

    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);

    printf("Elemento desempilhado: %d\n", pop(&minhaPilha));
    printf("Elemento desempilhado: %d\n", pop(&minhaPilha));

    push(&minhaPilha, 40);

    printf("Elemento desempilhado: %d\n", pop(&minhaPilha));
    printf("Elemento desempilhado: %d\n", pop(&minhaPilha));
    printf("Elemento desempilhado: %d\n", pop(&minhaPilha)); // Tentando desempilhar de pilha vazia

    return 0;
}
