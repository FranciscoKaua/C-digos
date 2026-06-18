#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP
#include "Usuario.hpp"
#include "Livro.hpp"
#include <string>
using namespace std;

class Emprestimo{
    private:
        Usuario* usuario;
        Livro* livro;
        string dataEmprestimo;
        string dataPrevistaDevolucao;
    public:
        Emprestimo(Usuario* usuario,Livro* livro,string dataEmprestimo,string dataPrevistaDevolucao);
        void registrar();
};

#endif