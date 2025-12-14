#include <stdio.h>

typedef struct no {
    int info;
    struct no *esq;
    struct no *dir;
} no;

// Função para criar nó
no* criar_no(int valor) {
    no *novo = malloc(sizeof(no));
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Inserção simples de ABB (como já vimos antes)
no* inserir(no *raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);

    if (valor < raiz->info)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}