#include <stdio.h>
typedef struct{
    int numerador;
    int denominador;
    
}Racional;

Racional criaRacional(int n, int d){
    Racional r1;
    r1.numerador = n;
    r1.denominador = d;
    
    return r1;
}

Racional somaRacional(Racional a, Racional b){
    Racional soma;
    
    soma.numerador = a.numerador * b.denominador + b.numerador*a.denominador;
    soma.denominador = a.denominador * b.denominador;
    
    return soma;
    
}

Racional multiRacional(Racional a, Racional b){
    Racional mult;
    mult.numerador = a.numerador * b.numerador;
    mult.denominador = a.denominador*b.denominador;
    
    return mult;
}

int main() {
    
    Racional novoRacional = criaRacional(1,2);
    Racional novoRacional2 = criaRacional(2,3);
    
    Racional soma = somaRacional(novoRacional, novoRacional2);
    Racional mult = multiRacional(novoRacional, novoRacional2);
    
    printf("%d/%d + %d/%d = %d/%d\n", novoRacional.numerador, novoRacional.denominador, novoRacional2.numerador,novoRacional2.denominador,soma.numerador,soma.denominador);
    printf("%d/%d * %d/%d = %d/%d", novoRacional.numerador, novoRacional.denominador, novoRacional2.numerador,novoRacional2.denominador,mult.numerador,mult.denominador);
    
    return 0;
}