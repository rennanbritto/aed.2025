// ex 2.3.4 da página 9 (físico)
// faça função recursiva que dado um N, some seus digitos. 132 = 6

#include <stdio.h>
int soma_digitos(int n) {
    if (n == 0){ 
        return 0;
    }
    // pega o ultimo numero (n %10) e soma com os resultados anteriores
    return (n % 10) + soma_digitos(n / 10);
}

int main() {
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("A soma dos digitos e: %d\n", soma_digitos(n));

    return 0;
}
