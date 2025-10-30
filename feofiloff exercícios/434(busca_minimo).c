typedef struct no {
    int info;
    struct no *prox;
}no;

int *busca_minimo(no *lista){
    if(lista == NULL) return -1;
    
    int menor = lista -> info;
    no * auxiliar = lista->prox;

    while (auxiliar != NULL){
        if(auxiliar->info < menor){
            menor = auxiliar -> info;
        }
        auxiliar = auxiliar->prox;
    }
    return menor;
    }

