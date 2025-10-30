//4.7.8: escreva uma função que remova a k-esima célula de uma lista encadeada

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} no;

no *remove_kesimo(no *lista, int k) {
    if (lista == NULL) {
        return NULL;
    }

    // Remover o primeiro nó
    if (k == 1) {
        no *removido = lista;
        lista = lista->prox; // o novo início será o segundo nó
        free(removido);
        return lista;
    }

    // Remover nó no meio ou no fim
    no *aux = lista;
    int contagem = 1;

    // percorre até o nó anterior ao que será removido
    while (aux != NULL && contagem < k - 1) {
        aux = aux->prox;
        contagem++;
    }

    // se k é maior que o tamanho da lista
    if (aux == NULL || aux->prox == NULL) {
        printf("Posição inválida!\n");
        return lista;
    }

    // remove o nó desejado
    no *removido = aux->prox;
    aux->prox = removido->prox;
    free(removido);

    return lista;
}