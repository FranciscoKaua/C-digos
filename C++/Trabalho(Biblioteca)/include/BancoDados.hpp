#ifndef BANCODADOS_HPP
#define BANCODADOS_HPP
#include <sqlite3.h>
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "Usuario.hpp"
#include "Bibliotecario.hpp"

class BancoDados{
    private:
        sqlite3* db;
    public:
        BancoDados();
        ~BancoDados();
    
        void criarTabelas();
        void salvarLivro(const Livro& livro);
        void atualizarLivro(string isbn,string titulo,string autor);
        void apagarLivro(const string& isbn);
        void listarLivrosBanco();
        
        void salvarUsuario(const Usuario& u);
        void atualizarUsuario(int matricula, string nome, string cpf);
        void apagarUsuario(int matricula);
        void listarUsuariosBanco();
        
        void salvarBibliotecario(const Bibliotecario& b);
        void atualizarBibliotecario(int codigo, string nome, string cpf);
        void removerBibliotecario(int codigo);
        void listarBibliotecarios();
        
        void salvarEmprestimo(int matricula, string isbn, string dataEmp, string dataDev);
        void atualizarEmprestimo(int id,string dataDevoluca);
        void removerEmprestimo(int id);
        void listarEmprestimos();
        
        void contarLivrosUsuario(int matricula);
        void contarLivrosAutor(string autor);
        void contarLivrosDisponiveis();
        void listarEmprestimosAtrasados();
                
};

#endif