#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Medico m1("Dr. João", 45, "CRM123", "Cardiologia");
    Enfermeiro e1("Maria", 30, "ENF456", "Noturno");
    
    vector<ProfissionalSaude *> equipe;
    
    equipe.push_back(&m1);
    equipe.push_back(&e1);
    
    cout << "Equipe de Saúde:" << endl;
    for (auto p : equipe)
    {
        p->exibirInfo();
        cout << "-------------------" << endl;
    }

    cout << "Realizando consulta..." << endl;
    
    Pessoa paciente("Carlos", 50);
    Consulta c1(m1, paciente, "Dor no peito");
    
    c1.exibirConsulta();
    
    return 0;
}