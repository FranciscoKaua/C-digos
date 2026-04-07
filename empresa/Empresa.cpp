#include "Empresa.hpp"
#include <string>
#include <vector>

Empresa::Empresa(string nome):nome(nome){};

void Empresa::adicionarFuncionario(Funcionario* f){
    funcionarios.push_back(f);
}

void Empresa::calcularFolha() const{
    double total = 0;
    for(Funcionario* f : funcionarios){
        total += f->calculaSalario();
    }
    cout<<"Folha total: "<<total<<endl;
}
Empresa::~Empresa(){
    for(Funcionario* f : funcionarios){
        delete f;
    }
}