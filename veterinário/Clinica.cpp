
#include <string>
#include <vector>
#include <iostream>
#include "Clinica.hpp"

Clinica::Clinica(std::string nome):nome(nome){}

void Clinica::adicionarAnimal(Animal* a){
    animais.push_back(a);
};

void Clinica::listarAnimais() const{
    for(Animal* a : animais){
        std::cout<<"Nome: "<<a -> getNome()
                 <<" Som: "<<a -> emitirSom() 
                 <<endl;
    }
};

Clinica::~Clinica(){
    for(Animal* a: animais){
        delete a;
    }
 };