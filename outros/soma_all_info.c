#include <stdio.h>

// soma todos os valores dos nós da ABB 

typedef struct no {
    int info;
    struct no *esq;
    struct no *dir;
} no;


int soma(no *raiz) {
    if (raiz == NULL)
        return 0;

    int soma_esq = soma(raiz->esq);  // soma da subárvore esquerda
    int soma_dir = soma(raiz->dir);  // soma da subárvore direita

    return raiz->info + soma_esq + soma_dir;
}
