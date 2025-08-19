/*
Supondo a seguinte fila:
   0     1     2     3     4
+-----+-----+-----+-----+-----+
|     |     | 3.2 | 3.0 | 7.3 |
+-----+-----+-----+-----+-----+
               ^     ^
               |     |
            início   |
                    Fim

Deseja-se enfileirar o 5.4 (O VETOR ACABOU, MAS HÁ ESPAÇO NO INÍCIO DA FILA!)
Exerício: deslocar os elementos para o início da fila
    * Uso de FILA CIRCULAR
        - Solução mais empregada
        - Tem menor custo computacional
        - mais fácil implementação

Para evitar que a fila ultrapasse a memória dos elementos após várias operações,
basta apontar o último elemento ao primeiro:

+-------------+             void enfilera (Fila *f, int a) {
| MAX -1 == 9 | ---+            f->elementos[f->ultimo] = a;
+-------------+    |            f->ultimo += 1;
       |           |            if (f->ultimo == MAX) {
+-------------+    |                f->ultimo = 0;
|      3      |    |            }
+-------------+    |        }
|      2      |    |        
+-------------+    |        int desenfilera (Fila *f) {
|      1      |    |            int r = f->elementos[f->primeiro];
+-------------+    |            f->primeiro += 1;
|      0      | <--+            if(f->primeiro == MAX) {
+-------------+                     f->primeiro = 0;
                                }
                                return r;
                            }
                            
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elementos[MAX];
    int primeiro;   // índice de remoção
    int ultimo;     // índice de inserção
    int qtd;        // controle de quantidade (necessário p/ detectar cheia/vazia)
} Fila;

Fila* cria(void) {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (!f) {
        perror("Erro ao alocar fila");
        exit(1);
    }
    f->primeiro = 0;
    f->ultimo = 0;
    f->qtd = 0;
    return f;
}

int filaCheia(Fila *f) {
    return f->qtd == MAX;
}

int filaVazia(Fila *f) {
    return f->qtd == 0;
}

// exatamente como no comentário
void enfilera(Fila *f, int a) {
    if (filaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->elementos[f->ultimo] = a;
    f->ultimo += 1;
    if (f->ultimo == MAX) {
        f->ultimo = 0;
    }
    f->qtd++;
}

// exatamente como no comentário
int desenfilera(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int r = f->elementos[f->primeiro];
    f->primeiro += 1;
    if (f->primeiro == MAX) {
        f->primeiro = 0;
    }
    f->qtd--;
    return r;
}

void imprimeFila(Fila *f) {
    printf("\nFila: ");
    int i = f->primeiro;
    for (int c = 0; c < f->qtd; c++) {
        printf("%d ", f->elementos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void destroiFila(Fila *f) {
    free(f);
}

int main(void) {
    int valor;
    char funcao;
    Fila *minhaFila = cria();

    while(1) {
        printf("\nDigite:\n");
        printf("   (e) para enfileirar\n");
        printf("   (d) para desenfileirar\n");
        printf("   (i) para imprimir\n");
        printf("   (f) para finalizar\n");
        printf("Opção: ");
        scanf(" %c", &funcao);

        switch (funcao) {
            case 'e':
                printf("\nDigite um valor a ser enfileirado: ");
                scanf("%d", &valor);
                enfilera(minhaFila, valor);
                break;
            case 'd':
                valor = desenfilera(minhaFila);
                if (valor != -1)
                    printf("\nO valor desenfileirado é: %d\n", valor);
                break;
            case 'i':
                imprimeFila(minhaFila);
                break;
            case 'f':
                destroiFila(minhaFila);
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
}
