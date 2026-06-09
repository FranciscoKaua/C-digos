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
int Maior(Fila *f1, Fila *f2, int *valor) {
    int v1, v2;
    if (vazio(f1) && vazio(f2))
        return 0;
    if (vazio(f1)){
        remover(f2, valor);
        return 1;
    }
    if (vazio(f2)){
        remover(f1, valor);
        return 1;
    }
    
    primeiro(f1, &v1);
    primeiro(f2, &v2);

    if (v1 >= v2) {
        remover(f1, valor);
    }else{
        remover(f2, valor);
    }

    return 1;
}
int main() {
    Fila f1, f2;
    int valor;

    iniciar(&f1, 0, META-1);
    iniciar(&f2, META, MAX-1);

    inserir(&f1, 10);
    inserir(&f1, 20);
    inserir(&f2, 30);
    inserir(&f2, 40);

    int maior;
    Maior(&f1, &f2, &maior);
    printf("Maior removido: %d\n", maior);

    return 0;
}