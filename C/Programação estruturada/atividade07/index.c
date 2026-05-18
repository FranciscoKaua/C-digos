/*
//Letra A
#include <stdio.h>
int main(){
    int v[10], i;
    for (i = 1;i <= 10; i++) //Falta parênteses
        v[i] = 0;
}

//Letra B
#include <stdio.h>
int main(){
    int v[10], i;
    for (i = 0;i <= 10; i++) //Falta parênteses
        v[i] = 0;
    v[i] = 101;
}
//Letra C
#include <stdio.h>
int main(){
    int i = 5;
    int v[i];
    for (i = 0;i <= 5; i++) //Falta parênteses
        v[i] = 0;           //modifica o o tamanho do array
}
//Letra D
#include <stdio.h>
int main(){
    int v[], i; //array sem tamnho
    for (i = 0;i <= 10; i++) //Falta parênteses
        v[i] = 0;
    v[i] = 101; //acessa fora do limite   
}
//Letra E
#include <stdio.h>
int main(){
    int i;
    int v[3] = {10,20,30,40,50};// muitos valores para o tamanho do array
    for (i = 0;i <= 10; i++) //Falta parênteses
        v[i] = 0;           //loop até 10, sendo que o tamnho do array é 3
    v[i] = 101;
}
//Letra F
#include <stdio.h>
#define MAX 30; // não precisa de ponto e vírgula
int main(){
    int v[MAX];
    for (i = 0;i <= 10; i++) //Falta parênteses
        v[i] = 0;
    v[i] = 101; 
}   */