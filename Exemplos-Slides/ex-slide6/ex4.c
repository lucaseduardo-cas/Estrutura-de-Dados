/*
4. Implemente o sistema para a biblioteca usando o TAD fila:
    - Cada livro deve ser representado por um registro
      • Nome do livro, disponibilidade, fila de espera
    - Ao requisitar um livro, a pessoa entra na fila de espera se o
      livro não estiver disponível
    - Quando um livro fica disponível, o primeiro da fila de espera do
      livro deve receber o livro
    - Implemente as demais funcionalidades (cadastra livro, retira
      livro, etc.) que julgar necessárias
*/

#include <stdio.h>
#include <string.h>
#define MAX_LIVROS 10
#define MAX_NOME 50
#define MAX_FILA 10

// TAD Fila simples de nomes (usuários esperando)
typedef struct {
    char nomes[MAX_FILA][MAX_NOME];
    int ini, fim;
} Fila;

typedef struct {
    char nome[MAX_NOME];
    int disponivel;
    Fila espera;
} Livro;

// Inicializa a fila
void inicializaFila(Fila *f) {
    f->ini = f->fim = 0;
}

// Enfileira nome na fila
void enfileira(Fila *f, char nome[]) {
    if (f->fim < MAX_FILA) {
        strcpy(f->nomes[f->fim++], nome);
    }
}

// Desenfileira nome
void desenfileira(Fila *f, char nome[]) {
    if (f->ini < f->fim) {
        strcpy(nome, f->nomes[f->ini++]);
    }
}

// Verifica se há alguém esperando
int filaVazia(Fila *f) {
    return f->ini == f->fim;
}

// Cadastra novo livro
void cadastrarLivro(Livro livros[], int *qtd) {
    printf("Nome do livro: ");
    getchar(); // Limpa buffer
    fgets(livros[*qtd].nome, MAX_NOME, stdin);
    livros[*qtd].nome[strcspn(livros[*qtd].nome, "\n")] = 0;
    livros[*qtd].disponivel = 1;
    inicializaFila(&livros[*qtd].espera);
    (*qtd)++;
    printf("Livro cadastrado com sucesso!\n");
}

// Requisita livro
void requisitarLivro(Livro livros[], int qtd) {
    char nome[MAX_NOME], usuario[MAX_NOME];
    printf("Nome do livro: ");
    getchar();
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < qtd; i++) {
        if (strcmp(livros[i].nome, nome) == 0) {
            if (livros[i].disponivel) {
                livros[i].disponivel = 0;
                printf("Livro entregue diretamente!\n");
            } else {
                printf("Livro indisponível. Nome para fila de espera: ");
                fgets(usuario, MAX_NOME, stdin);
                usuario[strcspn(usuario, "\n")] = 0;
                enfileira(&livros[i].espera, usuario);
                printf("Usuário adicionado à fila.\n");
            }
            return;
        }
    }
    printf("Livro não encontrado!\n");
}

// Devolve livro
void devolverLivro(Livro livros[], int qtd) {
    char nome[MAX_NOME], usuario[MAX_NOME];
    printf("Nome do livro: ");
    getchar();
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < qtd; i++) {
        if (strcmp(livros[i].nome, nome) == 0) {
            if (!filaVazia(&livros[i].espera)) {
                desenfileira(&livros[i].espera, usuario);
                printf("Livro entregue ao próximo da fila: %s\n", usuario);
            } else {
                livros[i].disponivel = 1;
                printf("Livro agora está disponível na biblioteca.\n");
            }
            return;
        }
    }
    printf("Livro não encontrado!\n");
}

// Mostra livros e status
void mostrarLivros(Livro livros[], int qtd) {
    printf("\n--- Livros na biblioteca ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Livro: %s | %s | Fila: %d pessoas\n", livros[i].nome,
               livros[i].disponivel ? "Disponível" : "Emprestado",
               livros[i].espera.fim - livros[i].espera.ini);
    }
    printf("----------------------------\n");
}

int main() {
    Livro livros[MAX_LIVROS];
    int qtd = 0, opc;

    do {
        printf("\n1 - Cadastrar livro\n2 - Requisitar livro\n3 - Devolver livro\n4 - Mostrar livros\n0 - Sair\nOpção: ");
        scanf("%d", &opc);
        switch (opc) {
            case 1: cadastrarLivro(livros, &qtd); break;
            case 2: requisitarLivro(livros, qtd); break;
            case 3: devolverLivro(livros, qtd); break;
            case 4: mostrarLivros(livros, qtd); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opc != 0);

    return 0;
}
