#include <stdio.h>
#define MAX 10
typedef struct{
  int dados[MAX];
  int qtd;
}Lista;
void iniciar(Lista *l){
  l->qtd = 0;
}
int cheio(Lista *l){
  return (l->qtd == MAX);
}
int vazio(Lista *l){
  return (l->qtd == 0);
}
int inserirFinal(Lista *l, int valor){
  if(cheio(l)) return 0;
  l->dados[l->qtd] = valor;
  l->qtd++;
  return 1;
}
int inserirPosicao(Lista *l, int valor, int pos){
  if(cheio(l)) return 0;
  if(pos < 0 || pos > l->qtd) return 0;
  for(int i = l->qtd; i>pos; i--){
      l->dados[i] = l->dados[i-1];
  }
  l->dados[pos] = valor;
  l->qtd++;
  return 1;
}
int buscar(Lista *l, int valor){
    for(int i = 0; i < l->qtd; i++){
        if(l->dados[i]==valor){
            return i;
        }
    }
    return -1;
}
int remover(Lista *l, int valor){
    int pos;
    pos = buscar(l, valor);
    if(pos == -1) return 0;
    for(int i = pos; i< l->qtd; i++){
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;
}
void exibir(Lista *l){
    if(vazio(l)) return;
    for(int i=0;i<l->qtd;i++){
        printf("%d\n", l->dados[i]);
    }
    
}

int main(){
    Lista l;
    iniciar(&l);
    inserirFinal(&l, 10);
    inserirFinal(&l, 50);
    inserirFinal(&l, 80);
    inserirFinal(&l, 30);
    
    inserirPosicao(&l, 4, 1);
    exibir(&l);
	
	return 0;
}