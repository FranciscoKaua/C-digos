#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* inserirFila(No* fila, int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (fila == NULL)
        return novo;

    No* aux = fila;

    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = novo;

    return fila;
}

No* removerFila(No* fila, int* valor) {
    if (fila == NULL)
        return NULL;

    No* temp = fila;
    *valor = temp->valor;

    fila = fila->prox;

    free(temp);

    return fila;
}

No* push(No* pilha, int valor) {
    No* novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = pilha;

    return novo;
}

No* pop(No* pilha, int* valor) {
    if (pilha == NULL)
        return NULL;

    No* temp = pilha;

    *valor = temp->valor;

    pilha = pilha->prox;

    free(temp);

    return pilha;
}
No* reverso(No* fila) {
    No* pilha = NULL;
    int valor;

    while (fila != NULL) {
        fila = removerFila(fila, &valor);
        pilha = push(pilha, valor);
    }

    while (pilha != NULL) {
        pilha = pop(pilha, &valor);
        fila = inserirFila(fila, valor);
    }

    return fila;
}
int main() {
    No* fila = NULL;

    fila = inserirFila(fila, 10);
    fila = inserirFila(fila, 20);
    fila = inserirFila(fila, 30);

    fila = reverso(fila);

    int valor;

    while (fila != NULL) {
        fila = removerFila(fila, &valor);
        printf("%d ", valor);
    }

    return 0;
}