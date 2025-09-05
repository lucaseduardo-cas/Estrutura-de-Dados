#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elementos[MAX];
    int inicio, fim, nItens;
} Fila;

Fila *cria(void) {
    Fila *f;
    f = (Fila*) malloc(sizeof(Fila));
    if(!f) {
        perror(NULL);
        exit(1);
    }
    f->inicio = 0;
    f->fim = 0;
    f->nItens = 0;
}

void enfilera (Fila *f, int A) {
    if (f->nItens == MAX) {
        printf("fila cheia.\n");
        exit(1);
    }
    f->elementos [f->fim] = A;
    f->fim++;
    f->nItens++;
    if(f->fim == MAX) {
        f->fim = 0;
    }
}

int desenfilera (Fila *f) {
    int valor;
    if(f->nItens == 0) {
        printf("fila vazia.\n");
        exit(1);
    }
    valor = f->elementos[f->inicio];
    f->inicio++;
    f->nItens--;
    if(f->inicio == MAX) {
        f->inicio = 0;
    }
    return valor;
}

void destroiFila(Fila *f) {
    free(f);
}

int mostraFila (Fila *f) {
    int i;
    if(f->nItens == 0) {
        printf("fila vazia.\n");
        exit(1);
    }
    printf("Elementos da fila circular: ");
    for (i = f->inicio; i != f->fim; i = (i + 1) % MAX) {
        printf("%d, ", f->elementos[i]);
    }
    printf("%d\n", f->elementos[i]);
}

int main(void) {
    int valor;
    char funcao;
    Fila *minhaFila = cria();

    while(1) {
        printf("\nDigite:\n");
        printf("   (e) para enfileirar\n");
        printf("   (d) para desenfileirar\n");
        printf("   (i) para imprimir\n");
        printf("   (f) para finalizar\n");
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
                if (valor != -1)
                    printf("\nO valor desenfileirado é: %d\n", valor);
                break;
            case 'i':
                mostraFila(minhaFila);
                break;
            case 'f':
                destroiFila(minhaFila);
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}