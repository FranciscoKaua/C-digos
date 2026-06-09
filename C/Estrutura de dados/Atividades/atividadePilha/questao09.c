#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void iniciar(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}
int vazio(Fila* f) {
    return (f->inicio == NULL);
}
void inserir(Fila* f, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (vazio(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }

    f->fim = novo;
}
int remover(Fila* f, int* valor) {
    if (vazio(f)) return 0;

    No* temp = f->inicio;
    *valor = temp->valor;

    f->inicio = temp->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
    return 1;
}
void intercalar(Fila* f1, Fila* f2, Fila* f3) {
    int v1, v2;

    while (!vazio(f1) && !vazio(f2)) {

        if (f1->inicio->valor <= f2->inicio->valor) {
            remover(f1, &v1);
            inserir(f3, v1);
        } else {
            remover(f2, &v2);
            inserir(f3, v2);
        }
    }
    while (!vazio(f1)) {
        remover(f1, &v1);
        inserir(f3, v1);
    }
    while (!vazio(f2)) {
        remover(f2, &v2);
        inserir(f3, v2);
    }
}
int main() {
    Fila f1, f2, f3;
    iniciar(&f1);
    iniciar(&f2);
    iniciar(&f3);

    inserir(&f1, 1);
    inserir(&f1, 3);
    inserir(&f1, 5);

    inserir(&f2, 2);
    inserir(&f2, 4);
    inserir(&f2, 6);

    intercalar(&f1, &f2, &f3);

    int valor;
    while (!vazio(&f3)) {
        remover(&f3, &valor);
        printf("%d ", valor);
    }

    return 0;
}