/*
Alocação dinâmica: malloc e calloc (Manipulação de memória via ponteiros)

A função malloc reserva um espaço de memória, em bytes, definido pelo usuário, do tipo definido pelo usuário
e retorna o endereço da memória genérico (void) na variável definida. Uma vantagem é não precisar de declarar 
uma variável auxiliar para passar o endereço para o ponteiro. Exemplo:
    int *p, a;
    p = &a;
    *p = 5;
    prinf("%d", a);

- A função malloc atribui um endereço de memória encontrado para a variável.
- (int*) é um casting: converte um ponteiro genérico (void*) apontado por malloc para um ponteiro do tipo int*. 
Ou seja, um ponteiro para um inteiro, já que 'p' é um ponteiro.
- Em geral, como o tamanho em bytes dos tipos de dados dependendem da arquitetura, o mais seguro é declarar 
da seguinte forma: p = (int*) malloc(sizeof(int));
- Operador sizeof retorna o tamanho em bytes de um tipo de dado ou variável

Já a função calloc faz algo bastante parecido, reserva um espaço de memória, mas ao mesmo tempo zera 
ese espaço na mamória. Coloca um série de 0 dentro desse espaço, que chamamos de inicializar.

- p = (int*) calloc(1,4); O primeiro digito '1' é a quantidade de elementos que o programador deseja alocar e '4' 
é quantos bytes ocupam esse elemento.
- free(p); é sempre importante usar depois de malloc, calloc, realloc, para liberar o espaço de memória alocado.
É importante para evitar "vazamento de memória". Ou esgotamento da memória fazendo cair a performace do programa.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc[], char **argv) {
    int *p;
    
    // p = (int*) malloc(4);
    p = (int*) malloc(sizeof(int));
    *p = 5;
    
    printf("Função malloc:\n");
    printf("%d\n\n", *p);
    free(p);
    
    // p = (int*) calloc(1,4); 
    p = (int*) calloc(1, sizeof(int));
    *p = 5;
    
    printf("Função calloc:\n");
    printf("%d\n", *p);
    free(p);
    return 0;
}