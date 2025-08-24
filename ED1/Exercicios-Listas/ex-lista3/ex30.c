/*
30) Considere listas implementadas por arranjos, então pede-se para implementar funções que:
• Localize/ Pesquise/Encontre (search) elementos
• Concatenar/intercalar (Merge) duas listas
• Dividir uma lista em várias (k)
• Copiar uma lista
• Ordenar (sort) uma lista por ordem crescente/decrescente
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int busca(int *lista, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) return i;
    }
    return -1;
}

int* concatena(int *a, int ta, int *b, int tb, int *tc) {
    int *c = malloc((ta + tb) * sizeof(int));
    for (int i = 0; i < ta; i++) c[i] = a[i];
    for (int i = 0; i < tb; i++) c[ta + i] = b[i];
    *tc = ta + tb;
    return c;
}

int** divide(int *lista, int tamanho, int k, int *tam_partes) {
    int **partes = malloc(k * sizeof(int*));
    int base = tamanho / k, sobra = tamanho % k, idx = 0;
    for (int i = 0; i < k; i++) {
        tam_partes[i] = base + (i < sobra);
        partes[i] = malloc(tam_partes[i] * sizeof(int));
        for (int j = 0; j < tam_partes[i]; j++) {
            partes[i][j] = lista[idx++];
        }
    }
    return partes;
}

int* copia(int *lista, int tamanho) {
    int *nova = malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) nova[i] = lista[i];
    return nova;
}

void ordena(int *lista, int tamanho, int crescente) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            int cond = crescente ? (lista[j] > lista[j + 1]) : (lista[j] < lista[j + 1]);
            if (cond) {
                int tmp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int a[] = {1, 3, 5}, b[] = {2, 4, 6}, tamanho_c;
    int *c = concatena(a, 3, b, 3, &tamanho_c);
    ordena(c, tamanho_c, 1);
    for (int i = 0; i < tamanho_c; i++) printf("%d ", c[i]);
    printf("\n");
    free(c);
    return 0;
}
