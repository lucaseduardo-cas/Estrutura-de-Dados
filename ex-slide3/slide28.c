/*
Atividade:
Crie um vetor dinâmico onde o usuário ira definir o tamanho inicial, depois preencha o vetor com valores aleatários. Em seguida redimensione esse vetor preenchendo com novos valores se necessário. Por fim, exibas os valores na tela (nâo esqueça de liberar a memória)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Funções de alocação dinámica - realloc () - Redmensionando memória
int main (void) {
    setlocale(LC_ALL, "portuguese");

    int *vet, tam, novo_tam, i;

    printf("Digite o tamanho inicial do vetor: ");
    scanf("%d", &tam);

    // Aloca memória para 'tam' inteiros
    vet = (int*) malloc(tam * sizeof(int));
    if (!vet) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Preenche o vetor com os valores digitados
    for (i = 0; i < tam; i++) {
        printf("Digite o %2d° elemento: ", i + 1);
        scanf("%d", &vet[i]);
    }

    // Solicita o novo tamanho do vetor
    printf("Digite o novo tamanho do vetor: ");
    scanf("%d", &novo_tam);

    // Redimensiona o vetor para o novo tamanho
    vet = (int*) realloc(vet, novo_tam * sizeof(int));
    if (!vet) {
        printf("Erro na realocação de memória!\n");
        return 1;
    }

    // Preenche os novos elementos (somente se o vetor foi aumentado)
    for (i = tam; i < novo_tam; i++) {
        printf("Digite o novo %2d elemento: ", i + 1);
        scanf("%d", &vet[i]);
    }

    // Exibe o vetor final
    printf("Vetor final: ");
    for (i = 0; i < novo_tam; i++)
        printf("%d ", vet[i]);

    // Libera a memória alocada dinamicamente
    free(vet);
    vet = NULL;

    printf("\n\n\n");
    return 0;
}
