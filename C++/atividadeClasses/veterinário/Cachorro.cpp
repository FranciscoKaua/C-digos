#include "Cachorro.hpp"
#include <string>
Cachorro::Cachorro(std::string nome, int idade):Animal(nome,idade){};

std::string Cachorro::emitirSom() const{
    return "Au Au";
};