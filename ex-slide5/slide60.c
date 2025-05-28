#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Define a estrutura da pilha
typedef struct pilha {
    int topo;
    float vet[MAX];
} Pilha;

// Cria uma nova pilha
Pilha* cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

// Empilha um valor
void push(Pilha* p, float v) {
    if (p->topo == MAX) {
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
    p->vet[p->topo] = v;
    p->topo++;
}

// Desempilha um valor
float pop(Pilha* p) {
    if (p->topo == 0) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    p->topo--;
    return p->vet[p->topo];
}

// Libera a pilha
void libera(Pilha* p) {
    free(p);
}

int main(void) {
    Pilha* p = cria(); // Cria a pilha

    // Empilha alguns valores
    push(p, 10.5);
    push(p, 20.0);
    push(p, 30.25);

    printf("Desempilhando valores:\n");

    // Desempilha e imprime os valores
    while (p->topo > 0) {
        float valor = pop(p);
        printf("Valor desempilhado: %.2f\n", valor);
    }

    libera(p); // Libera memória
    return 0;
}
