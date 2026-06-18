#include <iostream>
#include "../include/Bibliotecario.hpp"
using namespace std;

int main(){
    Bibliotecario biblioteca(1, "Maria", "111111111");;
    int opcao;
    do{
        cout << "----------\n";
        cout << "BIBLIOTECA\n";
        cout << "1 - Cadastrar Livro\n";
        cout << "2 - Cadastrar Usuario\n";
        cout << "3 - Listar Livros\n";
        cout << "4 - Listar Usuarios\n";
        cout << "5 - Realizar emprestimo\n";
        cout << "6 - Realizar devolucao\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:{
                string isbn;
                string titulo;
                string autor;
    
                cout << "ISBN: ";
                cin >> isbn;
    
                cin.ignore();
    
                cout << "Titulo: ";
                getline(cin, titulo);
    
                cout << "Autor: ";
                getline(cin, autor);
    
                Livro livro(isbn, titulo, autor);
                biblioteca.cadastrarLivro(livro);
                break;
            }
            case 2:{
                int matricula;
                string nome;
                string cpf;
    
                cout << "Matricula: ";
                cin >> matricula;
    
                cin.ignore();
    
                cout << "Nome: ";
                getline(cin, nome);
    
                cout << "CPF: ";
                getline(cin, cpf);
    
                Usuario usuario(matricula, nome, cpf);
                biblioteca.cadastrarUsuario(usuario);
                break;
            }
            case 3:
                biblioteca.listarLivros();
                break;
            case 4:
                biblioteca.listarUsuarios();
                break;
            case 5:{
                int usuario;
                int livro;
            
                cout << "Indice do usuario: ";
                cin >> usuario;
            
                cout << "Indice do livro: ";
                cin >> livro;
            
                biblioteca.realizarEmprestimo(
                    usuario - 1,
                    livro - 1,
                    "17/06/2026",
                    "24/06/2026"
                );
                break;
            }
            case 6:{
                int livro;
                cout << "Indice do livro: ";
                cin >> livro;
                biblioteca.realizarDevolucao(livro - 1);
                break;
            }
            case 0:
                cout << "Encerrando...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
            }

    }while(opcao != 0);
    return 0;
}