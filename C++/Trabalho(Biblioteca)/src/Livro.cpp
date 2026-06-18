#include <iostream>
#include "../include/Livro.hpp"
#include "string"
using namespace std;

Livro::Livro(string isbn, string titulo, string autor, bool disponivel):isbn(isbn), titulo(titulo), autor(autor), disponivel(disponivel){};
void Livro::emprestar(){
    disponivel = false;
};
void Livro::devolver(){
    disponivel = true;
};
string Livro::getTitulo() const{
    return titulo;
}
bool Livro::getDisponivel() const{
    return disponivel;
}