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
    f->fim = (f->fim +1) % MAX;
    f->qtd++;
    
    return 1;
}

int remover(Fila *f, int *valor){
    if(vazio(f)) return 0;
    
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio +1) % MAX;
    f->qtd--;
    
    return 1;
}
int primeiro(Fila *f, int *valor){
    if(vazio(f)) return 0;
    *valor = f->dados[f->inicio];
    
    return 1;
}
int imprimir(Fila *f){
    if(vazio(f)) return 0;
    int ini = f->inicio;
    for(int i = 0; i<f->qtd; i++){
        printf("%d\n", f->dados[ini]);
        ini = (ini + 1)%MAX;
    }
    return 1;
}
int main(){
	Fila F1;
	int valor;
	iniciar(&F1);
	
	inserir(&F1, 3);
	inserir(&F1, 2);
	inserir(&F1, 5);
	
	imprimir(&F1);
	remover(&F1, &valor);
	printf("removido: %d\n", valor);
	primeiro(&F1, &valor);
	printf("primeiro: %d\n", valor);
	imprimir(&F1);
	
	
	
	
	return 0;
}