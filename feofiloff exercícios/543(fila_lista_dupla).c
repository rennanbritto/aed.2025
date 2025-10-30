// 5.4.3: implemente uma fila em uma lista duplamente encadeada 
// sem cabeça. Mantenha um ponteiro para a primeira célula e um 
// ponteiro para a última

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *ant;
    struct no *prox;
} no;

typedef struct fila {
    no *inicio;
    no *fim;
} fila;

// Cria uma fila vazia
fila *criar_fila() {
    fila *f = malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Insere no final da fila
void inserir_fila(fila *f, int x) {
    no *novo = malloc(sizeof(no));
    novo->info = x;
    novo->ant = f->fim;
    novo->prox = NULL;

    // Caso 1: fila vazia
    if (f->fim == NULL) {
        f->inicio = novo;
    } else { // Caso 2: inserir no final
        f->fim->prox = novo;
    }

    f->fim = novo;
}

// Remove do início da fila
int remover_fila(fila *f) {
    if (f->inicio == NULL) {
        return -1; // Fila vazia
    }

    no *auxiliar = f->inicio;
    int valor = auxiliar->info;

    if (f->inicio == f->fim) { // só um elemento
        f->inicio = NULL;
        f->fim = NULL;
    } else {
        f->inicio = auxiliar->prox;
        f->inicio->ant = NULL;
    }

    free(auxiliar);
    return valor;
}

// Imprime a fila (opcional)
void imprimir_fila(fila *f) {
    for (no *p = f->inicio; p != NULL; p = p->prox)
        printf("%d ", p->info);
    printf("\n");
}

int main() {
    fila *f = criar_fila();

    inserir_fila(f, 10);
    inserir_fila(f, 20);
    inserir_fila(f, 30);

    imprimir_fila(f);

    printf("Removido: %d\n", remover_fila(f));
    imprimir_fila(f);

    return 0;
}
