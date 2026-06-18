#include <stdio.h>
#include <string.h>
#include "Pilha.h"

void iniciar(Pilha *p){
    p->topo = -1;
}
int vazia(Pilha *p){
    return p->topo == -1;
}
int cheio(Pilha *p){
    return p->topo == MAX -1;
}
int inserir(Pilha *p, char livro[]){
    if(cheio(p)) return 0;
    p->topo++;
    strcpy(p->livros[p->topo], livro);
    return 1;
}
int remover(Pilha *p){
    if(vazia(p)) return 0;
    p->topo--;
    return 1;
}
void imprimir(Pilha *p){
    for(int i = p->topo; i >= 0; i--){
        printf("%s\n", p->livros[i]);
    }
}