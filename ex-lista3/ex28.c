/*
28) Simulação de estacionamento com entrada e saída de carros,
permitindo manobras se necessário. Capacidade de até 10 carros.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int placa;
    int manobras;
} Carro;

int main() {
    Carro *estacionamento = malloc(MAX * sizeof(Carro));
    Carro *aux = malloc(MAX * sizeof(Carro));
    int topo = -1;
    int opcao;

    printf("======== ESTACIONAMENTO - RUA DIREITA ========\n");

    while (1) {
        printf("\n[1] Entrada de carro\n[2] Saída de carro\n[0] Encerrar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        if (opcao == 1) {
            if (topo == MAX - 1) {
                printf("Estacionamento cheio. Carro não entrou.\n");
                continue;
            }

            int placa;
            printf("Digite o número da placa do carro que vai ENTRAR: ");
            scanf("%d", &placa);

            topo++;
            estacionamento[topo].placa = placa;
            estacionamento[topo].manobras = 0;
            printf("Carro %d entrou no estacionamento.\n", placa);
        }

        else if (opcao == 2) {
            if (topo == -1) {
                printf("Estacionamento vazio. Nenhum carro para sair.\n");
                continue;
            }

            int placa, encontrado = 0, manobras = 0;
            printf("Digite o número da placa do carro que vai SAIR: ");
            scanf("%d", &placa);

            int aux_topo = -1;

            while (topo >= 0) {
                if (estacionamento[topo].placa == placa) {
                    encontrado = 1;
                    topo--;  // remove o carro da pilha
                    break;
                }
                aux[++aux_topo] = estacionamento[topo--];
                manobras++;
            }

            if (encontrado) {
                printf("Carro %d saiu após %d manobras.\n", placa, manobras);
            } else {
                printf("Carro %d não está no estacionamento.\n", placa);
            }

            // Reempilhar os carros removidos
            while (aux_topo >= 0) {
                estacionamento[++topo] = aux[aux_topo--];
            }
        }

        else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    free(estacionamento);
    free(aux);

    printf("Programa encerrado.\n");
    return 0;
}
