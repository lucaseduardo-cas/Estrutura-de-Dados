#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;       // índice do próximo espaço livre (tamanho da pilha)
    float *vetor;   // array dinâmico
} Pilha;

// Inicializa pilha
Pilha* inicializaPilha(void) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    p->topo = 0;
    p->vetor = NULL;   // começa vazio
    return p;
}

// Empilha (push)
void empilha(Pilha *p, float v) {
    // aumenta espaço em +1 float
    p->vetor = (float*) realloc(p->vetor, (p->topo + 1) * sizeof(float));
    if (p->vetor == NULL) {
        printf("Erro de realocação!\n");
        exit(1);
    }
    p->vetor[p->topo] = v;
    p->topo++;
}

// Desempilha (pop)
float desempilha(Pilha *p) {
    if (p->topo == 0) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    float v = p->vetor[p->topo - 1];
    p->topo--;

    // diminui tamanho do array
    p->vetor = (float*) realloc(p->vetor, p->topo * sizeof(float));
    return v;
}

// Imprime pilha (do fundo para o topo)
void imprimePilha(Pilha *p) {
    for (int i = 0; i < p->topo; i++) {
        printf("%3.2f\n", p->vetor[i]);
    }
    printf("\n");
}

int main(void) {
    Pilha *p = inicializaPilha();
    float valor;

    printf("Digite valores (0 para sair):\n");
    while (1) {
        scanf("%f", &valor);
        if (valor == 0) break;
        empilha(p, valor);
    }

    printf("\nConteúdo da pilha:\n");
    imprimePilha(p);

    printf("\nDesempilhando:\n");
    while (p->topo > 0) {
        printf("Retirado: %.2f\n", desempilha(p));
    }

    free(p->vetor);
    free(p);

    return 0;
}
