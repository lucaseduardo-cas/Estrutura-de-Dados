// Implementando uma pilha (Exemplo slide professor Rafael)


#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Pilha {
    int topo;
    float vet[MAX]; // Vetor do tipo float de tamanho MAX(5)
} Pilha;

Pilha* cria (void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0; /* inicializa com zero elementos */
    return p;
}

void push (Pilha* p, float v) {
    if (p->topo == MAX) { /* capacidade esgotada */
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }

    /* insere elemento na próxima posição livre */
    p->vet[p->topo] = v;
    p->topo++; //topo = topo + 1;
}

float pop (Pilha* p) {
    float v;
    if (p->topo == 0) {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }

    /* retira elemento do topo */
    p->topo--;
    v = p->vet[p->topo];
    return v;
}

void libera (Pilha* p) {
    free(p);
}

int main(void) {
    // 1. Criar a pilha
    Pilha* minhaPilha;
    minhaPilha = cria();

    // 2. Empilhar (push) os valores 10, 20, 30, 40, 50
    push(minhaPilha, 10.0);
    push(minhaPilha, 20.0);
    push(minhaPilha, 30.0);
    push(minhaPilha, 40.0);
    push(minhaPilha, 50.0);
    
    // 3. Imprimir os elementos para verificar
    printf("Elementos na pilha:\n");
    for (int i = minhaPilha->topo - 1; i >= 0; i--) {
        printf("%.1f\n", minhaPilha->vet[i]);
    }
    
    // 4. Desempilhar (pop) alguns valores
    float valor1 = pop(minhaPilha);
    float valor2 = pop(minhaPilha);
    float valor3 = pop(minhaPilha);
    float valor4 = pop(minhaPilha);
    float valor5 = pop(minhaPilha);
    
    printf("\nDesempilhou: %.1f\n", valor1);
    printf("Desempilhou: %.1f\n", valor2);
    printf("Desempilhou: %.1f\n", valor3);
    printf("Desempilhou: %.1f\n", valor4);
    printf("Desempilhou: %.1f\n", valor5);

    // 5. Verificar o estado da pilha depois do pop
    printf("\nElementos restantes na pilha:\n");
    for (int i = minhaPilha->topo - 1; i >= 0; i--) {
        printf("%.1f\n", minhaPilha->vet[i]);
    }

    // 6. Liberar a memória da pilha no final
    libera(minhaPilha);

    return 0;
}