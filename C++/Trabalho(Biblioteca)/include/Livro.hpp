#ifndef LIVRO_HPP
#define LIVRO_HPP
#include <string>
using namespace std;
class Livro{
    private:
        string isbn;
        string titulo;
        string autor;
        bool disponivel;
    public:
        Livro(string isbn, string titulo, string autor, bool disponivel=true);
        void emprestar();
        void devolver();
        string getTitulo() const;
        bool getDisponivel() const;
};
#endif