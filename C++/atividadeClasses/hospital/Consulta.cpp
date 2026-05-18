#include "Consulta.hpp"

Consulta::Consulta(Medico medico, Pessoa paciente, string descricao) : medico(medico), paciente(paciente), descricao(descricao) {}

void Consulta::exibirConsulta(){
    cout << "Consulta realizada por: " << medico.getNome() << endl;
    cout << "Paciente: " << paciente.getNome() << endl;
    cout << "Anamnese: " << descricao << endl;
}