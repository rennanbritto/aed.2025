// 4.7.11: Faça uma função que inverta uma lista encadeada apenas mudando os ponteiros (pag. 29)

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} no;

no *inverter_lista(no *inicio) {
    no *anterior = NULL;   // começa sem anterior
    no *atual = inicio;    // começa do início da lista
    no *proximo = NULL;    // ponteiro temporário

    while (atual != NULL) {
        proximo = atual->prox;   // guarda o próximo nó
        atual->prox = anterior;  // inverte o ponteiro
        anterior = atual;        // anda com o anterior
        atual = proximo;         // anda com o atual
    }

    // 'anterior' agora é o novo início da lista
    return anterior;
}

no *inserir_inicio(no *inicio, int valor) {
    no *novo = malloc(sizeof(no));
    novo->info = valor;
    novo->prox = inicio;
    return novo;
}

void imprimir(no *inicio) {
    for (no *p = inicio; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
}

int main() {
    no *lista = NULL;

    lista = inserir_inicio(lista, 40);
    lista = inserir_inicio(lista, 30);
    lista = inserir_inicio(lista, 15);

    printf("Lista inicial: ");
    imprimir(lista);

    lista = inverter_lista(lista);

    printf("Lista invertida: ");
    imprimir(lista);

    return 0;
}