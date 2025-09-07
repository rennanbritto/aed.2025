#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int X[N];

    // lê o primeiro número e inicializa
    scanf("%d", &X[0]);
    int menor = X[0];
    int posicao = 0;

    for (int i = 1; i < N; i++) {
        scanf("%d", &X[i]);
        if (X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
