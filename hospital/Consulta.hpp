#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include <string>
#include <iostream>
#include "Medico.hpp"
#include "Pessoa.hpp"

using namespace std;

class Consulta {
    private:
        Medico medico;
        Pessoa paciente;
        string descricao;
        
    public:
       
        Consulta(Medico medico, Pessoa paciente, string descricao);

        void exibirConsulta();
    
};
#endif