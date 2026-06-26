#include <stdio.h>
#include <stdlib.h>
#include "index.h"

int altura(No *n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

No* criarNo(int matricula) {
    No *novo = (No*) malloc(sizeof(No));
    novo->matricula = matricula;
    novo->altura = 1;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No* rotacaoDireita(No *y) {
    No *x = y->esquerda;
    No *t2 = x->direita;

    x->direita = y;
    y->esquerda = t2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

No* rotacaoEsquerda(No *x) {
    No *y = x->direita;
    No *t2 = y->esquerda;

    y->esquerda = x;
    x->direita = t2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

int fatorBalanceamento(No *n) {
    if (n == NULL)
        return 0;

    return altura(n->esquerda) - altura(n->direita);
}

No* inserir(No *raiz, int matricula) {

    if (raiz == NULL)
        return criarNo(matricula);

    if (matricula < raiz->matricula)
        raiz->esquerda = inserir(raiz->esquerda, matricula);

    else if (matricula > raiz->matricula)
        raiz->direita = inserir(raiz->direita, matricula);

    else
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    int fb = fatorBalanceamento(raiz);

    if (fb > 1 && matricula < raiz->esquerda->matricula)
        return rotacaoDireita(raiz);

    if (fb < -1 && matricula > raiz->direita->matricula)
        return rotacaoEsquerda(raiz);

    if (fb > 1 && matricula > raiz->esquerda->matricula) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (fb < -1 && matricula < raiz->direita->matricula) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}

No* buscar(No *raiz, int matricula) {
    if (raiz == NULL || raiz->matricula == matricula)
        return raiz;

    if (matricula < raiz->matricula)
        return buscar(raiz->esquerda, matricula);

    return buscar(raiz->direita, matricula);
}

void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->matricula);
        emOrdem(raiz->direita);
    }
}

void liberar(No *raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}