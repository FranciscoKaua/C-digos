#ifndef FILA_H
#define FILA_H
#define MAX 10
#define TAM 50
typedef struct{
    char clientes[MAX][TAM];
    int inicio,fim,qtd;
}Fila;

void iniciar(Fila *f);
int cheio(Fila *f);
int vazio(Fila *f);
int inserir(Fila *f, char cliente[]);
int remover(Fila *f);
void imprimir(Fila *f);

#endif