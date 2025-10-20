#include <stdio.h>
#include <time.h>

void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    int aux[fim - inicio + 1];

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim) aux[k++] = v[j++];
    for (i = inicio, k = 0; i <= fim; i++, k++) v[i] = aux[k];
}

void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menor])
                menor = j;
        }
        if (menor != i) {
            int temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
        }
    }
}

void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

int main() {
    int v[] = {512, 84, 763, 190, 678, 35, 927, 451, 203, 799,
               620, 74, 388, 953, 47, 119, 806, 290, 556, 675};

    int n = 100;
    int copia[100];

    clock_t inicio, fim;
    double tempo;

    copiarVetor(v, copia, n);
    inicio = clock();
    mergeSort(copia, 0, n - 1);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Tempo Merge Sort: %.3f ms\n", tempo);

    copiarVetor(v, copia, n);
    inicio = clock();
    selectionSort(copia, n);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Tempo Selection Sort: %.3f ms\n", tempo);

    return 0;
}
