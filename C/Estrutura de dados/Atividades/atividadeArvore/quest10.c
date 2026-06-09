#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{
    int valor;
    struct Nodo *esquerdo;
    struct Nodo *direito;
}Nodo;

Nodo* criarNodo(int valor) {
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

Nodo* removerFolha(Nodo *raiz, int valor) {
    if (raiz == NULL) return NULL;
    raiz->esquerdo = removerFolha(raiz->esquerdo, valor);
    raiz->direito = removerFolha(raiz->direito, valor);
    if (raiz->valor == valor &&
        raiz->esquerdo == NULL &&
        raiz->direito == NULL) {
        free(raiz);
        return NULL;
    }
    return raiz;
}
void preOrdem(Nodo *raiz) {
    if (raiz == NULL) return;

    printf("%d ", raiz->valor);
    preOrdem(raiz->esquerdo);
    preOrdem(raiz->direito);
}
int main() {
    Nodo *raiz = criarNodo(10);
    raiz->esquerdo = criarNodo(5);
    raiz->direito = criarNodo(20);

    raiz->esquerdo->esquerdo = criarNodo(3);
    raiz->esquerdo->direito = criarNodo(7);

    printf("Antes:\n");
    preOrdem(raiz);
    printf("\n");

    raiz = removerFolha(raiz, 3);

    printf("Depois:\n");
    preOrdem(raiz);
    printf("\n");

    return 0;
}