#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[10];
    struct Filho *primeiroFilho;
}Pessoa;

typedef struct Filho{
    Pessoa *pessoa;
    struct Filho *prox;
}Filho;

Pessoa *criarPessoa(char nome[]){
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
    strcpy(p->nome, nome);
    p->primeiroFilho = NULL;
    return p;
}
void adicionarFilho(Pessoa *pai, Pessoa *filho){
    Filho *novo = (Filho*)malloc(sizeof(Filho));
    novo->pessoa = filho;
    novo->prox = NULL;
    if(pai->primeiroFilho == NULL){
        pai->primeiroFilho = novo;
    }else{
        Filho *aux = pai->primeiroFilho;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox=novo;
    }
}
void imprimir(Pessoa *p, int nivel){
    if(p==NULL) return;
    for (int i = 0; i < nivel; i++){
        printf("  ");
    }
    printf("|-%s\n", p->nome);
    Filho *aux = p->primeiroFilho;
    while (aux != NULL){
        imprimir(aux->pessoa, nivel+1);
        aux=aux->prox;
    }
}
int main(){
    Pessoa *avo = criarPessoa("joao");
    Pessoa *pai = criarPessoa("lucas");
    Pessoa *tio = criarPessoa("pedro");
    Pessoa *filho1 = criarPessoa("joana");
    Pessoa *filho2 = criarPessoa("davi");

    adicionarFilho(avo, pai);
    adicionarFilho(avo, tio);
    adicionarFilho(pai, filho1);
    adicionarFilho(pai, filho2);

    imprimir(avo, 0);
}
