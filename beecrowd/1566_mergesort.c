#include <stdio.h>
#include <stdlib.h>

void intercala(int *vetor, int inicio, int meio, int fim) {
    int i = inicio;       // subvetor da esquerda
    int j = meio + 1;     // subvetor da direita
    int k = 0;            // vetor temporário

    int tamanho = fim - inicio + 1;
    int *temp = (int *) malloc(tamanho * sizeof(int));

    // Precisa ter elementos nos dois lados
    while (i <= meio && j <= fim) {
        if (vetor[i] <= vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    // Copia o restante do lado esquerdo (se houver)
    while (i <= meio) {
        temp[k++] = vetor[i++];
    }

    // Copia o restante do lado direito (se houver)
    while (j <= fim) {
        temp[k++] = vetor[j++];
    }

    // Copia o vetor temporário de volta ao vetor original
    for (i = 0; i < tamanho; i++) {
        vetor[inicio + i] = temp[i];
    }
    free(temp);
}

// Função principal para o Mergesort
void merge_sort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        // Intercala as duas metades ordenadas
        intercala(vetor, inicio, meio, fim);
    }
}

int main() {
    int nc;
    scanf("%d", &nc);
  
    while (nc--) {
        int n;
        scanf("%d", &n);

        int *alturas = (int *) malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &alturas[i]);
        }
      
        merge_sort(alturas, 0, n - 1);

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
