#include <iostream>
#include "Biblioteca.hpp"

int main() {
    
    Biblioteca b("Biblioteca Central");

    b.adicionarLivro("Dom Casmurro");
    b.adicionarLivro("O Pequeno Principe");
    b.adicionarLivro("Clean Code");
    
    
    std::cout << "\n--- Lista completa ---\n";
    b.listarLivro();

    std::cout << "\n--- Emprestando Dom Casmurro ---\n";
    b.emprestarLivro("Dom Casmurro");

    std::cout << "\n--- Disponiveis ---\n";
    b.consultarDisponivel();

    std::cout << "\n--- Devolvendo Dom Casmurro ---\n";
    b.devolverLivro("Dom Casmurro");

    std::cout << "\n--- Disponiveis ---\n";
    b.consultarDisponivel();

    return 0;
}