#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 1000000

int minimos[MAX_TAMANHO];

int main() {
    char operacao[5];   // Suporta até 4 letras + '\0'
    int quantidade, valor, minimo, topo;

    topo = -1;
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {

        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%d", &valor);

            if (topo == -1) {
                // Primeiro elemento, ele é o mínimo
                minimo = valor;
            } else {
                // Compara com o mínimo anterior
                if (valor < minimos[topo]) {
                    minimo = valor;
                } else {
                    minimo = minimos[topo];
                }
            }

            // Adiciona novo mínimo no topo
            topo++;
            minimos[topo] = minimo;
        }

        else if (strcmp(operacao, "POP") == 0) {
            if (topo == -1) {
                printf("EMPTY\n");
            } else {
                topo--;
            }
        }

        // Caso MIN: mostra o menor elemento atual
        else if (strcmp(operacao, "MIN") == 0) {
            if (topo == -1) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", minimos[topo]);
            }
        }
    }
    return 0;
}