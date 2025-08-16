#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = NULL;
}

void empilha(int dado, Pilha *p) {
    No *ptr = (No*) malloc(sizeof(No));
    if(ptr == NULL) {
        printf("Erro de alocação de nó.\n");
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

int desempilha(Pilha *p) {
    No* ptr = p->topo;
    int dado;
    if(ptr == NULL) {
        printf("Pilha vazia.\n");
        //return;
    } else {
        //p->topo = p->topo->prox;
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprimePilha(Pilha *p) {
    No *ptr = p->topo;
    if(ptr == NULL) {
        printf("Pilha vazia.\n");
        return;
    } else {
        while(ptr != NULL) {
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
    }
}

int main(void) {
    Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
    if (p1 == NULL) {
        printf("Erro de alocação de pilha.\n");
        exit(0);
    } else {
        inicializaPilha(p1);
        empilha(10, p1);
        empilha(20, p1);
        empilha(30, p1);

        printf("Imprimindo pilha: ");
        imprimePilha(p1);

        printf("\n\n");
        printf("\nTentando desempilhar - resultado: %d ", desempilha(p1));
        imprimePilha(p1);
        printf("\nTentando desempilhar - resultado: %d ", desempilha(p1));
        imprimePilha(p1);
        printf("\nTentando desempilhar - resultado: %d ", desempilha(p1));
        imprimePilha(p1);
    }

    return 0;
}