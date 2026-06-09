#include "Usuario.hpp"

Usuario::Usuario(string n, string m, string s) {
    nome = n;
    matricula = m;
    setor = s;
}

void Usuario::exibirDados() {
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Setor: " << setor << endl;
}

Usuario::~Usuario() {
}