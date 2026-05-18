#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa{
protected:
    std::string nome;
    int idade;
public:
    Pessoa(std::string nome, int idade);
    
    std::string getNome() const;
    int getIdade() const;
    void setNome(std::string nome);
    void setIdade(int idade);
    virtual void exibirInfo() const;
    
};

#endif