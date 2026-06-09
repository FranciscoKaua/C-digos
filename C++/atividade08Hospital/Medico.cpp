#include "Medico.hpp"

Medico::Medico(string n, string m, string s)
    : Usuario(n, m, s) {
}

void Medico::autenticar() {
    cout << nome << " autenticado como medico.\n";
}

void Medico::gerarRelatorio() {
    cout << nome << " gerou um relatorio medico.\n";
}

void Medico::assinarDocumento() {
    cout << nome << " assinou um documento digitalmente.\n";
}