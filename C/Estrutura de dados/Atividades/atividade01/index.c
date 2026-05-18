#include <stdio.h>
typedef struct {
    int numerador;
    int denominador;
} Racional;

Racional criaRacional(int n, int d){
    Racional r;
    r.numerador = n;
    r.denominador = d;
    return r;
}

Racional soma(Racional a, Racional b){
    Racional r;

    r.numerador = (a.numerador * b.denominador) +
                  (b.numerador * a.denominador);
    r.denominador = a.denominador * b.denominador;

    return r;
}

Racional subtracao(Racional a, Racional b){
    Racional r;

    r.numerador = (a.numerador * b.denominador) -
                  (b.numerador * a.denominador);
    r.denominador = a.denominador * b.denominador;

    return r;
}

Racional multiplicacao(Racional a, Racional b){
    Racional r;

    r.numerador = a.numerador * b.numerador;
    r.denominador = a.denominador * b.denominador;

    return r;
}

Racional divisao(Racional a, Racional b){
    Racional r;

    r.numerador = a.numerador * b.denominador;
    r.denominador = a.denominador * b.numerador;

    return r;
}

int mdc(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    
    return a;
}

Racional simplificar(Racional r) {
    
    int divisor = mdc(r.numerador, r.denominador);

    r.numerador = r.numerador / divisor;
    r.denominador = r.denominador / divisor;

    return r;
}

int main() {
    Racional r1 = criaRacional(2,4);
    Racional r2 = criaRacional(1,3);
    
    Racional resultadoSoma = simplificar(soma(r1,r2));
    Racional resultadoSub = simplificar(subtracao(r1,r2));
    Racional resultadoDivi = simplificar(divisao(r1,r2));
    
    printf("Soma: %d/%d\n", resultadoSoma.numerador, resultadoSoma.denominador);
    printf("Subtração: %d/%d\n", resultadoSub.numerador, resultadoSub.denominador);
    printf("Divisão: %d/%d\n", resultadoDivi.numerador, resultadoDivi.denominador);

    return 0;
}