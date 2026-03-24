#include <iostream>
using namespace std;
struct Racional{
    int numerador;
    int denominador;
};

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

int main() {
    Racional r1 = criaRacional(2,4);
    Racional r2 = criaRacional(1,3);
    
    Racional resultadoSoma = soma(r1,r2);
    Racional resultadoSub = subtracao(r1,r2);
    Racional resultadoDivi = divisao(r1,r2);
    
    cout<<"Soma: "<< resultadoSoma.numerador <<"/" << resultadoSoma.denominador << "\n";
    cout<<"Subtração: "<<resultadoSub.numerador <<"/" <<resultadoSub.denominador << "\n";
    cout<<"Divisão: "<<resultadoDivi.numerador <<"/" <<resultadoDivi.denominador;
    
    return 0;
}