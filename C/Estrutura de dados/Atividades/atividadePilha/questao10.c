#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* iniciar() {
    return NULL;
}
int vazio(No* fila) {
    return (fila == NULL);
}
No* inserir(No* fila, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (fila == NULL) {
        return novo;  
    }

    No* aux = fila;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return fila; 
}
No* remover(No* fila, int* valor) {
    if (fila == NULL) return NULL;
    No* temp = fila;
    *valor = temp->valor;
    fila = temp->prox;  
    free(temp);         
    return fila;        
}
int primeiro(No* fila, int* valor) {
    if (fila == NULL) return 0;
    *valor = fila->valor;
    return 1;
}
int main() {
    No* fila = iniciar();
    int valor;

    fila = inserir(fila, 10);
    fila = inserir(fila, 20);
    fila = inserir(fila, 30);

    while (!vazio(fila)) {
        fila = remover(fila, &valor);
        printf("%d ", valor);
    }

    return 0;
}