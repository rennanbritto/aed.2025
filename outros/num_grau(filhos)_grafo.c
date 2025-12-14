// a função verifica qual vértice ten maior grau(mais vizinhos, filhos) 

#include <stdio.h>

int vertice_maior_grau(int matriz[][100], int n) {
    int vertice_atual;      // variável para caminhar pelas linhas (vértices)
    int vizinho;            // variável para caminhar pelas colunas (1 se tem e 0 se nã tem)
    int grau;              
    int maior_grau = -1;    // guarda o maior grau encontrado até agora
    int melhor_vertice = 0; // guarda o vértice de resposta

    // cada iteração fixa uma linha e verifica as colunas (vizinhos)
    for (vertice_atual = 0; vertice_atual < n; vertice_atual++) {

        grau = 0; // zera o grau antes de contar as arestas daquele vértice

        // conta quantas arestas existem para esse vértice
        for (vizinho = 0; vizinho < n; vizinho++) {
            if (matriz[vertice_atual][vizinho] == 1) {
                grau = grau + 1;
            }
        }

        // ver se o grau atual é maior que o global
        if (grau > maior_grau) {
            maior_grau = grau;
            melhor_vertice = vertice_atual;
        }
    }

    return melhor_vertice;
}

int main() {
    int n;
    int matriz[100][100];
    int i, j;

    printf("Digite o numero de vertices: ");
    scanf("%d", &n);

    printf("Digite a matriz de adjacencia (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int resposta = vertice_maior_grau(matriz, n);

    printf("Vertice com maior grau: %d\n", resposta);

    return 0;
}