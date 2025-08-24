/*
16) Implemente uma fila em um vetor circular, sem armazenar o número total de
elementos (sugestão: nunca deixe que o indicador “fim” alcance o indicador
“início”, ainda que seja necessário perder uma posição do vetor.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Tamanho pequeno para facilitar o teste da circularidade e cheia

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int enfileirar(Fila *f, int valor) {
    if ((f->fim + 1) % MAX == f->inicio) { // Fila cheia
        printf("Erro: Fila cheia!\n");
        return 0;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    return 1;
}

int desenfileirar(Fila *f, int *valor) {
    if (f->inicio == f->fim) { // Fila vazia
        printf("Erro: Fila vazia!\n");
        return 0;
    }
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    return 1;
}

void imprimirFila(Fila *f) {
    if (f->inicio == f->fim) {
        printf("Fila: Vazia\n");
        return;
    }
    printf("Fila (inicio -> fim): ");
    int i = f->inicio;
    while (i != f->fim) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Fila minhaFila;
    inicializarFila(&minhaFila);

    printf("--- Testando Fila Circular ---\n");
    imprimirFila(&minhaFila);

    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);
    imprimirFila(&minhaFila); // 10 20 30

    int valorRemovido;
    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido); // 10
    }
    imprimirFila(&minhaFila); // 20 30

    enfileirar(&minhaFila, 40); // Entra na posição 0
    enfileirar(&minhaFila, 50); // Deve ser a última posição antes de ficar cheia
    imprimirFila(&minhaFila); // 20 30 40 50

    enfileirar(&minhaFila, 60); // Deve dar erro: Fila cheia!
    imprimirFila(&minhaFila); // Ainda 20 30 40 50

    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido); // 20
    }
    if (desenfileirar(&minhaFila, &valorRemovido)) {
        printf("Desenfileirado: %d\n", valorRemovido); // 30
    }
    imprimirFila(&minhaFila); // 40 50

    enfileirar(&minhaFila, 60); // Deve enfileirar
    imprimirFila(&minhaFila); // 40 50 60

    return 0;
}
