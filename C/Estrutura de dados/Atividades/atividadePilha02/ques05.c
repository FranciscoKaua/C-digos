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
int maior(Fila *f){ 
    int i = f->inicio;
    int maior = f->dados[i];
    for(int cont = 0; cont<f->qtd; cont++){
        if(f->dados[i] > maior){
            maior = f->dados[i];
        }
        i = (i + 1)%MAX;
    }
    return maior;
}
int menor(Fila *f){
    int i = f->inicio;
    int menor = f->dados[i];
    for(int cont = 0; cont<f->qtd; cont++){
        if(f->dados[i] < menor){
            menor = f->dados[i];
        }
        i = (i + 1)%MAX;
    }
    return menor;
}
float media(Fila *f){
    int i = f->inicio;
    int soma = 0;
    for(int cont = 0; cont<f->qtd; cont++){
        soma = soma + f->dados[i];
        i = (i + 1)%MAX;
    }
    return (float)soma/f->qtd;
}

int main(){
	Fila F1;
	int valor;
	iniciar(&F1);
	
	inserir(&F1, 3);
	inserir(&F1, 2);
	inserir(&F1, 5);
	inserir(&F1, 1);
	
	printf("dados: \n");
	imprimir(&F1);
	printf("Maior: %d\n", maior(&F1));
	printf("Menor: %d\n", menor(&F1));
	printf("Media: %.2f\n", media(&F1));


	return 0;
}