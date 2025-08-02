/*
14) Faça um esquema da implementação estática e seqüencial de uma fila.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = f->fim = 0;
}

int enfileirar(Fila *f, int valor) {
    if (f->fim == MAX) {
        printf("Erro: Fila cheia!\n");
        return 0;
    }
    f->dados[f->fim] = valor;
    f->fim++;
    return 1;
}

int desenfileirar(Fila *f, int *valor) {
    if (f->inicio == f->fim) {
        printf("Erro: Fila vazia!\n");
        return 0;
    }
    *valor = f->dados[f->inicio];
    f->inicio++;
    return 1;
}

void imprimirFila(Fila *f) {
    if (f->inicio == f->fim) {
        printf("Fila: Vazia\n");
        return;
    }
    printf("Fila (inicio -> fim): ");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    Fila minhaFila;
    inicializarFila(&minhaFila);

    printf("--- Testando Fila ---\n");
    imprimirFila(&minhaFila);

    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);
    imprimirFila(&minhaFila);

    int valorRemovido;
    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }
    imprimirFila(&minhaFila);

    enfileirar(&minhaFila, 40);
    imprimirFila(&minhaFila);

    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }
    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }
    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido);
    }
    desenfileirar(&minhaFila, &valorRemovido); // Tentando desenfileirar de fila vazia

    return 0;
}
