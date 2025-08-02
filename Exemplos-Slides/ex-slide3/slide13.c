/*
2.Os programas (trechos de código) abaixo possuem
erros. Qual(is)? Como deveriam ser?
*/

#include <stdio.h>

// a)
void funcao_a () {
    int x, *p;
    x = 100;
    //p = x; ERRO GRAVE: Você está tentando atribuir um inteiro (100) a um ponteiro (p).
    p = &x;
    printf("Valor de p: %d.\n", *p);
}

//b)
void funcao_b (int *i, int *j) { // Função troca
    // int *temp; ERRO: 'temp' deve ser uma variável int para armazenar o VALOR, não um ponteiro.
    int temp;
    // *temp = *i; ERRO GRAVE: Tentar desreferenciar um ponteiro não inicializado resulta em comportamento indefinido
    temp = *i;
    *i = *j;
    // *j = *temp; CORREÇÃO: Atribui o VALOR de temp ao que *j aponta.
    *j = temp;
}

int main (void) {
    char *a, *b;
    a = "abacate";
    b = "uva";

    if (a < b) {
        printf("%s vem antes de %s no dicionário\n", a, b);
    } else {
        printf("%s vem depois de %s no dicionário\n", a, b);
    }

    return 0;
}
