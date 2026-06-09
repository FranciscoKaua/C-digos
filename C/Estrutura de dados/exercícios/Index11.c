#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int valor;
    struct No *prox;
}No;
typedef struct{
    No *inicio;
    int qtd;
}Lista;
void iniciar(Lista *l){
    l->inicio = NULL;
    l->qtd = 0;
}
No* criarNo(int valor){
    No*novo = (No*)malloc(sizeof(No));
    if(novo == NULL) return NULL;
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}
int inserirFinal(Lista *l, int valor){
    No *novo = criarNo(valor);
    No *aux;
    if(novo == NULL) return NULL;
    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        aux = l->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
    return 1;
}
int inserirInicio(Lista *l, int valor){
    No*novo = criarNo(valor);
    if(novo == NULL) return NULL;
    novo->prox = l->inicio;
    l->inicio = valor;
    l->qtd++;
    return 1;
}
No* buscar(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux!=NULL){
        if(aux->valor == valor) return aux;
        aux = aux->prox;
    }
    return NULL;
}
int remover(Lista *l, int valor){
    No *aux = l->inicio;
    No *ant = NULL;
    while(aux != NULL && aux->valor != valor){
        ant = aux;
        aux = aux->prox;
    }
    if(aux==NULL) return 0;
    if(ant==NULL){
        l->inicio = aux->prox;
    }else{
        ant->prox = aux->prox;
    }
    free(aux);
    l->qtd--;
    return 1;
}
void exibir(Lista *l){
    No *aux = l->inicio;
    while(aux != NULL){
        printf("%d ->", aux->valor);
        aux = aux->prox;
    }
}
int main(){
    Lista l;
    iniciar(&l);
    inserirFinal(&l, 7);
    inserirFinal(&l, 9);
    inserirFinal(&l, 2);
    inserirFinal(&l, 5);
    
    exibir(&l);
    return 0;
}