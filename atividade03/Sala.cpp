#include <iostream>
#include "Sala.hpp"

using namespace std;

Sala::Sala(string nome, int quantAssentos):nome(nome){
    for(int i = 1; i <= quantAssentos; i++){
        assentos.push_back(Assento(i));
    }
}

void Sala::reservar(int numAssento){
    Assento &a = assentos[numAssento - 1];
    a.reservar();
    cout<<"Assento "<<numAssento<<" reservado\n";
}

void Sala::cancelar(int numAssento){
    Assento &a = assentos[numAssento - 1];
    a.liberar();
    cout<<"Assento "<<numAssento<<" cancelado\n";
}

void Sala::exibirMapa() const{
  cout << "Mapa da sala:\n";
    for (const Assento &a : assentos) {
        if (a.estaReservado()) {
            cout << "[X] ";
        } else {
            cout << "[" << a.getNumero() << "] ";
        }
    }
    cout << "\n";
}

void Sala::consultar() const{
    int livre = 0;
    for(const Assento &a : assentos){
        if(!a.estaReservado()){
            livre++;
        }
    }
    cout<<"Disponível: "<<livre <<"\n";
}
clang++ main.cpp Assento.cpp Sala.cpp -o