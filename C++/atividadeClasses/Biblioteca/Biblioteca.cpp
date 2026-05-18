#include <iostream>
#include <string>
#include <vector>
#include "Biblioteca.hpp"
using namespace std;

Biblioteca::Biblioteca(string nome):nome(nome){};

void Biblioteca::adicionarLivro(string nome){
    livros.push_back(Livro(nome));
};

void Biblioteca::emprestarLivro(string nome){
    for(Livro &l : livros){
        if(l.getTitulo() == nome){
            if(!l.estaEmprestado()){
               l.emprestar();
               cout<<"Livro "<<l.getTitulo()<<"  foi emprestado" <<endl;
            }else{
               cout<<"Livro "<<l.getTitulo()<<" indisponível" <<endl;
            }      
            return;                
        }
        
        
    }
    cout<<"Livro não encontrado\n";
};

void Biblioteca::devolverLivro(string nome){
      for(Livro &l : livros){
        if(l.getTitulo() == nome){
            if(l.estaEmprestado()){
               l.devolver();
               cout<<"Livro "<<l.getTitulo()<<"  foi devolvido" <<endl;
            }else{
               cout<<"Livro "<<l.getTitulo()<<" não foi emprestado" <<endl;
            }
            return;                     
        }
        
        
    }
    cout<<"Livro não encontrado\n";
};

void Biblioteca::listarLivro() const{
   int cont = 1;
   for(const Livro &l : livros){
       cout<<cont<<". "<<l.getTitulo()<<endl;
       cont ++;
   }
};

void Biblioteca::consultarDisponivel() const{
    int cont = 0;
    for(const Livro &l : livros){
        if(!l.estaEmprestado()){
            cout<<cont + 1<<". "<<l.getTitulo()<<endl;
            cont++;
        }
    }
    cout<<"Total: "
        <<cont
        <<" de " 
        <<livros.size()
        <<endl;
};        