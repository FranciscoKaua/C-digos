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
    int i = f->inicio;
    for(int cont = 0; cont<f->qtd; cont++){
        printf("%d\n", f->dados[i]);
        i = (i + 1)%MAX;
    }
    return 1;
}
Fila juntar(Fila *F1, Fila *F2){
    Fila F3;
    iniciar(&F3);
    int i;
    int valor;
    i = F1->inicio;
    for(int cont = 0; cont < F1->qtd; cont++){
        valor = F1->dados[i];
        inserir(&F3, valor);
        i = (i + 1) % MAX;
    }
    i = F2->inicio;
    for(int cont = 0; cont < F2->qtd; cont++){
        valor = F2->dados[i];
        inserir(&F3, valor);
        i = (i + 1) % MAX;
    }
    return F3;
}

int main(){
	Fila F1;
	Fila F2;
	int valor;
	iniciar(&F2);
	iniciar(&F1);

	inserir(&F1, 1);
	inserir(&F1, 2);
	inserir(&F1, 3);
	
	inserir(&F2, 4);
	inserir(&F2, 5);
	
	
	printf("dados: \n");
	imprimir(&F1);
	printf("Depois: \n");
	Fila F3 = juntar(&F1, &F2);
	imprimir(&F3);
	


	return 0;
}