#include <stdio.h>

int main(void) {
    int matriz[6][6], i, j, contador = 0;

    // Leitura da matriz 6x6
    printf("Digite os elementos da matriz 6x6:\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            // Verifica se o valor é maior que 10 e incrementa o contador
            if (matriz[i][j] > 10) {
                contador++;
            }
        }
    }

    // Exibe o resultado
    printf("\nA matriz possui %d valores maiores que 10.\n", contador);

    return 0;
}
