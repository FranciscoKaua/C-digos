#include "Administrador.hpp"

Administrador::Administrador(string n, string m, string s)
    : Usuario(n, m, s) {
}

void Administrador::autenticar() {
    cout << nome << " autenticado como administrador.\n";
}

void Administrador::registrarLog() {
    cout << nome << " registrou uma acao no sistema.\n";
}};