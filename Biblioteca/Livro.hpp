#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>
using namespace std;
class Livro{
    private:
        string titulo;
        bool emprestado;
        
    public:
        
        Livro(string titulo);
        
        void emprestar();
        void devolver();
        bool estaEmprestado() const;
        string getTitulo() const;
};
#endif