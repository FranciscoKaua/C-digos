#include "Livro.hpp"
#include <string>
#include <iostream>
using namespace std;

Livro::Livro(string titulo, int ano, string autor):Item(titulo, ano), autor(autor){};

void Livro::exibirInfo() const{
    Item::exibirInfo();
    cout<<"Autor: "<<autor<<endl;
};