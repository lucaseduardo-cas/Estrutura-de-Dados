/*
Ponteiros e Arrays
- Em C, o nome de um array já é um ponteiro para o
seu primeiro elemento
- Podemos acessar os elementos de um array usando aritmética
de ponteiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Ponteiros e Arrays
int main (void) {
    setlocale(LC_ALL, "portuguese");

    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr; // O ponteiro aponta para o primeiro elemento do array

    printf("1° elemento: %d\n", *ptr);
    printf("2° elemento: %d\n", *(ptr + 1)); // (ptr + 1) acessa o segumento elemento do array
    printf("3° elemento: %d\n", *(ptr + 2));
    printf("4° elemento: %d\n", *(ptr + 3));

    printf("\n\n\n");
    return 0;
}


/*
int main (void) {
    setlocale(LC_ALL, "portuguese");

    char arr[]="";
    int i=0;

    printf("Digite uma palavra: ");
    scanf("%[^ \n]", arr); // %[^ \n]

    char *ptr = arr; // O ponteiro aponta para o primeiro elemento do array

    while (*ptr != '\0') {
        printf("%d° elemento: %c\n", i+1, *ptr);
        ptr++; i++;
    }

    printf("\n\n\n");
    return 0;
}
*/
