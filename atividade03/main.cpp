#include <iostream>
#include "Sala.hpp"
using namespace std;

int main(){
    Sala sala("Sala 1", 10);

    sala.reservar(3);
    sala.reservar(5);

    sala.exibirMapa();
    sala.consultar();

    sala.cancelar(3);

    sala.exibirMapa();
    sala.consultar();

    return 0;
    
}
