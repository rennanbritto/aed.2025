#include <stdio.h>

#define MAX 100000

typedef struct {
    int valores[MAX];
    int frente, fim, tamanho;
} Fila;

void inicializar(Fila *f) {
    f->frente = 0;
    f->fim = 0;
    f->tamanho = 0;
}

// Adiciona um valor ao fim da fila
void adicionar_fim(Fila *f, int valor) {
    f->valores[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
}

// Remove um valor do início da fila
void remover_inicio(Fila *f) {
    if (f->tamanho > 0) {
        f->frente = (f->frente + 1) % MAX;
        f->tamanho--;
    }
}

// Obtém o valor do início da fila
int inicio(Fila *f) {
    return f->valores[f->frente];
}

// Verifica o tamanho da fila
int tamanho(Fila *f) {
    return f->tamanho;
}

// Verifica se a fila está vazia
int vazio(Fila *f) {
    return f->tamanho == 0;
}

int main() {
    int quantidade_cartas, primeira_iteracao;
    Fila cartas;

    while (scanf("%d", &quantidade_cartas) != EOF) {
        if (quantidade_cartas == 0)
            break;

        inicializar(&cartas);

        for (int i = 1; i <= quantidade_cartas; ++i) {
            adicionar_fim(&cartas, i);
        }

        primeira_iteracao = 1;
        printf("Discarded cards: ");
        while (tamanho(&cartas) > 1) {
            if (!primeira_iteracao)
                printf(", ");
            else
                primeira_iteracao = 0;

            printf("%d", inicio(&cartas));

            remover_inicio(&cartas);
            adicionar_fim(&cartas, inicio(&cartas));
            remover_inicio(&cartas);
        }
        if (vazio(&cartas)) {
            printf("\nRemaining card: \n");
        } else {
            printf("\nRemaining card: %d\n", inicio(&cartas));
        }
    }

    return 0;
}
