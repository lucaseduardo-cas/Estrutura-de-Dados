/*
- Deselocar os elementos para o inicio da fila (exercício)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    float elementos[MAX];
    int inicio;
    int fim;
} Fila;

// Inicializa a fila
void inicializa(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Enfileira um valor
void enfileira(Fila *f, float valor) {
    if (f->fim == MAX) {
        // Verifica se há espaço no início
        if (f->inicio > 0) {
            // Desloca os elementos para o início do vetor
            int j = 0;
            for (int i = f->inicio; i < f->fim; i++) {
                f->elementos[j++] = f->elementos[i];
            }
            f->fim = j;
            f->inicio = 0;
        } else {
            printf("Fila cheia!\n");
            return;
        }
    }

    f->elementos[f->fim] = valor;
    f->fim++;
}

// Desenfileira um valor
float desenfileira(Fila *f) {
    if (f->inicio == f->fim) {
        printf("Fila vazia!\n");
        exit(1);
    }

    float valor = f->elementos[f->inicio];
    f->inicio++;
    return valor;
}

// Imprime a fila atual
void imprime(Fila *f) {
    printf("Fila: ");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%.1f ", f->elementos[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializa(&f);

    // Etapa 1: Enfileirar os valores
    enfileira(&f, 1.0);
    enfileira(&f, 2.5);
    enfileira(&f, 3.2);
    enfileira(&f, 3.0);
    enfileira(&f, 7.3);

    printf("Fila cheia:\n");
    imprime(&f);

    // Etapa 2: Desenfileirar o primeiro elemento (1.0)
    float removido = desenfileira(&f);
    printf("\nDesenfileirando: %.1f\n", removido);

    // Etapa 3: Enfileirar novo elemento (5.4), que vai disparar o deslocamento
    enfileira(&f, 5.4);

    printf("\nFila após deslocamento e inclusão de 5.4:\n");
    imprime(&f);

    return 0;
}
