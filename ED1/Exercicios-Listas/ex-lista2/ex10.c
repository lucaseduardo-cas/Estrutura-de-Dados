#include <stdio.h>

int globalVar = 5; // Variável global

void alteraGlobal() {
    globalVar = 10; // Modificando a variável global
}

int main() {
    printf("Antes: %d\n", globalVar);
    alteraGlobal();
    printf("Depois: %d\n", globalVar); // Mostra que a variável foi 
    return 0;
}
