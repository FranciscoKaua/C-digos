#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
using namespace std;

class Usuario {
protected:
    string nome;
    string matricula;
    string setor;

public:
    Usuario(string n, string m, string s);

    virtual void exibirDados();

    virtual ~Usuario();
};

#endif