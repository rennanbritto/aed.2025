#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000
#define MAX_STR 1000005

// Vetor de ponteiros para strings
char *joias[MAX_STR];

// Função para ordenar as strings (qsort usa strcmp)
int compara(const void *a, const void *b) {
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;
    return strcmp(s1, s2);
}

int main() {
    char buffer[1000005]; // Temporario
    int total = 0;

    while (scanf("%s", buffer) == 1) {

        // Alocando memória para guardar a joia
        int tam = strlen(buffer);
        joias[total] = (char *)malloc((tam + 1) * sizeof(char));
        strcpy(joias[total], buffer);

        total++;
    }

    // Ordena todas as strings
    qsort(joias, total, sizeof(char *), compara);

    int distintos = 0;

    for (int i = 0; i < total; i++) {
        // Primeiro sempre é distinto
        if (i == 0) {
            distintos++;
        }
        // Se essa string é diferente da anterior, conta mais 1
        else if (strcmp(joias[i], joias[i - 1]) != 0) {
            distintos++;
        }
    }

    printf("%d\n", distintos);
    return 0;
}
