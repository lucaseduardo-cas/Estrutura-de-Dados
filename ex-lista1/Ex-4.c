/*
4. Leia um vetor de 20 posições e em seguida um valor X qualquer. Seu programa
devera fazer uma busca do valor de X no vetor lido e informar a posição em que
foi encontrado ou se não foi encontrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system("cls");

    int vetor[20];
    int x=0, i, j;

    
    printf("Digite 20 números inteiros:\n");
    for (int i = 0; i < 20; i++) {
        printf("%2d° número: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    while (1) {
        system("cls");
        printf("Digite 20 números inteiros:\n");
        for (int i = 0; i < 20; i++) {
            printf("%2d° número: %d\n", i + 1, vetor[i]);
        }
        printf("\n\n");
        printf("Digite um número (tecle '0'/sair): ");
        scanf("%d", &x);
        j = 0;

        if (x == 0) {
            printf("\nPrograma finalizado...");
            break;
        } else {
            for (i=0; i<20; i++) {
                if (x == vetor[i]) {
                    printf("\nPosição encontrada: %d\n\n\n", i + 1);
                    j = 1;
                    system("pause");
                    system("cls");
                } 
            }
            
            if (j != 1) {
                printf("\nNenhuma posição encontrada!\n\n\n");
                system("pause");
                system("cls");
            } 
        }
    }
   
    printf("\n\n\n");
    return 0;
}