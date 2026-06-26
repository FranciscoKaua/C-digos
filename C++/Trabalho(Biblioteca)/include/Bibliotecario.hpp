#ifndef BIBLIOTECARIO_HPP
#define BIBLIOTECARIO_HPP
#include <vector>
#include "Pessoa.hpp"
#include "Livro.hpp"
#include "Usuario.hpp"
#include "Emprestimo.hpp"
using namespace std;

class Bibliotecario: public Pessoa{
    private:
        vector<Livro> livros;
        vector<Usuario> usuarios;
        vector<Emprestimo> emprestimos;
        int codigoFuncionario;
    public:
        Bibliotecario(int codigoFuncionario, string nome, string cpf);
        void cadastrarLivro(Livro livro);
        void cadastrarUsuario(Usuario usuario);
        void realizarEmprestimo(int indiceUsuario, int indiceLivro, string dataEmprestimo, string dataDevolucao);
        void realizarDevolucao(int indiceLivro);
        void listarLivros();
        void listarUsuarios();
        int getCodigoFuncionario() const;
        void exibirDados() override;
};
#endif