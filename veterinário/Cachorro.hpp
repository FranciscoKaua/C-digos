#ifndef CACHORRO_HPP
#define CACHORRO_HPP
#include <string>
#include "Animal.hpp"

class Cachorro:public Animal{
    public:
        Cachorro(std::string nome, int idade);
        std::string emitirSom() const override;
        
};
#endif