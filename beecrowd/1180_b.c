// essa versão faz a troca de ponteiros

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int X[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    // ponteiro que aponta para o menor valor (inicia no primeiro elemento)
    int *p_menor = &X[0];

    // percorre o vetor com ponteiro
    for (int *p = X; p < X + N; p++) {
        if (*p < *p_menor) {
            p_menor = p; 
        }
    }

    // posição é a diferença entre ponteiros
    int posicao = p_menor - X;

    printf("Menor valor: %d\n", *p_menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
