#include <stdio.h>
#define MAX 10
typedef struct {
    int dados[MAX];
    int topo;
}Pilha;

void iniciar(Pilha*p){
    p->topo = -1;
}
int vazio(Pilha*p){
    return(p->topo == -1);
}
int cheio(Pilha*p){
    return(p->topo == MAX-1);
}
int push(Pilha*p, int valor){
    if(cheio(p)){
        return 0;
    }
    p->topo++;
    p->dados[p->topo] = valor;
    return 1;
}
int pop(Pilha*p, int *valor){
    if(vazio(p)){
        return 0;
    }
    *valor = p->dados[p->topo];
    p->topo--;
    return 1;
}
int topo(Pilha*p, int *valor){
    if(vazio(p)){
        return 0;
    }
    *valor = p->dados[p->topo];
    return 1;
}
int imprimir(Pilha*p){
    if(vazio(p)){
        return 0;
    }
    printf("Pilha:\n");
    for (int i = p->topo; i >= 0; i--){
        printf("%d\n", p->dados[i]);
    }
    return 1;
}
int quantidade(Pilha*p){
    int cont = 0;
    for(int i = 0; i <= p->topo; i++){
        cont ++;
    }
    return cont;
}

int main(){
    Pilha p;
    int valor;
    iniciar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    push(&p, 40);
    push(&p, 50);

    imprimir(&p);
    printf("Quantidade: %d\n", quantidade(&p));

    pop(&p, &valor);
    printf("Valor removido: %d\n", valor);
    pop(&p, &valor);
    printf("Valor removido: %d\n", valor);

    if (topo(&p, &valor)){
        printf("Topo: %d\n", valor);
    }
    
    imprimir(&p);
    printf("Quantidade: %d\n", quantidade(&p));
    
    return 0;
}