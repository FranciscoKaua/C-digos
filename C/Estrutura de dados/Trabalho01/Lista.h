#ifndef LISTA_H
#define LISTA_H

#define MAX 10
#define TAM 50

typedef struct{
    char dados[MAX][TAM];
    int qtd;
}Lista;

void iniciar(Lista *l);
int cheio(Lista *l);
int vazio(Lista *l);
int adicionarFinal(Lista *l, char valor[]);
void exibir(Lista *l);
void menuSublista(char nome[]);

#endif