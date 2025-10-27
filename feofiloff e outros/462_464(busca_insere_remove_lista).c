// aqui tem os exercícios da página 28 (edição física):
    // ex 4.6.1
    // ex 4.6.2
    // ex 4.6.3
    // ex 4.6.4

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
    
// ex 4.6.3
// remove **todos** os elementos com valor x
void Busca_Remove_Tudo_recursivo(lista *p, int x) {
    if (p == NULL || p->prox == NULL) return;

    if (p->prox->info == x) {
        lista *r = p->prox;
        p->prox = r->prox;
        free(r);
        Busca_Remove_Tudo_recursivo(p, x); // continua no mesmo p
    } else {
        Busca_Remove_Tudo_recursivo(p->prox, x); // avança
    }
}

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

// função auxiliar para imprimir a lista
void imprimir(lista *head) {
    lista *p = head->prox;
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}