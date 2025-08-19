#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elementos[MAX];
    int inicio;
    int fim;
} Fila;

Fila *cria(void) {
    Fila *f;
    f = (Fila*) malloc(sizeof(Fila));
    if (!f) {
        perror(NULL);
        exit(1);
    }
    f->inicio = 0;
    f->fim = 0;
}

void enfilera(Fila *f, int numero) {
    if (f->fim == MAX && f->inicio == 0) {
        printf("Fila cheia!\n");
        exit(1);
    }
    f->elementos[f->fim] = numero;
    f->fim++;
}

int desenfilera(Fila *f) {
    int r;
    if (f->inicio == f->fim) {
        printf("Fila vazia!\n");
        exit(1);
    }
    r = f->elementos[f->inicio];
    f->inicio++;
    return r;
}

void destroiFila(Fila *f) {
    free(f);
}

int main(void) {
    int valor;
    char funcao;
    Fila *minhaFila = cria();

    funcao = 'a';
    while(funcao != 'f') {
        printf("\nDigite:\n");
        printf("   (e) para enfileirar\n");
        printf("   (d) para desenfileirar\n");
        printf("   (f) para sair\n");
        printf("Opção: ");
        scanf(" %c", &funcao);

        switch (funcao) {
            case 'e':
                printf("\nDigite um valor a ser enfileirado: ");
                scanf("%d", &valor);
                enfilera(minhaFila, valor);
                break;
            case 'd':
                valor = desenfilera(minhaFila);
                printf("\nO valor desenfileirado é: %i", valor);
                break;
            case 'f':
                destroiFila(minhaFila);
                break;
            default:
                break;
        }
    }

    return 0;
}