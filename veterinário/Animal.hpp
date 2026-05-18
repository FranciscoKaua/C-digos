#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
using namespace std;
class Animal{
    protected:
        string nome;
        int idade;
    public:
        Animal(string nome, int idade);
        virtual string emitirSom() const;        string getNome() const;
        virtual ~Animal();
};
#endif