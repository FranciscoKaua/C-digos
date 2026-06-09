#include <stdio.h>
#define MAX 5
typedef struct{
    int dados[MAX];
    int inicio;
    int fim;
    int qtd;
}Fila;
void iniciar(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}
int vazio(Fila *f){
    return (f->qtd == 0);
}
int cheio(Fila *f){
    return (f->qtd == MAX);
}
int inserir(Fila *f, int valor){
    if(cheio(f)) return 0;
    f->dados[f->fim] = valor;
    f->fim = (f->fim +1)%MAX;
    f->qtd++;
    return 1;
}
int remover(Fila *f, int *valor){
    if(vazio(f)) return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio+1)%MAX;
    f->qtd--;
    return 1;
}
int primeiro(Fila *f, int *valor){
    if(vazio(f)) return 0;
    *valor = f->dados[f->inicio];
    return 1;
}
int ultimo(Fila *f, int *valor){
    if(vazio(f)) return 0;
    int pos = (f->fim -1+MAX)%MAX;
    *valor = f->dados[pos];
    return 1;
}

int main(){
	Fila f;
	int valor;
	iniciar(&f);
	
	inserir(&f, 2);
	inserir(&f, 4);
	inserir(&f, 5);
	inserir(&f, 7);
	
	remover(&f,&valor);
	remover(&f,&valor);
	
	primeiro(&f, &valor);
	printf("primeiro: %d\n", valor);
	ultimo(&f, &valor);
	printf("último: %d\n", valor);
	printf("quantidade: %d\n", f.qtd);
	return 0;
}