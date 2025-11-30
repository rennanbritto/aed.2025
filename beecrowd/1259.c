#include <stdio.h>
#include <stdlib.h>

/*
    Função de comparação usada pelo qsort.
   Reusmo:
    1) Todos os números PAR vêm primeiro.
    2) Entre os pares: ordem CRESCENTE.
    3) Depois os ÍMPARES.
    4) Entre os ímpares: ordem DECRESCENTE.
*/
int comparar(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;

    int A_par = (A % 2 == 0);
    int B_par = (B % 2 == 0);

    // Caso 1: os dois são pares -> ordem crescente
    if (A_par && B_par)
        return A - B;

    // Caso 2: A é par e B é ímpar -> A vem antes
    if (A_par && !B_par)
        return -1;

    // Caso 3: A é ímpar e B é par -> B vem antes
    if (!A_par && B_par)
        return 1;

    // Caso 4: os dois são ímpares -> ordem decrescente
    return B - A;
}

int main()
{
    int quantidade;
    int lista[100000];

    // qtdd de números
    scanf("%d", &quantidade);

    // Lê cada número da entrada
    for (int i = 0; i < quantidade; i++)
    {
        scanf("%d", &lista[i]);
    }

    // Ordena seguindo a função "comparar"
    qsort(lista, quantidade, sizeof(int), comparar);

    // Imprime o resultado
    for (int i = 0; i < quantidade; i++)
    {
        printf("%d\n", lista[i]);
    }

    return 0;
}
