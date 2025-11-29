#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *prox;
} No;

No *adj[10005];

// cores
// 0 = não visitado
// 1 = visitando
// 2 = visitado

int cor[10005];

int achou_ciclo;

// Função para inserir aresta A -> B //
void adiciona_aresta(int A, int B) {
    No *novo = malloc(sizeof(No));
    novo->v = B;
    novo->prox = adj[A];
    adj[A] = novo;
}

// DFS para detectar ciclo //
void dfs(int u) {
    if (achou_ciclo) return; // se já achou, pare

    cor[u] = 1; // marcando como visitando

    No *p = adj[u];
    while (p != NULL) {
        int v = p->v;

        if (cor[v] == 1) {
            // voltou para um nó na pilha então é ciclo
            achou_ciclo = 1;
            return;
        }
        else if (cor[v] == 0) {
            dfs(v);
        }

        p = p->prox;
    }

    cor[u] = 2; // terminou, marca como visitado
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        // limpando as listas de adjacência
        for (int i = 1; i <= N; i++) {
            No *p = adj[i];
            while (p != NULL) {
                No *temp = p;
                p = p->prox;
                free(temp);
            }
            adj[i] = NULL;
            cor[i] = 0;
        }

        // leitura arestas
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adiciona_aresta(A, B);
        }

        achou_ciclo = 0;

        // rodando DFS em todos os nós
        for (int i = 1; i <= N && !achou_ciclo; i++) {
            if (cor[i] == 0) {
                dfs(i);
            }
        }

        if (achou_ciclo) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}