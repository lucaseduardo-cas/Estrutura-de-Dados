/*
11) Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar bool

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo; // Indica o número de elementos na pilha, e a posição do próximo elemento a ser inserido
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

int pop(Pilha *p) { // Função pop estava faltando
    if (p->topo == 0) {
        printf("Erro: Pilha vazia! Nao e possivel desempilhar.\n");
        return -1; // Valor sentinela para indicar erro ou pilha vazia
    }
    p->topo--;
    return p->dados[p->topo];
}

int pilhasIguais(Pilha *p1, Pilha *p2) {
    if (p1->topo != p2->topo) {
        return 0; // Se os tamanhos são diferentes, as pilhas não são iguais
    }

    for (int i = 0; i < p1->topo; i++) {
        if (p1->dados[i] != p2->dados[i]) {
            return 0; // Se algum elemento na mesma posição é diferente, as pilhas não são iguais
        }
    }

    return 1; // Se chegar aqui, as pilhas são iguais
}

int main() {
    Pilha pilhaA, pilhaB, pilhaC;

    inicializarPilha(&pilhaA);
    inicializarPilha(&pilhaB);
    inicializarPilha(&pilhaC);

    // Pilhas A e B iguais
    push(&pilhaA, 10);
    push(&pilhaA, 20);
    push(&pilhaA, 30);

    push(&pilhaB, 10);
    push(&pilhaB, 20);
    push(&pilhaB, 30);

    // Pilha C diferente (menos elementos)
    push(&pilhaC, 10);
    push(&pilhaC, 20);

    printf("Comparando Pilha A e Pilha B:\n");
    if (pilhasIguais(&pilhaA, &pilhaB)) {
        printf("Pilha A e Pilha B sao iguais.\n");
    } else {
        printf("Pilha A e Pilha B NAO sao iguais.\n");
    }

    printf("\nComparando Pilha A e Pilha C:\n");
    if (pilhasIguais(&pilhaA, &pilhaC)) {
        printf("Pilha A e Pilha C sao iguais.\n");
    } else {
        printf("Pilha A e Pilha C NAO sao iguais.\n");
    }

    // Pilha C diferente (mesmo tamanho, mas elementos diferentes)
    pop(&pilhaC); // Remove o 20
    push(&pilhaC, 40); // Adiciona 40
    push(&pilhaC, 30); // Adiciona 30 (agora tem 10, 40, 30)

    printf("\nComparando Pilha A e Pilha C (apos alteracao de C):\n");
    if (pilhasIguais(&pilhaA, &pilhaC)) {
        printf("Pilha A e Pilha C sao iguais.\n");
    } else {
        printf("Pilha A e Pilha C NAO sao iguais.\n");
    }

    return 0;
}
