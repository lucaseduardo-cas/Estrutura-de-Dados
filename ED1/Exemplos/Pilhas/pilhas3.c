/*
• Desenvolva uma rotina para inverter a posição dos elementos de uma pilha P
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Pilha {
    int topo;
    float vet[MAX];
} Pilha;

Pilha *inicializaPilha(void) {
    Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
    p1->topo = 0;
}

void empilhaPilha(Pilha *p1, float v) {
    if (p1->topo == MAX) {
        printf("\nPilha cheia!\n");
        exit(1);
    }
    p1->vet[p1->topo] = v;
    p1->topo++;
}

float desempilhaPilha(Pilha *p1) {
    float v;
    if (p1->topo == MAX) {
        printf("\nPilha vazia!\n");
        exit(1);
    }
    
    v = p1->vet[p1->topo];
    p1->topo++;
    return v;
}

int main(void) {
    Pilha *valor;
    float dado = 10.0;

    valor = (Pilha*) malloc(sizeof(Pilha));
    if (valor == NULL) {
        printf("\nErro de alocação de memória\n");
        exit(0);
    } else {
        //inicializaPilha(valor);
        valor = inicializaPilha();
        for (int i = 0; i < MAX; i++) {
            empilhaPilha(valor, dado);
            dado += 10.0;
        }
        printf("\nImprimindo pilha:\n");
        for (int i = 0; i < valor->topo; i++) {
            printf("%.1f\n", valor->vet[i]);
        }

        valor->topo = 0;
        printf("\nImprimindo pilha invertida:\n");
        for (int i = 0; i < MAX; i++) {
            printf("%.1f\n", valor->vet[i]);
        }
    }

    return 0;
}