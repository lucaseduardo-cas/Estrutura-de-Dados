/*
Funções para Alocação Dinâmica
- malloc() é usada para reservar memória em tempo de execução.
- Ao contrário de variáveis normais, que têm tamanho fixo definido em tempo de compilação, malloc permite alocar memória quando o programa já está rodando.
- Retorna um ponteiro genérico (void*), então é comum fazer um cast para o tipo apropriado, como (int*).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função de alocação dinâmica - malloc () - Alocação simples
int main (void) {
    setlocale(LC_ALL, "portuguese");

    int *ptr;

    ptr = (int*) malloc(sizeof(int)); // Aloca espaço para um inteiro

    if (ptr == NULL) { // Boas práticas: sempre verificar se o malloc funcionou
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    *ptr = 42; // Atribui um valor à memória alocada
    printf("Valor armazenado: %d\n", *ptr);

    free(ptr); // Libera memória

    printf("\n\n\n");
    return 0;
}
