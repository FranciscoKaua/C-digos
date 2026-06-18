#include <iostream>
#include "../include/Usuario.hpp"
#include "string"
using namespace std;

Usuario::Usuario(int matricula, string nome, string cpf)
    : Pessoa(nome, cpf), matricula(matricula){}

void Usuario::consultarLivros(){
    cout << "Consultando livros..." << endl;
}

int Usuario::getMatricula() const{
    return matricula;
}

void Usuario::exibirDados(){
    cout << "Usuario" << endl;
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Matricula: " << matricula << endl;
}