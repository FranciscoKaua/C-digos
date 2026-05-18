#ifndef CLINICA_HPP
#define CLINICA_HPP
#include "Animal.hpp"
#include <string>
#include <vector>

class Clinica{
    private:
        std::string nome;
        std::vector<Animal*> animais;
    public:
        Clinica(std::string nome);
        void adicionarAnimal(Animal* a);
        void listarAnimais() const;
        ~Clinica();
};
#endif