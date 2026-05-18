#include <iostream>
#include "Funcionario.hpp"
#include <string>
using namespace std;

Funcionario::Funcionario(string nome, double salario):nome(nome), salario(salario){}

double Funcionario::calculaSalario() const{
    return salario;
}

string Funcionario::getNome() const{
    return nome;
}
Funcionario::~Funcionario() {}