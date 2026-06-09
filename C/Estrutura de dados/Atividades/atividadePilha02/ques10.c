#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int valor;
    struct No *prox;
}No;

typedef struct{
    No *fim;
}Fila;
void iniciar(Fila *f){
    f->fim = NULL;
}
int vazio(Fila *f){
    return (f->fim == NULL);
}
int inserir(Fila *f, int valor){
    No *novo = (No*) malloc(sizeof(No));
    if(novo == NULL) return 0;
    novo->valor = valor;
    if(vazio(f)){
        novo->prox = novo;
        f->fim = novo;
    } else {
        novo->prox = f->fim->prox;
        f->fim->prox = novo;       
        f->fim = novo;             
    }

    return 1;
}
int remover(Fila *f, int *valor){
    if(vazio(f)) return 0;
    No *inicio = f->fim->prox;
    *valor = inicio->valor;
    if(inicio == f->fim){
        f->fim = NULL;
    } else {
        f->fim->prox = inicio->prox;
    }
    free(inicio);
    return 1;
}
int primeiro(Fila *f, int *valor){
    if(vazio(f)) return 0;
    *valor = f->fim->prox->valor;
    return 1;
}
void imprimir(Fila *f){
    if(vazio(f)){
        printf("Fila vazia\n");
        return;
    }
    No *aux = f->fim->prox;
    do{
        printf("%d\n", aux->valor);
        aux = aux->prox;
    } while(aux != f->fim->prox);
}
int main(){
    Fila f;
    iniciar(&f);

    inserir(&f, 6);
    inserir(&f, 2);
    inserir(&f, 1);
    inserir(&f, 5);

    printf("dados:\n");
    imprimir(&f);
    int v;
    remover(&f, &v);
    printf("\nRemovido: %d\n", v);
    printf("\nDepois:\n");
    imprimir(&f);

    return 0;
}