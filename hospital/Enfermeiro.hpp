#ifndef ENFERMEIRO_HPP
#define ENFERMEIRO_HPP
#include "ProfissionalSaude.hpp"
#include <string>

class Enfermeiro: public ProfissionalSaude{
   private:
       std::string turno;
   public:
       Enfermeiro(std::string nome, int idade, std::string registro, std::string turno);
       
       void assistirPaciente();
       void exibirInfo() const override;
};
#endif