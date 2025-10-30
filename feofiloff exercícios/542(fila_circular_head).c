#include <stdio.h>
#include <stdlib.h>

//5.4.2: implemente uma fila em uma lista encadeada circular com cabeça

typedef struct no {
    int info;
    struct no *prox;
}no;

no *criar_fila(){
    no *head;
    head = malloc(sizeof(no));
    head->prox = head;
    return head;
}

//percorrer até head->prox = head
inserir_fila_circular(no *head, int x){
    no *novo;
    novo = malloc(sizeof(no));
    novo->info = x;

    no *auxiliar = head;
    while (auxiliar->prox != head){
        auxiliar = auxiliar->prox;
    }

    auxiliar->prox = novo;
    novo->prox = head; 
}

//por ser fila, remover o primeiro - fifo
int remover_fila_circular(no *head){
    //caso 1: fila vazia
    if (head->prox == head){
        return -1;
    }

    no *auxiliar;
    auxiliar = head->prox;
    int valor = auxiliar->info;

    //caso 2: removendo o ultimo nó, então a fila ficará vazia
    if(auxiliar->prox == head){
        head->prox = head;

    }else{ //caso 3: há mais que um nó
        head->prox = auxiliar->prox;
    }

    free(auxiliar);
    return valor;
}

void imprimir_lista_circular(no *head){
    if(head->prox == head) return;

    no *auxiliar = head->prox;
  
    while(auxiliar != head){
        printf("%d, ", auxiliar->info);
        auxiliar = auxiliar->prox;
    }
}