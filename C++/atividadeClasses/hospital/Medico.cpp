#include <string>
#include "Medico.hpp"

Medico::Medico(std:string nome,std::string registro, int idade, std::string especialização): ProfessionalSaude(nome, idade, registro), especialização(especialização){};

void Medico::diagnosticar(){
    std::cout<<"Diagnosticando..\n";
}

void Medico::exibirInfo() const {
    ProfissionalSaude:: exibirInfo();
    std::cout<<"Especialização: "<<especialização<<std::endl;
}
