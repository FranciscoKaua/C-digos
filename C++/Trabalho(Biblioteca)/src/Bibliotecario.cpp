#include <iostream>
#include "../include/Bibliotecario.hpp"
#include "string"
using namespace std;

Bibliotecario::Bibliotecario(int codigoFuncionario,string nome, string cpf):Pessoa(nome, cpf),codigoFuncionario(codigoFuncionario){};

void Bibliotecario::cadastrarLivro(Livro livro){
    livros.push_back(livro);
}
void Bibliotecario::cadastrarUsuario(Usuario usuario){
    usuarios.push_back(usuario);
}
void Bibliotecario::realizarEmprestimo(int indiceUsuario,int indiceLivro,string dataEmprestimo,string dataDevolucao){
    if(indiceLivro < 0 ||indiceLivro >= static_cast<int>(livros.size())){
       return;
    }
    if(indiceUsuario < 0 ||indiceUsuario >= static_cast<int>(usuarios.size())){
       return;
    }
    if(!livros[indiceLivro].getDisponivel()){
        cout << "Livro indisponivel.\n";
        return;
    }
    Emprestimo emp(
        &usuarios[indiceUsuario],
        &livros[indiceLivro],
        dataEmprestimo,
        dataDevolucao
    );
    emp.registrar();
    emprestimos.push_back(emp);
    cout << "Emprestimo realizado.\n";
}
void Bibliotecario::realizarDevolucao(int indiceLivro){
    if(indiceLivro < 0 ||indiceLivro >= static_cast<int>(livros.size())){
       return;
    }
    livros[indiceLivro].devolver();
    cout << "Livro devolvido.\n";
}
void Bibliotecario::listarLivros(){
    if(livros.empty()){
        cout << "Nenhum livro cadastrado.\n";
        return;
    }
    for(size_t i = 0; i < livros.size(); i++){
        cout << i + 1 << " - "
             << livros[i].getTitulo()
             << endl;
    }
}

void Bibliotecario::listarUsuarios(){
    if(usuarios.empty()){
        cout << "Nenhum usuario cadastrado.\n";
        return;
    }
    for(size_t i = 0; i < usuarios.size(); i++){
        usuarios[i].exibirDados();
        cout << endl;
    }
}

void Bibliotecario::exibirDados(){
    cout << "Bibliotecario" << endl;
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Codigo: " << codigoFuncionario << endl;
}