#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <string>
using namespace std;

class Funcionario{
    protected:
        string nome;
        double salario;
    public:
        Funcionario(string nome, double salario);
        virtual double calculaSalario() const;
        string getNome() const;
        
        virtual ~Funcionario();
};
#endif