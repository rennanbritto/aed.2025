#include <stdio.h>

#define TAM_MATRIZ 9

// Função para verificar se uma linha/coluna/matriz contém números de 1 a 9 sem repetição
int verificarRepeticao(int arr[]) {
    int visitados[TAM_MATRIZ + 1] = {0};
    for (int i = 0; i < TAM_MATRIZ; i++) {
        if (arr[i] < 1 || arr[i] > 9 || visitados[arr[i]] == 1)
            return 0; // Se tiver repetição ou número inválido, retorna falso
        visitados[arr[i]] = 1; // Define o atual como visitado
    }
    return 1; // Se não tiver repetição, retorna verdadeiro
}

// Função para verificar se uma matriz é uma solução válida para o Sudoku
int validarSudoku(int grade[TAM_MATRIZ][TAM_MATRIZ]) {
    // Verifica linhas
    for (int i = 0; i < TAM_MATRIZ; i++) {
        if (!verificarRepeticao(grade[i]))
            return 0; // Se tiver repetição em algu,a linha, retorna falso
    }

    // Verifica as colunas
    for (int j = 0; j < TAM_MATRIZ; j++) {
        int coluna[TAM_MATRIZ];
        for (int i = 0; i < TAM_MATRIZ; i++)
            coluna[i] = grade[i][j];
        if (!verificarRepeticao(coluna))
            return 0; // Se tiver repetição em alguma coluna, retorna falso
    }

    // Verifica matrizes 3x3
    for (int blocoLinha = 0; blocoLinha < 3; blocoLinha++) {
        for (int blocoColuna = 0; blocoColuna < 3; blocoColuna++) {
            int bloco[TAM_MATRIZ];
            int indice = 0;
            for (int i = blocoLinha * 3; i < blocoLinha * 3 + 3; i++) {
                for (int j = blocoColuna * 3; j < blocoColuna * 3 + 3; j++) {
                    bloco[indice++] = grade[i][j];
                }
            }
            if (!verificarRepeticao(bloco))
                return 0; // Se tiber repetição em algum bloco, retorna falso
        }
    }

    return 1; // Sucesso total = retorna verdadeoro
}

int main() {
    int numInstancias;
    scanf("%d", &numInstancias);

    for (int inst = 1; inst <= numInstancias; inst++) {
        int grade[TAM_MATRIZ][TAM_MATRIZ];
        for (int i = 0; i < TAM_MATRIZ; i++) {
            for (int j = 0; j < TAM_MATRIZ; j++) {
                scanf("%d", &grade[i][j]);
            }
        }

        printf("Instancia %d\n", inst);
        if (validarSudoku(grade))
            printf("SIM\n");
        else
            printf("NAO\n");
        printf("\n");
    }

    return 0;
}
