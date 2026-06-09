#include <stdio.h>
#include <string.h>
#include "lista.h"

void iniciar(Lista *l){
    l->qtd = 0;
}

int cheio(Lista *l){
    return (l->qtd == MAX);
}

int vazio(Lista *l){
    return (l->qtd == 0);
}

int adicionarFinal(Lista *l, char valor[]){
    if(cheio(l)) return 0;
    strcpy(l->dados[l->qtd], valor);
    l->qtd++;
    return 1;
}

void exibir(Lista *l){
    if(vazio(l))return;
    printf("\n--------------\n");
    for(int i = 0; i < l->qtd; i++){
        printf("%d - %s\n", i + 1, l->dados[i]);
    }
}

void menuSublista(char nome[]){
    printf("\n--------------\n");
    printf("1-Adicionar na lista de %s\n", nome);
    printf("2-Mostrar lista de %s\n", nome);
    printf("Opção: ");
}