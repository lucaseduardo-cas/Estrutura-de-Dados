/*
9) Desenvolva uma rotina para inverter a posição dos elementos de uma pilha P.
*/

#include <stdio.h>
#include <stdlib.h> // Incluído conforme sua preferência

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

void inverterPilha(Pilha *p) {
    Pilha aux1;
    Pilha aux2;
    int temp;

    inicializarPilha(&aux1);
    inicializarPilha(&aux2);

    while (p->topo > 0) { // Enquanto a pilha original não estiver vazia
        temp = pop(p);
        push(&aux1, temp);
    }

    while (aux1.topo > 0) { // Enquanto a primeira auxiliar não estiver vazia
        temp = pop(&aux1);
        push(&aux2, temp);
    }

    while (aux2.topo > 0) { // Enquanto a segunda auxiliar não estiver vazia
        temp = pop(&aux2);
        push(p, temp);
    }
}

void imprimirPilha(Pilha *p) {
    if (p->topo == 0) {
        printf("Pilha: Vazia\n");
        return;
    }
    printf("Pilha (topo -> base): ");
    for (int i = p->topo - 1; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int main() {
    Pilha minhaPilha;
    inicializarPilha(&minhaPilha);

    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);
    push(&minhaPilha, 40);

    printf("Pilha Original:\n");
    imprimirPilha(&minhaPilha);

    inverterPilha(&minhaPilha);

    printf("Pilha Invertida:\n");
    imprimirPilha(&minhaPilha);

    return 0;
}
