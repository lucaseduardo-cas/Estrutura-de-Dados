/*
10) Desenvolva uma função para testar se uma pilha P1 tem mais elementos que uma pilha P2.
*/

#include <stdio.h>
#include <stdlib.h>

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

int pilhaMaior(Pilha *p1, Pilha *p2) {
    return (p1->topo > p2->topo);
}

int main() {
    Pilha pilha1, pilha2;

    inicializarPilha(&pilha1);
    inicializarPilha(&pilha2);

    push(&pilha1, 10);
    push(&pilha1, 20);

    push(&pilha2, 5);

    if (pilhaMaior(&pilha1, &pilha2)) {
        printf("Pilha1 tem mais elementos que Pilha2.\n");
    } else {
        printf("Pilha1 NAO tem mais elementos que Pilha2.\n");
    }

    push(&pilha2, 15);
    push(&pilha2, 25);

    if (pilhaMaior(&pilha1, &pilha2)) {
        printf("Pilha1 tem mais elementos que Pilha2.\n");
    } else {
        printf("Pilha1 NAO tem mais elementos que Pilha2.\n");
    }

    return 0;
}
