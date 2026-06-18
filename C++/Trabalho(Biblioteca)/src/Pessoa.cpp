#include <iostream>
#include "../include/Pessoa.hpp"
#include "string"
using namespace std;

Pessoa::Pessoa(string nome, string cpf):nome(nome), cpf(cpf){};

void Pessoa::setNome(string nome){
    this->nome = nome;
};

string Pessoa::getNome() const{
    return nome;
};

void Pessoa::setCpf(string cpf){
    this->cpf = cpf;
}

string Pessoa::getCpf() const{
    return cpf;
}

void Pessoa::exibirDados(){
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
}
Pessoa::~Pessoa(){
}