/*
Ponteiro para struct

Regra: (Característica da linguagem C)
Quanto estiver manipulando struct, utiliza-se o operador "."
Quando estiver manipulando ponteiros para struct "->"
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
} Data;

void imprimirData(Data *x) {
    printf("%d/%02d/%d\n", x->dia, x->mes, x->ano);
}

int main (void) {
    Data data;
    Data *p;
    p = &data;

    imprimirData(p);
    printf("data: %p\tp: %p\n", &data, p);

    data.dia=29;
    data.mes=02;
    data.ano=2021;

    return 0;
}
