#include <iostream>
#include "Gerente.hpp"

Gerente::Gerente(string nome, double salario, double bonus): Funcionario(nome, salario), bonus(bonus){}

double Gerente::calculaSalario() const{
    return salario + bonus;
}