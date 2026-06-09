#include <vector>

#include "Medico.hpp"
#include "Enfermeiro.hpp"
#include "Administrador.hpp"

using namespace std;

int main() {

    vector<Usuario*> usuarios;

    usuarios.push_back(
        new Medico("Carlos", "M101", "Cardiologia")
    );

    usuarios.push_back(
        new Enfermeiro("Ana", "E202", "UTI")
    );

    usuarios.push_back(
        new Administrador("Marcos", "A303", "TI")
    );

    cout << "===== DADOS DOS USUARIOS =====\n\n";

    for (Usuario* u : usuarios) {
        u->exibirDados();
        cout << endl;
    }

    cout << "===== FUNCIONALIDADES =====\n\n";

    Medico m("Joao", "M404", "Neurologia");

    m.autenticar();
    m.gerarRelatorio();
    m.assinarDocumento();

    cout << endl;

    Enfermeiro e("Maria", "E505", "Pediatria");

    e.autenticar();
    e.gerarRelatorio();

    cout << endl;

    Administrador a("Pedro", "A606", "Administracao");

    a.autenticar();
    a.registrarLog();

    cout << endl;

    for (Usuario* u : usuarios) {
        delete u;
    }

    return 0;
}