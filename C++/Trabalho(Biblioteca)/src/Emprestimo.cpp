#include <iostream>
#include "../include/Emprestimo.hpp"
#include <string>
using namespace std;

Emprestimo::Emprestimo(Usuario* usuario,Livro* livro,string dataEmprestimo,string dataPrevistaDevolucao): usuario(usuario),livro(livro),dataEmprestimo(dataEmprestimo),dataPrevistaDevolucao(dataPrevistaDevolucao){};

void Emprestimo::registrar(){
    livro->emprestar();
    cout << "Emprestimo registrado para "
         << usuario->getNome()
         << endl;
}