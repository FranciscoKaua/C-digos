#include <stdio.h>
#define MAX 100
typedef struct{
    int num[MAX];
    int n;
} Lista;

void trocar(Lista *l, int p1, int p2){
    int n1 = p1 - 1;
    int n2 = p2 - 1;

    int troca = l->num[n1];
    l->num[n1] = l->num[n2];
    l->num[n2] = troca;
    
}

void imprimir(Lista l){
    for (int i = 0; i < l.n; i++){
        printf("%d ", l.num[i]);
    }; 
    printf("\n"); 
}

int main(){
    Lista n = {{11,20,32,45,50}, 5};
    imprimir(n);

    trocar(&n,3,1);
    imprimir(n);
    return 0;
}