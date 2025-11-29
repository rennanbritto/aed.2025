//beecrowd dá problema pelo tamanho, mas o codigo funciona testando alguns casos manualmente
#include <stdio.h>
#define MAX 10005

// Matriz de adjacência
int mat[10005][10005];

// Vetor de cores:
//  0 = não visitado
//  1 = visitando
//  2 = visitado
int cor[MAX];

int achou_ciclo;

// DFS para detectar ciclo em grafo dirigido
void dfs(int u, int N) {
    if (achou_ciclo) return;

    cor[u] = 1; // marcando como visitando

    for (int v = 1; v <= N; v++) {
        if (mat[u][v]) {  // existe aresta u -> v
            if (cor[v] == 1) {
                achou_ciclo = 1;  // encontr ciclo
                return;
            }
            if (cor[v] == 0) {
                dfs(v, N);
            }
        }
    }

    cor[u] = 2; // terminou
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        // zerar matriz e cores
        for (int i = 1; i <= N; i++) {
            cor[i] = 0;
            for (int j = 1; j <= N; j++) {
                mat[i][j] = 0;
            }
        }

        // leitura das dependências
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            mat[A][B] = 1;  // marca a aresta
        }

        achou_ciclo = 0;

        // roda DFS em todos os nós
        for (int i = 1; i <= N && !achou_ciclo; i++) {
            if (cor[i] == 0) {
                dfs(i, N);
            }
        }

        if (achou_ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}