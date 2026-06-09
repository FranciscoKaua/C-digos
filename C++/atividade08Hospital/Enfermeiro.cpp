#include "Enfermeiro.hpp"

Enfermeiro::Enfermeiro(string n, string m, string s)
    : Usuario(n, m, s) {
}

void Enfermeiro::autenticar() {
    cout << nome << " autenticado como enfermeiro.\n";
}

void Enfermeiro::gerarRelatorio() {
    cout << nome << " gerou um relatorio de enfermagem.\n";
}