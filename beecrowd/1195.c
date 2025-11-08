#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;             
    struct no *esq;        
    struct no *dir;      
} no;

no *cria_no(int valor) {
    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL) {
        exit(1); // encerra se não conseguir alocar memória
    }
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Se o valor for menor que o nó atual, vai para a esquerda
// Se for maior, vai para a direita
no *insere(no *raiz, int valor) {
    if (raiz == NULL) {
        return cria_no(valor);
    } else {
        if (valor < raiz->valor) {
            raiz->esq = insere(raiz->esq, valor);
        } else {
            raiz->dir = insere(raiz->dir, valor);
        }
    }
    return raiz;
}

// raiz -> esquerda -> direita
void pre_ordem(no *raiz, int *primeiro) {
    if (raiz == NULL) {
        return;
    }

    // Se for o primeiro valor, imprime sem espaço
    if (*primeiro == 0) {
        printf("%d", raiz->valor);
        *primeiro = 1; // marca que já imprimimos o primeiro valor
    } else {
        printf(" %d", raiz->valor);
    }

    pre_ordem(raiz->esq, primeiro);
    pre_ordem(raiz->dir, primeiro);
}

// esquerda -> raiz -> direita
void in_ordem(no *raiz, int *primeiro) {
    if (raiz == NULL) {
        return;
    }

    in_ordem(raiz->esq, primeiro);

    if (*primeiro == 0) {
        printf("%d", raiz->valor);
        *primeiro = 1;
    } else {
        printf(" %d", raiz->valor);
    }

    in_ordem(raiz->dir, primeiro);
}

// esquerda -> direita -> raiz
void pos_ordem(no *raiz, int *primeiro) {
    if (raiz == NULL) {
        return;
    }

    pos_ordem(raiz->esq, primeiro);
    pos_ordem(raiz->dir, primeiro);

    if (*primeiro == 0) {
        printf("%d", raiz->valor);
        *primeiro = 1;
    } else {
        printf(" %d", raiz->valor);
    }
}

void libera(no *raiz) {
    if (raiz == NULL) {
        return;
    }
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main() {
    int C; // número de casos de teste
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        int N; // quantidade de números da árvore
        scanf("%d", &N);

        no *raiz = NULL; // árvore inicialmente vazia

        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);
            raiz = insere(raiz, valor);
        }

        printf("Case %d:\n", caso);

        int primeiro = 0; // controla o espaço no início
        printf("Pre.: ");
        pre_ordem(raiz, &primeiro);
        printf("\n");

        primeiro = 0;
        printf("In..: ");
        in_ordem(raiz, &primeiro);
        printf("\n");

        primeiro = 0;
        printf("Post: ");
        pos_ordem(raiz, &primeiro);
        printf("\n\n");

        libera(raiz);
    }

    return 0;
}