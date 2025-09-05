/*
Desenvolva uma rotina para inverter a posição dos elementos de uma pilha P
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int topo;
    float vet[MAX];
} Pilha;

// Cria uma pilha vazia
Pilha* cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

// Empilha um valor
void push(Pilha* p, float v) {
    if (p->topo == MAX) {
        printf("Pilha cheia!\n");
        exit(1);
    }
    p->vet[p->topo] = v;
    p->topo++;
}

// Desempilha um valor
float pop(Pilha* p) {
    if (p->topo == 0) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    p->topo--;
    return p->vet[p->topo];
}

// Imprime a pilha
void imprime(Pilha* p) {
    printf("Pilha: ");
    for (int i = p->topo - 1; i >= 0; i--) {
    printf("%.1f ", p->vet[i]);
    }
    printf("\n");
}

// Inverte os elementos da pilha P
void inverter_pilha(Pilha* p) {
    Pilha* aux1 = cria();
    Pilha* aux2 = cria();

    // Move p → aux1 (primeira inversão)
    while (p->topo > 0) {
        push(aux1, pop(p));
    }

    // Move aux1 → aux2 (segunda inversão)
    while (aux1->topo > 0) {
        push(aux2, pop(aux1));
    }

    // Move aux2 → p (agora sim invertida!)
    while (aux2->topo > 0) {
        push(p, pop(aux2));
    }

    free(aux1);
    free(aux2);
}


int main(void) {
    Pilha* p = cria();

    // Empilha valores 1, 2, 3
    push(p, 1);
    push(p, 2);
    push(p, 3);

    printf("Antes de inverter:\n");
    imprime(p);  // Deve mostrar: 1 2 3

    inverter_pilha(p);

    printf("Depois de inverter:\n");
    imprime(p);  // Deve mostrar: 3 2 1

    free(p);
    return 0;
}
