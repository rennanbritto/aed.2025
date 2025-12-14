#include <stdio.h>

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir
}no;

no* remover_folhas(no *raiz) {
    if (raiz == NULL)
        return NULL;

    if (raiz->esq == NULL && raiz->dir == NULL) {
        free(raiz);
        return NULL;
    }

    raiz->esq = remover_folhas(raiz->esq);
    raiz->dir = remover_folhas(raiz->dir);

    return raiz;
}