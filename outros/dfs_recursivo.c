#include <stdio.h>
#define MAX 100

int matriz[MAX][MAX];  
int visitado[MAX];     
int n;                  // vertices


void dfs(int atual) {

    // Marca o vértice atual como visitado
    visitado[atual] = 1;

    // Percorre todos os vizinhos
    for (int v = 0; v < n; v++) {

        // Se existe aresta e o vertice ainda não foi visitado
        if (matriz[atual][v] == 1 && visitado[v] == 0) {
            dfs(v); 
        }
    }
}

// dfs vai aprofundando em cada vizinho no formato de pilha, 
// a recursão já empilha naturalmente