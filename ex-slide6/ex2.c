/*
2. Faça uma função que inverta uma fila F1, criando-se uma nova fila F2
*/

#include <stdio.h>
#define MAX 50

// Estrutura da fila
typedef struct {
    int dados[MAX];
    int ini, fim;
} Fila;

// Estrutura da pilha
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Inicializa a fila
void inicializaFila(Fila *f) {
    f->ini = f->fim = 0;
}

// Insere na fila
void enfileira(Fila *f, int valor) {
    if (f->fim < MAX) {
        f->dados[f->fim++] = valor;
    }
}

// Remove da fila
int desenfileira(Fila *f) {
    return f->dados[f->ini++];
}

// Inicializa a pilha
void inicializaPilha(Pilha *p) {
    p->topo = 0;
}

// Empilha
void push(Pilha *p, int valor) {
    p->dados[p->topo++] = valor;
}

// Desempilha
int pop(Pilha *p) {
    return p->dados[--p->topo];
}

// Função para inverter F1 e gerar F2
void inverterFila(Fila *f1, Fila *f2) {
    Pilha p;
    inicializaPilha(&p);

    // Passa da fila para a pilha
    while (f1->ini < f1->fim) {
        push(&p, desenfileira(f1));
    }

    // Passa da pilha para a nova fila (F2)
    while (p.topo > 0) {
        enfileira(f2, pop(&p));
    }
}

// Mostra os dados da fila
void exibirFila(Fila *f) {
    for (int i = f->ini; i < f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    Fila f1, f2;
    inicializaFila(&f1);
    inicializaFila(&f2);

    // Preenche a fila F1
    enfileira(&f1, 10);
    enfileira(&f1, 20);
    enfileira(&f1, 30);
    enfileira(&f1, 40);

    printf("Fila original (F1): ");
    exibirFila(&f1);

    inverterFila(&f1, &f2);

    printf("Fila invertida (F2): ");
    exibirFila(&f2);

    return 0;
}
