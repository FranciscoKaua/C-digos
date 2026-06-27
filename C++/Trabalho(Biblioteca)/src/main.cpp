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
        cout << "2 - Atualizar Livro\n";
        cout << "3 - Apagar Livro\n";
        cout << "4 - Listar Livros\n";
        
        cout << "5 - Cadastrar Usuario\n";
        cout << "6 - Atualizar Usuario\n";
        cout << "7 - Apagar Usuario\n";
        cout << "8 - Listar Usuarios\n";
        
        cout << "9 - Cadastrar Bibliotecario\n";
        cout << "10 - Atualizar Bibliotecario\n";
        cout << "11 - Apagar Bibliotecario\n";
        cout << "12 - Listar Bibliotecarios\n";
        
        cout << "13 - Cadastrar Emprestimo\n";
        cout << "14 - Atualizar Emprestimo\n";
        cout << "15 - Apagar Emprestimo\n";
        cout << "16 - Listar Emprestimos\n";
        
        cout << "17 - Livros por Usuario\n";
        cout << "18 - Livros por Autor\n";
        cout << "19 - Livros Disponiveis\n";
        cout << "20 - Livros Atrasados\n";

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
                string isbn;
                string titulo;
                string autor;
                cout << "ISBN do livro: ";
                cin >> isbn;
                cin.ignore();
                cout << "Novo titulo: ";
                getline(cin, titulo);
                cout << "Novo autor: ";
                getline(cin, autor);
            
                banco.atualizarLivro(isbn,titulo,autor);
                cout << "Livro atualizado.\n";
                break;
            }
            case 3:{
                string isbn;
                cout << "ISBN do livro: ";
                cin >> isbn;
                banco.apagarLivro(isbn);
                break;
            }
            case 4:{
                banco.listarLivrosBanco();
                break;
            }
            case 5:{
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
            case 6:{
                int matricula;
                string nome;
                string cpf;
                cout << "Matricula: ";
                cin >> matricula;
                cin.ignore();
                cout << "Novo nome: ";
                getline(cin,nome);
                cout << "Novo CPF: ";
                getline(cin,cpf);
                banco.atualizarUsuario(matricula,nome,cpf);
                break;
            }
            case 7:{
                int matricula;
                cout << "Matricula do usuario: ";
                cin >> matricula;
                banco.apagarUsuario(matricula);
                break;
            }
            case 8:{
                banco.listarUsuariosBanco();
                break;
            }
            case 9:{
                int codigo;
                string nome, cpf;
                cout << "Codigo: ";
                cin >> codigo;
                cin.ignore();
                cout << "Nome: ";
                getline(cin, nome);
                cout << "CPF: ";
                getline(cin, cpf);

                Bibliotecario b(codigo, nome, cpf);
                banco.salvarBibliotecario(b);
                break;
            }
            case 10:{
                int codigo;
                string nome, cpf;
                cout << "Codigo do bibliotecario: ";
                cin >> codigo;
                cin.ignore();
                cout << "Novo nome: ";
                getline(cin, nome);
                cout << "Novo CPF: ";
                getline(cin, cpf);
            
                banco.atualizarBibliotecario(codigo, nome, cpf);
                break;
            }
            case 11:{
                int codigo;
                cout << "Codigo do bibliotecario: ";
                cin >> codigo;
                banco.removerBibliotecario(codigo);
                break;
            }
            case 12:{
                banco.listarBibliotecarios();
                break;
            }
            case 13:{
                int matricula;
                string isbn;
                cout << "Matricula do usuario: ";
                cin >> matricula;
                cout << "ISBN do livro: ";
                cin >> isbn;
            
                banco.salvarEmprestimo(matricula,isbn,"2026-06-17","2026-06-24");
                break;
            }
            case 14:{
                int id;
                string data;
                cout << "ID do emprestimo: ";
                cin >> id;
                cout << "Nova data de devolucao: ";
                cin >> data;
                
                banco.atualizarEmprestimo(id,data);
                break;
            }
            case 15:{
                int id;
                cout << "ID do emprestimo: ";
                cin >> id;
                banco.removerEmprestimo(id);
                break;
            }
            case 16:{
                banco.listarEmprestimos();
                break;
            }
            case 17:{
                int matricula;
                cout << "Matricula: ";
                cin >> matricula;
                banco.contarLivrosUsuario(matricula);
                break;
            }
            case 18:{
                string autor;
                cin.ignore();
                cout << "Autor: ";
                getline(cin, autor);
            
                banco.contarLivrosAutor(autor);
                break;
            }
            case 19:{
                banco.contarLivrosDisponiveis();
                break;
            }
            case 20:{
                banco.listarEmprestimosAtrasados();
                break;
            } 
            case 0:{
                cout << "Encerrando...\n";
                break;
            }  
            default:{
                cout << "Opcao invalida.\n";
            }
        }

    }while(opcao != 0);

    return 0;
}