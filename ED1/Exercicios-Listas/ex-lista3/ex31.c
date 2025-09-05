/*
31)
Escreva uma função em C para trocar os elementos m e n de uma lista (m e n
podem ser chaves ou mesmo ponteiros para os elementos – a escolha é sua).
*/
#include <stdio.h>
#include <stdlib.h> // Incluído para consistência com o requisito de usar stdlib

// A questão já fornece uma implementação funcional para um array.
// Adaptando para uma lista encadeada dinâmica, conforme o contexto das questões anteriores.

typedef struct no {
    int valor;
    struct no *prox;
} No;

// Função para inserir um nó no início da lista (ajuda a construir a lista para teste)
No* insere(No *lista, int x) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        // Tratar erro de alocação se necessário
        exit(EXIT_FAILURE);
    }
    novo->valor = x;
    novo->prox = lista;
    return novo;
}

// Função para imprimir a lista
void imprime(No *lista) {
    while (lista) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

// Função para encontrar um nó pelo seu valor (chave)
No* buscarNoPorValor(No *lista, int chave) {
    No *atual = lista;
    while (atual != NULL && atual->valor != chave) {
        atual = atual->prox;
    }
    return atual; // Retorna o ponteiro para o nó ou NULL se não encontrado
}

// Função para trocar os valores de dois nós na lista encadeada
// A escolha foi trocar os valores, não os ponteiros dos nós em si, pois é mais simples
// e geralmente o objetivo de "trocar elementos" em uma lista.
void trocaElementos(No *lista, int valor1, int valor2) {
    if (lista == NULL) {
        return;
    }

    No *no1 = buscarNoPorValor(lista, valor1);
    No *no2 = buscarNoPorValor(lista, valor2);

    if (no1 != NULL && no2 != NULL) {
        // Troca os valores dos nós
        int temp = no1->valor;
        no1->valor = no2->valor;
        no2->valor = temp;
    } else {
        printf("Pelo menos um dos valores nao foi encontrado na lista.\n");
    }
}

int main() {
    No *minha_lista = NULL;

    // Construir a lista
    minha_lista = insere(minha_lista, 50);
    minha_lista = insere(minha_lista, 40);
    minha_lista = insere(minha_lista, 30);
    minha_lista = insere(minha_lista, 20);
    minha_lista = insere(minha_lista, 10);

    printf("Lista original: ");
    imprime(minha_lista); // Saída esperada: 10 20 30 40 50

    printf("Trocando 20 e 40...\n");
    trocaElementos(minha_lista, 20, 40);
    printf("Lista apos a troca: ");
    imprime(minha_lista); // Saída esperada: 10 40 30 20 50

    printf("Trocando 10 e 50...\n");
    trocaElementos(minha_lista, 10, 50);
    printf("Lista apos a troca: ");
    imprime(minha_lista); // Saída esperada: 50 40 30 20 10

    printf("Tentando trocar 25 (nao existe) e 30...\n");
    trocaElementos(minha_lista, 25, 30);
    printf("Lista apos tentativa de troca: ");
    imprime(minha_lista); // Lista deve permanecer igual

    // Liberar a memória alocada
    No *atual = minha_lista;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}
