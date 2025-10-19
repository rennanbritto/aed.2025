#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *vetor, int n) {
    int i, j, chave;
    // Percorre o vetor a partir do segundo elemento
    for (i = 1; i < n; i++) {
        chave = vetor[i];   // elemento atual a ser inserido na posição correta
        j = i - 1;
        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        // Insere a chave na posição correta
        vetor[j + 1] = chave;
    }
}

int main() {
    int nc;
    scanf("%d", &nc);

    while (nc--) {
        int n; 
        scanf("%d", &n);

        int *alturas = (int *) malloc(n * sizeof(int));
        // Leitura das alturas
        for (int i = 0; i < n; i++) {
            scanf("%d", &alturas[i]);
        }
        insertion_sort(alturas, n);

        // Imprime as alturas ordenadas
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}
