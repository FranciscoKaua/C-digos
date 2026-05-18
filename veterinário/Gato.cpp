#include "Cachorro.hpp"
#include <string>
Gato::Gato(std::string nome, int idade):Animal(nome,idade){};

std::string Gato::emitirSom() const{
    return "Miau";
};