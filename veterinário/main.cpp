#include <iostream>
#include "Clinica.hpp"
#include "Cachorro.hpp"
#include "Gato.hpp"
int main(){
    Clinica c("Veter");
    c.adicionarAnimal(new Cachorro("Rex", 4));
    c.adicionarAnimal(new Gato("Ana", 2));
    
    c.listarAnimais();
    return 0;
}