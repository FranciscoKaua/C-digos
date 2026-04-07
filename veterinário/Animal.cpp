#include "Animal.hpp"
#include <string>
using namespace std;
Animal::Animal(string nome, int idade):nome(nome), idade(idade){};

string Animal::emitirSom() const{
    return "Som genérico";
}
string Animal::getNome() const{
    return nome;
}
Animal::~Animal(){}