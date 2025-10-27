#include <stdio.h>

typedef struct celula {
    int info;
    struct celula *prox;
} celula;

// ex 4.3.3 pag 24
// busca um inteiro x numa lista encadeada (sem cabeça)
celula *busca(celula *head, int x){
    if(head == NULL){
        return NULL;
    }

    if(head->info == x){
        return head;
    }

    return busca(head->prox, x);
}

// usar essa função para ignorar a cabeça
celula *busca_com_cabeca(celula *head, int x){
    if (head == NULL){
        return NULL;
    }
    return busca(head->prox, x);
}
int main (){
    // exemplo de como puxar na main
    // ainda precisa declarar os nós
    celula *head = malloc(sizeof(celula));
    head->prox = NULL;
    int x = 100;

    celula *re= busca_com_cabeca(head, x); 
}