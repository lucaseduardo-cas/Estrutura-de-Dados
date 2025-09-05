/*
Exercício Slide 39
    • Crie funções que implementem as seguintes operações:
        - Verificar se a lista L está ordenada (crescente ou decrescente)
        - Fazer uma cópia da Lista L1 em outra L2
        - Fazer uma cópia da Lista L1 em L2, eliminando repetidos
        - Inverter L1, colocando o resultado em L2
        - Inverter a própria L1
        - Intercalar L1 com L2, gerando L3 ordenada (considere L1 e L2
        ordenadas)
        - Eliminar de L1 todas as ocorrências de um dado item (L1 está
        ordenada)
    • L1 = {3, 1, 5, 2, 1, 8, 1, 5}
    • L1(dec){8, 5, 5, 3, 2, 1, 1, 1}
    • L1(cre){1, 1, 1, 2, 3, 5, 5, 8}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

// Insere no final da lista
void inserir(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *atual = *lista;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo;
    }
}

// Verifica se a lista está ordenada crescente ou decrescente
int verificar_ordenada(No *l) {
    if (!l || !l->prox) return 1;
    int crescente = 1, decrescente = 1;
    while (l->prox) {
        if (l->valor < l->prox->valor) decrescente = 0;
        if (l->valor > l->prox->valor) crescente = 0;
        l = l->prox;
    }
    return crescente ? 1 : decrescente ? -1 : 0;
}

// Copia L1 para L2
void copiar_lista(No *l1, No **l2) {
    while (l1) {
        inserir(l2, l1->valor);
        l1 = l1->prox;
    }
}

// Copia L1 para L2 sem repetidos
int existe(No *l, int val) {
    while (l) {
        if (l->valor == val) return 1;
        l = l->prox;
    }
    return 0;
}

void copiar_sem_repetidos(No *l1, No **l2) {
    while (l1) {
        if (!existe(*l2, l1->valor)) {
            inserir(l2, l1->valor);
        }
        l1 = l1->prox;
    }
}

// Inverte L1 para L2
void inverter_lista(No *l1, No **l2) {
    while (l1) {
        No *novo = malloc(sizeof(No));
        novo->valor = l1->valor;
        novo->prox = *l2;
        *l2 = novo;
        l1 = l1->prox;
    }
}

// Inverte a própria lista L1
void inverter_inplace(No **l) {
    No *prev = NULL, *atual = *l, *prox = NULL;
    while (atual) {
        prox = atual->prox;
        atual->prox = prev;
        prev = atual;
        atual = prox;
    }
    *l = prev;
}

// Intercala duas listas ordenadas
void intercalar(No *l1, No *l2, No **l3) {
    while (l1 && l2) {
        if (l1->valor < l2->valor) {
            inserir(l3, l1->valor);
            l1 = l1->prox;
        } else {
            inserir(l3, l2->valor);
            l2 = l2->prox;
        }
    }
    while (l1) { inserir(l3, l1->valor); l1 = l1->prox; }
    while (l2) { inserir(l3, l2->valor); l2 = l2->prox; }
}

// Remove todas as ocorrências de um valor (lista ordenada)
void remover_todos(No **l, int valor) {
    while (*l && (*l)->valor == valor) {
        No *temp = *l;
        *l = (*l)->prox;
        free(temp);
    }

    No *atual = *l;
    while (atual && atual->prox) {
        if (atual->prox->valor == valor) {
            No *temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}

// Exibe a lista
void exibir(No *l) {
    while (l) {
        printf("%d ", l->valor);
        l = l->prox;
    }
    printf("\n");
}

int main() {
    No *L1 = NULL, *L2 = NULL, *L3 = NULL;

    int valores[] = {3, 1, 5, 2, 1, 8, 1, 5};
    for (int i = 0; i < 8; i++)
        inserir(&L1, valores[i]);

    printf("L1 original: ");
    exibir(L1);

    // 1. Verificar ordenação
    int status = verificar_ordenada(L1);
    if (status == 1) printf("L1 está ordenada em ordem crescente.\n");
    else if (status == -1) printf("L1 está ordenada em ordem decrescente.\n");
    else printf("L1 não está ordenada.\n");

    // 2. Cópia simples
    copiar_lista(L1, &L2);
    printf("Cópia de L1 em L2: ");
    exibir(L2);

    // 3. Cópia sem repetidos
    No *L2_sr = NULL;
    copiar_sem_repetidos(L1, &L2_sr);
    printf("L2 sem repetidos: ");
    exibir(L2_sr);

    // 4. Inverter L1 em L2
    No *L2_inv = NULL;
    inverter_lista(L1, &L2_inv);
    printf("L2 com L1 invertida: ");
    exibir(L2_inv);

    // 5. Inverter L1 inplace
    inverter_inplace(&L1);
    printf("L1 invertida: ");
    exibir(L1);

    // 6. Intercalar duas listas ordenadas
    No *Ord1 = NULL, *Ord2 = NULL;
    int v1[] = {1, 2, 4}, v2[] = {3, 5, 6};
    for (int i = 0; i < 3; i++) {
        inserir(&Ord1, v1[i]);
        inserir(&Ord2, v2[i]);
    }
    intercalar(Ord1, Ord2, &L3);
    printf("Intercalação de duas listas ordenadas: ");
    exibir(L3);

    // 7. Remover todas as ocorrências do número 1 (ordem necessária)
    remover_todos(&L3, 1);
    printf("L3 sem o número 1: ");
    exibir(L3);

    return 0;
}
