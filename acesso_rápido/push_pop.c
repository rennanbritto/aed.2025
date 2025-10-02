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
