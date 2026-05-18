#include "Usuario.hpp"
#include <vector>
#include <string>
using namespace std;

void Usuario:: adicionarItem(Item* i){
    itens.push_back(i);
}

void Usuario::listarItens() const{
    for(Item* i : itens){
        i->exibirInfo();
    }
}