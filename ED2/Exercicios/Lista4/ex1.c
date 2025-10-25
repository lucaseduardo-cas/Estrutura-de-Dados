#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do Nó da Árvore
typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

// Cria um novo nó com o valor especificado.
No* criarNovoNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Insere um novo nó na árvore (função auxiliar para construir a árvore).
No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNovoNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    
    return raiz;
}

// Retorna o maior de dois números.
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função recursiva que retorna o número total de nós na árvore.
int contarNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

// Função recursiva que retorna a altura (profundidade máxima) da árvore.
int alturaArvore(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + max(alturaArvore(raiz->esquerda), alturaArvore(raiz->direita));
}

// Imprime os resultados das funções de análise da árvore.
void imprimirResultados(int totalNos, int altura) {
    printf("--- Analise da Arvore Binaria ---\n");
    printf("1. Numero total de nos na arvore: %d\n", totalNos);
    printf("2. Altura (profundidade maxima) da arvore: %d\n", altura);
}

int main() {
    No* raiz = NULL;
    
    raiz = inserirNo(raiz, 50);
    inserirNo(raiz, 30);
    inserirNo(raiz, 70);
    inserirNo(raiz, 20);
    inserirNo(raiz, 40);
    inserirNo(raiz, 60);
    inserirNo(raiz, 80);
    inserirNo(raiz, 10);

    // Variáveis para armazenar os resultados
    int totalNos = contarNos(raiz);
    int altura = alturaArvore(raiz);

    // Chamada da função separada para imprimir as informações
    imprimirResultados(totalNos, altura);

    // Nota: Uma função para liberar a memória da árvore (free) seria recomendada em produção.

    return 0;
}