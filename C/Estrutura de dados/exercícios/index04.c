#include <stdio.h>
#define MAX 10
typedef struct{
    int dados[MAX];
    int topo;
}Pilha;

void iniciar(Pilha*p){
    p->topo = -1;
}

int vazia(Pilha*p){
    return (p->topo == -1);
}

int cheia(Pilha*p){
    return (p->topo == MAX -1);
}

int push(Pilha*p, int valor){
    if(cheia(p)){
        return 0;
    }
    p->topo++;
    p->dados[p->topo] = valor;
    return 1;
}

int pop(Pilha*p, int *valor){
    if(vazia(p)){
        return 0;
    }
    *valor = p->dados[p->topo];
    p->topo--;
    return 1;
}

int topo(Pilha*p, int *valor){
    if(vazia(p)){
        return 0;
    }
    *valor = p->dados[p->topo];
    return 1;
}


int main(){
    Pilha p;
    int valor;

    iniciar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    pop(&p, &valor);
    printf("remvoido: %d", valor);
    return 0;
}