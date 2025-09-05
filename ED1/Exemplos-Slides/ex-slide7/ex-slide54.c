/*
Criando uma lista encadeada:

Para se criar uma lista ligada, é necessário criar um nó que possua um ponteiro para outro nó

Os elementos da lista são registros com um dos componentes destinado a guardar o endereço do registro sucessor.
- Criar uma lista
- Insere um elemento na posição X
- Remove um elemento da posição Y
- Destruir uma lista
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista
struct No {
    int dado;
    struct No *proximo;
}; // <-- faltava o ponto e vírgula aqui

// Função para criar um nó
struct No* criaNo(int n) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória para o Nó.\n"); // corrigido prinB -> printf
        return NULL;
    }
    novoNo->dado = n;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para inserir um nó no início da lista
struct No* insereInicio(struct No* lista, int n) {
    struct No* novoNo = criaNo(n);
    if (novoNo == NULL) {
        return lista; // Se a alocação falhar, a lista permanece inalterada.
    }
    novoNo->proximo = lista;
    return novoNo;
}

// A estrutura de lista permite a inserção de elementos em qualquer posição
// Função para inserir um nó no ﬁm da lista
struct No* insereFim(struct No* lista, int n) {
    struct No* novoNo = criaNo(n);
    if (novoNo == NULL) {
        return lista;
    }
    if (lista == NULL) {
        return novoNo;
    }
    struct No* atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novoNo;
    return lista;
}

/*
Busca de um item (dada uma chave)

Buscar um item
- Percorre a lista sequencialmente, comparando o valor desejado com o valor em cada nó
    • Se o valor for encontrado, a função retorna o nó que contém o item
    desejado;
    • Caso contrário, ela retorna NULL
*/

// Função para recuperar um item da lista
struct No* buscaItem(struct No* lista, int n) {
    struct No* atual = lista;
    while (atual != NULL) {
        if (atual->dado == n) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Função para remover um nó da lista
struct No* removeLista(struct No* lista, int n) {
    if (lista == NULL) {
        return NULL;
    }
    if (lista->dado == n) {
        struct No* novaLista = lista->proximo;
        free(lista);
        return novaLista;
    }
    struct No* atual = lista;
    while ((atual->proximo != NULL) && (atual->proximo->dado != n)) {
        atual = atual->proximo;
    }
    if (atual->proximo != NULL) {
        struct No* temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
    }
    return lista;
}

// Função para imprimir os elementos da lista
void printLista(struct No* lista) {
    struct No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n"); // corrigido prinB -> printf
}

// Função para liberar a memória alocada para a lista
void freeList(struct No* lista) {
    struct No* atual = lista;
    while (atual != NULL) {
        struct No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

// Programa Principal
int main() {
    struct No* lista = NULL; // Inicializando a lista vazia
    lista = insereInicio(lista, 1);
    lista = insereInicio(lista, 2);
    lista = insereFim(lista, 3);

    printf("Lista encadeada: "); // corrigido prinB -> printf
    printLista(lista);

    lista = removeLista(lista, 2); // corrigido "Lista" -> "lista"
    printf("Lista após a remoção do item 2: "); // corrigido prinB -> printf
    printLista(lista);

    struct No* item = buscaItem(lista, 3);
    if (item != NULL) {
        printf("Item 3 encontrado na lista.\n"); // corrigido prinB -> printf
    } else {
        printf("Item 3 não encontrado na lista.\n"); // corrigido prinB -> printf
    }

    freeList(lista);
    return 0;
}
