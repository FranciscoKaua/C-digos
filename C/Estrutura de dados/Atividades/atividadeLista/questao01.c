#include <stdio.h>
#define MAX 100

typedef struct {
    int num[MAX];
    int n;
} Lista;

void inserir(Lista *l, int n1, int n2){
    for (int i = 0; i < l->n; i++){
        if(l->num[i] == n1){
            for (int a = l->n; a > i + 1;a--){
                l->num[a] = l->num[a-1];
            }
            
            l->num[i + 1] = n2;
            l->n++;    

            return;
        }
    }
    
}

void imprimir(Lista l){
    for (int i = 0; i < l.n; i++){
        printf("%d ", l.num[i]);
    }; 
    printf("\n"); 
}

int main(){
    Lista n = {{1,2,3}, 3};
    imprimir(n);

    inserir(&n,2,6);
    imprimir(n);
    return 0;
}