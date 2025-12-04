#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF 1000000000
#define MAX_CIDADE 500
#define MAX_ARESTA 250000

typedef struct no {
    int destino;
    int peso;
    int prox;
} No;

// Vetores globais para armazenar o grafo
No lista_adj[MAX_ARESTA];
No lista_adj_inv[MAX_ARESTA];

int inicio[MAX_CIDADE + 1];
int inicio_inv[MAX_CIDADE + 1];

int total_arestas;
int total_arestas_inv;

// Pilha usada no Kosaraju
int pilha[MAX_CIDADE + 1];
int topo;

// Controle dos componentes fortemente conectados
int visitado[MAX_CIDADE + 1];
int componente[MAX_CIDADE + 1];
int qtd_componentes;

// Heap do Dijkstra (implementação manual)
typedef struct {
    int cidade;
    int dist;
} Nodo;

Nodo heap[200000];
int tam_heap;

// Distâncias para o Dijkstra
int distancia[MAX_CIDADE + 1];

// Funções de heap (fila de prioridade)

void trocar(Nodo *a, Nodo *b){
    Nodo tmp = *a;
    *a = *b;
    *b = tmp;
}

void inserir_heap(int cidade, int dist){
    heap[++tam_heap].cidade = cidade;
    heap[tam_heap].dist = dist;

    int i = tam_heap;
    while(i > 1 && heap[i].dist < heap[i/2].dist){
        trocar(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

Nodo remover_heap(){
    Nodo topo = heap[1];
    heap[1] = heap[tam_heap--];

    int i = 1;
    while(1){
        int esq = 2*i, dir = 2*i+1, menor = i;

        if(esq <= tam_heap && heap[esq].dist < heap[menor].dist)
            menor = esq;
        if(dir <= tam_heap && heap[dir].dist < heap[menor].dist)
            menor = dir;

        if(menor == i) break;

        trocar(&heap[i], &heap[menor]);
        i = menor;
    }

    return topo;
}

// Adição de arestas

void adicionar_aresta(int origem, int destino, int peso){
    lista_adj[total_arestas].destino = destino;
    lista_adj[total_arestas].peso = peso;
    lista_adj[total_arestas].prox = inicio[origem];
    inicio[origem] = total_arestas++;
}

void adicionar_aresta_inv(int origem, int destino){
    lista_adj_inv[total_arestas_inv].destino = destino;
    lista_adj_inv[total_arestas_inv].prox = inicio_inv[origem];
    inicio_inv[origem] = total_arestas_inv++;
}

// Kosaraju - primeira DFS

void dfs_ida(int cidade){
    visitado[cidade] = 1;

    for(int i = inicio[cidade]; i != -1; i = lista_adj[i].prox){
        int prox_cidade = lista_adj[i].destino;
        if(!visitado[prox_cidade]) dfs_ida(prox_cidade);
    }

    pilha[++topo] = cidade;
}

// Kosaraju - segunda DFS

void dfs_volta(int cidade){
    visitado[cidade] = 1;
    componente[cidade] = qtd_componentes;

    for(int i = inicio_inv[cidade]; i != -1; i = lista_adj_inv[i].prox){
        int prox_cidade = lista_adj_inv[i].destino;
        if(!visitado[prox_cidade]) dfs_volta(prox_cidade);
    }
}

// Dijkstra

int dijkstra(int origem, int destino){
    for(int i = 1; i <= MAX_CIDADE; i++)
        distancia[i] = INF;

    tam_heap = 0;
    distancia[origem] = 0;
    inserir_heap(origem, 0);

    while(tam_heap){
        Nodo atual = remover_heap();
        int cidade = atual.cidade;

        if(atual.dist > distancia[cidade]) continue;
        if(cidade == destino) return distancia[cidade];

        for(int i = inicio[cidade]; i != -1; i = lista_adj[i].prox){
            int prox = lista_adj[i].destino;
            int custo = lista_adj[i].peso;

            if(distancia[cidade] + custo < distancia[prox]){
                distancia[prox] = distancia[cidade] + custo;
                inserir_heap(prox, distancia[prox]);
            }
        }
    }

    return INF;
}

int main(){
    int qtd_cidades, qtd_acordos;

    while(scanf("%d %d", &qtd_cidades, &qtd_acordos) && (qtd_cidades || qtd_acordos)){

        for(int i = 1; i <= qtd_cidades; i++){
            inicio[i] = -1;
            inicio_inv[i] = -1;
        }

        total_arestas = 0;
        total_arestas_inv = 0;

        for(int i = 0; i < qtd_acordos; i++){
            int origem, destino, horas;
            scanf("%d %d %d", &origem, &destino, &horas);

            adicionar_aresta(origem, destino, horas);
            adicionar_aresta_inv(destino, origem);
        }

        memset(visitado, 0, sizeof(visitado));
        topo = 0;

        for(int i = 1; i <= qtd_cidades; i++)
            if(!visitado[i]) dfs_ida(i);

        memset(visitado, 0, sizeof(visitado));
        qtd_componentes = 0;

        for(int i = topo; i >= 1; i--){
            int cidade = pilha[i];
            if(!visitado[cidade]){
                ++qtd_componentes;
                dfs_volta(cidade);
            }
        }

        for(int u = 1; u <= qtd_cidades; u++){
            for(int i = inicio[u]; i != -1; i = lista_adj[i].prox){
                int v = lista_adj[i].destino;
                if(componente[u] == componente[v]){
                    lista_adj[i].peso = 0;
                }
            }
        }

        int qtd_consultas;
        scanf("%d", &qtd_consultas);

        while(qtd_consultas--){
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            int resposta = dijkstra(origem, destino);

            if(resposta >= INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", resposta);
        }

        printf("\n");
    }

    return 0;
}