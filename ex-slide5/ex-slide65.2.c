/*
Pág 65 Slide
Desenvolva uma rotina para inverter a posição dos
elementos de uma pilha P
*/

#include <stdio.h>
#define MAX 10

typedef struct {
    int vet[MAX];
    int topo;
} Pilha;

void push(Pilha *p, int v) {
    if (p->topo < MAX - 1) {
        p->vet[++p->topo] = v;
    } else {
        printf("Pilha cheia!\n");
    }
}

int pop(Pilha *p) {
    if (p->topo >= 0) {
        return p->vet[p->topo--];
    } else {
        printf("Pilha vazia!\n");
        return -1; // Valor padrão de erro
    }
}

int main() {
    Pilha p = {.topo = -1}, aux = {.topo = -1};
    int n, i, valor;

    printf("Quantos elementos deseja empilhar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        push(&p, valor);
    }

    // Inverte a pilha
    while (p.topo >= 0) {
        int temp = pop(&p);
        push(&aux, temp);
    }

    printf("\nPilha invertida:\n");

    // Exibe pilha invertida
    while (aux.topo >= 0) {
        printf("%d\n", pop(&aux));
    }

    return 0;
}
