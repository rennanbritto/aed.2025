#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} lista;

// ex 4.6.2
// insere um valor val **imediatamente antes** do primeiro nó com valor x
void Busca_Insere_recursivo(lista *p, int x, int val) {
    if (p == NULL || p->prox == NULL) return;

    if (p->prox->info == x) {
        lista *novo = malloc(sizeof(lista));
        if (novo == NULL) {
            printf("Erro: sem memória!\n");
            return;
        }
        novo->info = val;
        novo->prox = p->prox;
        p->prox = novo;
        return; // insere apenas antes do primeiro x
    }

    Busca_Insere_recursivo(p->prox, x, val); // continua procurando
}