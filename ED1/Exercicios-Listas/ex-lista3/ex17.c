#include <stdio.h>
#include <stdlib.h>

/*
17) Implemente a funcionalidade de uma fila a partir de um TAD pilha (sugestão: use 2 pilhas).
*/

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

typedef struct {
    Pilha entrada;
    Pilha saida;
} Fila;

void inicializarPilha(Pilha *p) {
    p->topo = 0;
}

void inicializarFila(Fila *f) {
    inicializarPilha(&f->entrada);
    inicializarPilha(&f->saida);
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

void enfileirar(Fila *f, int x) {
    push(&f->entrada, x);
}

int desenfileirar(Fila *f, int *x) {
    if (f->saida.topo == 0) {
        while (f->entrada.topo > 0) {
            push(&f->saida, pop(&f->entrada));
        }
    }

    if (f->saida.topo == 0) {
        printf("Erro: Fila vazia!\n");
        return 0;
    }

    *x = pop(&f->saida);
    return 1;
}

void imprimirFila(Fila *f) {
    Pilha tempEntrada, tempSaida;
    int valor;

    inicializarPilha(&tempEntrada);
    inicializarPilha(&tempSaida);

    while (f->saida.topo > 0) {
        push(&tempSaida, pop(&f->saida));
    }

    printf("Fila (inicio -> fim): ");
    while (tempSaida.topo > 0) {
        valor = pop(&tempSaida);
        printf("%d ", valor);
        push(&f->saida, valor);
    }

    while (f->entrada.topo > 0) {
        push(&tempEntrada, pop(&f->entrada));
    }

    while (tempEntrada.topo > 0) {
        valor = pop(&tempEntrada);
        printf("%d ", valor);
        push(&f->entrada, valor);
    }

    if (f->entrada.topo == 0 && f->saida.topo == 0) {
        printf("Vazia");
    }
    printf("\n");
}

int main() {
    Fila minhaFila;
    inicializarFila(&minhaFila);

    printf("--- Testando Fila com 2 Pilhas ---\n");
    imprimirFila(&minhaFila);

    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    imprimirFila(&minhaFila);

    int valorRemovido;
    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }
    imprimirFila(&minhaFila);

    enfileirar(&minhaFila, 30);
    enfileirar(&minhaFila, 40);
    imprimirFila(&minhaFila);

    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }
    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }
    imprimirFila(&minhaFila);

    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }
    imprimirFila(&minhaFila);

    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }

    return 0;
}
