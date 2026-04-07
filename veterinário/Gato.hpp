#ifndef GATO_HPP
#define GATO_HPP
#include <string>
#include "Animal.hpp"

class Gato:public Animal{
    public:
        Gato(std::string nome, int idade);
        std::string emitirSom() const override;
        
};
#endif