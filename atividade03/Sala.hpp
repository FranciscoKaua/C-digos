#ifndef SALA_HPP
#define SALA_HPP

#include <string>
#include <vector>
#include "Assento.hpp"

using namespace std;

class Sala{
    private:
        string nome;
        vector<Assento> assentos; 
    public:
        Sala(string nome, int quantAssentos);
        
        void reservar(int numAssento);
        void cancelar(int numAssento);
        void exibirMapa() const;
        void consultar() const;
    
};
#endif