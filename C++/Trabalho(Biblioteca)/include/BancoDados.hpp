#ifndef BANCODADOS_HPP
#define BANCODADOS_HPP

#include <sqlite3.h>
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "Usuario.hpp"

class BancoDados{
    private:
        sqlite3* db;
    
    public:
        BancoDados();
        ~BancoDados();
    
        void criarTabelas();
        void salvarLivro(const Livro& livro);
        void salvarUsuario(const Usuario& u);
        void salvarEmprestimo(int matricula, string isbn, string dataEmp, string dataDev);
        void devolverLivro(const string& isbn);
        void listarLivrosBanco();
        void listarUsuariosBanco();
        void apagarLivro(const string& isbn);
        void apagarUsuario(int matricula);
        
};

#endif