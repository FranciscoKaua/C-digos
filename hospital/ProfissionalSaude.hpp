#ifndef PROFISSIONALSAUDE_HPP
#define PROFISSIONALSAUDE_HPP
#include "Pessoa.hpp"
#include <string>
class profissionalSaude:public Pessoa{
    protected:
        std::string registro;
    public:
        profissionalSaude(std::string nome, int idade, std::string registro);
        
        void exibirInfo() const override;
};

#endif