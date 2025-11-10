#include <stdio.h>
#include <stdlib.h>

// Estrutura do Nó da Árvore AVL
typedef struct NoAVL {
    int chave;
    int altura; // Armazena a altura do nó para o cálculo do Fator de Balanceamento
    struct NoAVL *esquerda;
    struct NoAVL *direita;
} NoAVL;

// Função utilitária para retornar o maior entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para retornar a altura de um nó
int altura(NoAVL *N) {
    if (N == NULL)
        return 0;
    return N->altura;
}

// Cria um novo nó AVL
NoAVL* novoNo(int chave) {
    NoAVL* no = (NoAVL*)malloc(sizeof(NoAVL));
    no->chave   = chave;
    no->esquerda  = NULL;
    no->direita = NULL;
    no->altura  = 1; // Novo nó é inicialmente adicionado na altura 1
    return(no);
}

// Calcula o Fator de Balanceamento (FB) de um nó N
int getFatorBalanceamento(NoAVL *N) {
    if (N == NULL)
        return 0;
    return altura(N->esquerda) - altura(N->direita);
}

// Rotação Simples à Direita (Casos LL e LR-parte 1)
NoAVL *rotacaoDireita(NoAVL *y) {
    NoAVL *x = y->esquerda;
    NoAVL *T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualiza alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    // Retorna a nova raiz (x)
    return x;
}

// Rotação Simples à Esquerda (Casos RR e RL-parte 1)
NoAVL *rotacaoEsquerda(NoAVL *x) {
    NoAVL *y = x->direita;
    NoAVL *T2 = y->esquerda;

    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualiza alturas
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    // Retorna a nova raiz (y)
    return y;
}

// Insere um nó e realiza o balanceamento
NoAVL* inserir(NoAVL* no, int chave) {
    // 1. Inserção normal de BST
    if (no == NULL)
        return(novoNo(chave));

    if (chave < no->chave)
        no->esquerda  = inserir(no->esquerda, chave);
    else if (chave > no->chave)
        no->direita = inserir(no->direita, chave);
    else // Chaves iguais não são permitidas
        return no;

    // 2. Atualiza a altura do nó ancestral
    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    // 3. Obtém o Fator de Balanceamento
    int balanceamento = getFatorBalanceamento(no);

    // 4. Se o nó estiver desbalanceado, há 4 casos a serem tratados:

    // Caso Esquerda-Esquerda (LL)
    if (balanceamento > 1 && chave < no->esquerda->chave)
        return rotacaoDireita(no);

    // Caso Direita-Direita (RR)
    if (balanceamento < -1 && chave > no->direita->chave)
        return rotacaoEsquerda(no);

    // Caso Esquerda-Direita (LR) - Rotação Dupla
    if (balanceamento > 1 && chave > no->esquerda->chave) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    // Caso Direita-Esquerda (RL) - Rotação Dupla
    if (balanceamento < -1 && chave < no->direita->chave) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

// Função para mostrar a árvore em ordem Pré-fixada (Preorder)
void preOrder(NoAVL *raiz) {
    if(raiz != NULL) {
        printf("%d (h:%d, fb:%d) ", raiz->chave, raiz->altura, getFatorBalanceamento(raiz));
        preOrder(raiz->esquerda);
        preOrder(raiz->direita);
    }
}

// Função principal de teste
int main() {
    NoAVL *raiz = NULL;

    printf("== Inserindo elementos na AVL ==\n");
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30); // Rotação Simples à Esquerda (RR)

    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 25); // Força Rotação Dupla (RL) ou (LR), dependendo da ordem

    printf("\n- Arvore AVL resultante (Preorder: Chave, Altura, FB) -\n");
    preOrder(raiz);
    printf("\n");

    return 0;
}