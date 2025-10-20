/*
O Merge Sort é um algoritmo recursivo baseado na técnica "dividir e conquistar".
Ele divide o vetor em duas metades, ordena cada uma recursivamente e depois combina (merge) os resultados.
*/

#include <stdio.h>

void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    int aux[fim - inicio + 1];

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while (i <= meio)
        aux[k++] = v[i++];
    while (j <= fim)
        aux[k++] = v[j++];

    for (i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = aux[k];
}

void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int main() {
    int v[] =  {512, 84, 763, 190, 678, 35, 927, 451, 203, 799,
                620, 74, 388, 953, 47, 119, 806, 290, 556, 675,
                821, 37, 611, 429, 960, 283, 502, 748, 133, 214,
                687, 512, 931, 465, 87, 708, 392, 178, 634, 850,
                952, 246, 519, 770, 112, 403, 680, 594, 305, 738,
                927, 490, 269, 803, 651, 382, 59, 772, 485, 140,
                646, 337, 951, 274, 512, 624, 97, 892, 311, 257,
                785, 433, 699, 206, 842, 500, 382, 991, 713, 456,
                628, 334, 412, 978, 232, 814, 377, 543, 935, 127,
                452, 640, 586, 293, 778, 359, 861, 471, 912, 215};

    int n = 100;

    mergeSort(v, 0, n - 1);

    printf("Vetor ordenado (Merge Sort): ");
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
    printf("\n");
    return 0;
}
