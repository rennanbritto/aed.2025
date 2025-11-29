#include <stdio.h>

int main() {
    int n, m;

    scanf("%d", &n);

    int fila[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &m);

    // Como os identificadores vão de 1 até até 100000, faz uma marcação
    static char saiu[100001] = {0};

    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        saiu[id] = 1;   // marca a saída
    }

    // Imprime todos que não saíram, na ordem original
    int primeiro = 1;
    for (int i = 0; i < n; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) printf(" ");
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");

    return 0;
}