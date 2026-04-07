#ifndef LIVRO_HPP
#define LIVRO_HPP
#include "Item.hpp"
#include <string>
using namespace std;

class Livro: public Item{
    private:
        string autor;
        
    public:
        Livro(string titulo, int ano, string autor);
        
        void exibirInfo() const override;
};
#endif