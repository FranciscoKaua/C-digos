#include <stdio.h>
#include <string.h>
#include "Fila.h"

void iniciar(Fila *f){
    f->inicio = 0;
    f->fim = -1;
    f->qtd = 0;
}
int cheio(Fila*f){
    return (f->qtd == MAX);
}
int vazia(Fila *f){
    return (f->qtd == 0);
}
int inserir(Fila *f, char cliente[]){
    if(cheio(f)) return 0;
    f->fim = (f->fim + 1) % MAX;
    strcpy(f->clientes[f->fim], cliente);
    f->qtd++;
    return 1;
}
int remover(Fila *f){
    if(vazia(f)) return 0;
    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;
    return 1;
}
void imprimir(Fila *f){
    int pos = f->inicio;
    for(int i = 0; i < f->qtd; i++){
        printf("%s\n", f->clientes[pos]);
        pos = (pos + 1) % MAX;
    }
}