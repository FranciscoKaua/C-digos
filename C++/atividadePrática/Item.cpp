#include <string>
#include <iostream>
#include "Item.hpp"
using namespace std;

Item::Item(string titulo, int ano):titulo(titulo), ano(ano){}

string Item::getTitulo() const{
    return titulo;
}
void Item::exibirInfo() const{
    cout<<"Titulo: "<<titulo
        <<" Ano: "<<ano<<endl;
}
Item::~Item(){}