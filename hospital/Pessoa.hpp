#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <iostream>
using namespace std;

class Pessoa{
private:
    string nome;
    int idade;
public:
    Pessoa(string nome, int idade);
    
    string getNome();
    int getIdade();
    string setNome();
    int setIdade();
    void exibirInfo() const;
};

#endif