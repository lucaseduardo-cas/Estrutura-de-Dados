/*
Comentário para a alternativa B:
O Selection Sort é um algoritmo iterativo simples que percorre o vetor,
encontrando o menor elemento a cada iteração e o colocando na posição correta.
*/

#include <stdio.h>

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

    selectionSort(v, n);

    printf("Vetor ordenado (Selection Sort): ");
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
    printf("\n");
    return 0;
}
