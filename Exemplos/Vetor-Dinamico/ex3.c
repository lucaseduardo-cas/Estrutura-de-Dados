/*
Alocação dinâmica de me mória com a função REALLOC
-> Retorna um ponteiro para a nova região de memória.
-> Se o ponteiro for nulo, ela aloca memória
-> Se o novo tamanho for zero, a memória é liberada
-> Se não houver memória suficiente, retorna null.

Exercício:
Crie um vetor dinâmico onde o usuário ira definir o tamanho inicial,
depois preencha o vetor com valores aleatórios. Em seguida
redimensione esse vetor preenchendo com novos valores se
necessário. Por fim, exibas os valores na tela (não esqueça de
liberar a memória)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, tam, ntam, *vet, *temp;

    system("clear");
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = (int*) malloc(tam * sizeof(int));

    if(vet == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("\nMemória alocada com sucesso!\n");
    printf("\nDigite %d números inteiros:\n", tam);
    for (i = 0; i < tam; i++) {
        printf("%2d° número: ", i + 1);
        scanf("%d", &vet[i]);
    }
    temp = vet;
    printf("\nVetor digitado: ");
    for (i = 0; i < tam; i++) {
        printf("%d", *temp);
        if (i < tam - 1) {
            printf("; ");
        }
        temp++;
    }
    printf("\n\n");

    printf("Digite o novo tamanho do vetor: ");
    scanf("%d", &ntam);
    if(ntam < tam) {
        printf("\nTamanho reduzido, alguns valores foram descartados.\n");
    }

    // vet =  realloc (vet, tam);
    temp = (int*) realloc(vet, ntam * sizeof(int));
    if (vet == NULL) {
        printf("Erro ao realocar memória!\n");
        return 1;
    }
    vet = temp;

    printf("\nVetor realocado:\n");
    for (i = tam; i < ntam; i++) {
        printf("%2d° número: ", i + 1);
        scanf("%d", &vet[i]);
    }
    printf("\nVetor atualizado: ");
    for (i = 0; i < ntam; i++) {
        printf("%d", vet[i]);
        if (i < ntam - 1) {
            printf("; ");
        }
    }
    
    free(vet);
    printf("\n\n");
    return 0;
}