#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* criar_no(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: memória insuficiente\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Inserir ABB valores: esq < raiz < dir
No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

//Funç~es de fila para usar na BFS
typedef struct {
    No **itens;     
    int capacidade; 
    int inicio;     
    int fim;        
} FilaCircular;

void iniciar_fila(FilaCircular *f, int capacidade_declarada) {
    f->capacidade = capacidade_declarada;
    f->itens = (No**) malloc(sizeof(No*) * f->capacidade);
    if (f->itens == NULL) {
        fprintf(stderr, "Erro: memória insuficiente para fila\n");
        exit(EXIT_FAILURE);
    }
    f->inicio = 0;
    f->fim = 0;
}

int fila_vazia(FilaCircular *f) {
    return f->inicio == f->fim;
}

int fila_cheia(FilaCircular *f) {
    return ((f->fim + 1) % f->capacidade) == f->inicio;
}


void enfileirar(FilaCircular *f, No *valor) {
    if (fila_cheia(f)) {
        fprintf(stderr, "Erro: tentativa de enfileirar em fila cheia\n");
        exit(EXIT_FAILURE);
    }
    // coloca o ponteiro no índice 'fim'
    f->itens[f->fim] = valor;
    // avança 'fim' (com wrap-around usando módulo)
    f->fim = (f->fim + 1) % f->capacidade;
}

No* desenfileirar(FilaCircular *f) {
    if (fila_vazia(f)) {
        return NULL;
    }
    No *ret = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    return ret;
}

void liberar_fila(FilaCircular *f) {
    free(f->itens);
    f->itens = NULL;
    f->capacidade = 0;
    f->inicio = f->fim = 0;
}

//visita os nós por nível, se tiver filhos, eles entrarão no final da fila
void BFS(No *raiz) {
    if (raiz == NULL) return;

    FilaCircular fila;
    iniciar_fila(&fila, 1005);
    enfileirar(&fila, raiz);

    int primeiro = 1; // não imprimir espaço antes do primeiro número

    // enquanto houver elementos na fila, processamos
    while (!fila_vazia(&fila)) {
        No *atual = desenfileirar(&fila);
    
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esq != NULL) {
            enfileirar(&fila, atual->esq);
        }
        if (atual->dir != NULL) {
            enfileirar(&fila, atual->dir);
        }
    }

    printf("\n");

    liberar_fila(&fila);
}

void liberar(No *raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int C;
    if (scanf("%d", &C) != 1) return 0;

    for (int caso = 1; caso <= C; caso++) {
        int N;
        scanf("%d", &N);

        No *raiz = NULL;

        // lemos os N valores e inserimos na ABB
        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        printf("Case %d:\n", caso);
        BFS(raiz);
        printf("\n"); // linha em branco após cada caso de teste

        liberar(raiz);
    }

    return 0;
}
