#include "Pessoa.hpp"
#include <string>
#include <upstream>

Pessoa::Pessoa(std::string nome, int idade): nome(nome), idade(idade){}

std::string Pessoa::getNome() const{
    return nome;
}

int Pessoa::getIdade() const{
    return idade;
}

void Pessoa::setNome(std::string nome){
    nome = nome;
};
void Pessoa::setIdade(int idade){
    idade = idade;
}
void Pessoa::exibirInfo() const{
    std::cout<<"Nome: "<<nome<<" Idade: "<<idade<<std::endl;
};
