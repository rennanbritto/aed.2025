#include <stdio.h>

typedef struct no {
    int info;
    struct no *esq;
    struct no *dir;
} no;


int altura(no *raiz) {
    if (raiz == NULL)
        return -1;  // árvore vazia tem altura -1

    int altura_esq = altura(raiz->esq);
    int altura_dir = altura(raiz->dir);

    if (altura_esq > altura_dir){ 
        return altura_esq + 1;
    }// não considera igual, pois em abb não tem valores iguais
    if (altura_esq < altura_dir){
        return altura_dir + 1;
    }
}