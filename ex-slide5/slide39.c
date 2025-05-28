#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int topo;           // Índice do topo da pilha
    float vet[MAX];     // Vetor que armazena os elementos
} Pilha;

// Cria e inicializa uma nova pilha
Pilha* cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    p->topo = 0;
    return p;
}

// Empilha (insere) um elemento no topo
void push(Pilha* p, float v) { // push: empilhar
    if (p->topo == MAX) {
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
    p->vet[p->topo] = v;
    p->topo++;
}

// Desempilha (remove) o elemento do topo
float pop(Pilha* p) { // pop: desempilhar
    if (p->topo == 0) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    p->topo--;
    return p->vet[p->topo];
}

// Libera a memória da pilha
void libera(Pilha* p) {
    free(p);
}

// Exibe os elementos da pilha (para teste)
void imprime(Pilha* p) {
    printf("Pilha: ");
    for (int i = 0; i < p->topo; i++) {
        printf("%.1f ", p->vet[i]);
    }
    printf("\n");
}

// Função principal para testar
int main(void) {
    Pilha* minhaPilha = cria();

    push(minhaPilha, 10);
    push(minhaPilha, 20);
    push(minhaPilha, 30);

    imprime(minhaPilha);

    float valor = pop(minhaPilha);
    printf("Desempilhado: %.1f\n", valor);

    imprime(minhaPilha);

    libera(minhaPilha);
    return 0;
}
