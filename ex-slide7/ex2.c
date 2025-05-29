/*
2. Lista Encadeada (Dinâmica)

O que é?
É uma lista em que cada elemento (nó) aponta para o próximo. Os elementos não ficam lado a lado na memória, são alocados dinamicamente com malloc.

Características:
- Memória cresce conforme o uso.
- Inserções e remoções são rápidas em qualquer posição.
- Acesso por índice é mais lento (precisa percorrer).

typedef struct No {
    int valor;
    struct No *prox;
} No;

* Exemplo (Teste de Mesa):
Queremos a lista: 10 → 20 → 30

Passo a passo:
1. Cria nó com 10: [10|*] → NULL
2. Cria nó com 20: [10|*] → [20|*] → NULL
3. Cria nó com 30: [10|*] → [20|*] → [30|*] → NULL
*/

// Código em C (lista encadeada simples):
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserir_final(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *temp = *inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void exibir(No *inicio) {
    while (inicio != NULL) {
        printf("%d → ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;

    inserir_final(&lista, 10);
    inserir_final(&lista, 20);
    inserir_final(&lista, 30);

    exibir(lista);

    return 0;
}

