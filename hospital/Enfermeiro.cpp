#include "Enfermeiro.hpp"
#include <string>

Enfermeiro::Enfermeiro(std::string nome, int idade, std::string registro, std::string turno): ProfessionalSaude(nome, idade, registro),turno(turno);

void Enfermeiro::assistirPaciente(){
    std::cout<<"Assistindo paciente\n";
}

void Enfermeiro::exibirInfo()const{
    Enfermeiro::exibirInfo();
    std::cout<<"Turno: "<<turno<<std::endl;
}