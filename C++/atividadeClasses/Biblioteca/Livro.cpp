#include <iostream>
#include "Livro.hpp"
#include <string>
using namespace std;

Livro::Livro(string titulo):titulo(titulo), emprestado(false){}

void Livro::emprestar(){
    emprestado = true;
};
void Livro::devolver(){
    emprestado = false;
};
bool Livro::estaEmprestado() const{
    return emprestado;
};
string Livro::getTitulo() const{
    return titulo;
};
