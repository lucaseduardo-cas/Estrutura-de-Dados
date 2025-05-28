/*
1. Faça uma função para verificar se os elementos de uma fila estão ordenados de forma crescente
*/

#include <stdio.h>
#define MAX 50

typedef struct {
    int dados[MAX];
    int ini;
    int fim;
} Fila;

// Inicializa a fila
void inicializaFila(Fila *f) {
    f->ini = 0;
    f->fim = 0;
}

// Insere um valor na fila
void enfileira(Fila *f, int valor) {
    if (f->fim < MAX) {
        f->dados[f->fim++] = valor;
    }
}

// Verifica se está ordenada de forma crescente
int estaOrdenada(Fila *f) {
    for (int i = f->ini; i < f->fim - 1; i++) {
        if (f->dados[i] > f->dados[i + 1]) {
            return 0; // Não está ordenada
        }
    }
    return 1; // Está ordenada
}

int main() {
    Fila f;
    inicializaFila(&f);

    // Exemplo: Fila com elementos ordenados
    enfileira(&f, 1);
    enfileira(&f, 3);
    enfileira(&f, 5);
    enfileira(&f, 7);

    if (estaOrdenada(&f))
        printf("A fila está em ordem crescente.\n");
    else
        printf("A fila NÃO está em ordem crescente.\n");

    return 0;
}
