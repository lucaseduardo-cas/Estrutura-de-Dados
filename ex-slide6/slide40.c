/*
Fila linear
*/

#include <stdio.h>
#include <stdlib.h>

#define Max 10

// Estrutura da fila
struct fila {
    int elementos[Max];
    int inicio, fim;
};

// Criação da fila
struct fila *cria(void) {
    struct fila *f;
    f = malloc(sizeof(struct fila));
    if (!f) {
        perror(NULL);
        exit(1);
    }
    f->inicio = 0;
    f->fim = 0;
    return f;
}

// Enfileirar
void enfileira(struct fila *f, int Numero) {
    if ((f->fim == Max && f->inicio == 0) || (f->fim == f->inicio - 1)) {
        printf("Fila cheia!\n");
        exit(1);
    }
    f->elementos[f->fim] = Numero;
    f->fim = f->fim + 1;
}

// Desenfileirar
int desenfileira(struct fila *f) {
    int r;
    if (f->inicio == f->fim) {
        printf("Fila vazia!\n");
        exit(1);
    }
    r = f->elementos[f->inicio];
    f->inicio = f->inicio + 1;
    return r;
}

// Destruir fila
void destroi(struct fila *f) {
    free(f);
}

// Programa principal
int main(void) {
    int valor;
    char funcao;
    struct fila *minhafila = cria();

    funcao = 'a';
    while (funcao != 'f') {
        printf("\nDigite (e) para enfileirar, (d) para desenfileirar ou (f) pra sair: ");
        scanf(" %c", &funcao);

        switch (funcao) {
            case 'e':
                printf("\nDigite um valor a ser enfileirado: ");
                scanf("%d", &valor);
                enfileira(minhafila, valor);
                break;
            case 'd':
                valor = desenfileira(minhafila);
                printf("\nO valor desenfileirado é: %d\n", valor);
                break;
            case 'f':
                destroi(minhafila);
                break;
        }
    }

    return 0;
}
