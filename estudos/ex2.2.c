#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da pilha
typedef struct No {
    int dado;
    struct No* prox;
} No;

// Empilha um valor no topo
void push(No** topo, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = *topo;
    *topo = novo;
}

// Desempilha o topo e retorna o valor
int pop(No** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    No* temp = *topo;
    int valor = temp->dado;
    *topo = temp->prox;
    free(temp);
    return valor;
}

// Imprime a pilha do topo até o fim
void imprimir(No* topo) {
    printf("Pilha: ");
    while (topo != NULL) {
        printf("%d ", topo->dado);
        topo = topo->prox;
    }
    printf("\n");
}

int main() {
    No* pilha = NULL; // Início: pilha vazia

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    imprimir(pilha);  // Deve mostrar: 30 20 10

    int removido = pop(&pilha);
    printf("Desempilhado: %d\n", removido);

    imprimir(pilha);  // Deve mostrar: 20 10

    return 0;
}
