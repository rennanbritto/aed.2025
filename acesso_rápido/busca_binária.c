int busca_binaria_recursiva(int vetor[], int inicio, int fim, int valor) {
    if (inicio > fim)
        return -1; // não encontrado

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == valor)
        return meio; // achou!

    if (vetor[meio] < valor)
        return busca_binaria_recursiva(vetor, meio + 1, fim, valor);
    else
        return busca_binaria_recursiva(vetor, inicio, meio - 1, valor);
}