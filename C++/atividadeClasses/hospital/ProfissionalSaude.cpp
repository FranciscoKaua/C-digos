#include <string>
#include "ProfissionalSaude.hpp"

ProfissionalSaude::ProfissionalSaude(std::string registro):Pessoa(nome, idade), registro(registro){}

void ProfissionalSaude::exibirInfo() const{
    Pessoa:: exibirInfo();
    std::cout<<"Registro: "<< registro <<endl;
}