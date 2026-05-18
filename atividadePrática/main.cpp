#include <iostream>
#include "Livro.hpp"
#include "Usuario.hpp"

int main() {
    Livro l1("Livro 01", 2020, "Alex");
    Livro* l2 = new Livro("Livro 02", 2024, "Jorge");

    Usuario user;

    user.adicionarItem(&l1);
    user.adicionarItem(l2);

    user.listarItens();

    delete l2;

    return 0;
}