#include <iostream>
#include "../include/BancoDados.hpp"
#include "../include/Bibliotecario.hpp"

using namespace std;

int main(){
    BancoDados banco;
    banco.criarTabelas();

    Bibliotecario biblioteca(1,"Maria","111111111");

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
        cout << "7 - Apagar Livro\n";
        cout << "8 - Apagar Usuario\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){

        case 1:{
            string isbn, titulo, autor;

            cout << "ISBN: ";
            cin >> isbn;
            cin.ignore();

            cout << "Titulo: ";
            getline(cin, titulo);

            cout << "Autor: ";
            getline(cin, autor);

            Livro livro(isbn, titulo, autor);

            biblioteca.cadastrarLivro(livro);
            banco.salvarLivro(livro);
            break;
        }

        case 2:{
            int matricula;
            string nome, cpf;

            cout << "Matricula: ";
            cin >> matricula;
            cin.ignore();

            cout << "Nome: ";
            getline(cin, nome);

            cout << "CPF: ";
            getline(cin, cpf);

            Usuario usuario(matricula, nome, cpf);

            biblioteca.cadastrarUsuario(usuario);
            banco.salvarUsuario(usuario);
            break;
        }
        
        case 3:
            banco.listarLivrosBanco();
            break;

        case 4:
            banco.listarUsuariosBanco();
            break;

        case 5:{
            int usuarioIdx, livroIdx;
            cout << "Indice do usuario: ";
            cin >> usuarioIdx;
            cout << "Indice do livro: ";
            cin >> livroIdx;
            biblioteca.realizarEmprestimo(
                usuarioIdx - 1,
                livroIdx - 1,
                "17/06/2026",
                "24/06/2026"
            );

            break;
        }

        case 6:{
            int livroIdx;
            cout << "Indice do livro: ";
            cin >> livroIdx;
            biblioteca.realizarDevolucao(livroIdx - 1);

            break;
        }
        case 7:{
            string isbn;
            cout << "ISBN do livro: ";
            cin >> isbn;
        
            banco.apagarLivro(isbn);
            break;
        }
        
        case 8:{
            int matricula;
            cout << "Matricula do usuario: ";
            cin >> matricula;
        
            banco.apagarUsuario(matricula);
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