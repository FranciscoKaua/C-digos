#ifndef INDEX_H
#define INDEX_H

typedef struct No {
    int matricula;
    int altura;
    struct No *esquerda;
    struct No *direita;
} No;

int altura(No *n);
int max(int a, int b);

No* criarNo(int matricula);
No* rotacaoDireita(No *y);
No* rotacaoEsquerda(No *x);

int fatorBalanceamento(No *n);

No* inserir(No *raiz, int matricula);
No* buscar(No *raiz, int matricula);

void emOrdem(No *raiz);
void liberar(No *raiz);

#endif