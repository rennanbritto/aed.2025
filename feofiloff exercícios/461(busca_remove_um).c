#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} lista;

// ex 4.6.1
// remove o **primeiro** elemento com valor x
    void Busca_Remove_recursivo(lista *p, int x) {
    if (p == NULL || p->prox == NULL) return;

    if (p->prox->info == x) {  
        lista *r = p->prox;
        p->prox = r->prox;     
        free(r);
        return;           
    }

    Busca_Remove_recursivo(p->prox, x); // continua procurando
    }