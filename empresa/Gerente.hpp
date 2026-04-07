#ifndef GERENTE_HPP
#define GERENTE_HPP
#include "Funcionario.hpp"

class Gerente: public Funcionario{
    private:
        double bonus;
    public:
        Gerente(string nome, double salario, double bonus);
        virtual double calculaSalario() const;
};

#endif