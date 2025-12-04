#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int vet[MAX];
    int topo;
} Pilha;

typedef struct {
    int vet[MAX];
    int ini, fim;
} Fila;

// Funções auxiliares da pilha
void push(Pilha *p, int x) { p->vet[++p->topo] = x; }
int pop(Pilha *p) { return p->vet[p->topo--]; }
int vazia_pilha(Pilha *p) { return p->topo < 0; }

// Funções da fila
void enfileira(Fila *f, int x) { f->vet[f->fim++] = x; }
int desenfileira(Fila *f) { return f->vet[f->ini++]; }
int vazia_fila(Fila *f) { return f->ini == f->fim; }

// Implementação simples de "priority queue" como max-heap
typedef struct {
    int vet[MAX];
    int tam;
} FP;

void heap_insere(FP *h, int x) {
    int i = h->tam++;
    h->vet[i] = x;

    while (i > 0) {
        int pai = (i - 1) / 2;
        if (h->vet[pai] >= h->vet[i]) break;
        int tmp = h->vet[pai];
        h->vet[pai] = h->vet[i];
        h->vet[i] = tmp;
        i = pai;
    }
}

int heap_remove(FP *h) {
    int maximo = h->vet[0];
    h->vet[0] = h->vet[--h->tam];

    int i = 0;
    while (1) {
        int esq = 2*i + 1, dir = 2*i + 2, maior = i;

        if (esq < h->tam && h->vet[esq] > h->vet[maior]) maior = esq;
        if (dir < h->tam && h->vet[dir] > h->vet[maior]) maior = dir;

        if (maior == i) break;

        int tmp = h->vet[i];
        h->vet[i] = h->vet[maior];
        h->vet[maior] = tmp;

        i = maior;
    }

    return maximo;
}

int vazia_fp(FP *h) { return h->tam == 0; }

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {

        // Estruturas
        Pilha pilha; pilha.topo = -1;
        Fila fila; fila.ini = fila.fim = 0;
        FP fp; fp.tam = 0;

        // Flags indicando possibilidades
        int possivel_pilha = 1;
        int possivel_fila = 1;
        int possivel_fp = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d", &op);

            if (op == 1) {
                scanf("%d", &x);

                if (possivel_pilha) push(&pilha, x);
                if (possivel_fila) enfileira(&fila, x);
                if (possivel_fp) heap_insere(&fp, x);

            } else { // op == 2
                scanf("%d", &x);

                if (possivel_pilha) {
                    if (vazia_pilha(&pilha) || pop(&pilha) != x)
                        possivel_pilha = 0;
                }

                if (possivel_fila) {
                    if (vazia_fila(&fila) || desenfileira(&fila) != x)
                        possivel_fila = 0;
                }

                if (possivel_fp) {
                    if (vazia_fp(&fp) || heap_remove(&fp) != x)
                        possivel_fp = 0;
                }
            }
        }

        int soma = possivel_pilha + possivel_fila + possivel_fp;

        if (soma == 0) printf("impossible\n");
        else if (soma > 1) printf("not sure\n");
        else if (possivel_pilha) printf("stack\n");
        else if (possivel_fila) printf("queue\n");
        else printf("priority queue\n");
    }

    return 0;
}
