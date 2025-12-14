#include <stdio.h>

typedef struct no {
    int valor;
    struct no *filho;  
    struct no *irmao;   
} no;

int contar_nivel(no *raiz, int nivel) {
    if (raiz == NULL)
        return 0;

    if (nivel == 0)
        return 1;

    int soma = 0;
    no *p = raiz->filho;

    while (p != NULL) {
        soma += contar_nivel(p, nivel - 1);
        p = p->irmao;
    }

    return soma;
}