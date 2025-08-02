/*
3. 3. Necessita-se de uma operação para inserir um elemento antes do primeiro. Implemente uma função chamada furaFila, que recebe como parametro o vetor, que representa a fila propriamente dita; o valor a ser inserido; a posição do primeiro elemento dentro do vetor e a quantidade de elementos na fila (nItens) e realiza a operação desejada.

- A função de furarafila só poderá ser realizada se a fila não estiver cheia.

* Objetivo
Criar uma função furaFila(...) que:
    - Recebe o vetor da fila
    - Recebe o valor a ser inserido na frente
    - Recebe os índices inicio, nItens e MAX da fila
    - Desloca os elementos para a direita e coloca o novo valor na frente (antes do inicio)

* Lógica da função
1- Verifica se a fila está cheia (nItens == MAX)

2- Se não estiver:
    - Desloca todos os elementos uma posição para a direita
    - Insere o novo valor na posição inicio
    - Incrementa nItens
*/

#include <stdio.h>
#define MAX 50

// Função para inserir elemento na frente da fila
int furaFila(int fila[], int valor, int *inicio, int *nItens) {
    if (*nItens == MAX) {
        return 0; // Falha: fila cheia
    }

    // Desloca os elementos para a direita
    for (int i = *nItens; i > *inicio; i--) {
        fila[i] = fila[i - 1];
    }

    // Insere o valor na frente (posição 'inicio')
    fila[*inicio] = valor;
    (*nItens)++;  // Incrementa número de itens

    return 1; // Sucesso
}

// Exibe a fila
void mostraFila(int fila[], int inicio, int nItens) {
    for (int i = inicio; i < inicio + nItens; i++) {
        printf("%d ", fila[i]);
    }
    printf("\n");
}

int main() {
    int fila[MAX];
    int inicio = 0, nItens = 0;

    // Simulando inserção normal
    fila[nItens++] = 10;
    fila[nItens++] = 20;
    fila[nItens++] = 30;

    printf("Fila antes de furar:\n");
    mostraFila(fila, inicio, nItens);

    // Furando a fila com o valor 99
    if (furaFila(fila, 99, &inicio, &nItens)) {
        printf("Fila após furar (inserir 99 no início):\n");
        mostraFila(fila, inicio, nItens);
    } else {
        printf("Fila cheia! Não foi possível furar.\n");
    }

    return 0;
}
