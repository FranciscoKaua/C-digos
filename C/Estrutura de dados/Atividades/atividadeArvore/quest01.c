#include <stdio.h>
#include <stdlib.h>
typedef struct Filho {
    struct No *filho;
    struct Filho *prox;
} Filho;

typedef struct No {
    int valor;
    Filho *primeiroFilho;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->primeiroFilho = NULL;

    return novo;
}
void adicionarFilho(No *pai, No *filho) {
    Filho *novoFilho = (Filho*) malloc(sizeof(Filho));
    novoFilho->filho = filho;
    novoFilho->prox = NULL;
    if (pai->primeiroFilho == NULL) {
        pai->primeiroFilho = novoFilho;
    } else {
        Filho *aux = pai->primeiroFilho;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novoFilho;
    }
}
No* copiarArvore(No *raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    No *novaRaiz = criarNo(raiz->valor);
    Filho *aux = raiz->primeiroFilho;
    while (aux != NULL) {
        No *filhoCopiado = copiarArvore(aux->filho);
        adicionarFilho(novaRaiz, filhoCopiado);
        aux = aux->prox;
    }
    return novaRaiz;
}
int main() {

    No *raiz = criarNo(1);

    No *n2 = criarNo(2);
    No *n3 = criarNo(3);
    No *n4 = criarNo(4);

    adicionarFilho(raiz, n2);
    adicionarFilho(raiz, n3);
    adicionarFilho(n2, n4);

    No *copia = copiarArvore(raiz);
    return 0;
}