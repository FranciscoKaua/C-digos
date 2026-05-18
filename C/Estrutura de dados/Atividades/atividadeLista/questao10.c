#include <stdio.h>
#define MAX 100
typedef struct{
    int num[MAX];
    int n;
} Lista;

void trocar(Lista *l){
    int ultimo = l->num[l->n - 1];
    
    for(int i = l->n-1; i > 0; i--){
        l->num[i] = l->num[i -1];
    }
    
    l->num[0] = ultimo;
}

void imprimir(Lista l){
    for (int i = 0; i < l.n; i++){
        printf("%d ", l.num[i]);
    }; 
    printf("\n"); 
}

int main(){
    Lista n ={{2, 10, 5, 8}, 4};
    imprimir(n);
    
    trocar(&n);
    imprimir(n);

    return 0;
}