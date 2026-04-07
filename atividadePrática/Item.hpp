#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
using namespace std;

class Item{
    protected:
        string titulo;
        int ano;
        
    public:
        Item(string titulo, int ano);
        string getTitulo() const;
        virtual void exibirInfo() const;
        virtual ~Item();
};
#endif