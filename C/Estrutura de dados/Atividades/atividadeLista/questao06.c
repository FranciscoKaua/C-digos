#include <stdio.h>
#define MAX 100

typedef struct{
    int num[MAX];
    int n;
} Lista;

void remover(Lista *l, int quant){
    for (int i = 0; i < l->n - quant; i++){
        l->num[i] = l->num[i + quant];    
    }
    l->n -= quant;
}

void imprimir(Lista l){
    for (int i = 0; i < l.n; i++){
        printf("%d ", l.num[i]);
    }; 
    printf("\n"); 
}

int main(){
    Lista n = {{1,2,3,4,5,6,7}, 7};
    imprimir(n);

    remover(&n, 2);
    imprimir(n);

    return 0;
}