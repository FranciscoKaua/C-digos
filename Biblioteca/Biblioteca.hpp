#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <string>
#include <vector>
#include "Livro.hpp"
using namespace std;

class Biblioteca{
    private:
        string nome;
        vector<Livro>livros;
    public:
        Biblioteca(string nome);
        void adicionarLivro(string nome);
        void emprestarLivro(string nome);
        void devolverLivro(string nome);
        void listarLivro() const;
        void consultarDisponivel() const;        
};
#endif