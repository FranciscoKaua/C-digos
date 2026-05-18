#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include "Funcionario.hpp"
#include <vector>
#include <string>
using namespace std;

class Empresa{
    private:
        string nome;
        vector<Funcionario*>funcionarios;
    public:
        Empresa(string nome);
        void adicionarFuncionario(Funcionario* f);
        void calcularFolha() const;
        
        ~Empresa();
};

#endif