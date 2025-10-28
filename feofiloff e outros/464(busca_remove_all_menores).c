#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} lista;


// ex 4.6.4
// remove todos os elementos com valor <= x
void Busca_Remove_Tudo_min_recursivo(lista *p, int x) {
    if (p == NULL || p->prox == NULL) return;

    if (p->prox->info <= x) {
        lista *r = p->prox;
        p->prox = r->prox;
        free(r);
        Busca_Remove_Tudo_min_recursivo(p, x); // continua no mesmo p
    } else {
        Busca_Remove_Tudo_min_recursivo(p->prox, x); // avança
    }
}