#include <iostream>

using namespace std;

const double HORA_TRABALHADA = 16.78;
const double TAXA_PREVIDENCIA_SOCIAL= 0.06;
const double TAXA_IMPOSTO_FEDERAL = 0.14;
const double TAXA_IMPOSTO_ESTADUAL = 0.05;
const double SINDICADO_SEMANAL = 10.;
const double SEGURO_SAUDE = 16.78;

double retornaSalarioBruto(int horasTrabalhada){
    return horasTrabalhada * HORA_TRABALHADA;
}

double retornaTaxaPrevidenciaSocial(double salarioBruto){
    return salarioBruto * TAXA_PREVIDENCIA_SOCIAL;
}

double retornaTaxaImpostoFederal(double salarioBruto){
    return salarioBruto * TAXA_IMPOSTO_FEDERAL;
}

double retornaTaxaImpostoEstadual(double salarioBruto){
    return salarioBruto * TAXA_IMPOSTO_ESTADUAL;
}

double retornaSeguroSaude(int numeroDependentes){
    if(numeroDependentes >= 3){
        return SEGURO_SAUDE;
    }
}

double retornaValorImposto(double salarioBruto){
    return salarioBruto * (TAXA_IMPOSTO_FEDERAL+TAXA_IMPOSTO_ESTADUAL);
}

int main() {
    int horaTrabalhada;
    int numeroDependentes;
    
    cout <<"Quantas horas de trabalho: ";
    cin >> horaTrabalhada;
    cout << "Quantos dependentes: ";
    cin >> numeroDependentes;
    
    
    return 0;
}
