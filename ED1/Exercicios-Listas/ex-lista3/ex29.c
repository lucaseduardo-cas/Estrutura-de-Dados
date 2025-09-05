/*
29)
Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas os testes
de fila e pilha vazias, as operações Enfileira, Desenfileira, Empilha,
Desempilha, e uma variável aux do TipoItem, escreva uma função que inverta a
ordem dos elementos da fila.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar 'bool'

// --- Definições das estruturas para Pilha ---
typedef struct no_pilha {
    int valor;
    struct no_pilha *prox;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

// --- Definições das estruturas para Fila ---
typedef struct no_fila {
    int valor;
    struct no_fila *prox;
} NoFila;

typedef struct {
    NoFila *ini, *fim;
} Fila;

// TipoItem para o valor a ser manipulado
typedef int TipoItem;

// --- Funções de Pilha ---
void inicializaPilha(Pilha *p) {
    p->topo = NULL;
}

bool pilhaVazia(Pilha *p) {
    return (p->topo == NULL);
}

void empilha(Pilha *p, TipoItem x) {
    NoPilha *novo = (NoPilha*) malloc(sizeof(NoPilha));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria na empilha.\n");
        exit(1);
    }
    novo->valor = x;
    novo->prox = p->topo;
    p->topo = novo;
}

TipoItem desempilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Nao e possivel desempilhar.\n");
        return -1; // Valor sentinela para indicar erro
    }
    NoPilha *temp = p->topo;
    TipoItem v = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return v;
}

// --- Funções de Fila ---
void inicializaFila(Fila *f) {
    f->ini = NULL;
    f->fim = NULL;
}

bool filaVazia(Fila *f) {
    return (f->ini == NULL);
}

void enfileira(Fila *f, TipoItem x) {
    NoFila *novo = (NoFila*) malloc(sizeof(NoFila));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria na enfileira.\n");
        exit(1);
    }
    novo->valor = x;
    novo->prox = NULL;
    if (f->fim) {
        f->fim->prox = novo;
    } else {
        f->ini = novo;
    }
    f->fim = novo;
}

TipoItem desenfileira(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nao e possivel desenfileirar.\n");
        return -1; // Valor sentinela para indicar erro
    }
    NoFila *temp = f->ini;
    TipoItem v = temp->valor;
    f->ini = temp->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return v;
}

// --- Função para inverter a fila ---
void inverterFila(Fila *f, Pilha *p) {
    TipoItem aux;

    while (!filaVazia(f)) {
        aux = desenfileira(f);
        empilha(p, aux);
    }

    while (!pilhaVazia(p)) {
        aux = desempilha(p);
        enfileira(f, aux);
    }
}

// --- Funções de impressão para teste ---
void imprimePilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Elementos na pilha (do topo para a base):\n");
    NoPilha *atual = p->topo;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

void imprimeFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos na fila (do inicio para o fim): ");
    NoFila *atual = f->ini;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Fila minha_fila;
    Pilha minha_pilha;

    inicializaFila(&minha_fila);
    inicializaPilha(&minha_pilha);

    printf("Enfileirando elementos na fila original:\n");
    enfileira(&minha_fila, 1);
    enfileira(&minha_fila, 2);
    enfileira(&minha_fila, 3);
    enfileira(&minha_fila, 4);
    enfileira(&minha_fila, 5);
    imprimeFila(&minha_fila);

    printf("\nInvertendo a fila...\n");
    inverterFila(&minha_fila, &minha_pilha);
    printf("Fila apos a inversao:\n");
    imprimeFila(&minha_fila);

    // Teste com uma fila vazia (não deve fazer nada)
    printf("\nTestando com uma fila vazia:\n");
    Fila fila_vazia;
    Pilha pilha_temp;
    inicializaFila(&fila_vazia);
    inicializaPilha(&pilha_temp);
    imprimeFila(&fila_vazia);
    inverterFila(&fila_vazia, &pilha_temp);
    imprimeFila(&fila_vazia);

    // Liberar a memória alocada na fila original (se houver elementos)
    while (!filaVazia(&minha_fila)) {
        desenfileira(&minha_fila);
    }
    // Liberar a memória alocada na fila vazia de teste (se houver elementos residuais)
    while (!filaVazia(&fila_vazia)) {
        desenfileira(&fila_vazia);
    }
    // A pilha auxiliar deve estar vazia ao final da função inverterFila, mas para garantir
    while (!pilhaVazia(&minha_pilha)) {
        desempilha(&minha_pilha);
    }
    while (!pilhaVazia(&pilha_temp)) {
        desempilha(&pilha_temp);
    }

    return 0;
}
