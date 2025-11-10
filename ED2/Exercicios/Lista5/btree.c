#include <stdio.h>
#include <stdlib.h>

#define T 3 // define uma ordem mínima da B-tree (grau mínimo)

// Estrutura de um nó da B-tree
typedef struct BTreeNode 
{
    int chaves[2 * T - 1];           // Vetor de chaves
    struct BTreeNode* filhos[2 * T]; // Ponteiros para filhos
    int n;                           // Número atual de chaves
    int folha;                       // 1 se for folha, 0 se não
} BTreeNode;

// Serve para criar um novo nó de B-tree
BTreeNode* novoNo(int folha) 
{
    BTreeNode* no = (BTreeNode*)malloc(sizeof(BTreeNode));
    no->folha = folha;
    no->n = 0;
    
    for (int i = 0; i < 2 * T; i++)
    {
        no->filhos[i] = NULL;
    }
    
    return no;
}

// Função que serve para percorrer a árvore (em ordem)
void percorrer(BTreeNode* raiz) 
{
    if (raiz != NULL) 
    {
        int i;
        
        for (i = 0; i < raiz->n; i++) 
        {
            // Percorre o filho antes de imprimir a chave
            if (!raiz->folha)
            {
                percorrer(raiz->filhos[i]);
            }
            
            printf("%d ", raiz->chaves[i]);
        }
        
        // Serve percorrer o último filho
        if (!raiz->folha)
        {
            percorrer(raiz->filhos[i]);
        }
    }
}

// Busca por uma chave na árvore
BTreeNode* buscar(BTreeNode* raiz, int k) 
{
    int i = 0;

    // Encontra a primeira chave >= k
    while (i < raiz->n && k > raiz->chaves[i])
    {
        i++;
    }

    if (i < raiz->n && raiz->chaves[i] == k)
    {
        return raiz; // chave encontrada
    }

    if (raiz->folha)
    {
        return NULL; // se for folha, não encontrada
    }

    return buscar(raiz->filhos[i], k);
}

// Divide um nó filho cheio
void dividirFilho(BTreeNode* pai, int i, BTreeNode* cheio) 
{
    // Cria um novo nó que armazenará t-1 chaves do nó cheio
    BTreeNode* novo = novoNo(cheio->folha);
    novo->n = T - 1;

    // Copia as últimas T-1 chaves para o novo nó
    for (int j = 0; j < T - 1; j++)
    {
        novo->chaves[j] = cheio->chaves[j + T];
    }

    // Copia os ponteiros de filhos, se não for folha
    if (!cheio->folha) 
    {
        for (int j = 0; j < T; j++)
        {
            novo->filhos[j] = cheio->filhos[j + T];
        }
    }

    // Reduz o número de chaves do nó cheio
    cheio->n = T - 1;

    // Move os ponteiros do pai para abrir espaço para o novo filho
    for (int j = pai->n; j >= i + 1; j--)
    {
        pai->filhos[j + 1] = pai->filhos[j];
    }

    // Liga o novo nó ao pai
    pai->filhos[i + 1] = novo;

    // Move as chaves do pai
    for (int j = pai->n - 1; j >= i; j--)
    {
        pai->chaves[j + 1] = pai->chaves[j];
    }

    // A chave do meio do nó cheio sobe para o pai
    pai->chaves[i] = cheio->chaves[T - 1];

    pai->n++;
}

// Insere uma chave em um nó não cheio
void inserirNaoCheio(BTreeNode* no, int k) 
{
    int i = no->n - 1;

    if (no->folha) 
    {
        // Move as chaves maiores para abrir espaço
        while (i >= 0 && k < no->chaves[i]) 
        {
            no->chaves[i + 1] = no->chaves[i];
            i--;
        }
        
        no->chaves[i + 1] = k;
        no->n++;
    }
    
    else 
    {
        // Encontra o filho apropriado
        while (i >= 0 && k < no->chaves[i])
        {
            i--;
        }
        i++;

        // Se o filho estiver cheio, precisa dividir
        if (no->filhos[i]->n == 2 * T - 1) {
            dividirFilho(no, i, no->filhos[i]);

            // Após a divisão, decide qual metade seguir
            if (k > no->chaves[i])
                i++;
        }
        inserirNaoCheio(no->filhos[i], k);
    }
}

// Função principal de inserção
BTreeNode* inserir(BTreeNode* raiz, int k) 
{
    // Verifica se a árvore estiver vazia
    if (raiz == NULL) 
    {
        raiz = novoNo(1); // se estiver vazia, ela cria um nó folha
        raiz->chaves[0] = k;
        raiz->n = 1;
        return raiz;
    }

    // Se a raiz já estiver cheia, ela deve ser dividida
    if (raiz->n == 2 * T - 1) 
    {
        BTreeNode* novaRaiz = novoNo(0);
        novaRaiz->filhos[0] = raiz;
        dividirFilho(novaRaiz, 0, raiz);

        // Decide para qual filho inserir
        int i = 0;
        if (k > novaRaiz->chaves[0])
        {
            i++;
        }
        
        inserirNaoCheio(novaRaiz->filhos[i], k);
        return novaRaiz;
    }
    
    else 
    {
        inserirNaoCheio(raiz, k);
        return raiz;
    }
}

// Função principal do programa 
int main() 
{
    BTreeNode* raiz = NULL;

    int valores[] = {10, 20, 30, 40, 5, 15, 25, 35};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("-= Arvore B-tree percorrida (em ordem) =-\n");
    percorrer(raiz);
    printf("\n");

    return 0;
}
