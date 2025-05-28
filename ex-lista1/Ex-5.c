/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system("cls");

    int vetor[10], i, j;
    int encontrou = 0; 
    
    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("%2d° número: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
            if (vetor[i] == vetor[j]) {
                printf("%d ", vetor[i]);
                encontrou = 1;
                break; 
            }
        }
    }

    if (encontrou == 0) {
        printf("\nValores repetidos no vetor:\n");
    } else {
        printf("Nenhum número repetido encontrado.");
    }

    printf("\n\n");
    return 0;    
}