#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da pilha
typedef struct No { // struct No é o nome tradicional da struct
    int dado;
    //struct No* prox;
    struct No* prox; // Cada "No" da pilha aponta para o próximo nó. Isso forma a cadeia de elementos: [30] → [20] → [10] → NULL
} No; // No (depois do }) é o apelido mais curto que você pode usar direto sem escrever struct toda vez. Então: struct No* p; e No* p; são a mesma coisa

// Empilha um valor no topo
void push(No** topo, int valor) { // No** topo: o parâmetro 'topo' é um ponteiro para um ponteiro para No. Modifica valor de topo e de pilha no main
    No* novo = (No*) malloc(sizeof(No)); // No* novo = declara nova variável "novo" que é um ponteiro para No que aponta para o novo nó que será criado. | (No*) é um cast
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
    }
    novo->dado = valor; // Guarda o valor dentro do novo nó.
    novo->prox = *topo; // Faz o novo nó apontar para o antigo topo da pilha.
    *topo = novo;       // Atualiza o topo para ser o novo elemento.
}

// Desempilha o topo e retorna o valor
int pop(No** topo) { // int: Indica que a função retornará um valor inteiro. Neste caso, será o dado do nó que foi desempilhado, ou -1 se a pilha estiver vazia.
    if (*topo == NULL) { // topo é o endereçode No que está no topo da pilha
        printf("Pilha vazia!\n");
        return -1;
    }
    No* temp = *topo; // Guarda o ponteiro atual do topo; (temp é um ponteiro para nó); *topo: atribui a temp o valor de *topo. Agora aponta para o nó que será desempilhado
    int valor = temp->dado; // Salva o valor que estava nesse topo. - Atribui a valor o conteúdo do campo dado do nó para o qual temp está apontando.
    *topo = temp->prox; // Avança o topo para o próximo nó.
    free(temp);
    return valor;
}

// Imprime a pilha do topo até o fim
void imprimir(No* topo) {
    printf("Pilha: ");
    while (topo != NULL) {
        printf("%d ", topo->dado);
        topo = topo->prox;
    }
    printf("\n");
}

int main() {
    No* pilha = NULL; // Início: pilha vazia

    push(&pilha, 10); // Pilha é um No* (ponteiro para No)
    push(&pilha, 20);
    push(&pilha, 30);

    imprimir(pilha);  // Deve mostrar: 30 20 10

    int removido = pop(&pilha);
    printf("Desempilhado: %d\n", removido);

    imprimir(pilha);  // Deve mostrar: 20 10

    return 0;
}
