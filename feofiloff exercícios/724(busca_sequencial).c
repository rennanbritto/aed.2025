// ex. 724: escreva a versão recurisva da função BuscaSequencial

int busca_sequencial_recursiva(int vetor[], int tamanho, int valor, int indice) {
    if (indice == tamanho){
        return -1;
    }
    if (vetor[indice] == valor){
        return indice;
    }
    return busca_sequencial_recursiva(vetor, tamanho, valor, indice + 1);
}