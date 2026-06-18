#ifndef PILHA_H
#define PILHA_H
#define MAX 10
#define TAM 50

typedef struct{
    char livros[MAX][TAM];
    int topo;
}Pilha;

void iniciar(Pilha *p);
int vazio(Pilha *p);
int cheio(Pilha *p);
int inserir(Pilha *p, char livro[]);
int remover(Pilha *p);
void imprimir(Pilha *p);

#endif