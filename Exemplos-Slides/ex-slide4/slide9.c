/*
• Implemente um TAD conta bancária com campos
número e saldo que suporte as as seguintes operações:
- Iniciar uma nova conta com um número e saldo
- Depositar um valor na conta
- Sacar um valor da conta
- Imprimir o saldo
• Testar o TAD
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // typedef permite que você use conta_bancaria diretamente como tipo de variável (sem precisar escrever struct conta_bancaria toda vez).
    int numero;
    float saldo;
} Conta;

void iniciar_conta(Conta *conta, int numero, float saldo_inicial) { // *conta é um ponteiro que aponta para uma variável do tipo conta bancária.
    conta->numero = numero; // Operador -> acessa os campos da struct apontada
    conta->saldo = saldo_inicial;
}

void depositar(Conta *conta, float valor) {
    conta->saldo += valor;
}

void sacar(Conta *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
    } else {
        printf("Saldo insuficiente!\n");
    }
}

void imprimir_saldo(Conta conta) {
    printf("Saldo da conta %d: R$%.2f\n", conta.numero, conta.saldo);
}

int main (void) {
    Conta contaBancaria;
    float saldo_inicial, valor_deposito, valor_saque;

    printf("Digite o número da conta: ");
    scanf("%d", &contaBancaria.numero);
    printf("Digite o saldo da conta: R$ ");
    scanf("%f", &saldo_inicial);
    iniciar_conta(&contaBancaria, contaBancaria.numero, saldo_inicial);

    printf("Valor para depósito: R$");
    scanf("%f", &valor_deposito);
    depositar(&contaBancaria, valor_deposito);

    printf("Valor para saque: R$");
    scanf("%f", &valor_saque);
    sacar(&contaBancaria, valor_saque);

    imprimir_saldo(contaBancaria);

    return 0;
}
