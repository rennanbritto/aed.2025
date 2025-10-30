// Em uma lista duplamente encadeada, escreva uma função que insira uma nova céula
// com conteúdo y logo após a célula cujo endereço é p. Que dados a função recebe? que coisa retorna?

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int info;           
    struct no *prox;   
    struct no *ant;     
} no;

// Retorna SEMPRE o início da lista
no* busca_insere_depois_recursivo(no* lista, int y, no* p) {

    // Caso a lista esteja vazia, cria o primeiro nó
    if (lista == NULL) {
        no* novo = malloc(sizeof(no));
        novo->info = y;
        novo->ant = novo->prox = NULL;
        return novo;
    }

    if (lista == p) {
        no* novo = malloc(sizeof(no));
        novo->info = y;
        novo->ant = lista;
        novo->prox = lista->prox;

        // Caso p não seja o último
        if (lista->prox != NULL){ 
            lista->prox->ant = novo;
        }
        // Faz p apontar para o novo nó
        lista->prox = novo;

        return lista;
    }

    busca_insere_depois_recursivo(lista->prox, y, p);
    return lista;
}

void imprime(no* lista) {
    printf("Lista: ");
    for (no* aux = lista; aux != NULL; aux = aux->prox)
        printf("%d ", aux->info);
    printf("\n");
}

int main() {
    // Exemplo teste
    no *a = malloc(sizeof(no));
    no *b = malloc(sizeof(no));
    no *c = malloc(sizeof(no));

    a->info = 10; a->ant = NULL; a->prox = b;
    b->info = 20; b->ant = a;    b->prox = c;
    c->info = 30; c->ant = b;    c->prox = NULL;

    no *lista = a;

    imprime(lista);
    lista = busca_insere_depois_recursivo(lista, 99, b); // insere 99 após o nó b (20)
    imprime(lista);

    return 0;
}