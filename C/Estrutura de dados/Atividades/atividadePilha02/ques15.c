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
void inverter(Fila *f){
    int aux[MAX];
    int i = 0;
    int valor;
    while(!vazio(f)){
        remover(f, &valor);
        aux[i++] = valor;
    }
    for(int j = i - 1; j >= 0; j--){
        inserir(f, aux[j]);
    }
}
int main(){
	Fila F1;
	int valor;
	iniciar(&F1);

	inserir(&F1, 6);
	inserir(&F1, 2);
	inserir(&F1, 1);
	inserir(&F1, 5);
	inserir(&F1, 5);
	
	printf("dados: \n");
	imprimir(&F1);
	printf("depois: ");
	inverter(&F1);
	imprimir(&F1);
	
	return 0;
}
