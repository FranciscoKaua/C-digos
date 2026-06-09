#include <stdio.h>
#define MAX 5
typedef struct{
    int dados[MAX];
    int inicio,fim,qtd;
}Fila;
void iniciar(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}
int cheio(Fila*f){
    return (f->qtd == MAX);
}
int vazio(Fila *f){
    return (f->qtd == 0);
}
int inserir(Fila *f, int valor){
    if(cheio(f)) return 0;
    f->dados[f->fim] = valor;
    f->fim = (f->fim+1)%MAX;
    f->qtd++;
    return 1;
}
int remover(Fila *f, int *valor){
    if (vazio(f)) return 0;
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
int pares(Fila*f){
    if (vazio(f)) return 0;
    int i = f->inicio;
    int par = 0;
    for(int cont = 0; cont < f->qtd; cont++){
        if (f->dados[i]%2==0){
            par ++;
        }
        i=(i+1)%MAX;
    }
    return par;
}
int copiar(Fila *origem, Fila *destino){
    if (vazio(origem)) return 0;
    int i = origem->inicio;
    for(int cont = 0; cont < origem->qtd; cont++){
        if(cheio(destino)) return 0;
        inserir(destino, origem->dados[i]);
        i=(i+1)%MAX;
    }
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
    Fila f;
    Fila f2;
    int valor;
    iniciar(&f);
    iniciar(&f2);
    inserir(&f, 2);
    inserir(&f, 5);
    inserir(&f, 6);
    inserir(&f, 9);
    inserir(&f, 4);

    remover(&f,&valor);
    printf("Valor removido: %d\n", valor);
    primeiro(&f,&valor);
    printf("Valor 1: %d\n", valor);
    printf("Pares: %d\n", pares(&f));
    copiar(&f, &f2);
    imprimir(&f2);
    return 0;
}