#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nó da pilha
struct No {
    char valor;
    struct No* prox;  // aponta para o próximo nó
};

// Pilha
struct Pilha {
    int tamanho;
    struct No* topo;
};

// Inicializa a pilha
void iniciar_pilha(struct Pilha* pilha) {
    pilha->tamanho = 0;
    pilha->topo = NULL;
}

// Retorna 1 se a pilha estiver vazia
int vazia(struct Pilha* pilha) {
    return pilha->tamanho == 0;
}

// Adiciona no topo da pilha
void push(struct Pilha* pilha, char valor) {
    pilha->tamanho += 1;

    struct No* p = (struct No*) malloc(sizeof(struct No)); // ponteiro auxiliar
    p->valor = valor;
    p->prox = pilha->topo;  // aponta para o antigo topo
    pilha->topo = p;        // topo agora é p
}

// Remove o topo da pilha
void pop(struct Pilha* pilha) {
    if (pilha->tamanho > 0) {
        pilha->tamanho -= 1;

        struct No* p = pilha->topo;  // ponteiro auxiliar para o topo
        pilha->topo = pilha->topo->prox; // topo aponta para próximo
        free(p); // libera memória do antigo topo
    }
}

// Esvazia a pilha, liberando toda memória
void esvaziar_pilha(struct Pilha* pilha) {
    while (!vazia(pilha)) {
        pop(pilha);
    }
}

int main() {
    struct Pilha pilha;
    char string[1001];

    // lê expressões até o fim do arquivo
    while (scanf("%s\n", string) != EOF) {
        iniciar_pilha(&pilha);
        int tam = strlen(string);

        int i;
        for (i = 0; i < tam; ++i) {
            if (string[i] == '(') {
                push(&pilha, '(');
            } else if (string[i] == ')') {
                if (vazia(&pilha)) break;  // ')' sem '(' correspondente
                else pop(&pilha);
            }
        }

        if (i == tam && vazia(&pilha)) 
            printf("correct\n");
        else 
            printf("incorrect\n");

        esvaziar_pilha(&pilha);
    }

    return 0;
}
