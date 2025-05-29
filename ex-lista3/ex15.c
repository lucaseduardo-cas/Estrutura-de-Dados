/*
15) Desenvolva uma função (com parâmetros) para testar se uma fila F1 tem mais
elementos do que uma fila F2 (não se esqueça de mexer nas filas apenas através
de seus operadores primitivos).
*/

#include <stdio.h>
#include <stdlib.h>


#define MAX 50

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = f->fim = 0;
}

int enfileirar(Fila *f, int valor) {
    if (f->fim == MAX) {
        printf("Erro: Fila cheia!\n");
        return 0;
    }
    f->dados[f->fim] = valor;
    f->fim++;
    return 1;
}

int desenfileirar(Fila *f, int *valor) {
    if (f->inicio == f->fim) {
        printf("Erro: Fila vazia!\n");
        return 0;
    }
    *valor = f->dados[f->inicio];
    f->inicio++;
    return 1;
}

int filaMaior(Fila *f1, Fila *f2) {
    int tamanho1 = f1->fim - f1->inicio;
    int tamanho2 = f2->fim - f2->inicio;
    return (tamanho1 > tamanho2);
}

int main() {
    Fila fila1, fila2;

    inicializarFila(&fila1);
    inicializarFila(&fila2);

    // Teste 1: Fila1 > Fila2
    enfileirar(&fila1, 1);
    enfileirar(&fila1, 2);
    enfileirar(&fila1, 3);
    enfileirar(&fila2, 10);

    printf("Teste 1: Fila1 (3 elementos) vs Fila2 (1 elemento)\n");
    if (filaMaior(&fila1, &fila2)) {
        printf("Fila1 tem mais elementos que Fila2 (Correto).\n");
    } else {
        printf("Fila1 NAO tem mais elementos que Fila2 (Incorreto).\n");
    }

    // Teste 2: Fila1 < Fila2
    enfileirar(&fila2, 20);
    enfileirar(&fila2, 30);
    enfileirar(&fila2, 40); // Fila2 agora tem 4 elementos

    printf("\nTeste 2: Fila1 (3 elementos) vs Fila2 (4 elementos)\n");
    if (filaMaior(&fila1, &fila2)) {
        printf("Fila1 tem mais elementos que Fila2 (Incorreto).\n");
    } else {
        printf("Fila1 NAO tem mais elementos que Fila2 (Correto).\n");
    }

    // Teste 3: Fila1 == Fila2
    int val;
    desenfileirar(&fila2, &val); // Fila2 agora tem 3 elementos
    printf("\nTeste 3: Fila1 (3 elementos) vs Fila2 (3 elementos)\n");
    if (filaMaior(&fila1, &fila2)) {
        printf("Fila1 tem mais elementos que Fila2 (Incorreto).\n");
    } else {
        printf("Fila1 NAO tem mais elementos que Fila2 (Correto).\n");
    }

    return 0;
}
