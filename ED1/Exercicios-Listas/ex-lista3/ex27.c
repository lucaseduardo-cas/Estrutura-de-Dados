/*
27)
Utilizando as operações de manipulação de pilhas vistas em sala, uma pilha
auxiliar e uma variável do tipo TipoItem, escreva um procedimento que
remove um item com chave c de uma posição qualquer de uma pilha. Note que você
não tem acesso à estrutura interna da pilha (topo, item, etc), apenas às
operações de manipulação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar 'bool'

// Definição da estrutura do nó da pilha
typedef struct no {
    int valor;
    struct no *prox;
} No;

// Definição da estrutura da Pilha
typedef struct {
    No *topo;
} Pilha;

// TipoItem para o valor a ser manipulado
typedef int TipoItem;

// Função para inicializar a pilha
void inicializa(Pilha *p) {
    p->topo = NULL;
}

// Função para verificar se a pilha está vazia
bool vazia(Pilha *p) {
    return (p->topo == NULL);
}

// Função para empilhar um elemento (push)
void empilha(Pilha *p, TipoItem x) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria na empilha.\n");
        exit(1);
    }
    novo->valor = x;
    novo->prox = p->topo;
    p->topo = novo;
}

// Função para desempilhar um elemento (pop)
TipoItem desempilha(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia! Nao e possivel desempilhar.\n");
        return -1; // Valor sentinela para indicar erro ou pilha vazia
    }
    No *temp = p->topo;
    TipoItem v = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return v;
}

// Função para remover um item com chave 'c' de uma posição qualquer da pilha
void removeItem(Pilha *p, TipoItem c) {
    Pilha aux;
    inicializa(&aux);
    TipoItem x;
    bool encontrado = false;

    // Desempilha tudo até encontrar o item
    while (!vazia(p)) {
        x = desempilha(p);
        if (x != c) {
            empilha(&aux, x);
        } else {
            encontrado = true;
            break; // achou o item, não empilha de volta
        }
    }

    if (!encontrado) {
        printf("Item '%d' nao encontrado na pilha.\n", c);
    } else {
        printf("Item '%d' removido da pilha.\n", c);
    }

    // Devolve os elementos para a pilha original
    while (!vazia(&aux)) {
        empilha(p, desempilha(&aux));
    }

    // Liberar a memória da pilha auxiliar (garantir que não haja vazamento caso a aux não esteja vazia ao final)
    No *atual_aux = aux.topo;
    while (atual_aux != NULL) {
        No *proximo_aux = atual_aux->prox;
        free(atual_aux);
        atual_aux = proximo_aux;
    }
}

// Função para imprimir os elementos da pilha (apenas para teste)
void imprimePilha(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Elementos na pilha (do topo para a base):\n");
    No *atual = p->topo;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

int main() {
    Pilha minha_pilha;
    inicializa(&minha_pilha);

    printf("Empilhando elementos...\n");
    empilha(&minha_pilha, 10);
    empilha(&minha_pilha, 20);
    empilha(&minha_pilha, 30);
    empilha(&minha_pilha, 40);
    empilha(&minha_pilha, 50);
    imprimePilha(&minha_pilha);

    printf("\nTentando remover o item 30:\n");
    removeItem(&minha_pilha, 30);
    imprimePilha(&minha_pilha);

    printf("\nTentando remover o item 50 (topo):\n");
    removeItem(&minha_pilha, 50);
    imprimePilha(&minha_pilha);

    printf("\nTentando remover o item 10 (base):\n");
    removeItem(&minha_pilha, 10);
    imprimePilha(&minha_pilha);

    printf("\nTentando remover um item que nao existe (99):\n");
    removeItem(&minha_pilha, 99);
    imprimePilha(&minha_pilha);

    printf("\nDesempilhando o restante para liberar memoria:\n");
    while (!vazia(&minha_pilha)) {
        printf("Desempilhou: %d\n", desempilha(&minha_pilha));
    }
    imprimePilha(&minha_pilha);

    return 0;
}
