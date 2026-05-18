#include <stdio.h>
#define MAX 10
typedef struct{
    int dados[MAX];
    int inicio;
    int fim;
    int std;
}Fila;

void iniciar(Fila*f){
    f->inicio = -1;
}