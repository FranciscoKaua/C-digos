#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "Item.hpp"
#include <vector>
#include <string>
using namespace std;

class Usuario{
    private:
        vector<Item*> itens;
    public:
       
        void adicionarItem(Item* i);
        void listarItens() const;
};
#endif