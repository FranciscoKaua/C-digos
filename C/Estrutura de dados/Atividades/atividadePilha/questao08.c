#include <stdio.h>
#define MAX 10
#define META (MAX/2)
typedef struct{
    int inicio;
    int fim;
    int qtd;
    int limiteInferior;
    int limiteSuperior; 
}Fila;
int array[MAX];

void iniciar(Fila *f, int limiteInferior, int limiteSuperior){
    f->inicio = limiteInferior;
    f->fim = limiteInferior;
    f->qtd = 0;
    f->limiteInferior = limiteInferior;
    f->limiteSuperior = limiteSuperior; 
}
int vazio(Fila*f){
    return (f->qtd==0);
}
int cheio(Fila *f) {
    return (f->qtd == (f->limiteSuperior - f->limiteInferior + 1));
}
int inserir(Fila *f, int valor) {
    if (cheio(f)) return 0;
    array[f->fim] = valor;
    f->fim++;
    if (f->fim > f->limiteSuperior)
        f->fim = f->limiteInferior;
    f->qtd++;
    return 1;
}
int remover(Fila *f, int *valor) {
    if (vazio(f)) return 0;
    *valor = array[f->inicio];
    f->inicio++;
    if (f->inicio > f->limiteSuperior)
        f->inicio = f->limiteInferior;
    f->qtd--;
    return 1;
}

int primeiro(Fila *f, int *valor) {
    if (vazio(f)) return 0;
    *valor = array[f->inicio];
    return 1;
}
void separa(Fila *f, Fila *fPares, Fila *fImpares) {
    int valor;
    while (!vazio(f)) {
        remover(f, &valor);

        if (valor % 2 == 0) {
            inserir(fPares, valor);
        } else {
            inserir(fImpares, valor);
        }
    }
}

int main() {
    Fila f, F_Pares, F_Impares;

    iniciar(&f,0,3);
    iniciar(&F_Pares,4,6);
    iniciar(&F_Impares,7,8);
    
    inserir(&f,2);
    inserir(&f,3);
    inserir(&f,4);
    inserir(&f,5);
    
    separa(&f,&F_Pares,&F_Impares);

    return 0;
}