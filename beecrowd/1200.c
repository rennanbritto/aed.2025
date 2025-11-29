#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor;
    struct no *esquerda;
    struct no *direita;
} No;

// criar nó
No* criar_no(char valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// inserir na BST (ignora repetidos)
No* inserir(No* raiz, char valor) {
    if (raiz == NULL)
        return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

// pesquisa 
int pesquisar(No* raiz, char valor) {
    if (raiz == NULL) return 0;
    if (valor == raiz->valor) return 1;
    if (valor < raiz->valor)
        return pesquisar(raiz->esquerda, valor);
    else
        return pesquisar(raiz->direita, valor);
}

// Impressões sem espaço no final
void imprimir_infixa(No* raiz, int *primeiro) {
    if (raiz == NULL) return;
    imprimir_infixa(raiz->esquerda, primeiro);

    if (*primeiro) { printf("%c", raiz->valor); *primeiro = 0; }
    else printf(" %c", raiz->valor);

    imprimir_infixa(raiz->direita, primeiro);
}

void imprimir_prefixa(No* raiz, int *primeiro) {
    if (raiz == NULL) return;

    if (*primeiro) { printf("%c", raiz->valor); *primeiro = 0; }
    else printf(" %c", raiz->valor);

    imprimir_prefixa(raiz->esquerda, primeiro);
    imprimir_prefixa(raiz->direita, primeiro);
}

void imprimir_posfixa(No* raiz, int *primeiro) {
    if (raiz == NULL) return;

    imprimir_posfixa(raiz->esquerda, primeiro);
    imprimir_posfixa(raiz->direita, primeiro);

    if (*primeiro) { printf("%c", raiz->valor); *primeiro = 0; }
    else printf(" %c", raiz->valor);
}

// libera árvore (opcional) 
void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

int main() {
    No* raiz = NULL;
    char comando[32];
    char caractere;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            if (scanf(" %c", &caractere) == 1)
                raiz = inserir(raiz, caractere);
        }
        else if (strcmp(comando, "P") == 0) {
            if (scanf(" %c", &caractere) == 1) {
                if (pesquisar(raiz, caractere))
                    printf("%c existe\n", caractere);
                else
                    printf("%c nao existe\n", caractere);
            }
        }
        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            imprimir_infixa(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            imprimir_prefixa(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            imprimir_posfixa(raiz, &primeiro);
            printf("\n");
        }
        /* ignora comandos desconhecidos silenciosamente */
    }

    liberar_arvore(raiz);
    return 0;
}
