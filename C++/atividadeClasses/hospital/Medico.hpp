#ifndef MEDICO_HPP
#define MEDICO_HPP
#include "ProfissionalSaude.hpp"
#include <string>

class Medico: public ProfissionalSaude{
    private:
        std::string especialização;
    public:
    
        Medico(std:string nome,std::string registro, int idade, std::string especialização);
        void diagnosticar();
        
        void exibirInfo() const override;
};

#endif